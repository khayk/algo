#include <gtest/gtest.h>
#include "tree/Tree.h"
#include "Utils.h"

using namespace alg;

TEST(TreeTests, Construct) {
  auto* root = createTNode(5, {createTNode(1,
                                           {
                                               createTNode(3, {createTNode(4)}),
                                           }),
                               createTNode(2)});

  std::vector<int> exp = {5, 1, 2, 3, 4};
  std::vector<int> act;

  levelOrderTraversal(
      root, [&act](const auto* const node, int level, bool levelChanged) {
        std::ignore = level;
        std::ignore = levelChanged;

        act.push_back(node->data());
      });

  EXPECT_EQ(exp, act);

  deleteTNode(root);
}


TEST(TreeTests, Dfs)
{
  const auto* root = createTNode(
      1, {createTNode(2,
                      {
                          createTNode(4, {createTNode(5),
                                          createTNode(6, {createTNode(8)}),
                                          createTNode(7, {createTNode(9)})}),
                      }),
          createTNode(3)});

  std::vector<int> expDiscovered = {1, 2, 4, 5, 6, 8, 7, 9, 3};
  std::vector<int> expVisited = {5, 8, 6, 9, 7, 4, 2, 3, 1};

  std::vector<int> discovered;
  std::vector<int> visited;

  dfs(root,
      [&discovered, &visited](const auto* const node, const auto* const parent,
                              NodeState state, int level) {
        std::ignore = level;
        std::ignore = parent;

        if (state == NodeState::Discovered) {
          discovered.push_back(node->data());
        } else if (state == NodeState::Visited) {
          visited.push_back(node->data());
        }
      });

  EXPECT_EQ(expDiscovered, discovered);
  EXPECT_EQ(expVisited, visited);
}