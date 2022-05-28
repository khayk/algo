#include "geometry/Geometry.h"

#include <gtest/gtest.h>

#include <random>
#include <array>

using namespace alg;

TEST(GeometryTests, VectorRotate) {
  Vector2d a{10, 3};
  Vector2d e{-3, 10};

  a = alg::rotate(a, 90.0);
  EXPECT_TRUE((a - e).squaredLength() < alg::Mathd::kEpsilon);
}


TEST(GeometryTests, LineContainsPoint) {
  Vector2d o{0, 0};
  Vector2d d{1, 0};
  Line2d l(o, d);

  EXPECT_TRUE(contains(l, Vector2d{1, 0}));
  EXPECT_TRUE(contains(l, Vector2d{5, 0}));
  EXPECT_TRUE(contains(l, Vector2d{0, 0}));
  EXPECT_TRUE(contains(l, Vector2d{-10000, 0}));
  EXPECT_FALSE(contains(l, Vector2d{-10000, 0.1}));
  EXPECT_FALSE(contains(l, Vector2d{1, 1}));
}


TEST(GeometryTests, LineContainsPointRandom) {
  std::random_device rd;
  std::uniform_int_distribution distrib(-1000000, 1000000);
  std::array<double, 4> rnd{};
  for (auto& r : rnd) {
    r = static_cast<double>(distrib(rd));
  }

  Vector2d o{rnd[0], rnd[1]};
  Vector2d d{rnd[2], rnd[3]};
  d.normalize();
  Line2d l{o, d};
  Vector2d v{o};

  constexpr int iters = 50000;
  constexpr double range = 1000000.0;
  constexpr double step = 2 * range / static_cast<double>(iters);

  int i = iters;
  double t = -range;

  while (--i > 0) {
    v = o + t * d;
    t += step;
    ASSERT_TRUE(contains(l, v));
  }

  // Tilt a little bit our direction
  i = iters;
  d.x() += Mathd::kEpsilon;

  while (--i > 0) {
    v = o + t * d;
    t += step;
    ASSERT_FALSE(contains(l, v));
  }
}