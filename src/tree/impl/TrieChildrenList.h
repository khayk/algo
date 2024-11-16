#pragma once

#include <forward_list>
#include <utility>

#include "../TrieFwd.h"

namespace alg {

class ListImpl {
  std::forward_list<std::pair<Character, TrieNodePtr>> children_;

 public:
  TrieNode* find(const Character ch) {
    for (auto& node : children_) {
      if (node.first == ch) {
        return node.second.get();
      }
    }

    return nullptr;
  };

  const TrieNode* find(const Character ch) const {
    for (const auto& node : children_) {
      if (node.first == ch) {
        return node.second.get();
      }
    }

    return nullptr;
  };

  TrieNode* insert(const Character ch, TrieNodePtr node) {
    children_.emplace_front(ch, std::move(node));
    return children_.front().second.get();
  }

  void remove(const Character ch) {
    children_.remove_if([ch](const auto& entry) {
      return entry.first == ch;
    });
  }

  template <typename Cb>
  void enumerate(Cb cb) const {
    for (const auto& [_, node] : children_) {
      cb(node.get());
    }
  }

  size_t empty() const noexcept { return children_.begin() == children_.end(); }
};

}  // namespace alg
