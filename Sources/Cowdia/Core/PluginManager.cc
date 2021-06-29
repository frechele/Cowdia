#include <Cowdia/Core/PluginManager.hpp>

#include <algorithm>

namespace Cowdia::Core
{
PluginManager::~PluginManager()
{
    for (auto& pr : plugins_)
        pr.second->Unload();
}

Plugin* PluginManager::Load(const std::string& name)
{
    const auto it = plugins_.find(name);
    if (it != end(plugins_))
        return it->second.get();

    plugins_[name] = std::make_unique<Plugin>(name);
    plugins_[name]->Load();

    return plugins_[name].get();
}

void PluginManager::Unload(const std::string& name)
{
    const auto it = plugins_.find(name);
    if (it == end(plugins_))
        return;

    it->second->Unload();
    plugins_.erase(it);
}
}  // namespace Cowdia::Core
