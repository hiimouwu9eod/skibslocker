#pragma once
#include <string>

namespace esp {

struct Settings {
    bool enabled = true;
    bool boxes = true;
    bool names = true;
    bool health = true;
    bool distance = false;
    bool teamCheck = true;
    float maxDistance = 1000.0f;
};

inline Settings g;

bool Save(const std::wstring& path);
bool Load(const std::wstring& path);
std::wstring ConfigPath();

} // namespace esp
