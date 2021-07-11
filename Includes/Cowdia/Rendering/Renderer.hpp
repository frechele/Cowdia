#ifndef COWDIA_RENDERER_HPP
#define COWDIA_RENDERER_HPP

#include <Cowdia/Core/Common.hpp>

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
};
}  // namespace Cowdia::Rendering

#endif  // COWDIA_RENDERER_HPP
