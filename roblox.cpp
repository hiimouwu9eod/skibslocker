#include "roblox.hpp"
#include "offsets.hpp"
#include <cmath>
#include <tlhelp32.h>

namespace roblox {
namespace {

// Children are a pointer vector at Instance::ChildrenStart (0x78);
// end sits +8 (standard vector layout). The dump's ChildrenEnd=0x8 is the
// identity field, not the vector end, so it is intentionally not used.
bool ReadChildren(const mem::Reader& r, uintptr_t inst, std::vector<uintptr_t>& out) {
    out.clear();
    uintptr_t start = 0, end = 0;
    if (!r.read<uintptr_t>(inst + Offsets::Instance::ChildrenStart, start))
        return false;
    if (!r.read<uintptr_t>(inst + Offsets::Instance::ChildrenStart + 8, end))
        return false;
    if (start < 0x10000 || end < start)
        return false;
    size_t count = (end - start) / 8;
    if (count > 5000)
        return false;
    out.resize(count);
    for (size_t i = 0; i < count; ++i) {
        if (!r.read<uintptr_t>(start + i * 8, out[i]))
            return false;
    }
    return true;
}

bool GetName(const mem::Reader& r, uintptr_t inst, std::string& name) {
    // NameContainer (0x70) holds the instance name string object.
    if (r.readString(inst + Offsets::Instance::NameContainer, name) && !name.empty())
        return true;
    return false;
}

bool GetClassName(const mem::Reader& r, uintptr_t inst, std::string& cls) {
    uintptr_t desc = 0;
    if (!r.read<uintptr_t>(inst + Offsets::Instance::ClassDescriptor, desc))
        return false;
    return r.readString(desc + Offsets::Instance::ClassName, cls);
}

bool FindChildByName(const mem::Reader& r, uintptr_t parent, const char* want, uintptr_t& found) {
    std::vector<uintptr_t> kids;
    if (!ReadChildren(r, parent, kids))
        return false;
    for (auto k : kids) {
        std::string n;
        if (GetName(r, k, n) && n == want) {
            found = k;
            return true;
        }
    }
    return false;
}

bool FindChildByClass(const mem::Reader& r, uintptr_t parent, const char* want, uintptr_t& found) {
    std::vector<uintptr_t> kids;
    if (!ReadChildren(r, parent, kids))
        return false;
    for (auto k : kids) {
        std::string c;
        if (GetClassName(r, k, c) && c == want) {
            found = k;
            return true;
        }
    }
    return false;
}

} // namespace

uintptr_t GetModuleBase(uint32_t pid) {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (snap == INVALID_HANDLE_VALUE)
        return 0;
    MODULEENTRY32W me{};
    me.dwSize = sizeof(me);
    uintptr_t base = 0;
    if (Module32FirstW(snap, &me))
        base = reinterpret_cast<uintptr_t>(me.modBaseAddr);
    CloseHandle(snap);
    return base;
}

bool Refresh(const mem::Reader& r, Snapshot& out, bool teamCheck, float maxDist) {
    out.players.clear();
    out.hasView = false;
    out.error.clear();
    if (!r.attached()) {
        out.error = L"not attached";
        return false;
    }
    uintptr_t base = r.base();

    // FakeDataModel(RVA) -> RealDataModel.
    uintptr_t fake = 0;
    if (!r.read<uintptr_t>(base + Offsets::FakeDataModel::Pointer, fake)) {
        out.error = L"FakeDataModel read failed (version mismatch or blocked)";
        return false;
    }
    uintptr_t dm = 0;
    if (!r.read<uintptr_t>(fake + Offsets::FakeDataModel::RealDataModel, dm)) {
        out.error = L"RealDataModel read failed";
        return false;
    }

    // View matrix via VisualEngine static.
    uintptr_t engine = 0;
    if (r.read<uintptr_t>(base + Offsets::VisualEngine::Pointer, engine)) {
        mem::ViewMatrix vm{};
        if (r.read<mem::ViewMatrix>(engine + Offsets::VisualEngine::ViewMatrix, vm))
            out.view = vm, out.hasView = true;
    }
    int vw = 0, vh = 0;
    if (r.read<int>(engine + Offsets::VisualEngine::Dimensions, vw) &&
        r.read<int>(engine + Offsets::VisualEngine::Dimensions + 4, vh)) {
        out.screenW = vw;
        out.screenH = vh;
    }

    // Players service: child of DataModel named/typed "Players".
    uintptr_t playersSvc = 0;
    if (!FindChildByName(r, dm, "Players", playersSvc) &&
        !FindChildByClass(r, dm, "Players", playersSvc)) {
        out.error = L"Players service not found";
        return false;
    }

    uintptr_t localPlayer = 0;
    r.read<uintptr_t>(playersSvc + Offsets::Player::LocalPlayer, localPlayer);
    uintptr_t localTeam = 0;
    if (localPlayer)
        r.read<uintptr_t>(localPlayer + Offsets::Player::Team, localTeam);

    std::vector<uintptr_t> kids;
    if (!ReadChildren(r, playersSvc, kids)) {
        out.error = L"Players children unreadable";
        return false;
    }

    for (auto p : kids) {
        PlayerEntry e{};
        e.isLocal = (p == localPlayer);
        if (e.isLocal)
            continue; // never draw self
        r.read<uintptr_t>(p + Offsets::Player::Team, e.team);
        if (teamCheck && localTeam && e.team == localTeam)
            continue;
        r.readString(p + Offsets::Player::DisplayName, e.name);
        if (e.name.empty())
            r.readString(p + Offsets::Instance::NameContainer, e.name);

        uintptr_t character = 0;
        r.read<uintptr_t>(p + Offsets::Player::ModelInstance, character);
        if (!character)
            continue;

        uintptr_t hrp = 0, humanoid = 0;
        FindChildByName(r, character, "HumanoidRootPart", hrp);
        FindChildByName(r, character, "Humanoid", humanoid);
        if (!humanoid)
            FindChildByClass(r, character, "Humanoid", humanoid);
        if (humanoid) {
            r.read<float>(humanoid + Offsets::Humanoid::Health, e.health);
            r.read<float>(humanoid + Offsets::Humanoid::MaxHealth, e.maxHealth);
            // Dead players: skip.
            if (e.maxHealth > 0 && e.health <= 0.5f)
                continue;
            // Prefer authoritative HRP pointer off the humanoid.
            uintptr_t hrp2 = 0;
            if (r.read<uintptr_t>(humanoid + Offsets::Humanoid::HumanoidRootPart, hrp2) && hrp2)
                hrp = hrp2;
        }
        if (hrp) {
            mem::Vec3 pos{};
            if (r.read<mem::Vec3>(hrp + Offsets::Primitive::Position, pos)) {
                e.root = pos;
                e.hasRoot = true;
            }
        }
        if (!e.hasRoot)
            continue;
        (void)maxDist; // distance culling happens in screen space after W2S
        out.players.push_back(std::move(e));
    }
    return true;
}

} // namespace roblox
