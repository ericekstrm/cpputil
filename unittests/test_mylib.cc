
#include "gtest/gtest.h"
#include "../mylib.cc"

TEST(Test1, test2)
{

    mylib_func();

    EXPECT_EQ(1, 1);
}
