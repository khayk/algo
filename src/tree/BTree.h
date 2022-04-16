#pragma once

#include <stack>
#include <queue>
#include <utility>

namespace alg {

/**
 * @brief  Binary tree node
 */
template <typename T>
struct BTNode {
  T data{};
  BTNode<T>* left{nullptr};
  BTNode<T>* right{nullptr};
};


template <typename T>
BTNode<T>* createBTNode(T data) {
  return new BTNode<T>{data};
}


template <typename T>
BTNode<T>* createBTNode(T data, BTNode<T>* left, BTNode<T>* right) {
  return new BTNode<T>{data, left, right};
}


template <typename T>
BTNode<T>* treeFromArray(const std::vector<T>& items, T nullValue = T{}) {
  BTNode<T>* root = nullptr;
  std::queue<BTNode<T>*> q;

  if (!items.empty()) {
    auto i = items.begin();
    root = createBTNode(*i);
    q.push(root);

    while (!q.empty()) {
      auto* n = q.front();
      q.pop();

      if (i == items.end() || ++i == items.end()) {
        break;
      }

      if (*i != nullValue) {
        n->left = createBTNode(*i);
        q.push(n->left);
      }

      if (i == items.end() || ++i == items.end()) {
        break;
      }

      if (*i != nullValue) {
        n->right = createBTNode(*i);
        q.push(n->right);
      }
    }
  }

  return root;
}


/**
 * @brief Performs in order traversal
 *
 * @param node  The start node for the traversal
 * @param cb  The function to be called each traversed node
 */
template <typename T, typename Cb>
void inOrderTraversal(const BTNode<T>* node, const Cb& cb) {
  if (!node) return;

  inOrderTraversal(node->left, cb);
  cb(node);
  inOrderTraversal(node->right, cb);
}


/**
 * @brief  Iterative version of in order traversal. Useful for very deep trees.
 *
 * @param node  The start node for the traversal
 * @param cb  The function to be called each traversed node
 */
template <typename T, typename Cb>
void inOrderTraversalIterative(const BTNode<T>* node, const Cb& cb) {
  if (!node) {
    return;
  }

  std::stack<const BTNode<T>*> s;
  const BTNode<T>* curr = node;

  while (curr || !s.empty()) {
    while (curr) {
      s.push(curr);
      curr = curr->left;
    }

    curr = s.top();
    s.pop();
    auto* tmp = curr;
    curr = curr->right;
    cb(tmp);
  }
}


template <typename T>
void deleteBTree(BTNode<T>* root) {
  inOrderTraversalIterative(root, [](const BTNode<T>* node) { delete node; });
}


}  // namespace alg