#include "injector.hpp"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <tlhelp32.h>

namespace injector {

std::wstring StrError(uint32_t code) {
    wchar_t* buf = nullptr;
    DWORD n = FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                                 FORMAT_MESSAGE_IGNORE_INSERTS,
                             nullptr, code, 0, reinterpret_cast<LPWSTR>(&buf), 0, nullptr);
    std::wstring msg = (n && buf) ? std::wstring(buf, n) : L"unknown error";
    if (buf)
        LocalFree(buf);
    while (!msg.empty() && (msg.back() == L'\r' || msg.back() == L'\n'))
        msg.pop_back();
    return msg;
}

std::vector<uint32_t> FindRobloxProcesses() {
    std::vector<uint32_t> pids;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE)
        return pids;
    PROCESSENTRY32W pe{};
    pe.dwSize = sizeof(pe);
    if (Process32FirstW(snap, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, L"RobloxPlayerBeta.exe") == 0)
                pids.push_back(pe.th32ProcessID);
        } while (Process32NextW(snap, &pe));
    }
    CloseHandle(snap);
    return pids;
}

bool InjectDll(uint32_t pid, const std::wstring& dllPath, std::wstring& error) {
    wchar_t fullPath[MAX_PATH]{};
    DWORD len = GetFullPathNameW(dllPath.c_str(), MAX_PATH, fullPath, nullptr);
    if (len == 0 || len >= MAX_PATH) {
        error = L"bad DLL path: " + dllPath;
        return false;
    }
    if (GetFileAttributesW(fullPath) == INVALID_FILE_ATTRIBUTES) {
        error = L"DLL not found: " + std::wstring(fullPath);
        return false;
    }

    HANDLE proc = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION |
                                  PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
                              FALSE, pid);
    if (!proc) {
        error = L"OpenProcess(" + std::to_wstring(pid) + L") failed: " + StrError(GetLastError());
        return false;
    }

    SIZE_T bytes = (wcslen(fullPath) + 1) * sizeof(wchar_t);
    LPVOID remote = VirtualAllocEx(proc, nullptr, bytes, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!remote) {
        error = L"VirtualAllocEx failed: " + StrError(GetLastError());
        CloseHandle(proc);
        return false;
    }

    if (!WriteProcessMemory(proc, remote, fullPath, bytes, nullptr)) {
        error = L"WriteProcessMemory failed: " + StrError(GetLastError());
        VirtualFreeEx(proc, remote, 0, MEM_RELEASE);
        CloseHandle(proc);
        return false;
    }

    HMODULE k32 = GetModuleHandleW(L"kernel32.dll");
    auto loadLib = reinterpret_cast<LPTHREAD_START_ROUTINE>(
        reinterpret_cast<void*>(GetProcAddress(k32, "LoadLibraryW")));
    if (!loadLib) {
        error = L"GetProcAddress(LoadLibraryW) failed: " + StrError(GetLastError());
        VirtualFreeEx(proc, remote, 0, MEM_RELEASE);
        CloseHandle(proc);
        return false;
    }

    HANDLE thread = CreateRemoteThread(proc, nullptr, 0, loadLib, remote, 0, nullptr);
    if (!thread) {
        error = L"CreateRemoteThread failed (Hyperion may be blocking): " + StrError(GetLastError());
        VirtualFreeEx(proc, remote, 0, MEM_RELEASE);
        CloseHandle(proc);
        return false;
    }

    DWORD wait = WaitForSingleObject(thread, 10000);
    DWORD mod = 0;
    GetExitCodeThread(thread, &mod);
    CloseHandle(thread);
    VirtualFreeEx(proc, remote, 0, MEM_RELEASE);
    CloseHandle(proc);

    if (wait != WAIT_OBJECT_0) {
        error = L"remote thread timed out";
        return false;
    }
    if (mod == 0) {
        error = L"LoadLibraryW returned NULL in target (arch mismatch or blocked DLL)";
        return false;
    }
    return true;
}

} // namespace injector
