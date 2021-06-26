#include <doctest.h>

#include <Cowdia/Types/Rect.hpp>

using namespace Cowdia::Types;

TEST_CASE("[Types/Rect] Constructor Tests")
{
    Recti r1(680, 480);
    CHECK_EQ(r1.GetLeft(), 0);
    CHECK_EQ(r1.GetTop(), 0);
    CHECK_EQ(r1.GetRight(), 680);
    CHECK_EQ(r1.GetBottom(), 480);
    CHECK_EQ(r1.GetWidth(), 680);
    CHECK_EQ(r1.GetHeight(), 480);

    Recti r2(100, 200, 680, 480);
    CHECK_EQ(r2.GetLeft(), 100);
    CHECK_EQ(r2.GetTop(), 200);
    CHECK_EQ(r2.GetRight(), 780);
    CHECK_EQ(r2.GetBottom(), 680);
    CHECK_EQ(r2.GetWidth(), 680);
    CHECK_EQ(r2.GetHeight(), 480);
}

TEST_CASE("[Types/Rect] Operator Tests")
{
    Recti rA(680, 480);
    Recti rB(0, 0, 680, 480);
    Recti rC(100, 0, 680, 480);

    CHECK_EQ(rA == rA, true);
    CHECK_EQ(rA != rA, false);
    CHECK_EQ(rA == rB, true);
    CHECK_EQ(rA != rB, false);
    CHECK_EQ(rA == rC, false);
    CHECK_EQ(rA != rC, true);
}
