#ifndef COWDIA_VECTOR_BASE_HPP
#define COWDIA_VECTOR_BASE_HPP

#include <cmath>
#include <cstddef>

namespace Cowdia::Math
{
template <std::size_t DIM>
struct VectorBase final
{
    //! Default constructor.
    VectorBase() = default;

    //! Default destructor.
    ~VectorBase() noexcept = default;

    //! Constructor with elements.
    template <typename... Args>
    explicit VectorBase(Args... args);

    //! Default copy constructor.
    VectorBase(const VectorBase<DIM>&) = default;

    //! Default move constructor.
    VectorBase(VectorBase<DIM>&&) = default;

    //! Default copy assignment operator.
    VectorBase<DIM>& operator=(const VectorBase<DIM>&) = default;

    //! Default move assignment operator.
    VectorBase<DIM>& operator=(VectorBase<DIM>&&) = default;

    //! Returns the dimension of vector.
    [[nodiscard]] std::size_t Dim() const;

    //! Returns the length of vector.
    [[nodiscard]] float Length() const;

    [[nodiscard]] VectorBase<DIM> operator+(const VectorBase<DIM>& other) const;
    [[nodiscard]] VectorBase<DIM> operator-(const VectorBase<DIM>& other) const;
    [[nodiscard]] VectorBase<DIM> operator+(float value) const;
    [[nodiscard]] VectorBase<DIM> operator-(float value) const;
    [[nodiscard]] VectorBase<DIM> operator*(float value) const;
    [[nodiscard]] VectorBase<DIM> operator/(float value) const;

    VectorBase<DIM>& operator+=(const VectorBase<DIM>& other);
    VectorBase<DIM>& operator-=(const VectorBase<DIM>& other);
    VectorBase<DIM>& operator+=(float value);
    VectorBase<DIM>& operator-=(float value);
    VectorBase<DIM>& operator*=(float value);
    VectorBase<DIM>& operator/=(float value);

    float ptr[DIM];
};

template <std::size_t DIM>
template <typename... Args>
VectorBase<DIM>::VectorBase(Args... args) : ptr{ args... }
{
    // Do nothing.
}

template <std::size_t DIM>
std::size_t VectorBase<DIM>::Dim() const
{
    return DIM;
}

template <std::size_t DIM>
float VectorBase<DIM>::Length() const
{
    float sum = 0;

    for (std::size_t i = 0; i < DIM; ++i)
        sum += ptr[i] * ptr[i];

    return std::sqrt(sum);
}

template <std::size_t DIM>
VectorBase<DIM> VectorBase<DIM>::operator+(const VectorBase<DIM>& other) const
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] += other.ptr[i];

    return ret;
}

template <std::size_t DIM>
VectorBase<DIM> VectorBase<DIM>::operator-(const VectorBase<DIM>& other) const
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] -= other.ptr[i];

    return ret;
}

template <std::size_t DIM>
VectorBase<DIM> VectorBase<DIM>::operator+(float x) const
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] += x;

    return ret;
}

template <std::size_t DIM>
VectorBase<DIM> VectorBase<DIM>::operator-(float x) const
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] -= x;

    return ret;
}

template <std::size_t DIM>
VectorBase<DIM> VectorBase<DIM>::operator*(float x) const
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] *= x;

    return ret;
}

template <std::size_t DIM>
VectorBase<DIM> VectorBase<DIM>::operator/(float x) const
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] /= x;

    return ret;
}

template <std::size_t DIM>
VectorBase<DIM>& VectorBase<DIM>::operator+=(const VectorBase<DIM>& other)
{
    for (std::size_t i = 0; i < DIM; ++i)
        ptr[i] += other.ptr[i];

    return *this;
}

template <std::size_t DIM>
VectorBase<DIM>& VectorBase<DIM>::operator-=(const VectorBase<DIM>& other)
{
    for (std::size_t i = 0; i < DIM; ++i)
        ptr[i] -= other.ptr[i];

    return *this;
}

template <std::size_t DIM>
VectorBase<DIM>& VectorBase<DIM>::operator+=(float x)
{
    for (std::size_t i = 0; i < DIM; ++i)
        ptr[i] += x;

    return *this;
}

template <std::size_t DIM>
VectorBase<DIM>& VectorBase<DIM>::operator-=(float x)
{
    VectorBase<DIM> ret{ *this };

    for (std::size_t i = 0; i < DIM; ++i)
        ret.ptr[i] -= x;

    return *this;
}

template <std::size_t DIM>
VectorBase<DIM>& VectorBase<DIM>::operator*=(float x)
{
    for (std::size_t i = 0; i < DIM; ++i)
        ptr[i] *= x;

    return *this;
}

template <std::size_t DIM>
VectorBase<DIM>& VectorBase<DIM>::operator/=(float x)
{
    for (std::size_t i = 0; i < DIM; ++i)
        ptr[i] /= x;

    return *this;
}
}  // namespace Cowdia::Math

#endif  // COWDIA_VECTOR_BASE_HPP
