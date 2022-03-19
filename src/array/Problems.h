#pragma once

#include <vector>
#include <array>
#include <type_traits>

namespace alg {

/**
 * @brief  Given an array of n numbers, the task is to calculate the maximum
 *         subarray sum, i.e., the largest possible sum of a sequence of
 *         consecutive values in the array
 *
 * @param a  An input array
 *
 * @return  The resulting sum
 */

template <typename T>
int maximumSubarraySum(const std::vector<T>& arr) {
  static_assert(std::is_integral_v<T>, "T must integer type");

  T best{}, sum{};

  for (const auto& a: arr) {
    sum = std::max(a, sum + a);
    best = std::max(best, sum);
  }

  return best;
}


/**
 * @brief  Is valid sudoku
 * @param board The board of size 9x9 with some numbers.
 * @return true, if the invariance of the sudoku rules is not violated, otherwise false
 */
bool isValidSudoku(const std::vector<std::vector<char>>& board);

}  // namespace alg