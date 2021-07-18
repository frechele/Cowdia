#ifndef COWDIA_ENGINE_HPP
#define COWDIA_ENGINE_HPP

#include <Cowdia/Core/Application.hpp>
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
    //! Set the engine to debug mode.
    //! \param value whether debug mode is enabled.
    void SetDebugMode(bool value);

    //! Register render system to engine.
    //! \param renderSystem render system to register.
    void RegisterRenderSystem(Rendering::RenderSystem* renderSystem);

    //! Unregister render system from engine.
    //! \param renderSystem render system to unregister.
    void UnregisterRenderSystem(Rendering::RenderSystem* renderSystem);

    //! Returns render system whose name is \p name.
    //! \param name name of the render system.
    [[nodiscard]] Rendering::RenderSystem* GetRenderSystemByName(
        const std::string& name) const;

    //! Set render system.
    //! \param renderSystem new render system.
    void SetRenderSystem(Rendering::RenderSystem* renderSystem);

    //! Returns current render system.
    [[nodiscard]] Rendering::RenderSystem* GetRenderSystem() const;

    //! Run the engine.
    void Run(Application& app);

    //! Stop the engine.
    void Stop();

    //! Returns engine runnign status.
    [[nodiscard]] bool IsRunning() const;

 private:
    bool isDebug_{ false };
    bool isRunning_{ false };

    Rendering::RenderSystem* curRenderSystem_{ nullptr };
    std::unordered_map<std::string, Rendering::RenderSystem*> renderSystem_;

    // Managers
    LogManager logMgr_;
    PluginManager pluginMgr_;
};
}  // namespace Cowdia::Core

#endif  // COWDIA_ENGINE_HPP
