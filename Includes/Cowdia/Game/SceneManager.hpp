#ifndef COWDIA_SCENE_MANAGER_HPP
#define COWDIA_SCENE_MANAGER_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Game/Scene.hpp>
#include <Cowdia/Rendering/RenderSystem.hpp>
#include <Cowdia/Rendering/Renderer.hpp>
#include <Cowdia/Utils/Singleton.hpp>

#include <memory>
#include <string>
#include <unordered_map>

namespace Cowdia::Game
{
class COWDIA_API SceneManager final : public Utils::Singleton<SceneManager>
{
 public:
    //! Destructor.
    ~SceneManager() noexcept;

    //! Register scene.
    //! \param name The name of the scene.
    //! \param args Arguments of scene constructor.
    template <class SceneT, typename... Args>
    void RegisterScene(const std::string& name, Args&&... args);

    //! Load scene by name.
    //! \param name The name of the scene.
    void LoadScene(const std::string& name);

    //! Unload the current scene.
    void UnloadScene();

    //! Process frame.
    void ProcessFrame();

    //! Update render system.
    void SetRenderSystem(Rendering::RenderSystem* renderSystem);

 private:
    Rendering::RenderSystem* renderSystem_{ nullptr };
    Rendering::Renderer* renderer_{ nullptr };

    std::unordered_map<std::string, Scene*> scenes_;
    Scene* currentScene_{ nullptr };
};

template <class SceneT, typename... Args>
void SceneManager::RegisterScene(const std::string& name, Args&&... args)
{
    scenes_[name] = new SceneT(std::forward<Args>(args)...);
}
}  // namespace Cowdia::Game

#endif  // COWDIA_SCENE_MANAGER_HPP
