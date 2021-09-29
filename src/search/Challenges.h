#pragma once

#include <stdexcept>

namespace alg {

/**
 * @brief Suppose you are given a sorted array A of size n that has been
 * circularly shifted k positions to the right. For example,
 * [35, 42, 5, 15, 27, 29] is a sorted array that has been circularly shifted
 * k = 2 positions, while [27, 29, 35, 42, 5, 15] has been shifted k = 4 positions.
 * Give an O(1) algorithm to find the largest number in A.
 *
 * @param a Sorted array A of size n that has been circularly shifted k positions to the right.
 *
 * @return The max element
 */
template <typename T>
T maxInSortedRightShifted(const std::vector<T>& a, int k)
{
  if (a.empty()) {
    throw std::runtime_error("Provide a non-empty array.");
  }

  if (k > 0) return a[k - 1];

  return a[k + a.size() - 1];
}

/**
 * @brief Give an O(lg n) algorithm to find the largest number in A
 *
 * @param a Sorted array A of size n that has been circularly shifted k positions to the right.
 *
 * @return The max element
 */
template <typename T>
T maxInSortedRightShifted(const std::vector<T>& a)
{
  if (a.empty()) {
    throw std::runtime_error("Provide a non-empty array.");
  }

  int l = 0;
  int r = static_cast<int>(a.size()) - 1;

  while (l < r) {
    int mid = (l + r) / 2;
    int off = a[l] > a[r] ? 0 : 1;

    if (a[l] < a[mid]) {
      l = mid + off;
    } else {
      r = mid + off;
    }
  }

  return a[l];
}

}  // namespace alg