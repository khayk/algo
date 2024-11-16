#pragma once

#include <unordered_map>
#include <map>
#include <utility>

#include "../TrieFwd.h"

namespace alg {

template <typename UnderlyingMap>
class MapImpl {
  UnderlyingMap children_;

 public:
  TrieNode* find(const Character ch) {
    auto it = children_.find(ch);

    if (it == children_.end()) {
      return nullptr;
    }

    return it->second.get();
  };

  const TrieNode* find(const Character ch) const {
    const auto it = children_.find(ch);

    if (it == children_.end()) {
      return nullptr;
    }

    return it->second.get();
  };

  TrieNode* insert(const Character ch, TrieNodePtr node) {
    auto it = children_.emplace(ch, std::move(node));
    return it.first->second.get();
  }

  template <typename Cb>
  void enumerate(Cb cb) const {
    for (const auto& [_, node] : children_) {
      cb(node.get());
    }
  }

  size_t empty() const noexcept {
    return children_.empty();
  }
};

using OrderedMapImpl   = MapImpl<std::map<Character, TrieNodePtr>>;
using UnorderedMapImpl = MapImpl<std::unordered_map<Character, TrieNodePtr>>;

} // alg