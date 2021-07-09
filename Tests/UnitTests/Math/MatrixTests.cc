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

	Math::Matrix<int> C{
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	};

    Math::Matrix<int> D{ 
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 
	};

    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(A.At(i, j), i * 4 + j + 1);
            CHECK_EQ(B.At(i, j), i * 4 + j + 3);
        }
    }

    Math::Matrix<int> AplusB = A + B;

    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(AplusB.At(i, j), i * 8 + j * 2 + 4);
        }
    }

    Math::Matrix<int> BminusA = B - A;
    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(BminusA.At(i, j), 2);
        }
    }

	Math::Matrix<int> CmulD = C * D;
    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(CmulD.At(i, j), 4);
        }
    }

	Math::Matrix<int> Aplus2 = A + 2;
    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(Aplus2.At(i, j), i * 4 + j + 3);
        }
    }

	Math::Matrix<int> Aminus2 = A - 2;
    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(Aminus2.At(i, j), i * 4 + j - 1);
        }
    }

    Math::Matrix<int> Amul = A * 3;
    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(Amul.At(i, j), i * 12 + j * 3 + 3);
        }
    }

    Math::Matrix<int> Adiv = A / 2;
    for (std::size_t i = 0; i < Math::Matrix<int>::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix<int>::MAT_SIZE; ++j)
        {
            CHECK_EQ(Adiv.At(i, j), i * 2 + (j + 1) / 2);
        }
    }
}
