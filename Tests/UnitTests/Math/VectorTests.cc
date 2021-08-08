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

TEST_CASE("[Math/Vector3] - Basic Arithmetic Operators")
{
    constexpr float eps = 1e-5f;

    Math::Vector3 A{ 1.f, 2.f, 3.f };
    Math::Vector3 B{ 4.f, 5.f, 6.f };

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
