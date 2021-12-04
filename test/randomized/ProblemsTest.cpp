#include <gtest/gtest.h>
#include "randomized/Problems.h"

using namespace alg;

TEST(RandomizedTests, FindSmallestWindow) {
  auto actual = minWindow("this is a test string", "tist");
  decltype(actual) expected = {13, 6};
  EXPECT_EQ(actual, expected);

  actual = minWindow("geeksforgeeks", "ork");
  expected = {3, 5};
  EXPECT_EQ(actual, expected);

  actual = minWindow("aaabggggca", "acga");
  expected = {1, 8};
  EXPECT_EQ(actual, expected);
}

