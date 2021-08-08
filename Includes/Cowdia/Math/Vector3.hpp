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

    //! Constructor with three elements.
    Vector3(float x, float y, float z);

    //! Constructor with VectorBase.
    Vector3(const VectorBase<3>& other);

    //! Default copy constructor.
    Vector3(const Vector3&) = default;

    //! Default move constructor.
    Vector3(Vector3&&) = default;

    //! Default copy assignment operator.
    Vector3& operator=(const Vector3&) = default;

    //! Default move assignment operator.
    Vector3& operator=(Vector3&&) = default;

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
