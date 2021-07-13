#ifndef COWDIA_PLUGIN_ASSEMBLY_HPP
#define COWDIA_PLUGIN_ASSEMBLY_HPP

#include <Cowdia/Core/Common.hpp>

#include <string>

namespace Cowdia::Core
{
using PluginHandle = void*;
using PluginProc = void (*)(void);

class COWDIA_API PluginAssembly final
{
 public:
    //! Constructor with plugin name.
    explicit PluginAssembly(const std::string& name);

    //! Load plugin.
    void Load();

    //! Unload plugin.
    void Unload();

    //! Returns plugin name.
    [[nodiscard]] const std::string& GetName() const noexcept;

    //! Load plugin procedure.
    [[nodiscard]] PluginProc GetProc(const std::string& procName) const;

 private:
    std::string name_;
    PluginHandle handle_{ nullptr };
};
}  // namespace Cowdia::Core

#endif  // COWDIA_PLUGIN_ASSEMBLY_HPP
