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

    //! Constructor with four elements.
    Vector4(float x, float y, float z, float w);

    //! Constructor with VectorBase.
    Vector4(const VectorBase<4>& other);

    //! Default copy constructor.
    Vector4(const Vector4&) = default;

    //! Default move constructor.
    Vector4(Vector4&&) = default;

    //! Default copy assignment operator.
    Vector4& operator=(const Vector4&) = default;

    //! Default move assignment operator.
    Vector4& operator=(Vector4&&) = default;

    //! Returns x element.
    [[nodiscard]] float& X();

    //! Returns x element.
    [[nodiscard]] float X() const;

    //! Returns y element.
    [[nodiscard]] float& Y();

    //! Returns y element.
    [[nodiscard]] float Y() const;

    //! Returns z element.
    [[nodiscard]] float& Z();

    //! Returns z element.
    [[nodiscard]] float Z() const;

    //! Returns w element.
    [[nodiscard]] float& W();

    //! Returns w element.
    [[nodiscard]] float W() const;
};
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR3_HPP
