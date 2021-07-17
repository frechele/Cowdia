#ifndef COWDIA_RENDERER_HPP
#define COWDIA_RENDERER_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Types/Color.hpp>

namespace Cowdia::Rendering
{
class COWDIA_API Renderer
{
 public:
    //! Default destructor.
    virtual ~Renderer() = default;

    //! Initialize the renderer.
    virtual void Initialize() = 0;

    //! Shutdown the renderer.
    virtual void Shutdown() = 0;

    //! Returns whether the renderer is initialized.
    virtual bool IsInitialized() const = 0;

    //! Begin frame.
    //! \param color Clear the color of the render target.
    virtual void BeginFrame(Types::Color color) = 0;

    //! End frame.
    virtual void EndFrame() = 0;
};
}  // namespace Cowdia::Rendering

#endif  // COWDIA_RENDERER_HPP
