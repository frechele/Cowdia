#include <Cowdia/Math/Matrix.hpp>

namespace Cowdia::Math
{
Matrix Matrix::Zero()
{
    return Matrix(0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);
}

Matrix Matrix::Identity()
{
    return Matrix(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f);
}

float Matrix::At(std::size_t y, std::size_t x) const
{
    return elem_[y][x];
}

float& Matrix::At(std::size_t y, std::size_t x)
{
    return elem_[y][x];
}

Matrix Matrix::T() const
{
    Matrix ret = Zero();

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] = elem_[j][i];

    return ret;
}

Matrix Matrix::operator-() const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] = -ret.elem_[i][j];

    return ret;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] += other.elem_[i][j];

    return ret;
}

Matrix Matrix::operator-(const Matrix& other) const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] -= other.elem_[i][j];

    return ret;
}

Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix ret = Zero();
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            for (std::size_t k = 0; k < MAT_SIZE; ++k)
                ret.elem_[i][j] += elem_[i][k] * other.elem_[k][j];
    return ret;
}

Matrix Matrix::operator+(float x) const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix Matrix::operator-(float x) const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] -= x;

    return ret;
}

Matrix Matrix::operator*(float x) const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] *= x;

    return ret;
}

Matrix Matrix::operator/(float x) const
{
    Matrix ret{ *this };

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            ret.elem_[i][j] /= x;

    return ret;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] += other.elem_[i][j];

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] -= other.elem_[i][j];

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    Matrix tmp = Zero();

    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            for (std::size_t k = 0; k < MAT_SIZE; ++k)
                tmp.elem_[i][j] += elem_[i][k] * other.elem_[k][j];

    *this = tmp;

    return *this;
}

Matrix& Matrix::operator+=(float x)
{
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] += x;

    return *this;
}

Matrix& Matrix::operator-=(float x)
{
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] -= x;

    return *this;
}

Matrix& Matrix::operator*=(float x)
{
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] *= x;

    return *this;
}

Matrix& Matrix::operator/=(float x)
{
    for (std::size_t i = 0; i < MAT_SIZE; ++i)
        for (std::size_t j = 0; j < MAT_SIZE; ++j)
            elem_[i][j] /= x;

    return *this;
}
}  // namespace Cowdia::Math
