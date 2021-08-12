#include <Cowdia/Math/Vector3.hpp>

namespace Cowdia::Math
{
Vector3::Vector3(float x, float y, float z) : VectorBase<3>{ x, y, z }
{
    // Do nothing.
}

Vector3::Vector3(const VectorBase<3>& other) : VectorBase<3>(other)
{
    // Do nothing.
}

Vector3 Vector3::Cross(const Vector3& other) const
{
    const float x = ptr[1] * other.ptr[2] - ptr[2] * other.ptr[1];
    const float y = ptr[2] * other.ptr[0] - ptr[0] * other.ptr[2];
    const float z = ptr[0] * other.ptr[1] - ptr[1] * other.ptr[0];

    return Vector3{ x, y, z };
}

float& Vector3::X()
{
    return ptr[0];
}

float Vector3::X() const
{
    return ptr[0];
}

float& Vector3::Y()
{
    return ptr[1];
}

float Vector3::Y() const
{
    return ptr[1];
}

float& Vector3::Z()
{
    return ptr[2];
}

float Vector3::Z() const
{
    return ptr[2];
}
}  // namespace Cowdia::Math
