#include "Utils.h"
#include <gtest/gtest.h>

using namespace alg;

TEST(UtilsTests, TrimRight) {
  std::string s = "  123  ";
  trimRight(s);
  EXPECT_EQ(s, "  123");

  s = "a";
  trimRight(s);
  EXPECT_EQ(s, "a");

  s = "";
  trimRight(s);
  EXPECT_EQ(s, "");

  s = "  \t \n  \r ";
  trimRight(s);
  EXPECT_EQ(s, "");
}


TEST(UtilsTests, NumberOfDigits) {
  EXPECT_EQ(numDigits(0), 1U);
  EXPECT_EQ(numDigits(1), 1U);
  EXPECT_EQ(numDigits(10), 2U);
  EXPECT_EQ(numDigits(99), 2U);
  EXPECT_EQ(numDigits(100), 3U);
}