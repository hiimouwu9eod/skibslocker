#include "mem.hpp"
#include <tlhelp32.h>

namespace mem {

bool Reader::attach(uint32_t pid, std::wstring& error) {
    detach();
    proc_ = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pid);
    if (!proc_) {
        DWORD e = GetLastError();
        error = L"OpenProcess failed (Hyperion likely stripped handle): " + std::to_wstring(e);
        return false;
    }
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (snap == INVALID_HANDLE_VALUE) {
        error = L"module snapshot failed";
        detach();
        return false;
    }
    MODULEENTRY32W me{};
    me.dwSize = sizeof(me);
    if (Module32FirstW(snap, &me)) {
        base_ = reinterpret_cast<uintptr_t>(me.modBaseAddr);
    }
    CloseHandle(snap);
    if (!base_) {
        error = L"could not find module base";
        detach();
        return false;
    }
    return true;
}

void Reader::detach() {
    if (proc_) {
        CloseHandle(proc_);
        proc_ = nullptr;
    }
    base_ = 0;
}

bool Reader::readBytes(uintptr_t addr, void* dst, size_t size) const {
    if (!proc_ || addr < 0x10000 || !dst || size == 0 || size > 1 << 20)
        return false;
    SIZE_T n = 0;
    return ReadProcessMemory(proc_, reinterpret_cast<LPCVOID>(addr), dst, size, &n) && n == size;
}

bool Reader::readString(uintptr_t strObj, std::string& out) const {
    out.clear();
    if (!proc_ || strObj < 0x10000)
        return false;
    // Layout (matches omega's read_roblox_string): count at +0x10;
    // long strings (>15) via data pointer, short ones inline (SSO).
    uint32_t count = 0;
    if (!read<uint32_t>(strObj + 0x10, count))
        return false;
    if (count == 0 || count > 128)
        return false;
    std::vector<char> buf(static_cast<size_t>(count) + 1, 0);
    if (count > 15) {
        uintptr_t data = 0;
        if (!read<uintptr_t>(strObj, data) || data < 0x10000)
            return false;
        if (!readBytes(data, buf.data(), count))
            return false;
    } else {
        if (!readBytes(strObj, buf.data(), count))
            return false;
    }
    out.assign(buf.data(), count);
    size_t z = out.find('\0');
    if (z != std::string::npos)
        out.resize(z);
    return !out.empty();
}

} // namespace mem
