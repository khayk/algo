#include "sort/Problems.h"
#include <gtest/gtest.h>
#include <algorithm>

TEST(SortProblemsTests, Partition) {
  std::vector v = {4, 6, -1, 0};
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
  std::vector v = {5, 2, 5, 4, 17, -1, 0, 1};
  std::vector vc = v;
  std::sort(vc.begin(), vc.end());

  for (size_t i = 0; i < vc.size(); ++i) {
    EXPECT_EQ(alg::kthElement(v, i), vc[i]);
  }

  EXPECT_THROW(alg::kthElement(v, v.size()), std::system_error);
}


TEST(SortProblemsTests, MaxDifference) {
  std::vector v = {6, 13, 19, 3, 8};
  const auto pairs = alg::maxDifference(v);

  EXPECT_EQ(std::abs(std::get<0>(pairs) - std::get<1>(pairs)), 16);
}


TEST(SortProblemsTests, ComputeHIndex) {
  std::vector<uint32_t> v = {6, 13, 19, 3, 8};
  auto hi = alg::computeHIndex(v);
  EXPECT_EQ(hi, 4U);

  v = {3, 0, 6, 1, 5};
  hi = alg::computeHIndex(v);
  EXPECT_EQ(hi, 3U);

  v = {1, 3, 1};
  hi = alg::computeHIndex(v);
  EXPECT_EQ(hi, 1U);
}


TEST(SortProblemsTests, MajorityElement) {
  std::vector<int> v = {1, 2, 5, 9, 5, 9, 5, 5, 5, 5};

  int m = alg::majorityElement(v);
  EXPECT_EQ(m, 5);

  v = {1, 1, 3, 2, 1, 2, 1, 2, 2, 1, 1};
  m = alg::majorityElement(v);
  EXPECT_EQ(m, 1);

  v = {1, 1, 3, 2, 1, 2, 2, 2, 1, 1};
  m = alg::majorityElement(v);
  EXPECT_EQ(m, std::numeric_limits<int>::min());

  v = {4, 4, 1, 4, 4, 1, 1, 1, 4, 4};
  m = alg::majorityElement(v);
  EXPECT_EQ(m, 4);
}


TEST(SortProblemsTests, QuarterElements) {
  std::vector<int> v;
  std::vector<int> act;
  std::vector<int> exp;

  v = {1, 2, 5, 9, 5, 9, 5, 5, 5, 5};
  exp = {5};
  act = alg::quarterElements(v);
  EXPECT_EQ(act, exp);

  v = {1, 1, 3, 2, 1, 2, 1, 2, 2, 1, 1};
  act = alg::quarterElements(v);
  exp = {1, 2};
  EXPECT_EQ(act, exp);

  v = {0, 1, 0, 2, 1, 2, 2, 2, 1, 0, 1, 0};
  act = alg::quarterElements(v);
  exp = {0, 1, 2};
  EXPECT_EQ(act, exp);

  v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
  act = alg::quarterElements(v);
  exp = {};
  EXPECT_EQ(act, exp);
}