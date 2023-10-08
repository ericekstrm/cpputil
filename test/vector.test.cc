#include <gtest/gtest.h>

#include <cpputil/vector.h>

#include <sstream>

TEST(Vector2, Initalization)
{
    vec2i v1 {5, 2};
    vec2f v2 {5.0, 2.0};

    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 2);
    ASSERT_FLOAT_EQ(v2.x, 5.0f);
    ASSERT_FLOAT_EQ(v2.y, 2.0f);

    // Default initalization
    vec2i v3 {};
    vec2f v4 {};
    ASSERT_EQ(v3.x, 0);
    ASSERT_EQ(v3.y, 0);
    ASSERT_FLOAT_EQ(v4.x, 0.0f);
    ASSERT_FLOAT_EQ(v4.y, 0.0f);

    // Union usage
    ASSERT_EQ(v1.r, 5);
    ASSERT_EQ(v1.g, 2);
    ASSERT_EQ(v1.s, 5);
    ASSERT_EQ(v1.t, 2);
}

TEST(Vector2, Operators)
{
    vec2i v1 {5, 2};
    vec2i v2 {7, 1};
    vec2i v3 {12, 3};
    vec2i v4 {v1};

    // Comparison
    ASSERT_TRUE(v1 == v4);
    ASSERT_FALSE(v1 == v2);
    ASSERT_TRUE(v1 != v2);
    ASSERT_FALSE(v1 != v4);

    // Addition, Subtraction
    ASSERT_EQ(v1 + v2, v3);
    ASSERT_EQ(v3 - v1, v2);
    v4 += v2;
    ASSERT_EQ(v4, v3);
    v4 -= v2;
    ASSERT_EQ(v4, v1);

    // Multiplication, Division
    vec2i v5 {4, 1};
    ASSERT_EQ(v5 * 3, v3);
    ASSERT_EQ(3 * v5, v3);
    vec2i v6 {v5};
    v6 *= 3;
    ASSERT_EQ(v6, v3);
    v6 /= 3;
    ASSERT_EQ(v6, v5);
}

TEST(Vector2, Functions)
{
    // Integer length
    vec2i v1 {3, 4};
    ASSERT_EQ(v1.length(), 5);
    vec2i v2 {5, 12};
    ASSERT_EQ(v2.length(), 13);
    vec2i v3 {36,77};
    ASSERT_EQ(v3.length(), 85);

    // Float length
    vec2f v4 {3.6, 5.2};
    ASSERT_FLOAT_EQ(v4.length(), 6.3245549);
    vec2f v5 {1, 1};
    ASSERT_FLOAT_EQ(v5.length(), 1.4142135);
    vec2f v6 {0.2, 0.4};
    ASSERT_FLOAT_EQ(v6.length(), 0.4472136);

    // Normalize
    vec2f v11 {1, 1};
    ASSERT_EQ(static_cast<std::string>(v11), "[1.000 1.000]");
    v11.normalize();
    ASSERT_EQ(static_cast<std::string>(v11), "[0.707 0.707]");

    // Normalize Integer (will round down to integer after division)
    vec2i v12 {3, 4};
    ASSERT_EQ(static_cast<std::string>(v12), "[3 4]");
    v12.normalize();
    ASSERT_EQ(static_cast<std::string>(v12), "[0 0]");

    // Zero (will round down to integer after division)
    vec2f v13 {0, 0};
    ASSERT_EQ(static_cast<std::string>(v13), "[0 0]");
    v13.normalize();
    ASSERT_EQ(static_cast<std::string>(v13), "[0 0]");
}

TEST(Vector2, Linear_Algebra)
{
    vec2i v1 {5, 2};
    vec2i v2 {7, 1};
    vec2i v3 {2, -5};

    // Dot product
    ASSERT_EQ(v1 * v2, 37);
    ASSERT_EQ(v1 * v3, 0);
}


