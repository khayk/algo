#include "geometry/Vector.h"
#include "geometry/Math.h"

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
  EXPECT_TRUE(a < b);
  EXPECT_FALSE(a < a);
}


TEST(VectorTests, Length) {
  Vec2 a{3, 4};

  EXPECT_EQ(a.length(), 5);
  EXPECT_EQ(a.squaredLength(), 25);
}


TEST(VectorTests, Dot) {
  Vec2 a{0, 2};
  Vec2 b{1, 0};

  EXPECT_EQ(a.dot(b), 0);
  EXPECT_EQ(a.dot(a), 4);
}


TEST(VectorTests, Cross) {
  Vec2 a{0, 2};
  Vec2 b{5, 0};

  EXPECT_EQ(b.cross(a), 10);
  EXPECT_EQ(a.cross(b), -10);
  EXPECT_EQ(b.cross(b), 0);
  EXPECT_EQ(a.cross(a), 0);
}


TEST(VectorTests, Perp) {
  Vec2 a{3, 7};
  Vec2 e{7, -3};
  EXPECT_EQ(a.perp(), e);
}


TEST(VectorTests, Distance) {
  Vec2 a{2, 2};
  Vec2 b{6, 5};

  EXPECT_EQ((a - b).length(), 5);
}


TEST(VectorTests, Rotate) {
  Vec2 a{10, 3};
  Vec2 e{-3, 10};

  EXPECT_EQ(alg::rotate(a, 90.0), e);
}