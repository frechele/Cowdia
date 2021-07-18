#include <doctest.h>

#include <Cowdia/Math/Matrix.hpp>

using namespace Cowdia;

TEST_CASE("[Math/Matrix] - Basic Arithmetic Operators")
{
	constexpr float eps = 1e-5;

    Math::Matrix A{
        1.0f,  2.0f,  3.0f,  4.0f, 
        5.0f,  6.0f,  7.0f,  8.0f,
        9.0f,  10.0f, 11.0f, 12.0f, 
        13.0f, 14.0f, 15.0f, 16.0f
    };

    Math::Matrix B{
        3.0f,  4.0f,  5.0f,  6.0f, 
        7.0f,  8.0f,  9.0f,  10.0f, 
        11.0f, 12.0f, 13.0f, 14.0f, 
        15.0f, 16.0f, 17.0f, 18.0f
    };

    Math::Matrix C{
        1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f
    };

    Math::Matrix D{ 
        1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f 
    };

    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(A.At(i, j) == doctest::Approx(i * 4 + j + 1).epsilon(eps));
            REQUIRE(B.At(i, j) == doctest::Approx(i * 4 + j + 3).epsilon(eps));
        }
    }

    Math::Matrix AplusB = A + B;

    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(AplusB.At(i, j) ==
                    doctest::Approx(i * 8 + j * 2 + 4).epsilon(eps));
        }
    }

    Math::Matrix BminusA = B - A;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(BminusA.At(i, j) == doctest::Approx(2).epsilon(eps));
        }
    }

	Math::Matrix CmulD = C * D;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(CmulD.At(i, j) == doctest::Approx(4).epsilon(eps));
        }
    }

	Math::Matrix Aplus2 = A + 2;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(Aplus2.At(i, j) ==
                    doctest::Approx(i * 4 + j + 3).epsilon(eps));
        }
    }

	Math::Matrix Aminus2 = A - 2;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(Aminus2.At(i, j) ==
                    doctest::Approx(i * 4 + j - 1).epsilon(eps));
        }
    }

    Math::Matrix Amul = A * 3;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(Amul.At(i, j) ==
                    doctest::Approx(i * 12 + j * 3 + 3).epsilon(eps));
        }
    }

    Math::Matrix Adiv = A / 2;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(Adiv.At(i, j) ==
                    doctest::Approx(i * 2 + (j + 1) / 2).epsilon(eps));
        }
    }

	Math::Matrix Atrans = A.T();
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(Adiv.At(j, i) ==
                    doctest::Approx(i * 4 + j + 1).epsilon(eps));
        }
    }

	Math::Matrix TwoplusA = 2 + A;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(TwoplusA.At(i, j) ==
                    doctest::Approx(i * 4 + j + 3).epsilon(eps));
        }
    }

	Math::Matrix TwominusA = 2 - A;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(TwominusA.At(i, j) ==
                    doctest::Approx(- i * 4 - j + 1).epsilon(eps));
        }
    }

	Math::Matrix Threemul = A * 3;
    for (std::size_t i = 0; i < Math::Matrix::MAT_SIZE; ++i)
    {
        for (std::size_t j = 0; j < Math::Matrix::MAT_SIZE; ++j)
        {
            REQUIRE(Threemul.At(i, j) ==
                    doctest::Approx(i * 12 + j * 3 + 3).epsilon(eps));
        }
    }
}
