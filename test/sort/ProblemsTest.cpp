#include "sort/Problems.h"
#include <gtest/gtest.h>
#include <algorithm>

TEST(SortProblemsTests, Partition) {
  std::vector<int> v = {4, 6, -1, 0};
  auto p = alg::partition(v, 0, v.size() - 1);
  size_t i = 0;

  while (i < p) {
    EXPECT_LE(v[i++], v[p]);
  }

  while (i < v.size()) {
    EXPECT_GE(v[i++], v[p]);
  }
}


TEST(SortProblemsTests, KthElement) {
  std::vector<int> v = {5, 2, 5, 4, 17, -1, 0, 1};
  std::vector<int> vc = v;
  std::sort(vc.begin(), vc.end());

  for (size_t i = 0; i < vc.size(); ++i) {
    EXPECT_EQ(alg::kthElement(v, i), vc[i]);
  }

  EXPECT_THROW(alg::kthElement(v, v.size()), std::system_error);
}


TEST(SortProblemsTests, MaxDifference) {
}