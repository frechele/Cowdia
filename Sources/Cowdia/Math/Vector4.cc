#include <Cowdia/Math/Vector4.hpp>

namespace Cowdia::Math
{
Vector4::Vector4(float x, float y, float z, float w)
    : VectorBase<4>{ x, y, z, w }
{
}

Vector4::Vector4(const VectorBase<4>& other) : VectorBase<4>(other)
{
}

float& Vector4::X()
{
    return ptr[0];
}

float Vector4::X() const
{
    return ptr[0];
}

float& Vector4::Y()
{
    return ptr[1];
}

float Vector4::Y() const
{
    return ptr[1];
}

float& Vector4::Z()
{
    return ptr[2];
}

float Vector4::Z() const
{
    return ptr[2];
}

float& Vector4::W()
{
    return ptr[3];
}

float Vector4::W() const
{
    return ptr[4];
}
}  // namespace Cowdia::Math
