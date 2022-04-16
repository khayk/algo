#include <gtest/gtest.h>
#include "tree/BTree.h"

#include <vector>

using namespace alg;
using Node = BTNode<int>;

TEST(BinaryTreeTests, TreeFromArray) {
  std::vector<int> nodes{5, 7, 2, 10, 8, 1, 3};

  auto tree = treeFromArray(nodes, -1);

  inOrderTraversalIterative(
      tree, [](const Node* node) { std::cout << node->data << ' '; });

  deleteBTree(tree);
}

