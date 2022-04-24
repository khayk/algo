#include <gtest/gtest.h>

#include "recursion/Problems.h"
#include "Utils.h"

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


TEST(RecursionProblemsTests, FindDinnerParties) {
  std::vector<int> friends;
  std::vector<int> answer;
  std::vector<std::vector<int>> combinations;
  size_t tableSize{};

  auto mathAnswer = [&friends, &tableSize]() {
    // n! / (k! * (n - k)!)
    return factorial(friends.size()) /
           (factorial(tableSize) * factorial(friends.size() - tableSize));
  };

  friends = {1, 2, 3};
  tableSize = 2;
  combinations = findDinnerParties(friends, tableSize);
  ASSERT_EQ(combinations.size(), mathAnswer());

  answer = {2, 3};
  EXPECT_EQ(combinations[0], answer);
  answer = {1, 3};
  EXPECT_EQ(combinations[1], answer);
  answer = {1, 2};
  EXPECT_EQ(combinations[2], answer);


  tableSize = 3;
  combinations = findDinnerParties(friends, tableSize);
  ASSERT_EQ(combinations.size(), mathAnswer());
  answer = {1, 2, 3};
  EXPECT_EQ(combinations[0], answer);
}