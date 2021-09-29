#include <gtest/gtest.h>

#include "Utils.h"
#include "search/Challenges.h"

#include <algorithm>

using namespace alg;

TEST(SearchChallengesTests, MaxInSortedRightShiftedKnownK) {
  ArrayInts a{1, 3, 4, 5, 8, 10, 17};
  const auto max = a.back();

  int n = static_cast<int>(a.size());
  for (int i = 0; i < n; ++i) {
    std::rotate(a.begin(), a.begin() + 1, a.end());
    EXPECT_EQ(maxInSortedRightShifted(a, n - i - 1), max);
  }

  EXPECT_THROW(maxInSortedRightShifted(ArrayInts(), 0), std::runtime_error);
}


TEST(SearchChallengesTests, MaxInSortedRightShiftedUnknownK) {
  ArrayInts a{1, 3, 4, 5, 8, 10, 17};
  const auto max = a.back();

  int n = static_cast<int>(a.size());
  for (int i = 0; i < n; ++i) {
    std::rotate(a.begin(), a.begin() + 1, a.end());
    EXPECT_EQ(maxInSortedRightShifted(a), max);
  }
}
