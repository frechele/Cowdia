#ifndef COWDIA_RENDER_WINDOW_HPP
#define COWDIA_RENDER_WINDOW_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Types/Rect.hpp>

#include <string>

namespace Cowdia::Rendering
{
class COWDIA_API RenderWindow
{
 public:
    //! Default destructor.
    virtual ~RenderWindow() = default;

    //! Create window.
    //! \param width window width.
    //! \param height window height.
    //! \return true if success to create.
    [[nodiscard]] virtual bool Create(int width, int height) = 0;

    //! Destroy window.
    virtual void Destroy() = 0;

    //! Set window title.
    //! \param title new window title.
    virtual void SetTitle(const std::string& title) = 0;

    //! Resize window.
    //! \param width new window width.
    //! \param height new window height.
    virtual void Resize(int width, int height);

    //! Set fullscreen mode.
    //! \param fullscreen whether make window fullscreen or not.
    virtual void Fullscreen(bool fullscreen);

    //! Returns window width.
    [[nodiscard]] int GetWidth() const;

    //! Returns window height.
    [[nodiscard]] int GetHeight() const;

    //! Returns whether window is full or not.
    [[nodiscard]] bool IsFullscreen() const;

 private:
    int width_{ 0 };
    int height_{ 0 };
    bool fullscreen_{ false };
};
}

#endif  // COWDIA_RENDER_WINDOW_HPP
