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


TEST(StackProblemsTests, ExclusiveTime) {
  std::vector<int> exp;
  std::vector<int> act;
  std::vector<std::string> logs;

  logs = {"0:start:0", "0:start:2", "0:end:5",
          "0:start:6", "0:end:6",   "0:end:7"};
  exp = {8};
  act = exclusiveTime(1, logs);
  EXPECT_EQ(act, exp);

  logs = {"0:start:0", "0:start:2", "0:end:5",
          "1:start:6", "1:end:6",   "0:end:7"};
  exp = {7, 1};
  act = exclusiveTime(2, logs);
  EXPECT_EQ(act, exp);

  logs = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
  exp = {3, 4};
  act = exclusiveTime(2, logs);
  EXPECT_EQ(act, exp);
}

TEST(StackProblemsTests, LargestRectangleInHistogram) {
  std::vector<size_t> heights;

  heights = {2, 1, 5, 6, 2, 3};
  EXPECT_EQ(largestRectangleInHistogram(heights), 10);

  heights = {2, 4};
  EXPECT_EQ(largestRectangleInHistogram(heights), 4);

  heights = {1, 2, 3, 4, 5};
  EXPECT_EQ(largestRectangleInHistogram(heights), 9);

  heights = {2, 3, 1, 1, 1};
  EXPECT_EQ(largestRectangleInHistogram(heights), 5);

  heights = {2, 1, 2};
  EXPECT_EQ(largestRectangleInHistogram(heights), 3);
}