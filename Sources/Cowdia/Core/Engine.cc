#include <Cowdia/Core/Engine.hpp>

#include <cassert>

namespace Cowdia::Core
{
void Engine::RegisterRenderSystem(Rendering::RenderSystem* renderSystem)
{
    assert(renderSystem_.find(renderSystem->GetName()) == end(renderSystem_));

    renderSystem_.emplace(renderSystem->GetName(), renderSystem);

    LOG().Logging(LogLevel::INFO, "RenderSystem " + renderSystem->GetName() +
                                      " was registered");
}

void Engine::UnregisterRenderSystem(Rendering::RenderSystem* renderSystem)
{
    renderSystem_.erase(renderSystem->GetName());

    LOG().Logging(LogLevel::INFO, "RenderSystem " + renderSystem->GetName() +
                                      " was unregistered");
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

    LOG().Logging(LogLevel::INFO,
                  "RenderSystem is changed to " + renderSystem->GetName());
}

Rendering::RenderSystem* Engine::GetRenderSystem() const
{
    return curRenderSystem_;
}

void Engine::Run()
{
    assert(curRenderSystem_ != nullptr);

    isRunning_ = true;

    LOG().Logging(LogLevel::INFO, "Engine starts to run");

    while (isRunning_)
    {
        const auto renderer = curRenderSystem_->GetRenderer();

        if (!curRenderSystem_->PollEvents() && renderer->IsInitialized())
        {
            renderer->BeginFrame(Types::Color(255, 0, 0));

            renderer->EndFrame();
        }
    }

    LOG().Logging(LogLevel::INFO, "Engine stopped");
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
