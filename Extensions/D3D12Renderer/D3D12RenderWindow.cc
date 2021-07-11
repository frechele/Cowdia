#include "D3D12RenderWindow.hpp"

#include <cassert>
#include <cstring>
#include <stdexcept>

namespace Cowdia::Rendering
{
D3D12RenderWindow::D3D12RenderWindow(HINSTANCE hInstance)
    : hInstance_(hInstance)
{
    // Do nothing.
}

bool D3D12RenderWindow::Create(int width, int height)
{
    assert(hwnd_ == nullptr);

    WNDCLASS wc;
    memset(&wc, 0, sizeof(wc));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = &D3D12RenderWindow::MsgProc;
    wc.hInstance = hInstance_;
    wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.lpszMenuName = 0;
    wc.lpszClassName = "D3D12RenderWindow";

    if (!RegisterClass(&wc))
    {
        return false;
    }

    windowStyle_ = WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

    RECT rc{ 0, 0, width, height };
    AdjustWindowRect(&rc, windowStyle_, false);
    const int adjWidth = rc.right - rc.left;
    const int adjHeight = rc.bottom - rc.top;

    hwnd_ = CreateWindow("D3D12RenderWindow", "D3D12RenderWindow",
                         windowStyle_, CW_USEDEFAULT, CW_USEDEFAULT,
                         adjWidth, adjHeight, 0, 0, hInstance_, this);
    if (!hwnd_)
    {
        return false;
    }

    ShowWindow(hwnd_, SW_SHOW);
    UpdateWindow(hwnd_);

    return true;
}

void D3D12RenderWindow::Destroy()
{
    DestroyWindow(hwnd_);
    hwnd_ = nullptr;
}

void D3D12RenderWindow::SetTitle(const std::string& title)
{
    SetWindowText(hwnd_, title.c_str());
}

void D3D12RenderWindow::Resize(int width, int height)
{
    RenderWindow::Resize(width, height);
}

void D3D12RenderWindow::Fullscreen(bool fullscreen)
{
    if (IsFullscreen() == fullscreen)
        return;

    RenderWindow::Fullscreen(fullscreen);

    if (fullscreen)
    {
        // Save the old window rect so we can restore it when exiting fullscreen mode.
        GetWindowRect(hwnd_, &windowRect_);

        // Make the window borderless so that the client area can fill the screen.
        SetWindowLong(
            hwnd_, GWL_STYLE,
            windowStyle_ & ~(WS_CAPTION | WS_MAXIMIZEBOX | WS_MINIMIZEBOX |
                             WS_SYSMENU | WS_THICKFRAME));

        DEVMODE devMode;
        memset(&devMode, 0, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &devMode);

        SetWindowPos(
            hwnd_, HWND_TOPMOST, devMode.dmPosition.x, devMode.dmPosition.y,
            devMode.dmPosition.x + static_cast<LONG>(devMode.dmPelsWidth),
            devMode.dmPosition.y + static_cast<LONG>(devMode.dmPelsHeight),
            SWP_FRAMECHANGED | SWP_NOACTIVATE);

        ShowWindow(hwnd_, SW_MAXIMIZE);
    }
    else
    {
        // Restore the window's attributes and size.
        SetWindowLong(hwnd_, GWL_STYLE, windowStyle_);

        SetWindowPos(hwnd_, HWND_NOTOPMOST, windowRect_.left, windowRect_.top,
                     GetWidth(), GetHeight(),
                     SWP_FRAMECHANGED | SWP_NOACTIVATE);

        ShowWindow(hwnd_, SW_NORMAL);
    }
}

HWND D3D12RenderWindow::GetHWND() const
{
    return hwnd_;
}

LRESULT D3D12RenderWindow::MsgProc(HWND hwnd, UINT msg, WPARAM wParam,
                                   LPARAM lParam)
{
    if (msg == WM_CREATE)
    {
        SetWindowLongPtr(
            hwnd, GWLP_USERDATA,
            reinterpret_cast<LONG_PTR>(
                reinterpret_cast<LPCREATESTRUCT>(lParam)->lpCreateParams));
        return 0;
    }

    RenderWindow* const window =
        reinterpret_cast<RenderWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (window != nullptr)
    {
        switch (msg)
        {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
}  // namespace Cowdia::Rendering
