#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "offsets.hpp"
#include "injector.hpp"
#include "esp.hpp"
#include "ui.hpp"
#include "roblox.hpp"

static void PrintOffsets() {
    std::cout << "skibslocker" << std::endl;
    std::cout << "ClientVersion: " << Offsets::ClientVersion << std::endl;
    std::cout << std::hex << std::showbase;
    std::cout << "FakeDataModel::Pointer = " << Offsets::FakeDataModel::Pointer << std::endl;
    std::cout << "TaskScheduler::Pointer = " << Offsets::TaskScheduler::Pointer << std::endl;
    std::cout << "VisualEngine::Pointer = " << Offsets::VisualEngine::Pointer << std::endl;
    std::cout << "Humanoid::HumanoidRootPart = " << Offsets::Humanoid::HumanoidRootPart << std::endl;
    std::cout << "Humanoid::Walkspeed = " << Offsets::Humanoid::Walkspeed << std::endl;
}

static void PrintUsage(const char* exe) {
    std::cout << "Usage:\n"
              << "  " << exe << "                 print offsets\n"
              << "  " << exe << " list            list Roblox PIDs\n"
              << "  " << exe << " inject <dll> [--pid <id>] [--wait <sec>]\n"
              << "  " << exe << " ui              open Player ESP toggles window\n"
              << "  " << exe << " diag [--pid <id>]  dump DataModel walk (debug)\n"
              << "  " << exe << " espstat [--pid <id>] show players + projections (debug)\n";
}

static std::wstring ToWide(const std::string& s) {
    if (s.empty())
        return L"";
    int n = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, nullptr, 0);
    std::wstring w(static_cast<size_t>(n > 0 ? n - 1 : 0), L'\0');
    if (n > 0)
        MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, w.data(), n);
    return w;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        PrintOffsets();
        return 0;
    }
    std::string cmd = argv[1];
    if (cmd == "list") {
        auto pids = injector::FindRobloxProcesses();
        if (pids.empty()) {
            std::cout << "no RobloxPlayerBeta.exe found\n";
            return 1;
        }
        for (auto pid : pids)
            std::cout << "Roblox PID: " << pid << "\n";
        return 0;
    }
    if (cmd == "inject") {
        if (argc < 3) {
            PrintUsage(argv[0]);
            return 1;
        }
        std::wstring dll = ToWide(argv[2]);
        uint32_t onlyPid = 0;
        int waitSec = 0;
        for (int i = 3; i < argc; ++i) {
            std::string a = argv[i];
            if (a == "--pid" && i + 1 < argc)
                onlyPid = static_cast<uint32_t>(std::stoul(argv[++i]));
            else if (a == "--wait" && i + 1 < argc)
                waitSec = std::stoi(argv[++i]);
        }
        std::vector<uint32_t> pids;
        if (onlyPid != 0) {
            pids.push_back(onlyPid);
        } else {
            for (int waited = 0;; ++waited) {
                pids = injector::FindRobloxProcesses();
                if (!pids.empty() || (waitSec <= 0 || waited >= waitSec))
                    break;
                Sleep(1000);
            }
        }
        if (pids.empty()) {
            std::cout << "no RobloxPlayerBeta.exe found (start Roblox first or use --pid)\n";
            return 1;
        }
        bool ok = true;
        for (auto pid : pids) {
            std::wstring err;
            std::cout << "injecting into PID " << pid << "...\n";
            if (injector::InjectDll(pid, dll, err)) {
                std::cout << "injected OK into " << pid << "\n";
            } else {
                std::wcout << L"FAILED pid " << pid << L": " << err << L"\n";
                ok = false;
            }
        }
        return ok ? 0 : 2;
    }
    if (cmd == "ui") {
        esp::Load(esp::ConfigPath());
        ui::RunEspUi();
        return 0;
    }
    if (cmd == "espstat") {
        uint32_t pid = 0;
        for (int i = 2; i < argc; ++i) {
            std::string a = argv[i];
            if (a == "--pid" && i + 1 < argc)
                pid = static_cast<uint32_t>(std::stoul(argv[++i]));
        }
        if (pid == 0) {
            auto pids = injector::FindRobloxProcesses();
            if (!pids.empty())
                pid = pids.front();
        }
        if (pid == 0) {
            std::cout << "no RobloxPlayerBeta.exe found\n";
            return 1;
        }
        mem::Reader r;
        std::wstring err;
        if (!r.attach(pid, err)) {
            std::wcout << L"attach failed: " << err << L"\n";
            return 1;
        }
        roblox::Snapshot snap;
        // No team filter here: show everything the walk finds.
        bool ok = roblox::Refresh(r, snap, false, 1e9f);
        std::wcout << L"refresh=" << (ok ? L"ok" : snap.error.c_str()) << L" hasView="
                   << (snap.hasView ? 1 : 0) << L" screen=" << snap.screenW << L"x" << snap.screenH
                   << L" n=" << snap.players.size() << L"\n";
        if (snap.hasView) {
            std::cout << "viewmatrix:\n";
            for (int row = 0; row < 4; ++row)
                printf("  %.4f %.4f %.4f %.4f\n", snap.view.m[row * 4], snap.view.m[row * 4 + 1],
                       snap.view.m[row * 4 + 2], snap.view.m[row * 4 + 3]);
        }
        int w = snap.screenW > 0 ? snap.screenW : 1920;
        int h = snap.screenH > 0 ? snap.screenH : 1080;
        for (size_t i = 0; i < snap.players.size(); ++i) {
            auto& pl = snap.players[i];
            float sx = 0, sy = 0, d = 0;
            bool vis = snap.hasView && roblox::Project(snap.view, pl.root, w, h, sx, sy, d);
            printf("[%llu] name='%s' hp=%.0f/%.0f hrp=0x%llx root=(%.1f,%.1f,%.1f) screen=(%.0f,%.0f) depth=%.1f %s\n",
                   (unsigned long long)i, pl.name.c_str(), pl.health, pl.maxHealth,
                   (unsigned long long)pl.hrp, pl.root.x,
                   pl.root.y, pl.root.z, sx, sy, d, vis ? "VIS" : "off");
            if (i < 2 && pl.hrp) {
                printf("  hrp float scan (offset: x y z):\n");
                for (uintptr_t o = 0xB0; o <= 0x230; o += 4) {
                    mem::Vec3 v{};
                    if (!r.read<mem::Vec3>(pl.hrp + o, v))
                        continue;
                    // plausible world coord: finite, |v|<20000, not all ~zero
                    if (fabsf(v.x) + fabsf(v.y) + fabsf(v.z) < 0.001f)
                        continue;
                    if (fabsf(v.x) > 20000 || fabsf(v.y) > 20000 || fabsf(v.z) > 20000)
                        continue;
                    printf("    +0x%llx: %.2f %.2f %.2f\n", (unsigned long long)o, v.x, v.y,
                           v.z);
                }
            }
        }
        return 0;
    }
    if (cmd == "diag") {
        uint32_t pid = 0;
        for (int i = 2; i < argc; ++i) {
            std::string a = argv[i];
            if (a == "--pid" && i + 1 < argc)
                pid = static_cast<uint32_t>(std::stoul(argv[++i]));
        }
        if (pid == 0) {
            auto pids = injector::FindRobloxProcesses();
            if (!pids.empty())
                pid = pids.front();
        }
        if (pid == 0) {
            std::cout << "no RobloxPlayerBeta.exe found\n";
            return 1;
        }
        std::cout << "pid=" << pid << "\n" << roblox::Diag(pid);
        return 0;
    }
    PrintUsage(argv[0]);
    return 1;
}
