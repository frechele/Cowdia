#ifndef D3D12RS_PLUGIN_HPP
#define D3D12RS_PLUGIN_HPP

#include "D3D12Common.hpp"
#include "D3D12RenderSystem.hpp"

#include <Cowdia/Core/Plugin.hpp>
#include <Cowdia/Core/PluginManager.hpp>

namespace Cowdia::Core
{
class COWDIA_D3D12_API D3D12Plugin final : public Plugin
{
 public:
    void OnInstalled() override;
    void OnUninstalled() override;

 private:
    Rendering::D3D12RenderSystem* renderSystem_{ nullptr };
};
}  // namespace Cowdia::Core

#endif  // D3D12RS_PLUGIN_HPP
