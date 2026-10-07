#include "ui.hpp"
#include "esp.hpp"
#include "offsets.hpp"
#include "overlay.hpp"
#include "injector.hpp"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <string>

namespace ui {
namespace {

enum : int {
    IDC_ENABLED = 101,
    IDC_BOXES,
    IDC_NAMES,
    IDC_HEALTH,
    IDC_DISTANCE,
    IDC_TEAM,
    IDC_MAXDIST_EDIT,
    IDC_APPLY,
    IDC_PID_EDIT,
    IDC_START,
    IDC_STOP,
    IDC_STATUS,
};

HWND gChecks[6]{};
HWND gDistEdit = nullptr;
HWND gPidEdit = nullptr;
HWND gStatus = nullptr;

void RefreshStatus() {
    std::wstring s = L"Client: ";
    s += std::wstring(Offsets::ClientVersion.begin(), Offsets::ClientVersion.end());
    s += esp::g.enabled ? L"  |  ESP ON" : L"  |  ESP OFF";
    s += L"\n";
    s += L"overlay: " + overlay::Status();
    SetWindowTextW(gStatus, s.c_str());
}

void CheckToSettings() {
    esp::g.enabled = SendMessageW(gChecks[0], BM_GETCHECK, 0, 0) == BST_CHECKED;
    esp::g.boxes = SendMessageW(gChecks[1], BM_GETCHECK, 0, 0) == BST_CHECKED;
    esp::g.names = SendMessageW(gChecks[2], BM_GETCHECK, 0, 0) == BST_CHECKED;
    esp::g.health = SendMessageW(gChecks[3], BM_GETCHECK, 0, 0) == BST_CHECKED;
    esp::g.distance = SendMessageW(gChecks[4], BM_GETCHECK, 0, 0) == BST_CHECKED;
    esp::g.teamCheck = SendMessageW(gChecks[5], BM_GETCHECK, 0, 0) == BST_CHECKED;
    wchar_t buf[64]{};
    GetWindowTextW(gDistEdit, buf, 64);
    try {
        float d = std::stof(buf);
        if (d > 0 && d < 100000)
            esp::g.maxDistance = d;
    } catch (...) {
    }
    RefreshStatus();
}

HWND MakeCheck(HWND parent, HINSTANCE h, int id, const wchar_t* text, int y, bool on) {
    HWND c = CreateWindowExW(0, L"BUTTON", text, WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 16, y,
                             260, 24, parent, reinterpret_cast<HMENU>(static_cast<INT_PTR>(id)), h,
                             nullptr);
    SendMessageW(c, BM_SETCHECK, on ? BST_CHECKED : BST_UNCHECKED, 0);
    return c;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_COMMAND: {
        int id = LOWORD(wp);
        int ev = HIWORD(wp);
        if ((id >= IDC_ENABLED && id <= IDC_TEAM && ev == BN_CLICKED) || id == IDC_APPLY) {
            CheckToSettings();
            esp::Save(esp::ConfigPath());
        } else if (id == IDC_START && ev == BN_CLICKED) {
            CheckToSettings();
            esp::Save(esp::ConfigPath());
            wchar_t buf[32]{};
            GetWindowTextW(gPidEdit, buf, 32);
            uint32_t pid = 0;
            try {
                pid = static_cast<uint32_t>(std::stoul(buf));
            } catch (...) {
            }
            if (pid == 0) {
                auto pids = injector::FindRobloxProcesses();
                if (!pids.empty())
                    pid = pids.front();
            }
            if (pid == 0) {
                SetWindowTextW(gStatus, L"no Roblox found: start the game or enter PID");
            } else {
                std::wstring err;
                if (!overlay::Start(pid, err))
                    SetWindowTextW(gStatus, (L"start failed: " + err).c_str());
                else
                    RefreshStatus();
            }
        } else if (id == IDC_STOP && ev == BN_CLICKED) {
            overlay::Stop();
            RefreshStatus();
        }
        return 0;
    }
    case WM_TIMER:
        RefreshStatus();
        return 0;
    case WM_CLOSE:
        CheckToSettings();
        esp::Save(esp::ConfigPath());
        overlay::Stop();
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

} // namespace

void RunEspUi() {
    esp::Load(esp::ConfigPath());
    HINSTANCE h = GetModuleHandleW(nullptr);
    const wchar_t* cls = L"SkibsLockerEspUi";
    WNDCLASSW wc{};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = h;
    wc.lpszClassName = cls;
    wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
    RegisterClassW(&wc);

    HWND wnd = CreateWindowExW(0, cls, L"skibslocker - Player ESP", WS_OVERLAPPED | WS_CAPTION |
                                                            WS_SYSMENU | WS_MINIMIZEBOX,
                               CW_USEDEFAULT, CW_USEDEFAULT, 300, 470, nullptr, nullptr, h, nullptr);
    if (!wnd)
        return;

    const wchar_t* labels[6] = {L"Enable ESP", L"Boxes", L"Player names", L"Health",
                                L"Distance", L"Team check"};
    const bool vals[6] = {esp::g.enabled, esp::g.boxes,   esp::g.names,
                          esp::g.health,  esp::g.distance, esp::g.teamCheck};
    for (int i = 0; i < 6; ++i)
        gChecks[i] = MakeCheck(wnd, h, IDC_ENABLED + i, labels[i], 14 + i * 30, vals[i]);

    CreateWindowExW(0, L"STATIC", L"Max distance:", WS_CHILD | WS_VISIBLE, 16, 200, 100, 22, wnd,
                    nullptr, h, nullptr);
    gDistEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", std::to_wstring(esp::g.maxDistance).c_str(),
                                WS_CHILD | WS_VISIBLE | ES_NUMBER, 120, 198, 100, 24, wnd,
                                reinterpret_cast<HMENU>(static_cast<INT_PTR>(IDC_MAXDIST_EDIT)), h,
                                nullptr);
    CreateWindowExW(0, L"BUTTON", L"Apply", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 16, 232, 100, 28,
                    wnd, reinterpret_cast<HMENU>(static_cast<INT_PTR>(IDC_APPLY)), h, nullptr);
    CreateWindowExW(0, L"STATIC", L"PID (blank = auto):", WS_CHILD | WS_VISIBLE, 16, 270, 130, 22,
                    wnd, nullptr, h, nullptr);
    gPidEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_NUMBER,
                               150, 268, 100, 24, wnd,
                               reinterpret_cast<HMENU>(static_cast<INT_PTR>(IDC_PID_EDIT)), h,
                               nullptr);
    CreateWindowExW(0, L"BUTTON", L"Start ESP", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 16, 300,
                    110, 30, wnd, reinterpret_cast<HMENU>(static_cast<INT_PTR>(IDC_START)), h,
                    nullptr);
    CreateWindowExW(0, L"BUTTON", L"Stop", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 136, 300, 110,
                    30, wnd, reinterpret_cast<HMENU>(static_cast<INT_PTR>(IDC_STOP)), h, nullptr);
    gStatus = CreateWindowExW(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE, 16, 340, 260, 70, wnd,
                              reinterpret_cast<HMENU>(static_cast<INT_PTR>(IDC_STATUS)), h, nullptr);
    RefreshStatus();
    SetTimer(wnd, 1, 1000, nullptr);

    ShowWindow(wnd, SW_SHOW);
    UpdateWindow(wnd);
    MSG m{};
    while (GetMessageW(&m, nullptr, 0, 0)) {
        TranslateMessage(&m);
        DispatchMessageW(&m);
    }
}

} // namespace ui
