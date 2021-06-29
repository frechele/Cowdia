#include <doctest.h>

#include <Cowdia/Types/Color.hpp>

using namespace Cowdia::Types;

TEST_CASE("[Types/Color] Constructor Tests")
{
    Color c1(0x6799FFFF);
    CHECK_EQ(c1.GetR(), 103);
    CHECK_EQ(c1.GetG(), 153);
    CHECK_EQ(c1.GetB(), 255);
    CHECK_EQ(c1.GetA(), 255);
    CHECK_EQ(c1.GetRGBA(), 0x6799FFFF);

    Color c2(171, 242, 0);
    CHECK_EQ(c2.GetR(), 171);
    CHECK_EQ(c2.GetG(), 242);
    CHECK_EQ(c2.GetB(), 0);
    CHECK_EQ(c2.GetA(), 255);
    CHECK_EQ(c2.GetRGBA(), 0xABF200FF);

    Color c3(217, 65, 197, 15);
    CHECK_EQ(c3.GetR(), 217);
    CHECK_EQ(c3.GetG(), 65);
    CHECK_EQ(c3.GetB(), 197);
    CHECK_EQ(c3.GetA(), 15);
    CHECK_EQ(c3.GetRGBA(), 0xD941C50F);
}

TEST_CASE("[Types/Color] Operator Tests")
{
    Color cA(0x6799FFFF);
    Color cB(103, 153, 255);
    Color cC(171, 242, 0);

    CHECK_EQ(cA == cA, true);
    CHECK_EQ(cA != cA, false);
    CHECK_EQ(cA == cB, true);
    CHECK_EQ(cA != cB, false);
    CHECK_EQ(cA == cC, false);
    CHECK_EQ(cA != cC, true);
}
