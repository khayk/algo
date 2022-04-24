#pragma once

#include "BTree.h"

namespace alg {

/**
 * @brief  Given a binary tree, find the lowest common ancestor (LCA) of two
 * given nodes in the tree.
 *
 * @param root The root of the tree
 * @param p  Node of the tree
 * @param q  Node of the tree
 *
 * @return The LCA of two given nodes
 *
 * @ref leetcode
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 */
template <typename T>
BTNode<T>* lowestCommonAncestor(BTNode<T>* root, BTNode<T>* p, BTNode<T>* q) {
  if (!root || root == p || root == q) {
    return root;
  }

  BTNode<T>* left = lowestCommonAncestor(root->left, p, q);
  BTNode<T>* right = lowestCommonAncestor(root->right, p, q);

  return !left ? right : (!right ? left : root);
}

}  // namespace alg