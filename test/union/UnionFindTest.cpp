#include "union/UnionFind.h"

#include <gtest/gtest.h>

using namespace alg;

TEST(UnionFindTests, UnionFind) {
  std::vector<uint32_t> nodes{0, 1, 2, 3, 4};

  UnionFind<uint32_t> uf(nodes.size());

  for (int i = 0; i < nodes.size(); ++i) {
    // Initially each item belongs to it's own group
    EXPECT_EQ(uf.find(i), i);

    // Joining items from the same group returns false, as there is nothing to join
    EXPECT_FALSE(uf.join(i, i));

    // Initially the rank is 1
    EXPECT_EQ(uf.rank(i), 1);
  }

  // Now 3 and 4 joined the same group (named 4)
  EXPECT_FALSE(uf.connected(3, 4));
  EXPECT_TRUE(uf.join(3, 4));
  EXPECT_TRUE(uf.connected(3, 4));

  EXPECT_EQ(uf.find(3), 4);
  EXPECT_EQ(uf.find(4), 4);
  EXPECT_EQ(uf.rank(3), 2);
  EXPECT_EQ(uf.rank(4), 2);

  // Now, 0 joined to the group 4
  EXPECT_TRUE(uf.join(0, 3));
  EXPECT_EQ(uf.find(0), 4);
  EXPECT_TRUE(uf.connected(0, 3));
  EXPECT_TRUE(uf.connected(0, 4));
  EXPECT_EQ(uf.rank(0), 3);

  // Join 1 and 2 into the same group
  EXPECT_TRUE(uf.join(1, 2));
  EXPECT_TRUE(uf.connected(1, 2));
  EXPECT_FALSE(uf.connected(1, 0));
  EXPECT_EQ(uf.rank(1), 2);


  // Now we have 2 groups with 2 and 3 sizes. After the join all the
  // elements will belong to the single group (with a rank 5)
  EXPECT_TRUE(uf.join(0, 2));
  EXPECT_EQ(uf.rank(1), 5);
}


