#ifndef D3D12RS_RENDER_SYSTEM_HPP
#define D3D12RS_RENDER_SYSTEM_HPP

#include "D3D12Common.hpp"

#include <Cowdia/Rendering/Renderer.hpp>
#include <Cowdia/Rendering/RenderSystem.hpp>
#include <Cowdia/Rendering/RenderWindow.hpp>

#include <Windows.h>

namespace Cowdia::Rendering
{
class COWDIA_D3D12_API D3D12RenderSystem final : public RenderSystem
{
 public:
    void Initialize() override;
    void Shutdown() override;

    [[nodiscard]] std::string GetName() const override;

    [[nodiscard]] Renderer* GetRenderer() override;

    [[nodiscard]] RenderWindow* GetRenderWindow() override;

    [[nodiscard]] bool PollEvents() override;

 private:
    HINSTANCE hInstance_{ nullptr };
    Renderer* renderer_{ nullptr };
    RenderWindow* renderWindow_{ nullptr };
};
}

#endif  // D3D12RS_RENDER_SYSTEM_HPP
