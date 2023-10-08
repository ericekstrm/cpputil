#include <gtest/gtest.h>

#include <cpputil/string_util.h>

#include <sstream>

using namespace std;

TEST(String, Split)
{
    string s1 {"123+456+789"};
    string s2 {"a.bc.defg.hjklm.nop"};
    string s3 {""};
    string s4 {"123xx456xx789x"};

    vector<string> v1 { split(s1, '+') };
    ASSERT_EQ(v1.size(), 3);
    ASSERT_EQ(v1[0], "123");
    ASSERT_EQ(v1[1], "456");
    ASSERT_EQ(v1[2], "789");

    vector<string> v2 { split(s2, '.') };
    ASSERT_EQ(v2.size(), 5);
    ASSERT_EQ(v2[0], "a");
    ASSERT_EQ(v2[1], "bc");
    ASSERT_EQ(v2[2], "defg");
    ASSERT_EQ(v2[3], "hjklm");
    ASSERT_EQ(v2[4], "nop");

    vector<string> v3 { split(s3, '+') };
    ASSERT_EQ(v3.size(), 0);

    vector<string> v4 { split(s4, 'x') };
    ASSERT_EQ(v4.size(), 3);
    ASSERT_EQ(v4[0], "123");
    ASSERT_EQ(v4[1], "456");
    ASSERT_EQ(v4[2], "789");
}
