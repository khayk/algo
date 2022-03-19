#include <gtest/gtest.h>
#include "hash/Problems.h"

using namespace alg;

TEST(HashProblemsTests, PairSums) {
  std::vector<int> arr;
  int k{};

  arr = {1, 2, 3, 4, 3};
  k = 6;
  EXPECT_EQ(numberOfWays(arr, k), 2);

  arr = {1, 5, 3, 3, 3};
  EXPECT_EQ(numberOfWays(arr, k), 4);

  k = 8;
  EXPECT_EQ(numberOfWays(arr, k), 3);

  k = 9;
  EXPECT_EQ(numberOfWays(arr, k), 0);

  arr = {};
  k = 0;
  EXPECT_EQ(numberOfWays(arr, k), 0);
}
