#pragma once

#include <utility>
#include <array>

#include "../TrieFwd.h"

namespace alg {

template <size_t N>
class ArrayImpl {
  std::array<TrieNodePtr, N> children_;

 public:
  TrieNode* find(Character ch) {
    ch -= 'a';
    return children_[ch].get();
  };

  const TrieNode* find(Character ch) const {
    ch -= 'a';
    return children_[ch].get();
  };

  TrieNode* insert(Character ch, TrieNodePtr node) {
    ch -= 'a';
    children_[ch] = std::move(node);
    return children_[ch].get();
  }

  template <typename Cb>
  void enumerate(Cb cb) const {
    for (const auto& node : children_) {
      if (node.get()) {
        cb(node.get());
      }
    }
  }

  size_t empty() const noexcept {
    return std::find_if(std::begin(children_), std::end(children_), [](const auto& itm) {
        return itm != nullptr;
    }) == std::end(children_);
  }
};

using CharArray26 = ArrayImpl<26>;

} // alg