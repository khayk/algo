#include <gtest/gtest.h>

#include "tree/Problems.h"

using namespace alg;

using Node = BTNode<int>;

TEST(TreeProblemsTests, LowestCommonAncestor) {
  std::vector<int> nodes{3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};

  auto tree = treeFromArray(nodes, -1);

  auto lca = lowestCommonAncestor(tree, tree->left->left, tree->left->right);
  EXPECT_EQ(lca, tree->left);
}