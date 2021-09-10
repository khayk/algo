#include <gtest/gtest.h>

#include "sort/Problems.h"

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