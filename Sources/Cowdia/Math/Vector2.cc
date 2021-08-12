#include <Cowdia/Math/Vector2.hpp>

namespace Cowdia::Math
{
Vector2::Vector2(float x, float y) : VectorBase<2>{ x, y }
{
}

Vector2::Vector2(const VectorBase<2>& other) : VectorBase<2>(other)
{
}

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
