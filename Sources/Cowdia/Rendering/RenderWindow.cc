#include <Cowdia/Rendering/RenderWindow.hpp>

namespace Cowdia::Rendering
{
Types::Recti RenderWindow::GetSize() const
{
    return Types::Recti(width_, height_);
}

bool RenderWindow::IsFullscreen() const
{
    return fullScreen_;
}
}  // namespace Cowdia::Rendering
