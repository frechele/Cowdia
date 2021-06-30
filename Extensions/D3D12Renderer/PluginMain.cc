#include "D3D12Plugin.hpp"

#include "D3D12Common.hpp"

using namespace Cowdia::Core;

static D3D12Plugin* pluginInstance;

extern "C" void COWDIA_D3D12_API OnPluginLoad()
{
    pluginInstance = new D3D12Plugin;
    PluginManager::Get().Install(pluginInstance);
}

extern "C" void COWDIA_D3D12_API OnPluginUnload()
{
    PluginManager::Get().Uninstall(pluginInstance);
    delete pluginInstance;
}
