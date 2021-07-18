#ifndef COWDIA_MATRIX_HPP
#define COWDIA_MATRIX_HPP

#include <cmath>
#include <cstddef>

namespace Cowdia::Math
{
class Matrix final
{
 public:
    static constexpr std::size_t MAT_SIZE = 4;

    //! Default constructor.
    Matrix() = default;

    //! Default destructor.
    ~Matrix() noexcept = default;

    //! Constructor with elements.
    template <typename... Args>
    explicit Matrix(Args... args);

    //! Default copy constructor.
    Matrix(const Matrix&) = default;

    //! Default move constructor.
    Matrix(Matrix&&) = default;

    //! Default copy assignment operator.
    Matrix& operator=(const Matrix&) = default;

    //! Default move assignment operator.
    Matrix& operator=(Matrix&&) = default;

    //! Returns zero matrix
    static Matrix Zero(void);

    //! Returns indentity matrix
    static Matrix Identity(void);

    //! Returns element at \p idx.
    //! \param idx the index of element.
    float At(std::size_t y, std::size_t x) const;

    //! Returns element at \p idx.
    //! \param idx the index of element.
    float& At(std::size_t y, std::size_t x);

	Matrix T() const;
    
	Matrix operator-() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator+(float value) const;
    Matrix operator-(float value) const;
    Matrix operator*(float value) const;
    Matrix operator/(float value) const;
    
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator+=(float value);
    Matrix& operator-=(float value);
    Matrix& operator*=(float value);
    Matrix& operator/=(float value);

	friend Matrix operator+(float value, const Matrix& other);
    friend Matrix operator+(double value, const Matrix& other);
    friend Matrix operator+(int value, const Matrix& other);
    friend Matrix operator+(long long value, const Matrix& other);
    friend Matrix operator-(float value, const Matrix& other);
    friend Matrix operator-(double value, const Matrix& other);
    friend Matrix operator-(int value, const Matrix& other);
    friend Matrix operator-(long long value, const Matrix& other);
    friend Matrix operator*(float value, const Matrix& other);
    friend Matrix operator*(double value, const Matrix& other);
    friend Matrix operator*(int value, const Matrix& other);
    friend Matrix operator*(long long value, const Matrix& other);

 private:
    float elem_[MAT_SIZE][MAT_SIZE];
};

template <typename... Args>
Matrix::Matrix(Args... args) : elem_{ args... }
{
    // Do nothing.
}


Matrix Matrix::Zero()
{
    return Matrix(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}


Matrix Matrix::Identity()
{
    return Matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
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

Matrix operator+(float x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator+(double x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator+(int x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator+(long long x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator-(float x, const Matrix& other)
{
    Matrix ret{ -other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator-(double x, const Matrix& other)
{
    Matrix ret{ -other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator-(int x, const Matrix& other)
{
    Matrix ret{ -other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator-(long long x, const Matrix& other)
{
    Matrix ret{ -other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] += x;

    return ret;
}

Matrix operator*(float x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] *= x;

    return ret;
}

Matrix operator*(double x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] *= x;

    return ret;
}

Matrix operator*(int x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] *= x;

    return ret;
}

Matrix operator*(long long x, const Matrix& other)
{
    Matrix ret{ other };

    for (std::size_t i = 0; i < Matrix::MAT_SIZE; ++i)
        for (std::size_t j = 0; j < Matrix::MAT_SIZE; ++j)
            ret.elem_[i][j] *= x;

    return ret;
}

}  // namespace Cowdia::Math

#endif  // COWDIA_MATRIX_HPP
