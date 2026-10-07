#include "roblox.hpp"
#include "offsets.hpp"
#include <cmath>
#include <cstdio>
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

    uintptr_t start = 0, end = 0;
    bool okS = r.read<uintptr_t>(dm + Offsets::Instance::ChildrenStart, start);
    bool okE = r.read<uintptr_t>(dm + Offsets::Instance::ChildrenStart + 8, end);
    snprintf(buf, sizeof(buf), "children start read=%d val=0x%llx\n", okS,
             (unsigned long long)start);
    rep += buf;
    snprintf(buf, sizeof(buf), "children end read=%d val=0x%llx\n", okE, (unsigned long long)end);
    rep += buf;
    if (okS && okE && end >= start) {
        size_t count = (end - start) / 8;
        snprintf(buf, sizeof(buf), "children count=%llu\n", (unsigned long long)count);
        rep += buf;
    } else {
        rep += "NOTE: [0x78]/[0x80] not a valid vector.\n";
        auto tryStr = [&](uintptr_t o, std::string& s) -> bool {
            uintptr_t dp = 0;
            uint32_t ln = 0;
            if (!r.read<uintptr_t>(o, dp) || !r.read<uint32_t>(o + 0x10, ln))
                return false;
            if (dp < 0x10000 || ln == 0 || ln > 64)
                return false;
            std::vector<char> sb(ln + 1, 0);
            if (!r.readBytes(dp, sb.data(), ln))
                return false;
            s.assign(sb.data(), ln);
            return true;
        };
        // DataModel's own class via static desc at dm+0x18.
        uintptr_t dmDesc = 0;
        r.read<uintptr_t>(dm + Offsets::Instance::ClassDescriptor, dmDesc);
        std::string dmCls;
        bool okCls = tryStr(dmDesc + Offsets::Instance::ClassName, dmCls);
        snprintf(buf, sizeof(buf), "dmDesc=0x%llx class ok=%d '%s'\n", (unsigned long long)dmDesc,
                 okCls, dmCls.c_str());
        rep += buf;
        // Player hunt: every table entry with a DisplayName string + ModelInstance.
        uintptr_t t0 = 0, t1 = 0;
        r.read<uintptr_t>(dm + 0xa0, t0);
        r.read<uintptr_t>(dm + 0xa8, t1);
        size_t tn = (t1 > t0) ? (t1 - t0) / 8 : 0;
        snprintf(buf, sizeof(buf), "table count=%llu -- players:\n", (unsigned long long)tn);
        rep += buf;
        for (size_t i = 0; i < tn && i < 2000; ++i) {
            uintptr_t k = 0;
            if (!r.read<uintptr_t>(t0 + i * 8, k) || k < 0x10000)
                continue;
            std::string dn;
            if (!tryStr(k + Offsets::Player::DisplayName, dn) || dn.empty())
                continue;
            uintptr_t model = 0, team = 0;
            uint64_t uid = 0;
            r.read<uintptr_t>(k + Offsets::Player::ModelInstance, model);
            r.read<uintptr_t>(k + Offsets::Player::Team, team);
            r.read<uint64_t>(k + Offsets::Player::UserId, uid);
            snprintf(buf, sizeof(buf), "  [%llu] k=0x%llx display='%s' uid=%llu model=0x%llx team=0x%llx\n",
                     (unsigned long long)i, (unsigned long long)k, dn.c_str(),
                     (unsigned long long)uid, (unsigned long long)model, (unsigned long long)team);
            rep += buf;
        }
        return rep + "HUNT DONE\n";
    }

    size_t count = (end - start) / 8;
    size_t show = count < 40 ? count : 40;
    for (size_t i = 0; i < show; ++i) {
        uintptr_t k = 0;
        if (!r.read<uintptr_t>(start + i * 8, k)) {
            rep += "  [i] ptr unreadable\n";
            continue;
        }
        std::string n, c;
        GetName(r, k, n);
        GetClassName(r, k, c);
        snprintf(buf, sizeof(buf), "  [%llu] 0x%llx name='%s' class='%s'\n", (unsigned long long)i,
                 (unsigned long long)k, n.c_str(), c.c_str());
        rep += buf;
    }
    return rep;
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
