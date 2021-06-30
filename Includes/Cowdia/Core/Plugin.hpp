#ifndef COWDIA_PLUGIN_HPP
#define COWDIA_PLUGIN_HPP

#include <Cowdia/Core/Common.hpp>

namespace Cowdia::Core
{
class COWDIA_API Plugin
{
 public:
    //! Default destructor.
    virtual ~Plugin() = default;

    //! Triggered when this plugin is installed.
    virtual void OnInstalled() = 0;

    //! Triggered when this plugin is uninstalled.
    virtual void OnUninstalled() = 0;
};
}  // namespace Cowdia::Core

#endif  // COWDIA_PLUGIN_HPP
