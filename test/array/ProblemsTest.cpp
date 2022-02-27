#include <gtest/gtest.h>
#include "array/Problems.h"

using namespace alg;

TEST(ArrayProblemsTests, MaximumSubarraySum) {
  std::vector<int> a = {-1, 2, 4, -3, 5, 2, -5, 2};
  EXPECT_EQ(maximumSubarraySum(a), 10);

  a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(maximumSubarraySum(a), 6);

  // Edge cases
  EXPECT_EQ({}, 0);
  EXPECT_EQ({7}, 7);
  EXPECT_EQ({-1}, -1);
}
