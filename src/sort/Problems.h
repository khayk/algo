#pragma once

#include <limits>
#include <vector>
#include <tuple>

namespace alg {

template <typename T>
size_t partition(std::vector<T>& v, size_t l, size_t h) {
  if (l >= h) return l;

  // select a random pivot
  size_t firstHigh = l;
  size_t p = l + rand() % (h - l);
  std::swap(v[p], v[h]);
  p = h;

  for (auto i = l; i < h; ++i) {
    if (v[i] < v[p]) {
      std::swap(v[firstHigh], v[i]);
      ++firstHigh;
    }
  }

  std::swap(v[p], v[firstHigh]);

  return firstHigh;
}


template <typename T>
T kthElement(std::vector<T>& v, size_t k) {
  if (k >= v.size())
    throw std::system_error(std::make_error_code(std::errc::invalid_argument));

  size_t n = v.size();
  size_t l = 0;
  size_t h = v.size() - 1;

  while (n != k) {
    n = partition(v, l, h);

    if (n < k) {
      l = n + 1;
    } else if (n > k) {
      h = n - 1;
    }
  }

  return v[k];
}


/**
 * @brief  Let S be an unsorted array of n integers. Give an algorithm that
 *         finds the pair x, y from S that maximizes |x - y|. Your algorithm must run
 *         in O(n) worst-case time.
 *
 * @param v  An input array
 *
 * @return  x and y elements
 */
template <typename T>
std::tuple<T, T> maxDifference(const std::vector<T>& v) {
  T min = std::numeric_limits<T>::max();
  T max = std::numeric_limits<T>::min();

  for (const auto& e : v) {
    if (e < min) min = e;
    if (e > max) max = e;
  }

  return std::make_tuple(max, min);
}


}  // namespace alg