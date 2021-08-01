#ifndef D3D12RS_RENDER_WINDOW_HPP
#define D3D12RS_RENDER_WINDOW_HPP

#include "D3D12Common.hpp"

#include <Cowdia/Rendering/RenderWindow.hpp>

#include <Windows.h>

namespace Cowdia::Rendering
{
class COWDIA_D3D12_API D3D12RenderWindow final : public RenderWindow
{
 public:
    explicit D3D12RenderWindow(HINSTANCE hInstance);

    bool Create(int width, int height) override;
    void Destroy() override;

    void SetTitle(const std::string& title) override;

    void Resize(int width, int height) override;

    void Fullscreen(bool fullscreen) override;

    HWND GetHWND() const;

 private:
    static LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

 private:
    HINSTANCE hInstance_;
    HWND hwnd_{ nullptr };

    UINT windowStyle_;
    RECT windowRect_;
};
}  // namespace Cowdia::Rendering

#endif  // D3D12RS_RENDER_WINDOW_HPP
