#include "combinatorial/Theory.h"
#include <gtest/gtest.h>
#include <algorithm>

using namespace alg;

TEST(CombinatorialTheoryTests, Sum) {
  std::vector<int> v = {0, 1, 2};
  std::vector<std::vector<int>> all;

  allSubsets(v, all);
  EXPECT_EQ(all.size(), (1 << v.size()));

  std::vector<std::vector<int>> expected{{},     {0},    {1},    {2},
                                         {0, 1}, {0, 2}, {1, 2}, {0, 1, 2}};
  
  std::sort(all.begin(), all.end());
  std::sort(expected.begin(), expected.end());

  EXPECT_EQ(all, expected);
}