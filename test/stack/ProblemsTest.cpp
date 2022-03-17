#include <gtest/gtest.h>
#include "stack/Problems.h"

TEST(StaclProblemsTests, ValidateStackSequences) {
  std::vector<int> pushed;
  std::vector<int> popped;

  pushed = {1, 2, 3, 4, 5};
  popped = {4, 5, 3, 2, 1};
  EXPECT_TRUE(alg::validateStackSequences(pushed, popped));

  pushed = {1, 2, 3, 4, 5};
  popped = {4, 3, 5, 1, 2};
  EXPECT_FALSE(alg::validateStackSequences(pushed, popped));

  pushed = {};
  popped = {};
  EXPECT_TRUE(alg::validateStackSequences(pushed, popped));
}