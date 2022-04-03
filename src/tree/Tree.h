#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <stack>

// #define VERBOSE_TREE

namespace alg {

// Forward declaration
template <typename T>
class TNode;


/**
 * @brief  Constructs a tree node
 */
template <typename T>
TNode<T>* createTNode(T&& data) {
  auto* const node = new TNode<T>(std::forward<T>(data));

#ifdef VERBOSE_TREE
  std::cout << "created: " << node << " [" << node->data() << "]\n";
#endif

  return node;
}


/**
 * @brief  Constructs a tree node with children
 */
template <typename T>
TNode<T>* createTNode(T&& data, const std::initializer_list<TNode<T>*>& children) {
  auto* const node = createTNode<T>(std::forward<T>(data));

  for (auto* child : children) {
    node->addChild(child);
  }

  return node;
}


/**
 * @brief  Destroyes a tree node
 */
template <typename T>
void deleteTNode(TNode<T>*& node) {
  if (node) {

#ifdef VERBOSE_TREE
    const auto data = node->data();
#endif

    delete node;

#ifdef VERBOSE_TREE
    std::cout << "deleted: " << node << " [" << data << "]\n";
#endif

    node = nullptr;
  }
}


/**
 * @brief  A generic tree node type
 * @tparam T  Type of the underlying data
 */
template <typename T>
class TNode {
  using Children = std::vector<TNode<T>*>;

  T data_;
  Children children_;

public:
  explicit TNode(T&& data) : data_(std::forward<T>(data)) {}

  TNode(T&& data, Children children)
      : data_(std::forward<T>(data)), children_(children) {}

  ~TNode() {
    while (!children_.empty()) {
      deleteTNode(children_.back());
      children_.pop_back();
    }
  }

  const T& data() const noexcept { return data_; }

  void data(const T& data) { data_ = data; }

  const Children& children() const noexcept { return children_; }

  TNode<T>* child(size_t i) { return children_[i]; }

  const TNode<T>* child(size_t i) const { return children_[i]; }

  void addChild(TNode<T>* ptr) { children_.push_back(ptr); }
};


/**
 * @brief  Calculates the depth of the tree. The tree with a single node has a
 *         depth of 0. If the node is nullptr, the depth is -1.
 *
 * @param node The root node of the tree
 */
template <typename T>
int depth(const TNode<T>* const node) {
  if (!node) return -1;

  int maxDepth = 0;

  for (const auto* const n : node->children()) {
    maxDepth = std::max(maxDepth, depth(n) + 1);
  }

  return maxDepth;
}


/**
 * @brief  Serialize the tree in a human-readable format.
 *
 * @param node  A node of the tree
 * @param indent  The number of spaces to increase indentation for each new line
 * @param offset
 */
template <typename T>
void serializeTree(const TNode<T>* node, int indent, std::string& offset) {
  if (!node) return;

  std::cout << offset << node->data() << std::endl;

  offset.append(std::string(indent, ' '));

  for (const auto* const n : node->children()) {
    serializeTree(n, indent, offset);
  }

  offset.erase(offset.size() - indent);
}


/**
 * @brief  Prints the tree in a human-readable format starting from the given
 *         node and below.
 *
 * @param node  A node of the tree
 * @param indent  The number of spaces to increase indentation for each new line
 */
template <typename T>
void serializeTree(const TNode<T>* node, int indent = 2) {
  std::string tmp;
  printHelper(node, indent, tmp);
}


/**
 * @brief  Traverse the tree in a level order.
 *
 * @param root  Any node of the tree
 * @param visited A function to be called for each traversed node. A prototype
 *                is provided below.
 *
 * void handler(const Node<T>* node, int level, bool levelChanged)
 *
 * Here, the node is the current node, the level is the current level,
 * levelChanged is true if the new is the first node of the given level, from
 * left
 */
template <typename T, typename Fn>
void levelOrderTraversal(const TNode<T>* root, const Fn& visited) {
  if (!root) return;

  struct Data {
    const TNode<T>* node;
    int level{0};
  };

  std::queue<Data> q;
  int level = -1;

  q.push({root, 0});

  while (!q.empty()) {
    const auto& data = q.front();
    const auto* node = data.node;
    const int l = data.level;
    const bool newLevel = level != l;

    if (newLevel) {
      level = l;
    }

    visited(node, level, newLevel);

    for (const auto* const n : node->children()) {
      q.push({n, level + 1});
    }

    q.pop();
  }
}

enum class NodeState : int32_t {
  None,
  Discovered,
  Visited
};



template <typename T, typename Fn>
void dfs(const TNode<T>* root, const Fn& cb) {
  if (!root) return;

  struct Data {
    const TNode<T>* node;
    const TNode<T>* parent{nullptr};
    int32_t level{0};
    NodeState state{NodeState::None};
  };

  std::stack<Data> s;
  s.push({root, nullptr, 0});

  while (!s.empty()) {
    auto& data = s.top();
    auto& state = data.state;
    const auto* node = data.node;
    const auto level = data.level;
    bool hasChildren = false;

    if (state == NodeState::None) {
      state = NodeState::Discovered;
      cb(node, data.parent, state, level);

      const auto& children = node->children();
      for (auto it = children.rbegin(); it != children.rend(); ++it) {
        s.push({*it, node, level + 1});
        hasChildren = true;
      }
    }

    if (!hasChildren) {
      state = NodeState::Visited;
      cb(node, data.parent, state, level);
      s.pop();
    }
  }
}


}  // namespace alg