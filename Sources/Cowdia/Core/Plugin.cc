#include <Cowdia/Core/Plugin.hpp>

#include <cassert>
#include <stdexcept>

#ifdef COWDIA_PLATFORM_WIN32
#define NOMINMAX
#include <Windows.h>
#endif

namespace
{
#ifdef COWDIA_PLATFORM_WIN32
Cowdia::Core::PluginHandle LoadDynamicLibrary(const std::string& name)
{
    return LoadLibrary((name + ".dll").c_str());
}

int UnloadDynamicLibrary(Cowdia::Core::PluginHandle handle)
{
    return FreeLibrary(reinterpret_cast<HINSTANCE>(handle));
}

Cowdia::Core::PluginMain LoadPluginMain(Cowdia::Core::PluginHandle handle)
{
    return reinterpret_cast<Cowdia::Core::PluginMain>(
        GetProcAddress(reinterpret_cast<HINSTANCE>(handle), "PluginMain"));
}
#else
Cowdia::Core::PluginHandle LoadDynamicLibrary([[maybe_unused]] const std::string& name)
{
    return nullptr;
}

int UnloadDynamicLibrary([[maybe_unused]] Cowdia::Core::PluginHandle handle)
{
    return -1;
}

Cowdia::Core::PluginMain LoadPluginMain([[maybe_unused]] Cowdia::Core::PluginHandle handle)
{
    return nullptr;
}
#endif
}  // namespace

namespace Cowdia::Core
{
Plugin::Plugin(const std::string& name) : name_(name)
{
    // Do nothing.
}

void Plugin::Load()
{
    using namespace std::string_literals;

    assert(handle_ == nullptr);

    if ((handle_ = LoadDynamicLibrary(name_)) == nullptr)
    {
        throw std::runtime_error("cannot load plugin: "s + name_);
    }
}

void Plugin::Unload()
{
    using namespace std::string_literals;

    assert(handle_ != nullptr);

    if (!UnloadDynamicLibrary(handle_))
    {
        throw std::runtime_error("cannot unload plugin: "s + name_);
    }

    handle_ = nullptr;
}

const std::string& Plugin::GetName() const noexcept
{
    return name_;
}

PluginMain Plugin::GetPluginMain() const
{
    assert(handle_ != nullptr);

    return LoadPluginMain(handle_);
}
}  // namespace Cowdia::Core
