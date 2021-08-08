#include <Cowdia/Math/Vector3.hpp>

namespace Cowdia::Math
{
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
