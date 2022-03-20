#include <gtest/gtest.h>
#include "list/List.h"

using namespace alg;

TEST(ListTests, CreateList) {
  auto* ls = createList({1, 2, 3, 4});

  std::string dumped = dumpList(ls, ',');
  EXPECT_EQ(dumped, "1,2,3,4");

  deleteList(ls);
}


TEST(ListTests, ReverseList) {
  auto* ls = createList({1, 2, 3, 4});
  ls = reverseList(ls);

  std::string dumped = dumpList(ls, ',');
  EXPECT_EQ(dumped, "4,3,2,1");

  deleteList(ls);
}