TEST(Vector2, Stream_Operator)
{
    vec2i v1 {1,2};
    vec2i v2 {3,4};
    vec2f v3 {1.12,2.0};
    vec2f v4 {789, 234.123};
    std::ostringstream oss;
    oss << v1 << " " << v2 << " " << v3 << " " << v4;
    ASSERT_EQ(oss.str(), "[1 2] [3 4] [1.120 2.000] [789.000 234.123]");
}
// ==================
// ===| vector 3 |===
// ==================

TEST(Vector3, Initalization)
{
    vec3i v1 {5, 2, 4};
    vec3f v2 {5.0, 2.0, 4.0};

    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 2);
    ASSERT_EQ(v1.z, 4);
    ASSERT_FLOAT_EQ(v2.x, 5.0f);
    ASSERT_FLOAT_EQ(v2.y, 2.0f);
    ASSERT_FLOAT_EQ(v2.z, 4.0f);

    // Default initalization
    vec3i v3 {};
    vec3f v4 {};
    ASSERT_EQ(v3.x, 0);
    ASSERT_EQ(v3.y, 0);
    ASSERT_EQ(v3.z, 0);
    ASSERT_FLOAT_EQ(v4.x, 0.0f);
    ASSERT_FLOAT_EQ(v4.y, 0.0f);
    ASSERT_FLOAT_EQ(v4.z, 0.0f);

    // Union usage
    ASSERT_EQ(v1.r, 5);
    ASSERT_EQ(v1.g, 2);
    ASSERT_EQ(v1.b, 4);
    ASSERT_EQ(v1.s, 5);
    ASSERT_EQ(v1.t, 2);
    ASSERT_EQ(v1.v, 4);
}

TEST(Vector3, Operators)
{
    vec3i v1 {5, 2, 3};
    vec3i v2 {7, 1, 3};
    vec3i v3 {12, 3, 6};
    vec3i v4 {v1};

    // Comparison
    ASSERT_TRUE(v1 == v4);
    ASSERT_FALSE(v1 == v2);
    ASSERT_TRUE(v1 != v2);
    ASSERT_FALSE(v1 != v4);

    // Addition, Subtraction
    ASSERT_EQ(v1 + v2, v3);
    ASSERT_EQ(v3 - v1, v2);
    v4 += v2;
    ASSERT_EQ(v4, v3);
    v4 -= v2;
    ASSERT_EQ(v4, v1);

    // Multiplication, Division
    vec3i v5 {4, 1, 2};
    ASSERT_EQ(v5 * 3, v3);
    ASSERT_EQ(3 * v5, v3);
    vec3i v6 {v5};
    v6 *= 3;
    ASSERT_EQ(v6, v3);
    v6 /= 3;
    ASSERT_EQ(v6, v5);
}

TEST(Vector3, Functions)
{
    // Integer length
    vec3i v1 {1, 2, 2};
    ASSERT_EQ(v1.length(), 3);
    vec3i v2 {8, 11, 16};
    ASSERT_EQ(v2.length(), 21);
    vec3i v3 {2, 7, 26};
    ASSERT_EQ(v3.length(), 27);

    // Float length
    vec3f v4 {3.6, 5.2, 6.7};
    ASSERT_FLOAT_EQ(v4.length(), 9.2135763);
    vec3f v5 {1, 1, 1};
    ASSERT_FLOAT_EQ(v5.length(), 1.7320508);
    vec3f v6 {0.2, 0.4, 0.1};
    ASSERT_FLOAT_EQ(v6.length(), 0.4582575);

    // Normalize
    vec3f v11 {1, 1, 1};
    ASSERT_EQ(static_cast<std::string>(v11), "[1.000 1.000 1.000]");
    v11.normalize();
    ASSERT_EQ(static_cast<std::string>(v11), "[0.577 0.577 0.577]");

    // Normalize Integer (will round down to integer after division)
    vec3i v12 {3, 4, 5};
    ASSERT_EQ(static_cast<std::string>(v12), "[3 4 5]");
    v12.normalize();
    ASSERT_EQ(static_cast<std::string>(v12), "[0 0 0]");
}

TEST(Vector3, Linear_Algebra)
{
    vec3i v1 {5, 2, 4};
    vec3i v2 {7, 1, 3};

    // Dot product
    ASSERT_EQ(v1 * v2, 49);

    vec3i v3 {0,1,0};
    vec3i v4 {1,0,1};
    ASSERT_EQ(v3 * v4, 0);
    
}

