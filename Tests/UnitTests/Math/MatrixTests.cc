#include <doctest.h>

#include <Cowdia/Math/Matrix.hpp>

using namespace Cowdia;

TEST_CASE("[Math/Matrix] - Basic Arithmetic Operators")
{
    Math::Matrix<int> A{
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 14, 15, 16
    };
    Math::Matrix<int> B{
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18
    };
    for (int i = 0; i < A.MAT_SIZE; ++i)
    {
        for (int j = 0; j < A.MAT_SIZE; ++j)
        {
            CHECK_EQ(A.At(i, j), i * 4 + j + 1);
            CHECK_EQ(B.At(i, j), i * 4 + j + 3);
        }
    }

    Math::Matrix<int> AplusB = A + B;

    for (int i = 0; i < A.MAT_SIZE; ++i)
    {
        for (int j = 0; j < A.MAT_SIZE; ++j)
        {
            CHECK_EQ(AplusB.At(i, j), i * 8 + j * 2 + 4);
        }
    }

    Math::Vector2i BminusA = B - A;
    for (int i = 0; i < A.MAT_SIZE; ++i)
    {
        for (int j = 0; j < A.MAT_SIZE; ++j)
        {
            CHECK_EQ(AplusB.At(i, j), 2);
        }
    }

    Math::Vector2i Amul = A * 3;
    for (int i = 0; i < A.MAT_SIZE; ++i)
    {
        for (int j = 0; j < A.MAT_SIZE; ++j)
        {
            CHECK_EQ(AplusB.At(i, j), i * 12 + j * 3 + 3);
        }
    }

    Math::Vector2i Adiv = A / 2;
    for (int i = 0; i < A.MAT_SIZE; ++i)
    {
        for (int j = 0; j < A.MAT_SIZE; ++j)
        {
            CHECK_EQ(AplusB.At(i, j), i * 2 + (j + 1) / 2);
        }
    }
}
