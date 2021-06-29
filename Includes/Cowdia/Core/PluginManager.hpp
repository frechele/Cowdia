#ifndef COWDIA_PLUGIN_MANAGER_HPP
#define COWDIA_PLUGIN_MANAGER_HPP

#include <Cowdia/Utils/Singleton.hpp>
#include <Cowdia/Core/Plugin.hpp>

#include <unordered_map>
#include <memory>

namespace Cowdia::Core
{
class PluginManager final : public Utils::Singleton<PluginManager>
{
 public:
    //! Destructor.
    ~PluginManager();

    //! Load plugin.
    //! \param name the name of plugin.
    [[nodiscard]] Plugin* Load(const std::string& name);

    //! Unload plugin.
    //! \param name the name of plugin.
    void Unload(const std::string& name);

 private:
    std::unordered_map<std::string, std::unique_ptr<Plugin>> plugins_;
};
}  // namespace Cowdia::Core

#endif  // COWDIA_PLUGIN_MANAGER_HPP
