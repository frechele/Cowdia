#ifndef COWDIA_VECTOR4_HPP
#define COWDIA_VECTOR4_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Math/VectorBase.hpp>

namespace Cowdia::Math
{
class COWDIA_API Vector4 final : public VectorBase<4>
{
 public:
    //! Default constructor.
    Vector4() = default;

    //! Constructor with elements.
    template <typename... Args>
    Vector4(Args... args) : VectorBase<4>(args...)
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

    //! Returns z element.
    float& Z();

    //! Returns z element.
    float Z() const;

    //! Returns w element.
    float& W();

    //! Returns w element.
    float W() const;
};
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR3_HPP
