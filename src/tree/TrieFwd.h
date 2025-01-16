#pragma once

#include <memory>
#include <string>
#include <string_view>

namespace alg {

class TrieNode;
class TrieNodeDeleter;
using TrieNodePtr = std::unique_ptr<TrieNode, TrieNodeDeleter>;

using Character  = char;
using String     = std::basic_string<Character>;
using StringView = std::basic_string_view<Character>;

TrieNodePtr createTrieNode(const Character ch);
void deleteTrieNode(TrieNode* node);
Character nodeCharacter(const TrieNode* node);

class TrieNodeDeleter {
 public:
  void operator()(TrieNode* node) const noexcept {
    deleteTrieNode(node);
  }
};

} // alg
