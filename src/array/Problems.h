#pragma once

#include <vector>
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
int maximumSubarraySum(const std::vector<T>& a) {
  static_assert(std::is_integral_v<T>, "T must integer type");

  T best{}, sum{};

  for (const auto& i: a) {
    sum = std::max(i, sum + i);
    best = std::max(best, sum);
  }

  return best;
}

}  // namespace alg