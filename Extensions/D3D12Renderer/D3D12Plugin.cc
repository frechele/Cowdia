#include "D3D12Plugin.hpp"

#include <Cowdia/Core/Engine.hpp>

namespace Cowdia::Core
{
void D3D12Plugin::OnInstalled()
{
    renderSystem_ = new Rendering::D3D12RenderSystem;

    Engine::Get().RegisterRenderSystem(renderSystem_);
}

void D3D12Plugin::OnUninstalled()
{
    Engine::Get().UnregisterRenderSystem(renderSystem_);

    SAFE_DELETE(renderSystem_);
}
}  // namespace Cowdia::Core
