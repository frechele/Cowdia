#ifndef COWDIA_QUATERNION_HPP
#define COWDIA_QUATERNION_HPP

#include <Cowdia/Core/Common.hpp>

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
    static Quaternion Identity();

    //! Returns quaternion from euler angle.
    static Quaternion Euler(float x, float y, float z);

    Quaternion operator+(const Quaternion& other) const;
    Quaternion operator-(const Quaternion& other) const;
    Quaternion operator*(float v) const;

    Quaternion& operator+=(const Quaternion& other);
    Quaternion& operator-=(const Quaternion& other);
    Quaternion& operator*=(float v);

 private:
    float x_{ 0 };
    float y_{ 0 };
    float z_{ 0 };
    float w_{ 0 };
};
}  // namespace Cowdia::Math

#endif  // COWDIA_QUATERNION_HPP
