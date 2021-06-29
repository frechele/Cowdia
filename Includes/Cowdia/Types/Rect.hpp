#ifndef COWDIA_RECT_HPP
#define COWDIA_RECT_HPP

namespace Cowdia::Types
{
template <typename T>
class Rect final
{
 public:
    //! Default constructor.
    constexpr Rect() = default;

    //! Constructor with width, height.
    constexpr Rect(T width, T height);

    //! Constructor with full arguments.
    constexpr Rect(T left, T top, T width, T height);

    [[nodiscard]] constexpr T GetLeft() const;
    [[nodiscard]] constexpr T GetRight() const;
    [[nodiscard]] constexpr T GetTop() const;
    [[nodiscard]] constexpr T GetBottom() const;
    [[nodiscard]] constexpr T GetWidth() const;
    [[nodiscard]] constexpr T GetHeight() const;

    [[nodiscard]] constexpr bool operator==(const Rect<T>& other) const;
    [[nodiscard]] constexpr bool operator!=(const Rect<T>& other) const;

 private:
    T left_{ 0 };
    T top_{ 0 };
    T width_{ 0 };
    T height_{ 0 };
};

using Recti = Rect<int>;
using Rectf = Rect<float>;

template <typename T>
constexpr Rect<T>::Rect(T width, T height) : Rect<T>(0, 0, width, height)
{
    // Do nothing
}

template <typename T>
constexpr Rect<T>::Rect(T left, T top, T width, T height)
    : left_(left), top_(top), width_(width), height_(height)
{
    // Do nothing
}

template <typename T>
constexpr T Rect<T>::GetLeft() const
{
    return left_;
}

template <typename T>
constexpr T Rect<T>::GetRight() const
{
    return left_ + width_;
}

template <typename T>
constexpr T Rect<T>::GetTop() const
{
    return top_;
}

template <typename T>
constexpr T Rect<T>::GetBottom() const
{
    return top_ + height_;
}

template <typename T>
constexpr T Rect<T>::GetWidth() const
{
    return width_;
}

template <typename T>
constexpr T Rect<T>::GetHeight() const
{
    return height_;
}

template <typename T>
constexpr bool Rect<T>::operator==(const Rect<T>& other) const
{
    return (left_ == other.left_) && (top_ == other.top_) &&
           (width_ == other.width_) && (height_ == other.height_);
}

template <typename T>
constexpr bool Rect<T>::operator!=(const Rect<T>& other) const
{
    return !(*this == other);
}
}  // namespace Cowdia::Types

#endif  // COWDIA_RECT_HPP
