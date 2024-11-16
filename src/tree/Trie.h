#pragma once

// Uncomment below to see details about structure during runtime
// #define VERBOSE_TRIE

#include "TrieFwd.h"

// Defaulting to list implementation
#include "impl/TrieChildrenList.h"
using Impl = alg::ListImpl;

#ifdef VERBOSE_TRIE
#include <iostream>
#endif

namespace alg {

class TrieNode {
  Impl impl_;
  Character ch_{' '};
  bool isLeaf_{false};

  Impl& impl() { return impl_; }
  const Impl& impl() const noexcept { return impl_; }

 public:
  TrieNode(const Character ch) { ch_ = ch; }

  Character character() const noexcept { return ch_; }

  bool insert(StringView word) {
    if (word.empty()) {
      return false;
    }

    const auto ch = word.front();
    TrieNode* node = impl().find(ch);

    if (!node) {
      node = impl().insert(ch, createTrieNode(ch));
    }

    if (word.size() == 1) {
      bool inserted = node->isLeaf_;
      node->isLeaf_ = true;
      return inserted;
    }

    word.remove_prefix(1);
    return node->insert(word);
  }

  bool remove(StringView word) {
    if (word.empty()) {
      bool removed = isLeaf_;
      isLeaf_ = false;
      return removed;
    }

    const char ch = word[0];
    auto* child = impl().find(ch);
    if (!child) {
      return false;
    }

    StringView suffix = word.substr(1);
    if (!child->remove(suffix)) {
      return false;
    }

    if (child->empty() && !child->isLeaf()) {
      impl().remove(ch);
      return true;
    }

    return false;
  }

  bool search(StringView word) const {
    const TrieNode* node = this;

    for (const auto ch : word) {
      node = node->impl().find(ch);

      if (!node) {
        return false;
      }
    }

    return node->isLeaf_;
  }

  size_t numNodes() const noexcept {
    size_t count = 0;
    impl().enumerate(
        [&count](const TrieNode* node) { count += node->numNodes(); });

    return count + 1;
  }

  size_t numWords() const noexcept {
    size_t count = 0;
    impl().enumerate(
        [&count](const TrieNode* node) { count += node->numWords(); });

    return count + (isLeaf_ ? 1 : 0);
  }

  bool empty() { return impl().empty(); }

  bool isLeaf() const noexcept { return isLeaf_; }
};


inline void deleteTrieNode(TrieNode* node) {
  if (node) {
#ifdef VERBOSE_TRIE
    const auto ch = node->character();
#endif

    delete node;

#ifdef VERBOSE_TRIE
    std::cout << "deleted: " << node << " [" << ch << "]\n";
#endif
    node = nullptr;
  }
}


inline TrieNodePtr createTrieNode(const Character ch) {
  TrieNodePtr node(new TrieNode(ch));

#ifdef VERBOSE_TRIE
  std::cout << "created: " << node << " [" << node->character() << "]\n";
#endif
  return node;
}


class Trie {
  TrieNodePtr root_;

 public:
  Trie() : root_(createTrieNode('*')) {}

  bool insert(StringView word) { return root_->insert(word); }

  bool remove(StringView word) { return root_->remove(word); }

  bool search(StringView word) { return root_->search(word); }

  size_t numNodes() const noexcept { return root_->numNodes(); }

  size_t numWords() const noexcept { return root_->numWords(); }
};

}  // namespace alg