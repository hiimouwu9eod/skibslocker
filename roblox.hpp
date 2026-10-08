#pragma once
#include "mem.hpp"
#include <string>
#include <vector>

namespace roblox {

struct PlayerEntry {
    std::string name;
    uintptr_t team = 0;
    float health = 0;
    float maxHealth = 100;
    mem::Vec3 root{};
    uintptr_t hrp = 0;
    bool hasRoot = false;
    bool isLocal = false;
};

struct Snapshot {
    std::vector<PlayerEntry> players;
    mem::ViewMatrix view{};
    bool hasView = false;
    int screenW = 0;
    int screenH = 0;
    std::wstring error;
};

// One full ESP refresh. Returns false on fatal attach/read failure (see error).
bool Refresh(const mem::Reader& r, Snapshot& out, bool teamCheck, float maxDist);

uintptr_t GetModuleBase(uint32_t pid);

// Projects world pos to screen. Returns false if behind/outside.
// depth ~ distance proxy used for max-distance culling.
bool Project(const mem::ViewMatrix& vm, const mem::Vec3& p, int w, int h, float& sx, float& sy,
             float& depth);

// Read-only diagnostic: walks base -> Fake -> DataModel -> children,
// returns a text report (for `skibslocker.exe diag`).
std::string Diag(uint32_t pid);

} // namespace roblox
