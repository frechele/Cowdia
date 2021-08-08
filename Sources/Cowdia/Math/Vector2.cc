#include <Cowdia/Math/Vector2.hpp>

namespace Cowdia::Math
{
float& Vector2::X()
{
    return ptr[0];
}

float Vector2::X() const
{
    return ptr[0];
}

float& Vector2::Y()
{
    return ptr[1];
}

float Vector2::Y() const
{
    return ptr[1];
}
}  // namespace Cowdia::Math
