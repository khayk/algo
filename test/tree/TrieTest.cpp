#include <gtest/gtest.h>
#include "tree/Trie.h"
#include <filesystem>
#include <fstream>

using namespace alg;
namespace fs = std::filesystem;

TEST(TrieTests, Defaults) {
  Trie trie;

  EXPECT_EQ(1, trie.numNodes());  // there is always a root node
  EXPECT_EQ(0, trie.numWords());
  EXPECT_FALSE(trie.search(""));
  EXPECT_FALSE(trie.search("*"));
}


TEST(TrieTests, Insert) {
  Trie trie;

  EXPECT_NO_THROW(trie.insert("foo"));

  EXPECT_EQ(1, trie.numWords());
  EXPECT_EQ(4, trie.numNodes());
}


TEST(TrieTests, InsertIdempotent) {
  Trie trie;

  for (int i = 0; i < 2; ++i)
  {
    trie.insert("foo");

    EXPECT_EQ(1, trie.numWords());
    EXPECT_EQ(4, trie.numNodes());
  }
}

TEST(TrieTests, Search) {
  Trie trie;

  const auto word = "hello";

  EXPECT_FALSE(trie.search(word));
  EXPECT_NO_THROW(trie.insert(word));
  EXPECT_TRUE(trie.search(word));
}


TEST(TrieTests, Remove) {
  Trie trie;

  const auto word = "erase";

  EXPECT_FALSE(trie.search(word));
  trie.insert(word);
  EXPECT_TRUE(trie.search(word));

  trie.remove(word);

  EXPECT_FALSE(trie.search(word));
  EXPECT_EQ(1, trie.numNodes());
  EXPECT_EQ(0, trie.numWords());
}


TEST(TrieTests, RemoveHasNoSideEffects) {
  Trie trie;

  trie.insert("good");
  trie.insert("goods");

  EXPECT_TRUE(trie.search("good"));
  EXPECT_TRUE(trie.search("goods"));
  EXPECT_EQ(2, trie.numWords());
  EXPECT_EQ(6, trie.numNodes());
  
  trie.remove("good");

  EXPECT_FALSE(trie.search("good"));
  EXPECT_TRUE(trie.search("goods"));
  EXPECT_EQ(1, trie.numWords());
  EXPECT_EQ(6, trie.numNodes());
}


TEST(TrieTests, MultipleWords) {
  Trie trie;

  trie.insert("fee");
  EXPECT_EQ(1, trie.numWords());
  EXPECT_EQ(4, trie.numNodes());

  trie.insert("feed");
  EXPECT_EQ(2, trie.numWords());
  EXPECT_EQ(5, trie.numNodes());

  trie.insert("ask");
  EXPECT_EQ(8, trie.numNodes());
  EXPECT_EQ(3, trie.numWords());

  EXPECT_TRUE(trie.search("fee"));
  EXPECT_TRUE(trie.search("feed"));
  EXPECT_TRUE(trie.search("ask"));
}


TEST(TrieTests, Performance) {
  Trie trie;
  StringView word("congratulations");

  for (int i = 0; i < 1'000'000; ++i) {
   trie.insert(word);
   EXPECT_TRUE(trie.search(word));
  }
}


TEST(TrieTests, DISABLED_LargeDictionary) {
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
