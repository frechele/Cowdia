#ifndef COWDIA_VECTOR2_HPP
#define COWDIA_VECTOR2_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Math/VectorBase.hpp>

namespace Cowdia::Math
{
class COWDIA_API Vector2 final : public VectorBase<2>
{
 public:
    //! Default constructor.
    Vector2() = default;

    //! Constructor with two elements.
    Vector2(float x, float y);

    //! Constructor with VectorBase.
    Vector2(const VectorBase<2>& other);

    //! Default copy constructor.
    Vector2(const Vector2&) = default;

    //! Default move constructor.
    Vector2(Vector2&&) = default;

    //! Default copy assignment operator.
    Vector2& operator=(const Vector2&) = default;

    //! Default move assignment operator.
    Vector2& operator=(Vector2&&) = default;

    //! Returns x element.
    [[nodiscard]] float& X();

    //! Returns x element.
    [[nodiscard]] float X() const;

    //! Returns y element.
    [[nodiscard]] float& Y();

    //! Returns y element.
    [[nodiscard]] float Y() const;
};
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR2_HPP