TEST(Vector3, Stream_Operator)
{
    vec3i v1 {1,2,3};
    vec3f v2 {1.12,2.0,3.789};
    std::ostringstream oss;
    oss << v1 << " " << v2;
    ASSERT_EQ(oss.str(), "[1 2 3] [1.120 2.000 3.789]");
}

// ===================
// ===| Vector 4  |===
// ===================

TEST(Vector4, Initalization)
{
    vec4i v1 {5, 2, 4, 7};
    vec4f v2 {5.0, 2.0, 4.0, 3.3};

    ASSERT_EQ(v1.x, 5);
    ASSERT_EQ(v1.y, 2);
    ASSERT_EQ(v1.z, 4);
    ASSERT_EQ(v1.w, 7);
    ASSERT_FLOAT_EQ(v2.x, 5.0f);
    ASSERT_FLOAT_EQ(v2.y, 2.0f);
    ASSERT_FLOAT_EQ(v2.z, 4.0f);
    ASSERT_FLOAT_EQ(v2.w, 3.3f);

    // Default initalization
    vec4i v3 {};
    vec4f v4 {};
    ASSERT_EQ(v3.x, 0);
    ASSERT_EQ(v3.y, 0);
    ASSERT_EQ(v3.z, 0);
    ASSERT_EQ(v3.w, 0);
    ASSERT_FLOAT_EQ(v4.x, 0.0f);
    ASSERT_FLOAT_EQ(v4.y, 0.0f);
    ASSERT_FLOAT_EQ(v4.z, 0.0f);
    ASSERT_FLOAT_EQ(v4.w, 0.0f);

    // Union usage
    ASSERT_EQ(v1.r, 5);
    ASSERT_EQ(v1.g, 2);
    ASSERT_EQ(v1.b, 4);
    ASSERT_EQ(v1.a, 7);
    ASSERT_EQ(v1.s, 5);
    ASSERT_EQ(v1.t, 2);
    ASSERT_EQ(v1.v, 4);
    ASSERT_EQ(v1.u, 7);
}

TEST(Vector4, Operators)
{
    vec4i v1 {5, 2, 3, 7};
    vec4i v2 {7, 1, 3, 8};
    vec4i v3 {12, 3, 6, 15};
    vec4i v4 {5, 2, 3, 7};

    // Comparison
    ASSERT_TRUE(v1 == v4);
    ASSERT_FALSE(v1 == v2);
    ASSERT_TRUE(v1 != v2);
    ASSERT_FALSE(v1 != v4);

    // Addition, Subtraction
    ASSERT_EQ(v1 + v2, v3);
    ASSERT_EQ(v3 - v1, v2);
    v4 += v2;
    ASSERT_EQ(v4, v3);
    v4 -= v2;
    ASSERT_EQ(v4, v1);

    // Multiplication, Division
    vec4i v5 {4, 1, 2, 5};
    ASSERT_EQ(v5 * 3, v3);
    ASSERT_EQ(3 * v5, v3);
    vec4i v6 {v5};
    v6 *= 3;
    ASSERT_EQ(v6, v3);
    v6 /= 3;
    ASSERT_EQ(v6, v5);
}

TEST(Vector4, Linear_Algebra)
{
    vec4i v1 {5, 2, 4, 7};
    vec4i v2 {7, 1, 3, 2};

    // Dot product
    ASSERT_EQ(v1 * v2, 63);

    vec4i v3 {0, 1, 0, 0};
    vec4i v4 {1, 0, 1, 1};
    ASSERT_EQ(v3 * v4, 0);
    
}

TEST(Vector4, Stream_Operator)
{
    vec4i v1 {1,2,3,4};
    vec4f v2 {1.123,2.343,3.789,4.000};
    std::ostringstream oss;
    oss << v1 << " " << v2;
    ASSERT_EQ(oss.str(), "[1 2 3 4] [1.123 2.343 3.789 4.000]");
}
