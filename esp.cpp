#include "esp.hpp"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <fstream>

namespace esp {

std::wstring ConfigPath() {
    wchar_t exe[MAX_PATH]{};
    GetModuleFileNameW(nullptr, exe, MAX_PATH);
    std::wstring p = exe;
    size_t slash = p.find_last_of(L"\\/");
    if (slash != std::wstring::npos)
        p.resize(slash + 1);
    return p + L"skibslocker_esp.cfg";
}

bool Save(const std::wstring& path) {
    std::wofstream f(path, std::ios::trunc);
    if (!f)
        return false;
    f << L"enabled=" << (g.enabled ? 1 : 0) << L"\n";
    f << L"boxes=" << (g.boxes ? 1 : 0) << L"\n";
    f << L"names=" << (g.names ? 1 : 0) << L"\n";
    f << L"health=" << (g.health ? 1 : 0) << L"\n";
    f << L"distance=" << (g.distance ? 1 : 0) << L"\n";
    f << L"teamCheck=" << (g.teamCheck ? 1 : 0) << L"\n";
    f << L"maxDistance=" << g.maxDistance << L"\n";
    return true;
}

static bool ParseBool(const std::wstring& v) {
    return v == L"1" || v == L"true" || v == L"True";
}

bool Load(const std::wstring& path) {
    std::wifstream f(path);
    if (!f)
        return false;
    std::wstring line;
    while (std::getline(f, line)) {
        size_t eq = line.find(L'=');
        if (eq == std::wstring::npos)
            continue;
        std::wstring k = line.substr(0, eq), v = line.substr(eq + 1);
        if (k == L"enabled")
            g.enabled = ParseBool(v);
        else if (k == L"boxes")
            g.boxes = ParseBool(v);
        else if (k == L"names")
            g.names = ParseBool(v);
        else if (k == L"health")
            g.health = ParseBool(v);
        else if (k == L"distance")
            g.distance = ParseBool(v);
        else if (k == L"teamCheck")
            g.teamCheck = ParseBool(v);
        else if (k == L"maxDistance") {
            try {
                g.maxDistance = std::stof(v);
            } catch (...) {
            }
        }
    }
    return true;
}

} // namespace esp
