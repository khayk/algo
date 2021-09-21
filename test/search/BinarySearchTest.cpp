#include "search/BinarySearch.h"
#include "Utils.h"

#include <gtest/gtest.h>

using namespace alg;

TEST(BinarySearchTests, BinarySearch) {
  ArrayInts a{1, 3, 4, 5, 8, 10, 17};

  EXPECT_FALSE(binarySearch(a, 2));
  EXPECT_FALSE(binarySearch(a, -1));
  EXPECT_FALSE(binarySearch(a, 6));
  EXPECT_FALSE(binarySearch(a, 15));
  EXPECT_FALSE(binarySearch(a, 37));

  for (const auto& i: a) {
    EXPECT_TRUE(binarySearch(a, i)) << i << " was not found";
  }
}


TEST(BinarySearchTests, LowerBound) {
  ArrayInts a{1, 4, 4, 5};

  EXPECT_EQ(lowerBound(a, 0), 0);
  EXPECT_EQ(lowerBound(a, 1), 0);
  EXPECT_EQ(lowerBound(a, 4), 1);
  EXPECT_EQ(lowerBound(a, 5), 3);

  a = {4, 4, 4, 4, 5};

  EXPECT_EQ(lowerBound(a, 1), 0);
  EXPECT_EQ(lowerBound(a, 4), 0);
  EXPECT_EQ(lowerBound(a, 5), 4);
  EXPECT_EQ(lowerBound(a, 6), 5);
}


TEST(BinarySearchTests, UpperBound) {
  ArrayInts a{1, 4, 4, 5};

  EXPECT_EQ(upperBound(a, 0), 0);
  EXPECT_EQ(upperBound(a, 1), 1);
  EXPECT_EQ(upperBound(a, 4), 3);
  EXPECT_EQ(upperBound(a, 5), 4);

  a = {4, 4, 4, 4, 5};

  EXPECT_EQ(upperBound(a, 1), 0);
  EXPECT_EQ(upperBound(a, 4), 4);
  EXPECT_EQ(upperBound(a, 5), 5);
  EXPECT_EQ(upperBound(a, 6), 5);
}

TEST(BinarySearchTests, Occurences) {
  ArrayInts a{1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

  for (int i = 1; i <= 4; ++i) {
    EXPECT_EQ(occurences(a, i), i);
  }
}