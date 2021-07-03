#ifndef COWDIA_MATRIX_HPP
#define COWDIA_MATRIX_HPP

#include <cmath>
#include <cstddef>
#define MAT_SIZE 4

namespace Cowdia::Math
{
template <typename T>
class Matrix
{
 public:
    //! Default constructor.
    Matrix() = default;

    //! Default destructor.
    ~Matrix() noexcept = default;

    //! Constructor with elements.
    template <typename... Args>
    explicit Matrix(Args... args);

    //! Default copy constructor.
    Matrix(const Matrix<T>&) = default;

    //! Default move constructor.
    Matrix(Matrix<T>&&) = default;

    //! Default copy assignment operator.
    Matrix<T>& operator=(const Matrix<T>&) = default;

    //! Default move assignment operator.
    Matrix<T>& operator=(Matrix<T>&&) = default;

    //! Returns element at \p idx.
    //! \param idx the index of element.
    T At(std::size_t y, std::size_t x) const;

    //! Returns element at \p idx.
    //! \param idx the index of element.
    T& At(std::size_t y, std::size_t x);

    template <typename U>
    Matrix<T> operator+(const Matrix<U>& other) const;
    template <typename U>
    Matrix<T> operator-(const Matrix<U>& other) const;
    template <typename U>
    Matrix<T> operator*(U value) const;
    template <typename U>
    Matrix<T> operator/(U value) const;

    template <typename U>
    Matrix<T>& operator+=(const Matrix<U>& other);
    template <typename U>
    Matrix<T>& operator-=(const Matrix<U>& other);
    template <typename U>
    Matrix<T>& operator*=(U value);
    template <typename U>
    Matrix<T>& operator/=(U value);

 protected:
    T elem_[MAT_SIZE][MAT_SIZE];
};

template <typename T>
template <typename... Args>
Matrix<T>::Matrix(Args... args) : elem_{ args... }
{
    // Do nothing.
}

template <typename T>
T Matrix<T>::At(std::size_t y, std::size_t x) const
{
    return elem_[y][x];
}

template <typename T>
T& Matrix<T>::At(std::size_t y, std::size_t x)
{
    return elem_[y][x];
}

template <typename T>
template <typename U>
Matrix<T> Matrix<T>::operator+(const Matrix<U>& other) const
{
    Matrix<T> ret{ *this };

    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] += other.elem_[i][j];

    return ret;
}

template <typename T>
template <typename U>
Matrix<T> Matrix<T>::operator-(const Matrix<U>& other) const
{
    Matrix<T> ret{ *this };

    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] -= other.elem_[i][j];

    return ret;
}

template <typename T>
template <typename U>
Matrix<T> Matrix<T>::operator*(U x) const
{
    Matrix<T> ret{ *this };

    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] *= x;

    return ret;
}

template <typename T>
template <typename U>
Matrix<T> Matrix<T>::operator/(U x) const
{
    Matrix<T> ret{ *this };

    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] /= x;

    return ret;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator+=(const Matrix<U>& other)
{
    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] += other.elem_[i][j];

    return *this;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator-=(const Matrix<U>& other)
{
    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] -= other.elem_[i][j];

    return *this;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator*=(U x)
{
    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] *= x;

    return *this;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator/=(U x)
{
    for (int i = 0; i < MAT_SIZE; ++i)
        for (int j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] /= x;

    return *this;
}
}  // namespace Cowdia::Math

#endif  // COWDIA_MATRIX_HPP