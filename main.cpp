#include <Windows.h>

using namespace std;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

MSG message;

HWND hwnd;
HWND hTitle, hDescription, hButtonOK;
HFONT hFont;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    auto className = const_cast<LPSTR>("STIKFIGZ RANSOMWARE");
    WNDCLASSEXA window;
    window.cbSize = sizeof(WNDCLASSEX);
    window.style = 0;
    window.lpfnWndProc = WindowProc;
    window.cbClsExtra = 0;
    window.cbWndExtra = 0;
    window.hInstance = hInstance;
    window.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    window.hCursor = LoadCursor(nullptr, IDC_ARROW);
    window.hbrBackground = (HBRUSH) (COLOR_WINDOW);
    window.lpszMenuName = nullptr;
    window.lpszClassName = className;
    window.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassExA(&window)) {
        MessageBoxA(nullptr, "Failed registering main window!", "Error", MB_OK | MB_ICONSTOP | MB_SYSTEMMODAL);
        return 1;
    }

    hwnd = CreateWindowExA(WS_EX_WINDOWEDGE | WS_EX_TOPMOST, className, className, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 0, 0,
                           GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), nullptr, nullptr, hInstance, nullptr);
    if (hwnd == nullptr) {
        MessageBoxA(nullptr, "Failed creating main window!", "Error", MB_OK | MB_ICONSTOP | MB_SYSTEMMODAL);
        return 2;
    }

    SetWindowLong(hwnd, GWL_STYLE, 0);

    auto hNormalFont = (HFONT) GetStockObject(DEFAULT_GUI_FONT);
    hFont = CreateFontW(100, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                        DEFAULT_PITCH | FF_SWISS, L"Arial");

    hTitle = CreateWindowExA(0, "STATIC", "STIKFIGZ RANSOMWARE", WS_CHILD | WS_VISIBLE, 0, 0, GetSystemMetrics(SM_CXSCREEN),
                             120, hwnd, nullptr, nullptr, nullptr);
    SendMessageW(hTitle, WM_SETFONT, WPARAM(hFont), TRUE);

    hTitle = CreateWindowExA(0, "STATIC", "Send stikfigz all your Maple pics and money or never see your files again", WS_CHILD | WS_VISIBLE, 0, 150,
                             GetSystemMetrics(SM_CXSCREEN),
                             120, hwnd, nullptr, nullptr, nullptr);
    SendMessageW(hDescription, WM_SETFONT, WPARAM(hNormalFont), TRUE);

    hButtonOK = CreateWindowExW(0, L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE | WS_DISABLED, GetSystemMetrics(SM_CXSCREEN) - 120, GetSystemMetrics(SM_CYSCREEN) - 70, 100, 50, hwnd, nullptr, nullptr, nullptr);
    SendMessageA(hButtonOK, WM_SETFONT, (WPARAM) hNormalFont, 0);

    EnableMenuItem(GetSystemMenu(hwnd, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    SetWindowLong(hwnd, GWL_STYLE,GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
    SetWindowLong(hwnd, GWL_STYLE,GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessageA(&message, nullptr, 0, 0)) {
        TranslateMessage(&message);
        DispatchMessageA(&message);
    }
    return message.wParam; // NOLINT(cppcoreguidelines-narrowing-conversions)
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE: {
            return 0;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default: {
            return DefWindowProcA(hWnd, msg, wParam, lParam);
        }
    }
    return DefWindowProcA(hWnd, msg, wParam, lParam);
}