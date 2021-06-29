#include <Cowdia/Core/PluginManager.hpp>

#include <iostream>

using namespace Cowdia;
using namespace Cowdia::Core;

int main()
{
    PluginManager pluginMgr;

    auto plugin = PluginManager::Get().Load("D3D12Renderer");

    std::cout << "Plugin name: " << plugin->GetName() << std::endl;
    std::cout << "Plugin main return: " << plugin->GetPluginMain() << std::endl;

    PluginManager::Get().Unload("D3D12Renderer");
}
