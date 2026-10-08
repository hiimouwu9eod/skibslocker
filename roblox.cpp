#include "roblox.hpp"
#include "offsets.hpp"
#include <cmath>
#include <cstdio>
#include <tlhelp32.h>

namespace roblox {
namespace {

// Children live behind a node struct at Instance::ChildrenStart (0x78):
// end = [node+8], first entry = [node], stride 0x10 until entry == end.
// (Ported from omega's get_children; a flat pointer array does not match live memory.)
bool ReadChildren(const mem::Reader& r, uintptr_t inst, std::vector<uintptr_t>& out) {
    out.clear();
    uintptr_t node = 0;
    if (!r.read<uintptr_t>(inst + Offsets::Instance::ChildrenStart, node) || node < 0x10000)
        return false;
    uintptr_t end = 0, cur = 0;
    if (!r.read<uintptr_t>(node + 8, end))
        return false;
    if (!r.read<uintptr_t>(node, cur))
        return false;
    for (int i = 0; i < 9000; ++i) {
        if (cur == end)
            break;
        uintptr_t child = 0;
        if (!r.read<uintptr_t>(cur, child))
            return false;
        out.push_back(child);
        cur += 0x10;
    }
    return true;
}

bool GetName(const mem::Reader& r, uintptr_t inst, std::string& name) {
    // NameContainer (0x70) points at the name string object (omega's get_name).
    uintptr_t p = 0;
    if (!r.read<uintptr_t>(inst + Offsets::Instance::NameContainer, p))
        return false;
    return r.readString(p, name);
}

bool GetClassName(const mem::Reader& r, uintptr_t inst, std::string& cls) {
    // 3-hop with 0x1F flag redirect (omega's get_class_name).
    uintptr_t p1 = 0, p2 = 0;
    if (!r.read<uintptr_t>(inst + Offsets::Instance::ClassDescriptor, p1) || p1 < 0x10000)
        return false;
    if (!r.read<uintptr_t>(p1 + Offsets::Instance::ClassName, p2) || p2 < 0x10000)
        return false;
    uintptr_t fl = 0;
    if (r.read<uintptr_t>(p2 + 0x18, fl) && fl == 0x1F) {
        if (!r.read<uintptr_t>(p2, p2) || p2 < 0x10000)
            return false;
    }
    return r.readString(p2, cls);
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

bool Project(const mem::ViewMatrix& vm, const mem::Vec3& p, int w, int h, float& sx,
             float& sy, float& depth) {
    float x = vm.m[0] * p.x + vm.m[4] * p.y + vm.m[8] * p.z + vm.m[12];
    float y = vm.m[1] * p.x + vm.m[5] * p.y + vm.m[9] * p.z + vm.m[13];
    float ww = vm.m[3] * p.x + vm.m[7] * p.y + vm.m[11] * p.z + vm.m[15];
    if (ww < 0.1f)
        return false;
    depth = ww;
    sx = (w * 0.5f) * (1.0f + x / ww);
    sy = (h * 0.5f) * (1.0f - y / ww);
    return true;
}

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

std::string Diag(uint32_t pid) {
    char buf[256];
    std::string rep;
    mem::Reader r;
    std::wstring err;
    if (!r.attach(pid, err)) {
        rep += "attach: FAIL\n";
        return rep;
    }
    uintptr_t base = r.base();
    snprintf(buf, sizeof(buf), "base=0x%llx\n", (unsigned long long)base);
    rep += buf;

    uintptr_t fake = 0;
    bool okFake = r.read<uintptr_t>(base + Offsets::FakeDataModel::Pointer, fake);
    snprintf(buf, sizeof(buf), "fake read=%d val=0x%llx\n", okFake, (unsigned long long)fake);
    rep += buf;
    if (!okFake)
        return rep + "STOP: FakeDataModel unreadable\n";

    uintptr_t dm = 0;
    bool okDm = r.read<uintptr_t>(fake + Offsets::FakeDataModel::RealDataModel, dm);
    snprintf(buf, sizeof(buf), "datamodel read=%d val=0x%llx\n", okDm, (unsigned long long)dm);
    rep += buf;
    if (!okDm)
        return rep + "STOP: RealDataModel unreadable\n";

    uintptr_t ws = 0;
    bool okWs = r.read<uintptr_t>(dm + Offsets::DataModel::Workspace, ws);
    snprintf(buf, sizeof(buf), "workspace read=%d val=0x%llx\n", okWs, (unsigned long long)ws);
    rep += buf;

    std::vector<uintptr_t> kids;
    if (!ReadChildren(r, dm, kids)) {
        snprintf(buf, sizeof(buf), "children walk FAILED\n");
        rep += buf;
        return rep + "DIAG DONE\n";
    }
    snprintf(buf, sizeof(buf), "children count=%llu\n", (unsigned long long)kids.size());
    rep += buf;
    size_t show = kids.size() < 60 ? kids.size() : 60;
    for (size_t i = 0; i < show; ++i) {
        std::string n, c;
        GetName(r, kids[i], n);
        GetClassName(r, kids[i], c);
        snprintf(buf, sizeof(buf), "  [%llu] 0x%llx name='%s' class='%s'\n", (unsigned long long)i,
                 (unsigned long long)kids[i], n.c_str(), c.c_str());
        rep += buf;
    }
    // Players hunt via class match.
    for (auto k : kids) {
        std::string c;
        if (GetClassName(r, k, c) && c == "Players") {
            snprintf(buf, sizeof(buf), "PLAYERS at 0x%llx\n", (unsigned long long)k);
            rep += buf;
            break;
        }
    }
    return rep + "DIAG DONE\n";
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
                e.hrp = hrp;
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
