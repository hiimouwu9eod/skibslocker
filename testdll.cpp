#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <fstream>
#include <string>

// Proof-of-injection payload: writes %TEMP%\skibslocker_inject_test.txt on attach.
// Keep DllMain minimal (no MessageBox here) to avoid loader-lock issues.
static void WriteProof() {
    wchar_t tmp[MAX_PATH]{};
    DWORD n = GetTempPathW(MAX_PATH, tmp);
    if (n == 0 || n >= MAX_PATH)
        return;
    std::wstring path = std::wstring(tmp) + L"skibslocker_inject_test.txt";
    std::wofstream f(path, std::ios::out | std::ios::trunc);
    if (f) {
        f << L"injected OK pid=" << GetCurrentProcessId() << L"\n";
    }
}

BOOL APIENTRY DllMain(HMODULE, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH)
        WriteProof();
    return TRUE;
}
