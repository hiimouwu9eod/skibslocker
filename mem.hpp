#pragma once
#include <cstdint>
#include <string>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace mem {

struct Vec3 {
    float x = 0, y = 0, z = 0;
};

struct ViewMatrix {
    float m[16]{};
};

// Lightweight external reader. Handle opened with VM_READ|QUERY only
// (less56 flagged than ALL_ACCESS, still often stripped by Hyperion).
class Reader {
  public:
    Reader() = default;
    ~Reader() {
        detach();
    }
    Reader(const Reader&) = delete;
    Reader& operator=(const Reader&) = delete;

    bool attach(uint32_t pid, std::wstring& error);
    void detach();
    bool attached() const {
        return proc_ != nullptr;
    }
    uintptr_t base() const {
        return base_;
    }

    template <typename T> bool read(uintptr_t addr, T& out) const {
        if (!proc_ || addr < 0x10000)
            return false;
        SIZE_T n = 0;
        return ReadProcessMemory(proc_, reinterpret_cast<LPCVOID>(addr), &out, sizeof(T), &n) &&
               n == sizeof(T);
    }

    bool readBytes(uintptr_t addr, void* dst, size_t size) const;
    // Roblox string: [0x0 ptr][0x10 len]; falls back to small-string buffer.
    bool readString(uintptr_t strObj, std::string& out) const;

  private:
    HANDLE proc_ = nullptr;
    uintptr_t base_ = 0;
};

} // namespace mem
