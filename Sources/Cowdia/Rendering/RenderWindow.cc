#include <Cowdia/Rendering/RenderWindow.hpp>

namespace Cowdia::Rendering
{
void RenderWindow::Resize(int width, int height)
{
    width_ = width;
    height_ = height;
}

void RenderWindow::Fullscreen(bool fullscreen)
{
    fullscreen_ = fullscreen;
}

Types::Recti RenderWindow::GetSize() const
{
    return Types::Recti(width_, height_);
}

bool RenderWindow::IsFullscreen() const
{
    return fullscreen_;
}
}  // namespace Cowdia::Rendering
