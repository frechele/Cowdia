#ifndef COWDIA_COLOR_HPP
#define COWDIA_COLOR_HPP

#include <cstdint>

namespace Cowdia::Types
{
class Color final
{
 public:
    //! Default constructor.
    constexpr Color() = default;

    //! Constructor with RGB.
    constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b);

    //! Constructor with RGBA.
    constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b,
                    std::uint8_t a);

    //! Constructor with integer.
    constexpr explicit Color(std::uint32_t value);

    [[nodiscard]] constexpr std::uint8_t GetR() const;
    [[nodiscard]] constexpr std::uint8_t GetG() const;
    [[nodiscard]] constexpr std::uint8_t GetB() const;
    [[nodiscard]] constexpr std::uint8_t GetA() const;

    [[nodiscard]] constexpr std::uint32_t GetRGBA() const;

    [[nodiscard]] constexpr bool operator==(const Color& other) const;
    [[nodiscard]] constexpr bool operator!=(const Color& other) const;

 private:
    std::uint32_t value_{ 0xFFFFFFFF };
};

constexpr Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b)
    : Color(r, g, b, 255)
{
    // Do nothing.
}

constexpr Color::Color(std::uint8_t r, std::uint8_t g, std::uint8_t b,
                       std::uint8_t a)
    : Color(((r & 0xFF) << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) |
            (a & 0xFF))
{
    // Do nothing.
}

constexpr Color::Color(std::uint32_t value) : value_(value)
{
    // Do nothing.
}

constexpr std::uint8_t Color::GetR() const
{
    return (value_ >> 24) & 0xFF;
}

constexpr std::uint8_t Color::GetG() const
{
    return (value_ >> 16) & 0xFF;
}

constexpr std::uint8_t Color::GetB() const
{
    return (value_ >> 8) & 0xFF;
}

constexpr std::uint8_t Color::GetA() const
{
    return value_ & 0xFF;
}

constexpr std::uint32_t Color::GetRGBA() const
{
    return value_;
}

constexpr bool Color::operator==(const Color& other) const
{
    return value_ == other.value_;
}

constexpr bool Color::operator!=(const Color& other) const
{
    return !(*this == other);
}
}  // namespace Cowdia::Types

#endif  // COWDIA_COLOR_HPP
