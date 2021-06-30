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

bool D3D12RenderWindow::Create(int width, int height, bool fullscreen)
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

    DWORD dwStyle = 0;

    if (fullscreen)
    {
        dwStyle = WS_EX_TOPMOST | WS_POPUP;
    }
    else
    {
        dwStyle = WS_OVERLAPPEDWINDOW;
    }

    RECT rc{ 0, 0, width, height };
    AdjustWindowRect(&rc, dwStyle, false);
    const int adjWidth = rc.right - rc.left;
    const int adjHeight = rc.bottom - rc.top;

    hwnd_ = CreateWindow("D3D12RenderWindow", "D3D12RenderWindow",
                         dwStyle, CW_USEDEFAULT, CW_USEDEFAULT,
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
    RenderWindow::Fullscreen(fullscreen);
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

    RenderWindow* window =
        reinterpret_cast<RenderWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (window != nullptr)
    {
        switch (msg)
        {
            case WM_DESTROY:
                window->Destroy();
                PostQuitMessage(0);
                return 0;
        }
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
}  // namespace Cowdia::Rendering
