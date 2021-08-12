#ifndef COWDIA_QUATERNION_HPP
#define COWDIA_QUATERNION_HPP

#include <Cowdia/Core/Common.hpp>
#include <Cowdia/Math/Vector3.hpp>

namespace Cowdia::Math
{
class COWDIA_API Quaternion final
{
 public:
    //! Default constructor.
    Quaternion() = default;

    //! Constructor with x, y, z, w.
    Quaternion(float x, float y, float z, float w);

    //! Default copy constructor.
    Quaternion(const Quaternion&) = default;

    //! Default move constructor.
    Quaternion(Quaternion&&) = default;

    //! Default copy assignment operator.
    Quaternion& operator=(const Quaternion&) = default;

    //! Default move assignment operator.
    Quaternion& operator=(Quaternion&&) = default;

    //! Returns identity quaternion.
    [[nodiscard]] static Quaternion Identity();

    //! Returns quaternion from euler angle.
    [[nodiscard]] static Quaternion Euler(float x, float y, float z);

    //! Returns vector part.
    [[nodiscard]] const Vector3& GetVector() const;

    //! Returns scalar part.
    [[nodiscard]] float GetScalar() const;

    //! Returns the length of quaternion.
    [[nodiscard]] float Length() const;

    //! Calculate inner product.
    [[nodiscard]] float Dot(const Quaternion& other) const;

    [[nodiscard]] Quaternion operator+(const Quaternion& other) const;
    [[nodiscard]] Quaternion operator-(const Quaternion& other) const;
    [[nodiscard]] Quaternion operator*(const Quaternion& other) const;
    [[nodiscard]] Quaternion operator*(float v) const;

    Quaternion& operator+=(const Quaternion& other);
    Quaternion& operator-=(const Quaternion& other);
    Quaternion& operator*=(const Quaternion& other);
    Quaternion& operator*=(float v);

 private:
    Vector3 vector_;
    float w_{ 0 };
};
}  // namespace Cowdia::Math

#endif  // COWDIA_QUATERNION_HPP
