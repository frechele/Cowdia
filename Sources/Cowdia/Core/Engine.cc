#include <Cowdia/Core/Engine.hpp>

#include <cassert>

namespace Cowdia::Core
{
void Engine::RegisterRenderSystem(Rendering::RenderSystem* renderSystem)
{
    assert(renderSystem_.find(renderSystem->GetName()) == end(renderSystem_));

    renderSystem_.emplace(renderSystem->GetName(), renderSystem);
}

void Engine::UnregisterRenderSystem(Rendering::RenderSystem* renderSystem)
{
    renderSystem_.erase(renderSystem->GetName());
}

Rendering::RenderSystem* Engine::GetRenderSystemByName(
    const std::string& name) const
{
    const auto it = renderSystem_.find(name);
    if (it == end(renderSystem_))
        return nullptr;

    return it->second;
}

void Engine::SetRenderSystem(Rendering::RenderSystem* renderSystem)
{
    curRenderSystem_ = renderSystem;
}

Rendering::RenderSystem* Engine::GetRenderSystem() const
{
    return curRenderSystem_;
}

void Engine::Run()
{
    assert(curRenderSystem_ != nullptr);

    isRunning_ = true;

    while (isRunning_)
    {
        if (!curRenderSystem_->PollEvents())
        {
            // Rendering.
        }
    }
}

void Engine::Stop()
{
    isRunning_ = false;
}

bool Engine::IsRunning() const
{
    return isRunning_;
}
}  // namespace Cowdia::Core
