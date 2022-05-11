#include "tree/BTree.h"

#include <gtest/gtest.h>

#include <vector>

using namespace alg;

using Node = BTNode<int>;

TEST(BinaryTreeTests, TreeFromArray) {
  std::vector<int> nodes{5, 7, 2, 10, 8, 1, 3};
  std::vector<int> exp{10, 7, 8, 5, 1, 2, 3};
  std::vector<int> act;

  auto tree = treeFromArray(nodes, -1);

  inOrderTraversalIterative(
      tree, [&act](const Node* node) { act.push_back(node->data); });

  deleteBTree(tree);

  EXPECT_EQ(act, exp);
}

