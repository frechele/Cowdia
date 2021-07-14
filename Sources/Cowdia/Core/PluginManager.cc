#include <Cowdia/Core/PluginManager.hpp>

#include <Cowdia/Core/LogManager.hpp>

#include <algorithm>

namespace Cowdia::Core
{
PluginManager::~PluginManager()
{
    for (auto it : plugins_)
    {
        it->OnUninstalled();

        // the instance of plugin is not allocated in engine code.
        // so we must not deallocate.
    }

    for (auto& pr : assemblies_)
    {
        pr.second->Unload();
        delete pr.second;
    }
}

void PluginManager::Load(const std::string& name)
{
    const auto it = assemblies_.find(name);
    if (it != end(assemblies_))
        return;

    const auto plugin = assemblies_[name] = new PluginAssembly(name);
    plugin->Load();

    plugin->GetProc("OnPluginLoad")();

    LOG().Logging(LogLevel::INFO, "Plugin loaded " + name);
}

void PluginManager::Unload(const std::string& name)
{
    const auto it = assemblies_.find(name);
    if (it == end(assemblies_))
        return;

    it->second->GetProc("OnPluginUnload")();

    it->second->Unload();
    delete it->second;

    assemblies_.erase(it);

    LOG().Logging(LogLevel::INFO, "Plugin unloaded " + name);
}

void PluginManager::Install(Plugin* plugin)
{
    assert(plugins_.find(plugin) == end(plugins_));

    plugins_.emplace(plugin);
    plugin->OnInstalled();
}

void PluginManager::Uninstall(Plugin* plugin)
{
    plugin->OnUninstalled();
    plugins_.erase(plugin);
}
}  // namespace Cowdia::Core
