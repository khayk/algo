#include <gtest/gtest.h>
#include "stack/Problems.h"

TEST(StackProblemsTests, ValidateStackSequences) {
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


TEST(StackProblemsTests, ContiguousSubarrays) {
  std::vector<int> arr{3, 4, 1, 6, 2};
  std::vector<int> exp{1, 3, 1, 5, 1};
  std::vector<int> act{};

  act = alg::countSubarrays(arr);
  EXPECT_EQ(act, exp);

  arr = {4, 1, 2, 3, 2, 1, 2, 5, 3, 7};
  exp = {7, 1, 2, 6, 3, 1, 3, 9, 1, 10};
  act = alg::countSubarrays(arr);
  EXPECT_EQ(act, exp);

  arr = {};
  exp = {};
  act = alg::countSubarrays(arr);
  EXPECT_EQ(act, exp);

  arr = {1, 1, 1};
  exp = {3, 3, 3};
  act = alg::countSubarrays(arr);
  EXPECT_EQ(act, exp);
}