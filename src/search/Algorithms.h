#pragma once

#include <set>

namespace alg {

/**
 * @brief  Finds the element nearest to x
 *
 * @param s  A set data structure to search requested element
 * @param x  An arbitrary value
 *
 * @return  Iterator to the nearest element to x. If the set is empty, an
 *          iterator to the end() will be returned.
 */
template <typename T>
typename std::set<T>::const_iterator findNearestElement(const std::set<T>& s, const T& x) {
  if (s.empty()) {
    return s.end();
  }

  // The iterator points to the smallest element whose value is at least x
  auto it = s.lower_bound(x);

  if (it == s.begin() || s.size() == 1) {
    return s.begin();
  } else if (it == s.end()) {
    return --it;
  }

  // There are at least 2 elements
  auto prev = it;
  --prev;

  if (x - *prev < *it - x) {
    return prev;
  }

  return it;
}

}  // namespace alg