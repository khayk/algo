#pragma once

#include <cstddef>
#include <type_traits>
#include <vector>

namespace alg {

/**
 * @brief Given a set of `n` items numbered from 1 up to `n`, each with a weight `w[i]` and a value `v[i]`, along with a maximum weight capacity W.
 * Maximize sum for `v[i]*x[i]` where sum of `w[i]*x[i] <= W` and `x[i]` is from the set {0, 1}.
 * Here `x[i]` represents the number of instances of item `i` to include in the knapsack
 *
 * @param profits  The array of profits
 * @param weights  The array of weights
 * @param capacity  The knapsack capacity
 *
 * @return T  The maximum value that can be obtains within the given constraints
 */
template <typename T, typename U, typename = std::enable_if_t<std::is_unsigned_v<T>>>
T zeroOneKnapsack(const std::vector<T>& profits, const std::vector<T>& weights, U capacity) {
  // Invalid input
  if (capacity == 0 || profits.size() == 0 || profits.size() != weights.size()) {
    return 0;
  }

  const auto n = profits.size();
  const auto W = static_cast<size_t>(capacity);
  std::vector<std::vector<T>> m(profits.size(), std::vector<T>(capacity + 1, 0));

  for (size_t i = 0; i < n; ++i) {
    m[i][0] = 0;
  }

  for (size_t i = 0; i <= W; ++i) {
    if (weights[0] <= i) {
      m[0][i] = profits[0];
    }
  }

  for (size_t i = 1; i < n; ++i) {
    for (size_t w = 0; w <= W; ++w) {
      if (weights[i] > w) {
        m[i][w] = m[i - 1][w];
      }
      else {
        m[i][w] = std::max(m[i - 1][w], m[i - 1][w - weights[i]] + profits[i]);
      }
    }
  }

  return m.back().back();
}

} // namespace alg