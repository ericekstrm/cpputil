
#include <gtest/gtest.h>

#include <cpputil/container.h>

#include <sstream>

TEST(Vector2, Initalization)
{
    std::vector<int> vi { 1,2,3,4,5 };

    std::ostringstream oss;
    oss << vi;
    ASSERT_EQ(oss.str(), "1, 2, 3, 4, 5");
}
