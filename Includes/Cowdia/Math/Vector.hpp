#ifndef COWDIA_VECTOR_BASE_HPP
#define COWDIA_VECTOR_BASE_HPP

#include <cmath>
#include <cstddef>

namespace Cowdia::Math
{
template <typename T, int DIM>
class VectorBase
{
 public:
    //! Default constructor.
    VectorBase() = default;

    //! Default destructor.
    ~VectorBase() noexcept = default;

    //! Constructor with elements.
    template <typename... Args>
    VectorBase(Args... args);

    //! Default copy constructor.
    VectorBase(const VectorBase<T, DIM>&) = default;

    //! Default move constructor.
    VectorBase(VectorBase<T, DIM>&&) = default;

    //! Default copy assignment operator.
    VectorBase<T, DIM>& operator=(const VectorBase<T, DIM>&) = default;

    //! Default move assignment operator.
    VectorBase<T, DIM>& operator=(VectorBase<T, DIM>&&) = default;

    //! Returns element at \p idx.
    //! \param idx the index of element.
    T At(std::size_t idx) const;

    //! Returns element at \p idx.
    //! \param idx the index of element.
    T& At(std::size_t idx);

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
    T elem_[DIM];
};

using Vector2i = VectorBase<int, 2>;
using Vector2f = VectorBase<float, 2>;

template <typename T, int DIM>
template <typename... Args>
VectorBase<T, DIM>::VectorBase(Args... args) : elem_{ args... }
{
    // Do nothing.
}

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
T VectorBase<T, DIM>::At(std::size_t idx) const
{
    return elem_[idx];
}

template <typename T, int DIM>
T& VectorBase<T, DIM>::At(std::size_t idx)
{
    return elem_[idx];
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
    VectorBase<T, DIM> ret{ *this };

    for (int i = 0; i < DIM; ++i)
        ret.elem_[i] -= other.elem_[i];

    return ret;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM> VectorBase<T, DIM>::operator*(U x) const
{
    VectorBase<T, DIM> ret{ *this };

    for (int i = 0; i < DIM; ++i)
        ret.elem_[i] *= x;

    return ret;
}

template <typename T, int DIM>
template <typename U>
VectorBase<T, DIM> VectorBase<T, DIM>::operator/(U x) const
{
    VectorBase<T, DIM> ret{ *this };

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
