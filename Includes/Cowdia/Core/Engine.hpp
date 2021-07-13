#ifndef COWDIA_ENGINE_HPP
#define COWDIA_ENGINE_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Core/LogManager.hpp>
#include <Cowdia/Core/PluginManager.hpp>
#include <Cowdia/Rendering/RenderSystem.hpp>
#include <Cowdia/Utils/Singleton.hpp>

#include <string>
#include <unordered_map>

namespace Cowdia::Core
{
class COWDIA_API Engine final : public Utils::Singleton<Engine>
{
 public:
    //! Register render system to engine.
    //! \param renderSystem render system to register.
    void RegisterRenderSystem(Rendering::RenderSystem* renderSystem);

    //! Unregister render system from engine.
    //! \param renderSystem render system to unregister.
    void UnregisterRenderSystem(Rendering::RenderSystem* renderSystem);

    //! Returns render system whose name is \p name.
    //! \param name name of the render system.
    Rendering::RenderSystem* GetRenderSystemByName(
        const std::string& name) const;

    //! Set render system.
    //! \param renderSystem new render system.
    void SetRenderSystem(Rendering::RenderSystem* renderSystem);

    //! Returns current render system.
    Rendering::RenderSystem* GetRenderSystem() const;

    //! Run the engine.
    void Run();

    //! Stop the engine.
    void Stop();

    //! Returns engine runnign status.
    bool IsRunning() const;

 private:
    bool isRunning_{ false };

    // Managers
    LogManager logMgr_;
    PluginManager pluginMgr_;

    Rendering::RenderSystem* curRenderSystem_{ nullptr };
    std::unordered_map<std::string, Rendering::RenderSystem*> renderSystem_;
};
}  // namespace Cowdia::Core

#endif  // COWDIA_ENGINE_HPP
