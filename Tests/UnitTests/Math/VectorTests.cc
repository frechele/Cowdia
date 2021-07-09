#include <doctest.h>

#include <Cowdia/Math/Vector.hpp>

using namespace Cowdia;

TEST_CASE("[Math/Vector2] - Basic Arithmetic Operators")
{
    Math::Vector2i A{ 1, 2 };
    Math::Vector2i B{ 3, 4 };
    CHECK_EQ(A.At(0), 1);
    CHECK_EQ(A.At(1), 2);
    CHECK_EQ(B.At(0), 3);
    CHECK_EQ(B.At(1), 4);

    Math::Vector2i AplusB = A + B;
    CHECK_EQ(AplusB.At(0), 4);
    CHECK_EQ(AplusB.At(1), 6);

    Math::Vector2i BminusA = B - A;
    CHECK_EQ(BminusA.At(0), 2);
    CHECK_EQ(BminusA.At(1), 2);

    Math::Vector2i Aplus2 = A + 2;
    CHECK_EQ(Aplus2.At(0), 3);
    CHECK_EQ(Aplus2.At(1), 4);

    Math::Vector2i Aminus2 = A - 2;
    CHECK_EQ(Aminus2.At(0), -1);
    CHECK_EQ(Aminus2.At(1), 0);

    Math::Vector2i Amul = A * 3;
    CHECK_EQ(Amul.At(0), 3);
    CHECK_EQ(Amul.At(1), 6);

    Math::Vector2i Adiv = A / 2;
    CHECK_EQ(Adiv.At(0), 0);
    CHECK_EQ(Adiv.At(1), 1);
}
