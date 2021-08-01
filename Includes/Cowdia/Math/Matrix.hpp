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
    [[nodiscard]] static Matrix Zero(void);

    //! Returns indentity matrix
    [[nodiscard]] static Matrix Identity(void);

    //! Returns element at \p idx.
    //! \param idx the index of element.
    [[nodiscard]] float At(std::size_t y, std::size_t x) const;

    //! Returns element at \p idx.
    //! \param idx the index of element.
    [[nodiscard]] float& At(std::size_t y, std::size_t x);

    [[nodiscard]] Matrix T() const;

    [[nodiscard]] Matrix operator-() const;

    [[nodiscard]] Matrix operator+(const Matrix& other) const;
    [[nodiscard]] Matrix operator-(const Matrix& other) const;
    [[nodiscard]] Matrix operator*(const Matrix& other) const;
    [[nodiscard]] Matrix operator+(float value) const;
    [[nodiscard]] Matrix operator-(float value) const;
    [[nodiscard]] Matrix operator*(float value) const;
    [[nodiscard]] Matrix operator/(float value) const;

    [[nodiscard]] Matrix& operator+=(const Matrix& other);
    [[nodiscard]] Matrix& operator-=(const Matrix& other);
    [[nodiscard]] Matrix& operator*=(const Matrix& other);
    [[nodiscard]] Matrix& operator+=(float value);
    [[nodiscard]] Matrix& operator-=(float value);
    [[nodiscard]] Matrix& operator*=(float value);
    [[nodiscard]] Matrix& operator/=(float value);

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

[[nodiscard]] Matrix operator+(float x, const Matrix& other);
[[nodiscard]] Matrix operator+(double x, const Matrix& other);
[[nodiscard]] Matrix operator+(int x, const Matrix& other);
[[nodiscard]] Matrix operator+(long long x, const Matrix& other);
[[nodiscard]] Matrix operator-(float x, const Matrix& other);
[[nodiscard]] Matrix operator-(double x, const Matrix& other);
[[nodiscard]] Matrix operator-(int x, const Matrix& other);
[[nodiscard]] Matrix operator-(long long x, const Matrix& other);
[[nodiscard]] Matrix operator*(float x, const Matrix& other);
[[nodiscard]] Matrix operator*(double x, const Matrix& other);
[[nodiscard]] Matrix operator*(int x, const Matrix& other);
[[nodiscard]] Matrix operator*(long long x, const Matrix& other);
}  // namespace Cowdia::Math

#endif  // COWDIA_MATRIX_HPP
