#pragma once

#include <vector>

namespace alg {
namespace {

template <typename T, typename Cmp>
int64_t binarySearch(const std::vector<T>& v, T key, int64_t low, int64_t high,
                     const Cmp& cmp) {
  while (low < high) {
    auto mid = (high + low) / 2;

    if (cmp(key, v[mid])) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return low;
}

}  // namespace

/**
 * @brief  Implementation of classic binary search algorithm
 *
 * @param v An input array sorted in a ascending order
 * @param key The key to search inside an array
 *
 * @return  Return true if the key is found, otherwise false
 */
template <typename T>
bool binarySearch(const std::vector<T>& v, T key) {
  const auto i = binarySearch(v, key, 0, v.size() - 1, std::less_equal<T>());

  return i >= 0 && i < static_cast<int64_t>(v.size()) && v[i] == key;
}


template <typename T>
int64_t lowerBound(const std::vector<T>& v, T key) {
  return binarySearch(v, key, 0, v.size(), std::less_equal<T>());
}


template <typename T>
int64_t upperBound(const std::vector<T>& v, T key) {
  return binarySearch(v, key, 0, v.size(), std::less<T>());
}


template <typename T>
int64_t occurences(const std::vector<T>& v, T key) {
  return upperBound(v, key) - lowerBound(v, key);
}

}  // namespace alg