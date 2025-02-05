#pragma once

// Uncomment below to see details about structure during runtime
// #define VERBOSE_TRIE

#include "TrieFwd.h"

// Defaulting to list implementation
#include "impl/TrieChildrenList.h"
#include <vector>
using Impl = alg::ListImpl;

#ifdef VERBOSE_TRIE
#include <iostream>
#endif

namespace alg {

class TrieNode {
  Impl impl_;
  uint32_t words_{0};
  Character ch_{' '};
  bool isLeaf_{false};

  Impl& impl() { return impl_; }
  const Impl& impl() const noexcept { return impl_; }

 public:
  TrieNode(const Character ch) {
    ch_ = ch;
  }

  Character character() const noexcept { return ch_; }

  bool insert(StringView word) {
    if (word.empty()) {
      return false;
    }

    bool inserted = false;
    const auto ch = word.front();
    TrieNode* node = impl().find(ch);

    if (!node) {
      node = impl().insert(createTrieNode(ch));
    }

    if (word.size() == 1) {
      inserted = !node->isLeaf_;
      node->isLeaf_ = true;
    } else {
      word.remove_prefix(1);
      inserted = node->insert(word);
    }

    words_ += (inserted ? 1 : 0);
    return inserted;
  }

  bool remove(StringView word) {
    bool removed = true;

    if (word.empty()) {
      removed = isLeaf_;
      isLeaf_ = false;
    } else {
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
      }
    }

    words_ -= (removed ? 1 : 0);
    return removed;
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

  uint32_t numNodes() const noexcept {
    uint32_t count = 0;
    impl().enumerate(
        [&count](const TrieNode* node) { count += node->numNodes(); });

    return count + 1;
  }

  uint32_t numWords() const noexcept {
    return words_;
  }

  bool empty() { return impl().empty(); }

  bool isLeaf() const noexcept { return isLeaf_; }
};

// std::vector<char> g_mem(22'313'636 * sizeof(TrieNode) + 10, ' ');
// size_t g_idx{0};

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
  // TrieNode* ptr = (TrieNode*)(&g_mem[g_idx]);
  //ptr = &g_nodes[g_idx++];
  // g_idx += sizeof(TrieNode);

  // TrieNodePtr node(new (ptr)TrieNode(ch));
  TrieNodePtr node(new TrieNode(ch));
#ifdef VERBOSE_TRIE
  std::cout << "created: " << node << " [" << node->character() << "]\n";
#endif
  return node;
}

inline Character nodeCharacter(const TrieNode* node)
{
  return node->character();
}

class Trie {
  TrieNodePtr root_;

 public:
  Trie() : root_(createTrieNode('*')) {}

  bool insert(StringView word) { return root_->insert(word); }

  bool remove(StringView word) { return root_->remove(word); }

  bool search(StringView word) const { return root_->search(word); }

  uint32_t numNodes() const noexcept { return root_->numNodes(); }

  uint32_t numWords() const noexcept { return root_->numWords(); }
};

}  // namespace alg
