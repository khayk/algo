#include <gtest/gtest.h>

#include "string/Problems.h"

using namespace alg;

TEST(StringProblemsTests, MinimumLengthSubstring) {
  std::string s;
  std::string t;

  s = "adobecodebanc";
  t = "abc";
  EXPECT_EQ(minimumLengthSubstring(s, t), 4);

  s = "dcbefebce";
  t = "fd";
  EXPECT_EQ(minimumLengthSubstring(s, t), 5);

  s = "a";
  t = "a";
  EXPECT_EQ(minimumLengthSubstring(s, t), 1);

  s = "a";
  t = "aa";
  EXPECT_EQ(minimumLengthSubstring(s, t), -1);

  s = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  t = "cbccfafebccdccebdd";
  EXPECT_EQ(minimumLengthSubstring(s, t), -1);
}