#include <doctest.h>

#include <cmath>

#include <Cowdia/Math/Angle.hpp>
#include <Cowdia/Math/Constants.hpp>

using namespace Cowdia::Math;

TEST_CASE("[Math/Angle] Radian Tests")
{
    constexpr float eps = 1e-5f;

    const Radian rad(3.14159265358979f);
    REQUIRE(rad.value == doctest::Approx(Constants::PI).epsilon(eps));
    REQUIRE(std::sin(rad.value) == doctest::Approx(0).epsilon(eps));
    REQUIRE(rad.ToDegree().value == doctest::Approx(180).epsilon(eps));

    const Radian deg90(Constants::PI / 2.f);
    REQUIRE(std::cos(deg90.value) == doctest::Approx(0).epsilon(eps));
    REQUIRE(deg90.ToDegree().value == doctest::Approx(90).epsilon(eps));
}

TEST_CASE("[Math/Angle] Degree Tests")
{
    constexpr float eps = 1e-5f;

    const Degree deg(90.f);
    REQUIRE(deg.value == doctest::Approx(90.f).epsilon(eps));
    REQUIRE(std::sin(deg.ToRadian().value) == doctest::Approx(1).epsilon(eps));
}
