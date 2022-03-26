#include <gtest/gtest.h>
#include "queue/Problems.h"

//#include <algorithm>

using namespace alg;

TEST(QueueProblemsTests, QueueRemovals) {
  std::vector<int> arr;
  std::vector<int> exp;

  arr = {1, 2, 2, 3, 4, 5};
  exp = {5, 6, 4, 1, 2};
  EXPECT_EQ(findPositions(arr, 5), exp);

  arr = {2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
  exp = {2, 5, 10, 13};
  EXPECT_EQ(findPositions(arr, 4), exp);
}