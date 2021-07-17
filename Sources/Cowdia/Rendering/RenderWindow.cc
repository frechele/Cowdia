#include <Cowdia/Rendering/RenderWindow.hpp>

namespace Cowdia::Rendering
{
bool RenderWindow::Create(int width, int height)
{
    width_ = width;
    height_ = height;

    return true;
}

void RenderWindow::Resize(int width, int height)
{
    width_ = width;
    height_ = height;
}

void RenderWindow::Fullscreen(bool fullscreen)
{
    fullscreen_ = fullscreen;
}

int RenderWindow::GetWidth() const
{
    return width_;
}

int RenderWindow::GetHeight() const
{
    return height_;
}

bool RenderWindow::IsFullscreen() const
{
    return fullscreen_;
}
}  // namespace Cowdia::Rendering
