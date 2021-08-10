#ifndef COWDIA_ANGLE_HPP
#define COWDIA_ANGLE_HPP

#include <Cowdia/Core/Common.hpp>

namespace Cowdia::Math
{
struct Degree;

struct Radian final
{
    //! Default constructor.
    Radian() = default;

    //! Constructor with a radian value.
    explicit Radian(float rad);

    //! Default copy constructor.
    Radian(const Radian&) = default;

    //! Default move constructor.
    Radian(Radian&&) = default;

    //! Default copy assignment operator.
    Radian& operator=(const Radian&) = default;

    //! Default move assignment operator.
    Radian& operator=(Radian&&) = default;

    //! Convert to degree angle.
    [[nodiscard]] Degree ToDegree() const;

    [[nodiscard]] bool operator==(Radian other) const;
    [[nodiscard]] bool operator!=(Radian other) const;

    float value{ 0 };
};

struct Degree final
{
    //! Default constructor.
    Degree() = default;

    //! Constructor with a degree value.
    explicit Degree(float deg);

    //! Default copy constructor.
    Degree(const Degree&) = default;

    //! Default move constructor.
    Degree(Degree&&) = default;

    //! Default copy assignment operator.
    Degree& operator=(const Degree&) = default;

    //! Default move assignment operator.
    Degree& operator=(Degree&&) = default;

    //! Convert to radius angle.
    [[nodiscard]] Radian ToRadian() const;

    [[nodiscard]] bool operator==(Degree other) const;
    [[nodiscard]] bool operator!=(Degree other) const;

    float value{ 0 };
};
}

#endif  // COWDIA_ANGLE_HPP
