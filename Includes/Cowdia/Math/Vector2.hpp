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

    //! Constructor with elements.
    template <typename... Args>
    Vector2(Args... args) : VectorBase<2>(args...)
    {
    }

    //! Returns x element.
    float& X();

    //! Returns x element.
    float X() const;

    //! Returns y element.
    float& Y();

    //! Returns y element.
    float Y() const;
};
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR2_HPP
