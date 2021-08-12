#include <doctest.h>

#include <Cowdia/Math/Vector2.hpp>
#include <Cowdia/Math/Vector3.hpp>
#include <Cowdia/Math/Vector4.hpp>

using namespace Cowdia;

TEST_CASE("[Math/Vector2] - Basic Arithmetic Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector2 A{ 1.f, 2.f };
    Math::Vector2 B{ 3.f, 4.f };

    CHECK_EQ(A.Dim(), 2);

    REQUIRE(A.X() == doctest::Approx(1.f).epsilon(eps));
    REQUIRE(A.Y() == doctest::Approx(2.f).epsilon(eps));
    REQUIRE(B.X() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(B.Y() == doctest::Approx(4.f).epsilon(eps));

    Math::Vector2 AplusB = A + B;
    REQUIRE(AplusB.X() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(AplusB.Y() == doctest::Approx(6.f).epsilon(eps));

    Math::Vector2 BminusA = B - A;
    REQUIRE(BminusA.X() ==  doctest::Approx(2.f).epsilon(eps));
    REQUIRE(BminusA.Y() ==  doctest::Approx(2.f).epsilon(eps));

    Math::Vector2 Aplus2 = A + 2;
    REQUIRE(Aplus2.X() ==  doctest::Approx(3.f).epsilon(eps));
    REQUIRE(Aplus2.Y() ==  doctest::Approx(4.f).epsilon(eps));

    Math::Vector2 Aminus2 = A - 2;
    REQUIRE(Aminus2.X() ==  doctest::Approx(-1.f).epsilon(eps));
    REQUIRE(Aminus2.Y() ==  doctest::Approx(0.f).epsilon(eps));

    Math::Vector2 Amul = A * 3;
    REQUIRE(Amul.X() ==  doctest::Approx(3.f).epsilon(eps));
    REQUIRE(Amul.Y() ==  doctest::Approx(6.f).epsilon(eps));

    Math::Vector2 Adiv = A / 2;
    REQUIRE(Adiv.X() ==  doctest::Approx(0.5f).epsilon(eps));
    REQUIRE(Adiv.Y() ==  doctest::Approx(1.f).epsilon(eps));
}

TEST_CASE("[Math/Vector2] - Advanced Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector2 A{ 1.f, 2.f };
    Math::Vector2 B{ 3.f, 4.f };

    REQUIRE(B.Length() == doctest::Approx(5.f).epsilon(eps));
    REQUIRE(A.Dot(B) == doctest::Approx(11.f).epsilon(eps));
}

TEST_CASE("[Math/Vector3] - Basic Arithmetic Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector3 A(1, 2, 3);
    Math::Vector3 B(4, 5, 6);

    CHECK_EQ(A.Dim(), 3);

    REQUIRE(A.X() == doctest::Approx(1.f).epsilon(eps));
    REQUIRE(A.Y() == doctest::Approx(2.f).epsilon(eps));
    REQUIRE(A.Z() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(B.X() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(B.Y() == doctest::Approx(5.f).epsilon(eps));
    REQUIRE(B.Z() == doctest::Approx(6.f).epsilon(eps));

    Math::Vector3 AplusB = A + B;
    REQUIRE(AplusB.X() == doctest::Approx(5.f).epsilon(eps));
    REQUIRE(AplusB.Y() == doctest::Approx(7.f).epsilon(eps));
    REQUIRE(AplusB.Z() == doctest::Approx(9.f).epsilon(eps));

    Math::Vector3 BminusA = B - A;
    REQUIRE(BminusA.X() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(BminusA.Y() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(BminusA.Z() == doctest::Approx(3.f).epsilon(eps));

    Math::Vector3 Aplus2 = A + 2;
    REQUIRE(Aplus2.X() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(Aplus2.Y() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(Aplus2.Z() == doctest::Approx(5.f).epsilon(eps));

    Math::Vector3 Aminus2 = A - 2;
    REQUIRE(Aminus2.X() == doctest::Approx(-1.f).epsilon(eps));
    REQUIRE(Aminus2.Y() == doctest::Approx(0.f).epsilon(eps));
    REQUIRE(Aminus2.Z() == doctest::Approx(1.f).epsilon(eps));

    Math::Vector3 Amul = A * 3;
    REQUIRE(Amul.X() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(Amul.Y() == doctest::Approx(6.f).epsilon(eps));
    REQUIRE(Amul.Z() == doctest::Approx(9.f).epsilon(eps));

    Math::Vector3 Adiv = A / 2;
    REQUIRE(Adiv.X() == doctest::Approx(0.5f).epsilon(eps));
    REQUIRE(Adiv.Y() == doctest::Approx(1.f).epsilon(eps));
    REQUIRE(Adiv.Z() == doctest::Approx(1.5f).epsilon(eps));
}

TEST_CASE("[Math/Vector3] - Advanced Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector3 A{ 1.f, 2.f, 3.f };
    Math::Vector3 B{ 4.f, 5.f, 6.f };

    REQUIRE(B.Length() == doctest::Approx(std::sqrt(77.f)).epsilon(eps));
    REQUIRE(A.Dot(B) == doctest::Approx(32.f).epsilon(eps));

    auto AcrossA = A.Cross(A);
    REQUIRE(AcrossA.X() == doctest::Approx(0).epsilon(eps));
    REQUIRE(AcrossA.Y() == doctest::Approx(0).epsilon(eps));
    REQUIRE(AcrossA.Z() == doctest::Approx(0).epsilon(eps));

    Math::Vector3 C{ 1.f, 3.f, 4.f };
    Math::Vector3 D{ 2.f, 7.f, -5.f };
    auto CcrossD = C.Cross(D);
    REQUIRE(CcrossD.X() == doctest::Approx(-43.f).epsilon(eps));
    REQUIRE(CcrossD.Y() == doctest::Approx(13.f).epsilon(eps));
    REQUIRE(CcrossD.Z() == doctest::Approx(1.f).epsilon(eps));
}

TEST_CASE("[Math/Vector4] - Basic Arithmetic Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector4 A{ 1.f, 2.f, 3.f, 4.f };
    Math::Vector4 B{ 5.f, 6.f, 7.f, 8.f };

    CHECK_EQ(A.Dim(), 4);
    REQUIRE(B.Length() == doctest::Approx(std::sqrt(174.f)).epsilon(eps));
    REQUIRE(A.Dot(B) == doctest::Approx(70.f).epsilon(eps));

    REQUIRE(A.X() == doctest::Approx(1.f).epsilon(eps));
    REQUIRE(A.Y() == doctest::Approx(2.f).epsilon(eps));
    REQUIRE(A.Z() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(A.W() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(B.X() == doctest::Approx(5.f).epsilon(eps));
    REQUIRE(B.Y() == doctest::Approx(6.f).epsilon(eps));
    REQUIRE(B.Z() == doctest::Approx(7.f).epsilon(eps));
    REQUIRE(B.W() == doctest::Approx(8.f).epsilon(eps));

    Math::Vector4 AplusB = A + B;
    REQUIRE(AplusB.X() == doctest::Approx(6.f).epsilon(eps));
    REQUIRE(AplusB.Y() == doctest::Approx(8.f).epsilon(eps));
    REQUIRE(AplusB.Z() == doctest::Approx(10.f).epsilon(eps));
    REQUIRE(AplusB.W() == doctest::Approx(12.f).epsilon(eps));

    Math::Vector4 BminusA = B - A;
    REQUIRE(BminusA.X() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(BminusA.Y() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(BminusA.Z() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(BminusA.W() == doctest::Approx(4.f).epsilon(eps));

    Math::Vector4 Aplus2 = A + 2;
    REQUIRE(Aplus2.X() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(Aplus2.Y() == doctest::Approx(4.f).epsilon(eps));
    REQUIRE(Aplus2.Z() == doctest::Approx(5.f).epsilon(eps));
    REQUIRE(Aplus2.W() == doctest::Approx(6.f).epsilon(eps));

    Math::Vector4 Aminus2 = A - 2;
    REQUIRE(Aminus2.X() == doctest::Approx(-1.f).epsilon(eps));
    REQUIRE(Aminus2.Y() == doctest::Approx(0.f).epsilon(eps));
    REQUIRE(Aminus2.Z() == doctest::Approx(1.f).epsilon(eps));
    REQUIRE(Aminus2.W() == doctest::Approx(2.f).epsilon(eps));

    Math::Vector4 Amul = A * 3;
    REQUIRE(Amul.X() == doctest::Approx(3.f).epsilon(eps));
    REQUIRE(Amul.Y() == doctest::Approx(6.f).epsilon(eps));
    REQUIRE(Amul.Z() == doctest::Approx(9.f).epsilon(eps));
    REQUIRE(Amul.W() == doctest::Approx(12.f).epsilon(eps));

    Math::Vector4 Adiv = A / 2;
    REQUIRE(Adiv.X() == doctest::Approx(0.5f).epsilon(eps));
    REQUIRE(Adiv.Y() == doctest::Approx(1.f).epsilon(eps));
    REQUIRE(Adiv.Z() == doctest::Approx(1.5f).epsilon(eps));
    REQUIRE(Adiv.W() == doctest::Approx(2.f).epsilon(eps));
}

TEST_CASE("[Math/Vector4] - Advanced Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector4 A{ 1.f, 2.f, 3.f, 4.f };
    Math::Vector4 B{ 5.f, 6.f, 7.f, 8.f };

    REQUIRE(B.Length() == doctest::Approx(std::sqrt(174.f)).epsilon(eps));
    REQUIRE(A.Dot(B) == doctest::Approx(70.f).epsilon(eps));
}
