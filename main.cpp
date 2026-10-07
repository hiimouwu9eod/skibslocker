#include <iostream>
#include <iomanip>
#include <string>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include "offsets.hpp"
#include "injector.hpp"

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
              << "  " << exe << " inject <dll> [--pid <id>] [--wait <sec>]\n";
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
    PrintUsage(argv[0]);
    return 1;
}
