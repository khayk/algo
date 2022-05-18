#include <gtest/gtest.h>

#include "search/Algorithms.h"

using namespace alg;

TEST(SearchAlgorithmsTests, FindNearestElement) {
  std::set<int> s{1, 3, 4, 5, 8, 10, 17};

  // Search inside the non empty set will always return an iterator to an existing element
  EXPECT_EQ(findNearestElement(s, -4), s.find(1));
  EXPECT_EQ(findNearestElement(s, 1), s.find(1));
  EXPECT_EQ(findNearestElement(s, 6), s.find(5));
  EXPECT_EQ(findNearestElement(s, 7), s.find(8));
  EXPECT_EQ(findNearestElement(s, 50), s.find(17));

  // Now, any search will return end().
  s.clear();
  EXPECT_EQ(findNearestElement(s, 5), s.end());
}