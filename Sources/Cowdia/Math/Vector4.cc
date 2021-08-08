#include <Cowdia/Math/Vector4.hpp>

namespace Cowdia::Math
{
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
