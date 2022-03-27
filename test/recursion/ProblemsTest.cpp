#include <gtest/gtest.h>

#include "recursion/Problems.h"

using namespace alg;

TEST(RecursionProblemsTests, EncryptedWords) {
  EXPECT_EQ(findEncryptedWord("abc"), "bac");
  EXPECT_EQ(findEncryptedWord("abcd"), "bacd");
  EXPECT_EQ(findEncryptedWord("abcxcba"), "xbacbca");
  EXPECT_EQ(findEncryptedWord("facebook"), "eafcobok");

  std::string s(100000, 'c');
  EXPECT_EQ(findEncryptedWord(s), s);
}


TEST(RecursionProblemsTests, CanGetExactChange) {
  std::vector<int> denominations;
  int targetMoney{};

  denominations = {5, 10, 25, 100, 200};
  targetMoney = 94;
  EXPECT_EQ(canGetExactChange(targetMoney, denominations), false);

  denominations = {4, 17, 29};
  targetMoney = 75;
  EXPECT_EQ(canGetExactChange(targetMoney, denominations), true);

  denominations = {3};
  targetMoney = 1000000;
  EXPECT_EQ(canGetExactChange(targetMoney, denominations), false);
}