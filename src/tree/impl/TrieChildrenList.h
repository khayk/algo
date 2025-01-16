#pragma once

#include <forward_list>
#include <utility>

#include "../TrieFwd.h"
#include "tree/Trie.h"

namespace alg {

class ListImpl {
  std::forward_list<TrieNodePtr> children_;

 public:
  TrieNode* find(const Character ch) {
    for (auto& node : children_) {
      if (nodeCharacter(node.get()) == ch) {
        return node.get();
      }
    }

    return nullptr;
  };

  const TrieNode* find(const Character ch) const {
    for (const auto& node : children_) {
      if (nodeCharacter(node.get()) == ch) {
        return node.get();
      }
    }

    return nullptr;
  };

  TrieNode* insert(TrieNodePtr node) {
    children_.emplace_front(std::move(node));
    return children_.front().get();
  }

  void remove(const Character ch) {
    children_.remove_if([ch](const auto& entry) {
      return nodeCharacter(entry.get()) == ch;
    });
  }

  template <typename Cb>
  void enumerate(Cb cb) const {
    for (const auto& node : children_) {
      cb(node.get());
    }
  }

  size_t empty() const noexcept { return children_.begin() == children_.end(); }
};

}  // namespace alg
