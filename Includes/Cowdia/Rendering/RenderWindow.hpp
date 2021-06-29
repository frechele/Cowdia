#ifndef COWDIA_RENDER_WINDOW_HPP
#define COWDIA_RENDER_WINDOW_HPP

#include <Cowdia/Types/Rect.hpp>

#include <string>

namespace Cowdia::Rendering
{
class RenderWindow
{
 public:
    //! Default destructor.
    virtual ~RenderWindow() = default;

    //! Create window.
    //! \param width window width.
    //! \param height window height.
    //! \param fullscreen whether make window fullscreen or not.
    //! \return true if success to create.
    virtual bool Create(int width, int height, bool fullscreen) = 0;

    //! Destroy window.
    virtual void Destroy() = 0;

    //! Set window title.
    //! \param title new window title.
    virtual void SetTitle(const std::string& title) = 0;

    //! Resize window.
    //! \param width new window width.
    //! \param height new window height.
    virtual void Resize(int width, int height) = 0;

    //! Set fullscreen mode.
    //! \param fullscreen whether make window fullscreen or not.
    virtual void Fullscreen(bool fullscreen) = 0;

    //! Returns window size.
    Types::Recti GetSize() const;

    //! Returns whether window is full or not.
    bool IsFullscreen() const;

 protected:
    int width_{ 0 };
    int height_{ 0 };
    bool fullScreen_{ false };
};
}

#endif  // COWDIA_RENDER_WINDOW_HPP
