#include "D3D12RenderSystem.hpp"

#include "D3D12Renderer.hpp"
#include "D3D12RenderWindow.hpp"

namespace Cowdia::Rendering
{
void D3D12RenderSystem::Initialize()
{
    hInstance_ = GetModuleHandle(NULL);
}

void D3D12RenderSystem::Shutdown()
{
    SAFE_DELETE(renderer_);
    SAFE_DELETE(renderWindow_);
}

std::string D3D12RenderSystem::GetName() const
{
    using namespace std::string_literals;

    return "D3D12RenderSystem"s;
}

Renderer* D3D12RenderSystem::GetRenderer()
{
    if (renderer_ == nullptr)
    {
        renderer_ = new D3D12Renderer(this);
    }

    return renderer_;
}

RenderWindow* D3D12RenderSystem::GetRenderWindow()
{
    if (renderWindow_ == nullptr)
    {
        renderWindow_ = new D3D12RenderWindow(hInstance_);
    }

    return renderWindow_;
}

bool D3D12RenderSystem::PollEvents()
{
    MSG msg;
    if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        return true;
    }

    return false;
}
}  // namespace Cowdia::Rendering
