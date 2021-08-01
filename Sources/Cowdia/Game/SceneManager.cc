#include <Cowdia/Game/SceneManager.hpp>

#include <Cowdia/Core/LogManager.hpp>

namespace Cowdia::Game
{
SceneManager::~SceneManager() noexcept
{
    for (const auto it : scenes_)
    {
        delete it.second;
    }
}

void SceneManager::LoadScene(const std::string& name)
{
    auto it = scenes_.find(name);
    if (it == end(scenes_))
    {
        Core::LOG(Core::LogLevel::WARNING, "Cannot find scene named " + name);
        return;
    }

    if (currentScene_ != nullptr)
    {
        currentScene_->OnUnload();
    }

    currentScene_ = it->second;
    currentScene_->OnLoad();

    Core::LOG(Core::LogLevel::INFO, "Scene " + name + " is loaded");
}

void SceneManager::UnloadScene()
{
    if (currentScene_ != nullptr)
    {
        currentScene_->OnUnload();
    }

    currentScene_ = nullptr;
}

void SceneManager::ProcessFrame()
{
    if (currentScene_ == nullptr)
        return;

    renderer_->BeginFrame(currentScene_->ClearColor);

    renderer_->EndFrame();
}

void SceneManager::SetRenderSystem(Rendering::RenderSystem* renderSystem)
{
    renderSystem_ = renderSystem;
    renderer_ = renderSystem_->GetRenderer();
}
}  // namespace Cowdia::Game
