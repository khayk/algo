#pragma once

#include <vector>

namespace alg {

template <typename T>
bool binarySearch(const std::vector<T>& v, T key, size_t low, size_t high)
{
  if (low > high) return false;
  if (high > v.size()) return false;

  auto mid = (low + high) / 2;

  if (v[mid] > key) {
    return binarySearch(v, key, low, mid - 1);
  } else if (v[mid] < key) {
    return binarySearch(v, key, mid + 1, high);
  }

  return true;
}

/**
 * @brief  Implementation of classic binary search algorithm
 *
 * @param v An input array
 * @param key The key to search inside an array
 *
 * @return  Return true if the key is found, otherwise false
 */
template <typename T>
bool binarySearch(const std::vector<T>& v, T key) {
  return binarySearch(v, key, 0, v.size() - 1);
}

}  // namespace alg