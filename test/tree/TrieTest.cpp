#include <gtest/gtest.h>

#include "tree/Trie.h"
#include "System.h"

#include <filesystem>
#include <fstream>
#include <queue>

using namespace alg;

namespace fs = std::filesystem;

namespace {

class MemoryUsageReporter {
  size_t initialMem_{};

 public:
  MemoryUsageReporter() { initialMem_ = sys::currentProcessMemoryUsage(); }
  ~MemoryUsageReporter() {
    const auto currentMem = sys::currentProcessMemoryUsage();
    if (currentMem > initialMem_) {
      std::cout << "Used memory: " << currentMem - initialMem_ << " bytes\n";
    } else {
      std::cout << "Free memory: " << initialMem_ - currentMem << " bytes\n";
    }
  }
};

} // namespace

TEST(TrieTests, Defaults) {
  Trie trie;

  EXPECT_EQ(1, trie.numNodes());  // there is always a root node
  EXPECT_EQ(0, trie.numWords());
  EXPECT_FALSE(trie.search(""));
  EXPECT_FALSE(trie.search("*"));
}


TEST(TrieTests, Insert) {
  Trie trie;

  EXPECT_TRUE(trie.insert("foo"));

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
  EXPECT_TRUE(trie.insert(word));
  EXPECT_TRUE(trie.search(word));
}


TEST(TrieTests, Remove) {
  Trie trie;

  const auto word = "erase";

  EXPECT_FALSE(trie.search(word));
  EXPECT_TRUE(trie.insert(word));
  EXPECT_TRUE(trie.search(word));

  EXPECT_TRUE(trie.remove(word));

  EXPECT_FALSE(trie.search(word));
  EXPECT_EQ(1, trie.numNodes());
  EXPECT_EQ(0, trie.numWords());
}


TEST(TrieTests, RemoveSubWordRemains) {
  Trie trie;

  trie.insert("foo");
  const size_t numNodes = trie.numNodes();
  EXPECT_EQ(1, trie.numWords());

  trie.insert("foobar");
  EXPECT_EQ(2, trie.numWords());

  EXPECT_TRUE(trie.remove("foobar"));

  EXPECT_FALSE(trie.search("foobar"));
  EXPECT_TRUE(trie.search("foo"));
  EXPECT_EQ(numNodes, trie.numNodes());
  EXPECT_EQ(1, trie.numWords());
}


TEST(TrieTests, RemoveNonExistingWord) {
  Trie trie;

  trie.insert("foo");
  trie.insert("foobar");

  // The word doesn't exist, remove should have no effect
  EXPECT_FALSE(trie.remove("fooba"));

  EXPECT_TRUE(trie.search("foobar"));
  EXPECT_TRUE(trie.search("foo"));
  EXPECT_EQ(2, trie.numWords());
  EXPECT_EQ(7, trie.numNodes());
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


TEST(TrieTests, MixUsage) {
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

  trie.remove("feed");
  EXPECT_EQ(2, trie.numWords());
  EXPECT_EQ(7, trie.numNodes());
  EXPECT_TRUE(trie.search("ask"));
  EXPECT_TRUE(trie.search("fee"));
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

  std::queue<std::string> words;
  size_t inserted = 0;
  size_t skipped = 0;

  {
    MemoryUsageReporter mur;

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
      words.push(word);
    }
  }

  std::cout << "node size: " << sizeof(TrieNode) << '\n';
  std::cout << "words:     " << trie.numWords() << '\n';
  std::cout << "nodes:     " << trie.numNodes() << '\n';
  std::cout << "inserted:  " << inserted << '\n';
  std::cout << "skipped:   " << skipped << '\n';

  {
    MemoryUsageReporter mur;
    size_t numWords = trie.numWords();
    while (!words.empty())
    {
      trie.remove(words.front());
      --numWords;
      EXPECT_FALSE(trie.search(word));
      ASSERT_EQ(numWords, trie.numWords());

      words.pop();
    }
  }

  std::cout << "node size: " << sizeof(TrieNode) << '\n';
  std::cout << "words:     " << trie.numWords() << '\n';
  std::cout << "nodes:     " << trie.numNodes() << '\n';
  std::cout << "inserted:  " << inserted << '\n';
  std::cout << "skipped:   " << skipped << '\n';
}

TEST(TrieTests, LargeDictionaryFiles) {
  Trie trie;
  fs::path dict("C:\\Code\\allfiles.txt");
  std::ifstream in(dict, std::ios::in);
  std::string word;
  ASSERT_TRUE(in);

  size_t inserted = 0;
  size_t skipped = 0;

  {
    MemoryUsageReporter mur;

    while (in) {
      word.clear();
      std::getline(in, word);

      if (!word.empty()) {
        ++inserted;
        trie.insert(word);
      }
    }
  }

  std::cout << "node size: " << sizeof(TrieNode) << '\n';
  std::cout << "words:     " << trie.numWords() << '\n';
  std::cout << "nodes:     " << trie.numNodes() << '\n';
  std::cout << "inserted:  " << inserted << '\n';
  std::cout << "skipped:   " << skipped << '\n';
}
