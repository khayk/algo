#include "search/Problems.h"
#include "Utils.h"

#include <gtest/gtest.h>

#include <algorithm>

using namespace alg;

TEST(SearchProblemsTests, MaxInSortedRightShiftedKnownK) {
  ArrayInts a{1, 3, 4, 5, 8, 10, 10, 17};
  const auto max = a.back();

  int n = static_cast<int>(a.size());
  for (int i = 0; i < n; ++i) {
    std::rotate(a.begin(), a.begin() + 1, a.end());
    EXPECT_EQ(maxInSortedRightShifted(a, n - i - 1), max);
  }

  EXPECT_THROW(maxInSortedRightShifted(ArrayInts(), 0), std::runtime_error);
}


TEST(SearchProblemsTests, MaxInSortedRightShiftedUnknownK) {
  ArrayInts a{1, 3, 4, 5, 8, 10, 10, 17};
  const auto max = a.back();

  int n = static_cast<int>(a.size());
  for (int i = 0; i < n; ++i) {
    std::rotate(a.begin(), a.begin() + 1, a.end());
    EXPECT_EQ(maxInSortedRightShifted(a), max);
  }
}


TEST(SearchProblemsTests, MissingInSortedArray) {
  ArrayInts a{1, 2, 4, 5};

  constexpr int n = 10;
  a.resize(n);

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < n; ++j) {
      a[j] = j + 1;

      if (j >= i) {
        ++a[j];
      }
    }

    EXPECT_EQ(missingInSortedArray(a), i + 1);
  }
}


TEST(SearchProblemsTests, MedianOfSortedArrays) {
  ArrayInts a;
  ArrayInts b;

  a = {1, 3};
  b = {2};
  EXPECT_EQ(medianOfSortedArrays(a, b), 2);

  a = {1, 2};
  b = {3, 4};
  EXPECT_EQ(medianOfSortedArrays(a, b), 2.5);

  a = {1, 3, 5, 7};
  b = {9, 11, 17, 19, 19};
  EXPECT_EQ(medianOfSortedArrays(a, b), 9);

  b = {2, 4, 6};
  EXPECT_EQ(medianOfSortedArrays(a, b), 4);

  a = {5, 6, 11, 17, 18};
  b = {1, 2, 3, 20, 20, 10000};
  EXPECT_EQ(medianOfSortedArrays(a, b), 11);

  a.clear();
  b.clear();
  EXPECT_EQ(medianOfSortedArrays(a, b), 0.0);

  b = {1};
  EXPECT_EQ(medianOfSortedArrays(a, b), 1);
}


TEST(SearchProblemsTests, GetBillionUsersDay) {
  std::vector<float> a{1.5f};
  EXPECT_EQ(getBillionUsersDay(a), 52);

  a = {1.1f, 1.2f, 1.3f};
  EXPECT_EQ(getBillionUsersDay(a), 79);

  a = {1.01f, 1.02f};
  EXPECT_EQ(getBillionUsersDay(a), 1047);

  a = std::vector<float>(1000, 1.00001f);
  EXPECT_EQ(getBillionUsersDay(a), 1379685);
}
