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
 * @refs skiena 5-1
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
 * @refs skiena 5-1
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


/**
 * @brief A sorted array of size n contains distinct integers between 1 and
 * n + 1, with one element missing. Give an O(log n) algorithm to find the missing
 * integer, without using any extra space.
 *
 * @param a  A sorted array of size n with distinct integers between 1 and n + 1
 *
 * @return
 */
template <typename T>
T missingInSortedArray(const std::vector<T>& a)
{
  if (a.empty()) {
    throw std::runtime_error("Provide a non-empty array.");
  }

  int n = static_cast<int>(a.size());
  int l = 0;
  int h = n - 1;

  while (l < h) {
    int m = (l + h) / 2;

    if (a[m] - m == 1) {
      l = m + 1;
    } else {
      h = m;
    }
  }

  if (a[l] - l == 1) {
    return a[l] + 1;
  }

  return a[l] - 1;
}


/**
 * @brief Given two sorted arrays A and B of size n and m respectively, find the
 * median of the n + m elements. The overall run time complexity should be
 * O(log(m + n)).
 *
 * @param a  Array of size n
 * @param b  Array of size m
 *
 * @refs skiena 5-8:[5]
 *
 * @return The median of the n + m elements
 */
template <typename T>
T medianOfSortedArrays(const std::vector<T>& a, const std::vector<T>& b)
{
  std::ignore = a;
  std::ignore = b;
  //int an = static_cast<int>(a.size());
  //int la = 0;
  //int ha = an - 1;

  //int bn = static_cast<int>(b.size());
  //int lb = 0;
  //int hb = bn - 1;

  //int m = (an + ab) / 2 - 1;

  //while (la + lb != m) {

  //}

  return T();
}


}  // namespace alg