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