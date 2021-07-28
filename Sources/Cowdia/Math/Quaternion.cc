#include <Cowdia/Math/Quaternion.hpp>

#include <cmath>

namespace Cowdia::Math
{
Quaternion::Quaternion(float x, float y, float z, float w)
    : x_(x), y_(y), z_(z), w_(w)
{
    // Do nothing.
}

Quaternion Quaternion::Identity()
{
    return Quaternion(0, 0, 0, 1);
}

Quaternion Quaternion::Euler(float x, float y, float z)
{
    const float cosx = std::cos(x / 2.f);
    const float cosy = std::cos(y / 2.f);
    const float cosz = std::cos(z / 2.f);
    const float sinx = std::sin(x / 2.f);
    const float siny = std::sin(y / 2.f);
    const float sinz = std::sin(z / 2.f);

    const float quatX = sinx * cosy * cosz - cosx * siny * sinz;
    const float quatY = cosx * siny * cosz + sinx * cosy * sinz;
    const float quatZ = cosx * cosy * sinz - sinx * siny * cosz;
    const float quatW = cosx * cosy * cosz + sinx * siny * sinz;

    return Quaternion(quatX, quatY, quatZ, quatW);
}

Quaternion Quaternion::operator+(const Quaternion& other) const
{
    Quaternion tmp{ *this };
    tmp += other;
    return tmp;
}

Quaternion Quaternion::operator-(const Quaternion& other) const
{
    Quaternion tmp{ *this };
    tmp -= other;
    return tmp;
}

Quaternion Quaternion::operator*(float v) const
{
    Quaternion tmp{ *this };
    tmp *= v;
    return tmp;
}

Quaternion& Quaternion::operator+=(const Quaternion& other)
{
    x_ += other.x_;
    y_ += other.y_;
    z_ += other.z_;
    w_ += other.w_;

    return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& other)
{
    x_ -= other.x_;
    y_ -= other.y_;
    z_ -= other.z_;
    w_ -= other.w_;

    return *this;
}

Quaternion& Quaternion::operator*=(float v)
{
    x_ *= v;
    y_ *= v;
    z_ *= v;
    w_ *= v;

    return *this;
}
}  // namespace Cowdia::Math
