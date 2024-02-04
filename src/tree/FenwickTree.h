#pragma once

#include <vector>

namespace alg {

/**
 * @brief  Fenwick tree, know also as binary indexed tree.
 *
 * Space complexity is O(N)
 */
template <typename T>
class FenwickTree {
  std::vector<T> nums_;
  std::vector<T> bits_;

  constexpr size_t complement(const size_t i) const noexcept { return ~i + 1; }

  constexpr size_t parent(const size_t i) const noexcept {
    return i - (i & complement(i));
  }

  constexpr size_t next(const size_t i) const noexcept {
    return i + (i & complement(i));
  }

 public:
  /**
   * @brief Initializes a tree with an initial input data
   *
   * @param nums An input numbers
   *
   * @note Time complexity is O(N * log(N))
   */
  explicit FenwickTree(const std::vector<T>& nums)
      : nums_(nums.size(), 0), bits_(nums_.size() + 1, 0) {
    for (size_t i = 0; i < nums_.size(); ++i) {
      update(i, nums[i]);
    }
  }

  /**
   * @brief Update value at position i with a new value
   *
   * @param i An index of the original array
   * @param value A new value at given index
   *
   * @note Time complexity is O(log(N))
   */
  void update(size_t i, const T& value) {
    auto delta = value - nums_[i];

    auto j = i + 1;
    while (j < bits_.size()) {
      bits_[j] += delta;
      j = next(j);
    }

    nums_[i] = value;
  }

  /**
   * @brief  Returns sum of input array elements from range [0, i] inclusive
   *
   * @param i  The index of the input array
   *
   * @note Time complexity is O(log(N))
   */
  T sum(size_t i) const noexcept {
    ++i;
    T s = 0;

    while (i > 0) {
      s += bits_[i];
      i = parent(i);
    }

    return s;
  }

  /**
   * @brief  Returns sum of array elements from range [l, r] inclusive
   *
   * @param l  The start of the range
   * @param r  The end of the range
   *
   * @note Time complexity is O(log(N))
   */
  T rangeSum(size_t l, size_t r) const { return sum(r) - sum(l - 1); }
};

}  // namespace alg