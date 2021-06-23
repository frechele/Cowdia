#ifndef COWDIA_VECTOR_BASE_HPP
#define COWDIA_VECTOR_BASE_HPP

#include <cstddef>
#include <cmath>

namespace Cowdia::Math
{
template <typename T, int DIM>
class VectorBase
{
 public:
    //! Returns the dimension of vector.
    std::size_t Dim() const;

    //! Returns the length of vector.
    float Length() const;

    template <typename U>
    VectorBase<T, DIM> operator+(const VectorBase<U, DIM>& other) const;
    template <typename U>
    VectorBase<T, DIM> operator-(const VectorBase<U, DIM>& other) const;
    template <typename U>
    VectorBase<T, DIM> operator*(U value) const;
    template <typename U>
    VectorBase<T, DIM> operator/(U value) const;

    template <typename U>
    VectorBase<T, DIM>& operator+=(const VectorBase<U, DIM>& other);
    template <typename U>
    VectorBase<T, DIM>& operator-=(const VectorBase<U, DIM>& other);
    template <typename U>
    VectorBase<T, DIM>& operator*=(U value);
    template <typename U>
    VectorBase<T, DIM>& operator/=(U value);

 protected:
    float elem_[DIM];
};

template <typename T, int DIM>
std::size_t VectorBase<T, DIM>::Dim() const
{
    return DIM;
}

template <typename T, int DIM>
float VectorBase<T, DIM>::Length() const
{
    float sum = 0;

    for (int i = 0; i < DIM; ++i)
        sum += elem_[i] * elem_[i];

    return std::sqrt(sum);
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM> VectorBase<T, DIM>::operator+(
    const VectorBase<U, DIM>& other) const
{
    VectorBase<T, DIM> ret{ *this };

    for (int i = 0; i < DIM; ++i)
        ret.elem_[i] += other.elem_[i];

    return ret;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM> VectorBase<T, DIM>::operator-(
    const VectorBase<U, DIM>& other) const
{
    VectorBase<DIM> ret{ *this };

    for (int i = 0; i < DIM; ++i)
        ret.elem_[i] -= other.elem_[i];

    return ret;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM> VectorBase<T, DIM>::operator*(U x) const
{
    VectorBase<DIM> ret{ *this };

    for (int i = 0; i < DIM; ++i)
        ret.elem_[i] *= x;

    return ret;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM> VectorBase<T, DIM>::operator/(U x) const
{
    VectorBase<DIM> ret{ *this };

    for (int i = 0; i < DIM; ++i)
        ret.elem_[i] /= x;

    return ret;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM>& VectorBase<T, DIM>::operator+=(
    const VectorBase<U, DIM>& other)
{
    for (int i = 0; i < DIM; ++i)
        elem_[i] += other.elem_[i];

    return *this;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM>& VectorBase<T, DIM>::operator-=(
    const VectorBase<U, DIM>& other)
{
    for (int i = 0; i < DIM; ++i)
        elem_[i] -= other.elem_[i];

    return *this;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM>& VectorBase<T, DIM>::operator*=(U x)
{
    for (int i = 0; i < DIM; ++i)
        elem_[i] *= x;

    return *this;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM>& VectorBase<T, DIM>::operator/=(U x)
{
    for (int i = 0; i < DIM; ++i)
        elem_[i] /= x;

    return *this;
}
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR_BASE_HPP
