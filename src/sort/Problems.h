#pragma once

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
T findKthSmallest(const std::vector<T>& data, size_t k) {

}

}  // namespace alg