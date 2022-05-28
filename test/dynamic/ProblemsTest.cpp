#include <gtest/gtest.h>
#include "dynamic/Problems.h"

using namespace alg;

TEST(DynamicProblemsTests, ZeroOneKnapsack) {
  std::vector<size_t> p = {1, 4, 2, 5};
  std::vector<size_t> w = {3, 1, 5, 2};

  EXPECT_EQ(zeroOneKnapsack(p, w, 1), 4U);
  EXPECT_EQ(zeroOneKnapsack(p, w, 2), 5U);
  EXPECT_EQ(zeroOneKnapsack(p, w, 3), 9U);
  EXPECT_EQ(zeroOneKnapsack(p, w, 4), 9);
  EXPECT_EQ(zeroOneKnapsack(p, w, 5), 9U);
  EXPECT_EQ(zeroOneKnapsack(p, w, 6), 10U);
  EXPECT_EQ(zeroOneKnapsack(p, w, 7), 10U);
  EXPECT_EQ(zeroOneKnapsack(p, w, 8), 11U);

  p = {20, 5, 10, 40, 15, 25 };
  w = {1, 2, 3, 8, 7, 4 };
  EXPECT_EQ(zeroOneKnapsack(p, w, 10), 60U);
}
