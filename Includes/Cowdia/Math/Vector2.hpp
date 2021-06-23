#ifndef COWDIA_VECTOR2_HPP
#define COWDIA_VECTOR2_HPP

#include <Cowdia/Math/VectorBase.hpp>

namespace Cowdia::Math
{
template <typename T>
class Vector2 : public VectorBase<T, 2>
{
 public:
    //! Default constructor.
    Vector2() = default;

    //! Constructor with elements.
    Vector2(T x, T y) : elem_{ x, y }
    {
        // Do nothing.
    }

    //! Default copy constructor.
    Vector2(const Vector2&) = default;

    //! Default move constructor.
    Vector2(Vector2&&) = default;

    //! Default copy assignment operator.
    Vector2& operator=(const Vector2&) = default;

    //! Default move assignment operator.
    Vector2& operator=(Vector2&&) = default;

    //! Returns x element.
    T X() const
    {
        return elem_[0];
    }

    //! Returns x element.
    T& X()
    {
        return elem_[0];
    }

    //! Returns y element.
    T Y() const
    {
        return elem_[1];
    }

    //! Returns y element.
    T& Y()
    {
        return elem_[1];
    }
};

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR2_HPP
