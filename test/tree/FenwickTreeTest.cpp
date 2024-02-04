#include "tree/FenwickTree.h"

#include <gtest/gtest.h>

using namespace alg;

TEST(FenwickTreeTests, Sum) {
  std::vector<int> input{3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};
  FenwickTree tree(input);

  int sum = 0;
  for (size_t i = 0; i < input.size(); ++i) {
    sum += input[i];
    EXPECT_EQ(tree.sum(i), sum);
  }
}


TEST(FenwickTreeTests, RangeSum) {
  std::vector<int> input{1, 2, 3, 4, 5, 6};
  const auto n = static_cast<int>(input.size());
  FenwickTree tree(input);

  for (size_t i = 0; i < input.size(); ++i) {
    EXPECT_EQ(tree.rangeSum(i, i), input[i]);
  }

  EXPECT_EQ(tree.rangeSum(0, input.size() - 1), n * (n + 1) / 2);
  EXPECT_EQ(tree.rangeSum(1, 2), 5);
}
