#include <Cowdia/Math/Angle.hpp>

#include <Cowdia/Math/Constants.hpp>

namespace Cowdia::Math
{
Radian::Radian(float rad) : value(rad)
{
}

Degree Radian::ToDegree() const
{
    return Degree(value * 180.f / Constants::PI);
}

bool Radian::operator==(Radian other) const
{
    return value == other.value;
}

bool Radian::operator!=(Radian other) const
{
    return value != other.value;
}

Degree::Degree(float deg) : value(deg)
{
}

Radian Degree::ToRadian() const
{
    return Radian(value * Constants::PI / 180.f);
}

bool Degree::operator==(Degree other) const
{
    return value == other.value;
}

bool Degree::operator!=(Degree other) const
{
    return value != other.value;
}
}  // namespace Cowdia::Math
