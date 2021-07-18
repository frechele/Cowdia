#include <Cowdia/Core/Engine.hpp>

#include <Cowdia/Core/Exception.hpp>

#include <cassert>

namespace Cowdia::Core
{
void Engine::SetDebugMode(bool value)
{
    if (isRunning_)
    {
        throw RuntimeException(
            "cannot set debug mode while engine is running.");
    }

    isDebug_ = value;
}

void Engine::RegisterRenderSystem(Rendering::RenderSystem* renderSystem)
{
    assert(renderSystem_.find(renderSystem->GetName()) == end(renderSystem_));

    renderSystem_.emplace(renderSystem->GetName(), renderSystem);

    LOG(LogLevel::INFO,
        "RenderSystem " + renderSystem->GetName() + " was registered");
}

void Engine::UnregisterRenderSystem(Rendering::RenderSystem* renderSystem)
{
    renderSystem_.erase(renderSystem->GetName());

    LOG(LogLevel::INFO,
        "RenderSystem " + renderSystem->GetName() + " was unregistered");
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
    if (isRunning_)
    {
        throw RuntimeException(
            "cannot change render system while engine is running.");
    }

    curRenderSystem_ = renderSystem;
    sceneMgr_.SetRenderSystem(renderSystem);

    LOG(LogLevel::INFO,
        "RenderSystem is changed to " + renderSystem->GetName());
}

Rendering::RenderSystem* Engine::GetRenderSystem() const
{
    return curRenderSystem_;
}

void Engine::Run(Application& app)
{
    try
    {
        app.OnInitialize();

        if (curRenderSystem_ == nullptr)
        {
            throw RuntimeException("render system not found");
        }

        const auto renderer = curRenderSystem_->GetRenderer();

        if (!renderer->IsInitialized())
        {
            throw RuntimeException("renderer is not initialized");
        }

        isRunning_ = true;

        LOG(LogLevel::INFO, "Engine starts to run");

        while (isRunning_)
        {
            if (!curRenderSystem_->PollEvents())
            {
                renderer->BeginFrame(Types::Color(255, 0, 0));

                renderer->EndFrame();
            }
        }

        LOG(LogLevel::INFO, "Engine stopped");

        app.OnShutdown();
    }
    catch (Exception& e)
    {
        LOG(e);

        if (isDebug_)
            throw;
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
