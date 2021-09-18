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
