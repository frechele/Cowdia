#ifndef COWDIA_PLUGIN_HPP
#define COWDIA_PLUGIN_HPP

#include <string>

namespace Cowdia::Core
{
using PluginHandle = void*;
using PluginMain = int (*)(void);

class Plugin final
{
 public:
    //! Constructor with plugin name.
    explicit Plugin(const std::string& name);

    //! Load plugin.
    void Load();

    //! Unload plugin.
    void Unload();

    //! Returns plugin name.
    [[nodiscard]] const std::string& GetName() const noexcept;

    //! Load plugin main entry.
    [[nodiscard]] PluginMain GetPluginMain() const;

 private:
    std::string name_;
    PluginHandle handle_{ nullptr };
};
}  // namespace Cowdia::Core

#endif  // COWDIA_PLUGIN_HPP
