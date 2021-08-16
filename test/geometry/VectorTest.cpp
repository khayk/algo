#include "geometry/Vector.h"
#include <gtest/gtest.h>

using Vec2 = alg::Vector2d;

TEST(VectorTests, Addition) {
  Vec2 a {1, 1};
  Vec2 b {2, -1};
  Vec2 c = a + b;

  EXPECT_EQ(c.x(), 3);
  EXPECT_EQ(c.y(), 0);
}


TEST(VectorTests, Subtraction) {
  Vec2 b{2, -1};
  Vec2 c{3, 0};
  Vec2 a = c - b;

  EXPECT_EQ(a.x(), 1);
  EXPECT_EQ(a.y(), 1);
}


TEST(VectorTests, Scaling) {
  Vec2 a{3, 2};
  Vec2 b = a * 2;

  EXPECT_EQ(b.x(), 6);
  EXPECT_EQ(b.y(), 4);

  b = b * 1;

  EXPECT_EQ(b.x(), 6);
  EXPECT_EQ(b.y(), 4);
}


TEST(VectorTests, Normalize) {
  Vec2 a{3, 4};
  EXPECT_NE(a.length(), 1);
  EXPECT_NO_THROW(a.normalize());
  EXPECT_EQ(a.length(), 1);

  // Very small vector
  a = Vec2(0.000001, 0.000001);
  EXPECT_NE(a.length(), 1);
  EXPECT_NO_THROW(a.normalize());
  EXPECT_EQ(a.length(), 1);
}


TEST(VectorTests, NormalizeZero) {
  Vec2 a{0, 0};
  EXPECT_EQ(a.length(), 0);
  EXPECT_NO_THROW(a.normalize());
  EXPECT_EQ(a.length(), 0);
}


TEST(VectorTests, Compare) {
  Vec2 a{1, 1};
  Vec2 b{1, 1.0000001};

  EXPECT_TRUE(a != b);
  EXPECT_TRUE(a == a);
  EXPECT_TRUE(b == b);
}