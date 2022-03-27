#include <gtest/gtest.h>
#include "sort/Problems.h"

#include <algorithm>

using namespace alg;

TEST(SortProblemsTests, Partition) {
  std::vector v = {4, 6, -1, 0};
  auto p = partition(v, 0, v.size() - 1);
  size_t i = 0;

  while (i < p) {
    EXPECT_LE(v[i++], v[p]);
  }

  while (i < v.size()) {
    EXPECT_GE(v[i++], v[p]);
  }
}


TEST(SortProblemsTests, KthElement) {
  std::vector v = {5, 2, 5, 4, 17, -1, 0, 1};
  std::vector vc = v;
  std::sort(vc.begin(), vc.end());

  for (size_t i = 0; i < vc.size(); ++i) {
    EXPECT_EQ(kthElement(v, i), vc[i]);
  }

  EXPECT_THROW(kthElement(v, v.size()), std::system_error);
}


TEST(SortProblemsTests, MaxDifference) {
  std::vector v = {6, 13, 19, 3, 8};
  const auto pairs = maxDifference(v);

  EXPECT_EQ(std::abs(std::get<0>(pairs) - std::get<1>(pairs)), 16);
}


TEST(SortProblemsTests, ComputeHIndex) {
  std::vector<uint32_t> v = {6, 13, 19, 3, 8};
  auto hi = computeHIndex(v);
  EXPECT_EQ(hi, 4U);

  v = {3, 0, 6, 1, 5};
  hi = computeHIndex(v);
  EXPECT_EQ(hi, 3U);

  v = {1, 3, 1};
  hi = computeHIndex(v);
  EXPECT_EQ(hi, 1U);
}


TEST(SortProblemsTests, MajorityElement) {
  std::vector<int> v = {1, 2, 5, 9, 5, 9, 5, 5, 5, 5};

  int m = majorityElement(v);
  EXPECT_EQ(m, 5);

  v = {1, 1, 3, 2, 1, 2, 1, 2, 2, 1, 1};
  m = majorityElement(v);
  EXPECT_EQ(m, 1);

  v = {1, 1, 3, 2, 1, 2, 2, 2, 1, 1};
  m = majorityElement(v);
  EXPECT_EQ(m, std::numeric_limits<int>::min());

  v = {4, 4, 1, 4, 4, 1, 1, 1, 4, 4};
  m = majorityElement(v);
  EXPECT_EQ(m, 4);
}


TEST(SortProblemsTests, QuarterElements) {
  std::vector<int> v;
  std::vector<int> act;
  std::vector<int> exp;

  v = {1, 2, 5, 9, 5, 9, 5, 5, 5, 5};
  exp = {5};
  act = quarterElements(v);
  EXPECT_EQ(act, exp);

  v = {1, 1, 3, 2, 1, 2, 1, 2, 2, 1, 1};
  act = quarterElements(v);
  exp = {1, 2};
  EXPECT_EQ(act, exp);

  v = {0, 1, 0, 2, 1, 2, 2, 2, 1, 0, 1, 0};
  act = quarterElements(v);
  exp = {0, 1, 2};
  EXPECT_EQ(act, exp);

  v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
  act = quarterElements(v);
  exp = {};
  EXPECT_EQ(act, exp);
}


TEST(SearchProblemsTests, BalancedSplitExists) {
  std::vector<int> arr;

  arr = {2, 1, 2, 5};
  EXPECT_EQ(balancedSplitExists(arr), true);

  arr = {3, 6, 3, 4, 4};
  EXPECT_EQ(balancedSplitExists(arr), false);

  arr = {1, 5, 7, 1};
  EXPECT_EQ(balancedSplitExists(arr), true);

  arr = {12, 7, 6, 7, 6};
  EXPECT_EQ(balancedSplitExists(arr), false);
}