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


template <typename T>
int findRotation(const std::vector<T>& a) {
  int n = static_cast<int>(a.size());
  int low = 0;
  int high = n - 1;

  while (low < high) {
    int mid = (low + high) / 2;

    // Check if element (mid+1) is minimum element.
    if (mid < high && a[mid + 1] < a[mid]) return (mid + 1);

    // Check if mid itself is minimum element
    if (mid > low && a[mid] < a[mid - 1]) return mid;

    if (a[high] > a[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return low;
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

  int k = findRotation(a);

  return maxInSortedRightShifted(a, k);
}

}  // namespace alg