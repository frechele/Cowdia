#ifndef COWDIA_RENDER_SYSTEM_HPP
#define COWDIA_RENDER_SYSTEM_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Rendering/Renderer.hpp>
#include <Cowdia/Rendering/RenderWindow.hpp>

#include <string>

namespace Cowdia::Rendering
{
class COWDIA_API RenderSystem
{
 public:
    //! Default destructor
    virtual ~RenderSystem() = default;

    //! Initialize render system.
    virtual void Initialize() = 0;

    //! Shutdown render system.
    virtual void Shutdown() = 0;

    //! Returns the name of render system.
    [[nodiscard]] virtual std::string GetName() const = 0;

    //! Returns renderer.
    [[nodiscard]] virtual Renderer* GetRenderer() = 0;

    //! Returns render window instance.
    [[nodiscard]] virtual RenderWindow* GetRenderWindow() = 0;

    //! Poll events.
    //! \return true if there is events to process else false.
    [[nodiscard]] virtual bool PollEvents() = 0;
};
}  // namespace Cowdia::Rendering

#endif  // COWDIA_RENDER_SYSTEM_HPP
