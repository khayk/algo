#pragma once

// #define VERBOSE_TRIE

#include <memory>
#include <string>
#include <string_view>
#include <array>
#include <forward_list>

// #include <unordered_map>
// #include <map>

#ifdef VERBOSE_TRIE
#include <iostream>
#endif

namespace alg {

class TrieNode;
class TrieNodeDeleter;
using TrieNodePtr = std::unique_ptr<TrieNode, TrieNodeDeleter>;

using Character  = char;
using String     = std::basic_string<Character>;
using StringView = std::basic_string_view<Character>;

TrieNodePtr createTrieNode(const Character ch);
void deleteTrieNode(TrieNode* node);

class TrieNodeDeleter {
 public:
  void operator()(TrieNode* node) const noexcept {
    deleteTrieNode(node);
  }
};


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
};


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
};

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

  template <typename Cb>
  void enumerate(Cb cb) const {
    for (const auto& [_, node] : children_) {
      cb(node.get());
    }
  }
};

//using Impl = MapImpl<std::map<Character, TrieNodePtr>>;
//using Impl = MapImpl<std::unordered_map<Character, TrieNodePtr>>;
//using Impl = ArrayImpl<26>;
using Impl = ListImpl;

class TrieNode {
  Impl impl_;
  Character ch_{' '};
  bool isLeaf_{false};

  Impl& impl() { return impl_; }
  const Impl& impl() const noexcept { return impl_; }

 public:
  TrieNode(const Character ch) { ch_ = ch; }

  Character character() const noexcept { return ch_; }

  void insert(StringView word) {
    if (word.empty()) {
      return;
    }

    const auto ch = word.front();
    TrieNode* node = impl().find(ch);

    if (!node) {
      node = impl().insert(ch, createTrieNode(ch));
    }

    if (word.size() == 1) {
      node->isLeaf_ = true;
    }

    word.remove_prefix(1);
    node->insert(word);
  }

  void remove(StringView word) { std::ignore = word; }

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

//size_t idx_{1500000};
//std::vector<TrieNode> nodes_(idx_ + 1);

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

  void insert(StringView word) { root_->insert(word); }

  void remove(StringView word) { root_->remove(word); }

  bool search(StringView word) { return root_->search(word); }

  size_t numNodes() const noexcept { return root_->numNodes(); }

  size_t numWords() const noexcept { return root_->numWords(); }
};

}  // namespace alg