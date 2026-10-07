#include "overlay.hpp"
#include "esp.hpp"
#include "mem.hpp"
#include "roblox.hpp"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <atomic>
#include <mutex>
#include <thread>

namespace overlay {
namespace {

std::atomic<bool> running{false};
std::thread worker;
std::mutex statusMu;
std::wstring status = L"idle";
size_t lastCount = 0;
uint32_t targetPid = 0;

bool WorldToScreen(const mem::ViewMatrix& vm, const mem::Vec3& p, int w, int h, float& sx,
                   float& sy, float& depth) {
    // Column-major style (D3D-like): clip rows at m[12..15].
    float x = vm.m[0] * p.x + vm.m[4] * p.y + vm.m[8] * p.z + vm.m[12];
    float y = vm.m[1] * p.x + vm.m[5] * p.y + vm.m[9] * p.z + vm.m[13];
    float z = vm.m[2] * p.x + vm.m[6] * p.y + vm.m[10] * p.z + vm.m[14];
    float ww = vm.m[3] * p.x + vm.m[7] * p.y + vm.m[11] * p.z + vm.m[15];
    (void)z;
    if (ww < 0.1f)
        return false;
    depth = ww;
    sx = (w * 0.5f) * (1.0f + x / ww);
    sy = (h * 0.5f) * (1.0f - y / ww);
    return sx > -200 && sx < w + 200 && sy > -200 && sy < h + 200;
}

void SetStatus(const std::wstring& s, size_t n) {
    std::lock_guard<std::mutex> lk(statusMu);
    status = s;
    lastCount = n;
}

LRESULT CALLBACK OverlayProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    if (msg == WM_DESTROY) {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}

void Loop() {
    mem::Reader reader;
    std::wstring err;
    if (!reader.attach(targetPid, err)) {
        SetStatus(L"attach failed: " + err, 0);
        running = false;
        return;
    }

    HINSTANCE h = GetModuleHandleW(nullptr);
    const wchar_t* cls = L"SkibsLockerOverlay";
    WNDCLASSW wc{};
    wc.lpfnWndProc = OverlayProc;
    wc.hInstance = h;
    wc.lpszClassName = cls;
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    RegisterClassW(&wc);

    int fw = GetSystemMetrics(SM_CXSCREEN), fh = GetSystemMetrics(SM_CYSCREEN);
    HWND wnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW,
                               cls, L"", WS_POPUP, 0, 0, fw, fh, nullptr, nullptr, h, nullptr);
    if (!wnd) {
        SetStatus(L"overlay window failed", 0);
        running = false;
        return;
    }
    SetLayeredWindowAttributes(wnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
    ShowWindow(wnd, SW_SHOW);
    UpdateWindow(wnd);

    roblox::Snapshot snap;
    MSG msg{};
    while (running) {
        while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                running = false;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
        if (!running)
            break;

        bool ok = roblox::Refresh(reader, snap, esp::g.teamCheck, esp::g.maxDistance);
        if (!ok) {
            SetStatus(snap.error.empty() ? L"read failed" : snap.error, 0);
        } else {
            SetStatus(L"live", snap.players.size());
        }

        HDC dc = GetDC(wnd);
        // Clear via full repaint: fill with colorkey (transparent).
        HBRUSH clearBrush = CreateSolidBrush(RGB(0, 0, 0));
        RECT rc{0, 0, fw, fh};
        FillRect(dc, &rc, clearBrush);
        DeleteObject(clearBrush);

        if (esp::g.enabled && ok && snap.hasView) {
            HPEN boxPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
            HPEN hp = static_cast<HPEN>(SelectObject(dc, boxPen));
            SetBkMode(dc, TRANSPARENT);
            SetTextColor(dc, RGB(255, 255, 255));
            HFONT font = CreateFontW(16, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                    DEFAULT_PITCH, L"Arial");
            HFONT oldFont = static_cast<HFONT>(SelectObject(dc, font));
            for (auto& pl : snap.players) {
                float sx = 0, sy = 0, depth = 0;
                if (!WorldToScreen(snap.view, pl.root, fw, fh, sx, sy, depth))
                    continue;
                if (depth > esp::g.maxDistance)
                    continue;
                float scale = 1000.0f / (depth + 100.0f);
                if (scale < 0.3f)
                    scale = 0.3f;
                if (scale > 3.0f)
                    scale = 3.0f;
                int bw = static_cast<int>(40 * scale), bh = static_cast<int>(80 * scale);
                int x0 = static_cast<int>(sx - bw / 2), y0 = static_cast<int>(sy - bh);
                if (esp::g.boxes)
                    Rectangle(dc, x0, y0, x0 + bw, y0 + bh);
                int ty = y0 - 20;
                if (esp::g.names && !pl.name.empty()) {
                    std::wstring wn(pl.name.begin(), pl.name.end());
                    TextOutW(dc, x0, ty, wn.c_str(), static_cast<int>(wn.size()));
                    ty -= 18;
                }
                if (esp::g.health) {
                    wchar_t hb[64]{};
                    swprintf_s(hb, L"%.0f/%.0f", pl.health,
                               pl.maxHealth > 0 ? pl.maxHealth : 100.0f);
                    TextOutW(dc, x0, ty, hb, static_cast<int>(wcslen(hb)));
                    ty -= 18;
                }
                if (esp::g.distance) {
                    wchar_t db[64]{};
                    swprintf_s(db, L"%.0fm", depth);
                    TextOutW(dc, x0, ty, db, static_cast<int>(wcslen(db)));
                }
            }
            SelectObject(dc, oldFont);
            DeleteObject(font);
            SelectObject(dc, hp);
            DeleteObject(boxPen);
        }
        ReleaseDC(wnd, dc);
        Sleep(33);
    }
    DestroyWindow(wnd);
    UnregisterClassW(cls, h);
    SetStatus(L"stopped", 0);
}

} // namespace

bool Start(uint32_t pid, std::wstring& error) {
    if (running) {
        error = L"already running";
        return false;
    }
    targetPid = pid;
    running = true;
    try {
        worker = std::thread(Loop);
    } catch (...) {
        running = false;
        error = L"thread spawn failed";
        return false;
    }
    // Detach ownership: Stop() joins. Give the loop a moment to report attach errors.
    Sleep(400);
    std::lock_guard<std::mutex> lk(statusMu);
    if (!running && status.find(L"attach failed") != std::wstring::npos) {
        error = status;
        if (worker.joinable())
            worker.join();
        return false;
    }
    return true;
}

void Stop() {
    running = false;
    PostQuitMessage(0);
    if (worker.joinable())
        worker.join();
}

bool Running() {
    return running;
}

std::wstring Status() {
    std::lock_guard<std::mutex> lk(statusMu);
    wchar_t buf[128]{};
    swprintf_s(buf, L"%ls (%llu players)", status.c_str(),
               static_cast<unsigned long long>(lastCount));
    return buf;
}

} // namespace overlay
