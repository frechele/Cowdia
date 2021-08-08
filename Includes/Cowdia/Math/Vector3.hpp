#ifndef COWDIA_VECTOR3_HPP
#define COWDIA_VECTOR3_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Math/VectorBase.hpp>

namespace Cowdia::Math
{
class COWDIA_API Vector3 final : public VectorBase<3>
{
 public:
    //! Default constructor.
    Vector3() = default;

    //! Constructor with elements.
    template <typename... Args>
    Vector3(Args... args) : VectorBase<3>(args...)
    {
    }

    //! Returns outer product.
    Vector3 Cross(const Vector3& other) const;

    //! Returns x element.
    float& X();

    //! Returns x element.
    float X() const;

    //! Returns y element.
    float& Y();

    //! Returns y element.
    float Y() const;

    //! Returns z element.
    float& Z();

    //! Returns z element.
    float Z() const;
};
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR3_HPP
