#include <gtest/gtest.h>
#include "list/Problems.h"

using namespace alg;

TEST(ListProblemsTests, ReverseOperation) {
  auto* ls = createList({1, 2, 8, 9, 12, 16});
  ls = reverseOperation(ls);
  std::string dumped = dumpList(ls, ',');

  EXPECT_EQ(dumped, "1,8,2,9,16,12");
  deleteList(ls);


  ls = createList({2, 8, 9, 12, 16});
  ls = reverseOperation(ls);
  dumped = dumpList(ls, ',');

  EXPECT_EQ(dumped, "8,2,9,16,12");
  deleteList(ls);
}
