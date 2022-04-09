#include <gtest/gtest.h>
#include "array/Problems.h"

using namespace alg;

TEST(ArrayProblemsTests, MaximumSubarraySum) {
  std::vector<int> a = {-1, 2, 4, -3, 5, 2, -5, 2};
  EXPECT_EQ(maximumSubarraySum(a), 10);

  a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(maximumSubarraySum(a), 6);

  // Edge cases
  EXPECT_EQ({}, 0);
  EXPECT_EQ({7}, 7);
  EXPECT_EQ({-1}, -1);
}


TEST(ArrayProblemsTests, IsValidSudoku) {
  std::vector<std::vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  EXPECT_TRUE(isValidSudoku(board));

  board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  EXPECT_FALSE(isValidSudoku(board));
}


TEST(ArrayProblemsTests, LargestTripleProducts) {
  std::vector<int> arr;
  std::vector<int> act;
  std::vector<int> exp;

  arr = {1, 2, 3, 4, 5};
  exp = {-1, -1, 6, 24, 60};
  act = largestTripleProducts(arr);

  EXPECT_EQ(act, exp);

  arr = {2, 4, 7, 1, 5, 3};
  exp = {-1, -1, 56, 56, 140, 140};
  act = largestTripleProducts(arr);

  EXPECT_EQ(act, exp);

  arr = {10, 1, 1, 1};
  exp = {-1, -1, 10, 10};
  act = largestTripleProducts(arr);

  EXPECT_EQ(act, exp);
}


TEST(ArrayProblemsTests, MinimumHops) {
  std::vector<int64_t> arr;
  int64_t n = 0;

  n = 3;
  arr = {1};
  EXPECT_EQ(minimumHops(n, arr), 2);

  n = 6;
  arr = {5, 2, 4};
  EXPECT_EQ(minimumHops(n, arr), 4);

  n = 20;
  arr = {3, 4, 5, 8, 9, 13, 14, 16};
  EXPECT_EQ(minimumHops(n, arr), 17);
}
