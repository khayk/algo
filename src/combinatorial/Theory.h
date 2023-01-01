#pragma once

#include <vector>

namespace alg {

namespace detail {

template <typename T, typename Callback>
void search(const std::vector<T>& set, const size_t k, std::vector<T>& subset,
            const Callback& subsetCb) {
  if (k >= set.size()) {
    subsetCb(subset);
    return;
  }

  search(set, k + 1, subset, subsetCb);
  subset.push_back(set[k]);
  search(set, k + 1, subset, subsetCb);
  subset.pop_back();
}

template <typename T, typename Callback>
void search(const std::vector<T>& set, size_t k, const Callback& subsetCb) {
  std::vector<T> subset;

  search(set, k, subset, subsetCb);
}

} // namespace detail

template <typename T>
void allSubsets(const std::vector<T>& set, std::vector<std::vector<T>>& all) {
  detail::search(
      set, 0, [&all](const std::vector<T>& subset) { all.push_back(subset); });
}

} // namespace alg