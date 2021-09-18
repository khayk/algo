#pragma once

#include <vector>

namespace alg {

template <typename T>
bool binarySearch(const std::vector<T>& v, T key, size_t low, size_t high)
{
  if (low > high) return false;
  if (high > v.size()) return false;

  std::ignore = key;

  return false;
}

template <typename T>
bool binarySearch(const std::vector<T>& v, T key) {
  return binarySearch(v, key, 0, v.size() - 1);
}

}  // namespace alg