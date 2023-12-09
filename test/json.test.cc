#include <gtest/gtest.h>

#include <cpputil.h>

using json = nlohmann::json;

TEST(json, basics)
{
    json j = {
        {"pi", 3.14},
        {"happy", true}
    };

    ASSERT_EQ(j["pi"], 3.14);
    ASSERT_EQ(j["happy"], true);

    j["insert"] = "a string";
    ASSERT_EQ(j["insert"], "a string");
}
