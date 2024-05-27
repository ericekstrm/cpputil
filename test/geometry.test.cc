#include <cpputil.h>

#include <gtest/gtest.h>

TEST(Geometry, rect)
{

    Rect r1 {{10,9},{5,6}};

    ASSERT_EQ(r1.pos.x, 10);
    ASSERT_EQ(r1.pos.y, 9);

    ASSERT_EQ(r1.size.x, 5);
    ASSERT_EQ(r1.size.y, 6);

    // Point inside
    ASSERT_TRUE(r1.contains({12,9}));
    ASSERT_TRUE(r1.contains({8,9}));
    ASSERT_TRUE(r1.contains({10,7}));
    ASSERT_TRUE(r1.contains({10,11}));
    ASSERT_TRUE(r1.contains({12,7}));
    ASSERT_TRUE(r1.contains({12,11}));
    ASSERT_TRUE(r1.contains({8,7}));
    ASSERT_TRUE(r1.contains({8,11}));

    // Point outside
    ASSERT_FALSE(r1.contains({13,9}));
    ASSERT_FALSE(r1.contains({7,9}));
    ASSERT_FALSE(r1.contains({10,5}));
    ASSERT_FALSE(r1.contains({10,13}));
    ASSERT_FALSE(r1.contains({13,5}));
    ASSERT_FALSE(r1.contains({13,13}));
    ASSERT_FALSE(r1.contains({7,5}));
    ASSERT_FALSE(r1.contains({7,13}));

    Rect r2 {{12,12}, {2,2}};
    Rect r3 {{0,0}, {200,200}};
    Rect r4 {{10,-10}, {1,100}};
    Rect r5 {{12,12}, {0,0}};

    ASSERT_TRUE(r1.intersects(r2));
    ASSERT_TRUE(r1.intersects(r3));
    ASSERT_TRUE(r1.intersects(r4));
    ASSERT_TRUE(r1.intersects(r5));

    Rect r6 {{21,21}, {2,2}};
    Rect r7 {{-100,-100}, {200,200}};
    Rect r8 {{13,-10}, {0.5,100}};
    Rect r9 {{}, {}};

    ASSERT_FALSE(r1.intersects(r6));
    ASSERT_FALSE(r1.intersects(r7));
    ASSERT_FALSE(r1.intersects(r8));
    ASSERT_FALSE(r1.intersects(r9));    
}

TEST(Geometry, circle)
{

    Circle c1 {{10,9}, 8};

    ASSERT_EQ(c1.pos.x, 10);
    ASSERT_EQ(c1.pos.y, 9);

    ASSERT_EQ(c1.radius, 8);

    // Point inside
    ASSERT_TRUE(c1.contains({12,9}));
    ASSERT_TRUE(c1.contains({8,7}));
    
    // Point outside
    ASSERT_FALSE(c1.contains({0,0}));
    ASSERT_FALSE(c1.contains({19,9}));

    Circle c2 {{5,5}, 5};
    Circle c3 {{30,30}, 5};

    ASSERT_TRUE(c1.intersects(c2));
    ASSERT_FALSE(c1.intersects(c3));
}

TEST(Geometry, circle_rect)
{
    Rect r1 {{0,0}, {10,10}};
    Rect r2 {{10, 0}, {10,10}};

    Circle c1 {{-2,-2}, 5};
    Circle c2 {{0,25}, 20.5};
    Circle c3 {{0,0}, 100};

    ASSERT_TRUE(r1.intersects(c1));
    ASSERT_TRUE(r1.intersects(c2));
    ASSERT_TRUE(r1.intersects(c3));
    ASSERT_FALSE(r2.intersects(c1));
    ASSERT_FALSE(r2.intersects(c2));
    ASSERT_TRUE(r2.intersects(c3));
    
}
