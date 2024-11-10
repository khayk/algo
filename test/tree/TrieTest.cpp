#include <gtest/gtest.h>
#include "tree/Trie.h"
#include <filesystem>
#include <fstream>

using namespace alg;
namespace fs = std::filesystem;

TEST(TrieTests, Basics) {
  Trie trie;

  trie.insert("foo");
  trie.insert("bar");
  trie.insert("food");

  EXPECT_EQ(8, trie.numNodes());
  EXPECT_EQ(3, trie.numWords());

  EXPECT_TRUE(trie.search("foo"));
  EXPECT_TRUE(trie.search("food"));
  EXPECT_TRUE(trie.search("bar"));

  EXPECT_FALSE(trie.search("fo"));
  EXPECT_FALSE(trie.search("bark"));
}

TEST(TrieTests, Performance) {
  Trie trie;
  StringView word("congratulations");

  for (int i = 0; i < 1'000'000; ++i) {
   trie.insert(word);
   EXPECT_TRUE(trie.search(word));
  }
}

TEST(TrieTests, LargeDictionary) {
  Trie trie;
  fs::path dict("C:\\Code\\words.txt");
  std::ifstream in(dict, std::ios::in);
  std::string word;

  ASSERT_TRUE(in);

  size_t inserted = 0;
  size_t skipped = 0;

  while (in) {
    in >> word;
    if (!word.empty()) {
      if (!std::all_of(word.begin(), word.end(), ::islower)) {
        ++skipped;
        continue;
      }
      ++inserted;
      trie.insert(word);
      EXPECT_TRUE(trie.search(word));
    }
  }

  std::cout << "node size: " << sizeof(TrieNode) << '\n';
  std::cout << "words:     " << trie.numWords() << '\n';
  std::cout << "nodes:     " << trie.numNodes() << '\n';
  std::cout << "inserted:  " << inserted << '\n';
  std::cout << "skipped:   " << skipped << '\n';
}