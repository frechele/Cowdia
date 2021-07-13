#ifndef COWDIA_PLUGIN_MANAGER_HPP
#define COWDIA_PLUGIN_MANAGER_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Core/Plugin.hpp>
#include <Cowdia/Core/PluginAssembly.hpp>
#include <Cowdia/Utils/Singleton.hpp>

#include <unordered_map>
#include <set>

namespace Cowdia::Core
{
class COWDIA_API PluginManager final : public Utils::Singleton<PluginManager>
{
 public:
    //! Destructor.
    ~PluginManager();

    //! Load plugin.
    //! \param name the name of plugin.
    void Load(const std::string& name);

    //! Unload plugin.
    //! \param name the name of plugin.
    void Unload(const std::string& name);

    //! Install plugin.
    //! \param plugin the plugin pointer to install.
    void Install(Plugin* plugin);

    //! Uninstall plugin.
    //! \param plugin the plugin pointer to uninstall.
    void Uninstall(Plugin* plugin);

 private:
    std::set<Plugin*> plugins_;
    std::unordered_map<std::string, PluginAssembly*> assemblies_;
};
}  // namespace Cowdia::Core

#endif  // COWDIA_PLUGIN_MANAGER_HPP
