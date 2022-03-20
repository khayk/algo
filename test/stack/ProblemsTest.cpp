#include <gtest/gtest.h>
#include "stack/Problems.h"

using namespace alg;

TEST(StackProblemsTests, ValidateStackSequences) {
  std::vector<int> pushed;
  std::vector<int> popped;

  pushed = {1, 2, 3, 4, 5};
  popped = {4, 5, 3, 2, 1};
  EXPECT_TRUE(validateStackSequences(pushed, popped));

  pushed = {1, 2, 3, 4, 5};
  popped = {4, 3, 5, 1, 2};
  EXPECT_FALSE(validateStackSequences(pushed, popped));

  pushed = {};
  popped = {};
  EXPECT_TRUE(validateStackSequences(pushed, popped));
}


TEST(StackProblemsTests, ContiguousSubarrays) {
  std::vector<int> arr{3, 4, 1, 6, 2};
  std::vector<int> exp{1, 3, 1, 5, 1};
  std::vector<int> act{};

  act = countSubarrays(arr);
  EXPECT_EQ(act, exp);

  arr = {4, 1, 2, 3, 2, 1, 2, 5, 3, 7};
  exp = {7, 1, 2, 6, 3, 1, 3, 9, 1, 10};
  act = countSubarrays(arr);
  EXPECT_EQ(act, exp);

  arr = {};
  exp = {};
  act = countSubarrays(arr);
  EXPECT_EQ(act, exp);

  arr = {1, 1, 1};
  exp = {3, 3, 3};
  act = countSubarrays(arr);
  EXPECT_EQ(act, exp);
}


TEST(StackProblemsTests, IsBracketsBalanced) {
  EXPECT_TRUE(isBracketsBalanced("{[()]}"));
  EXPECT_TRUE(isBracketsBalanced("{}()"));
  EXPECT_TRUE(isBracketsBalanced("[{}({})]{}"));
  EXPECT_FALSE(isBracketsBalanced("{(})"));
  EXPECT_FALSE(isBracketsBalanced(")"));
  EXPECT_FALSE(isBracketsBalanced("("));
}