#pragma once

#include <vector>
#include <cassert>

namespace alg {

template <typename T>
class UnionFind {
  static_assert(std::is_unsigned_v<T>, "T must be unsigned type");

  std::vector<T> group_;
  std::vector<size_t> rank_;

 public:
  explicit UnionFind(size_t size) : group_(size, 0), rank_(size, 1) {
    for (size_t i = 0; i < size; ++i) {
      group_[i] = static_cast<T>(i);
      rank_[i] = 1;
    }
  }


  T find(T i) noexcept {
    assert(i < group_.size());

    // While finding a head do path compression
    while (group_[i] != i) {
      group_[i] = group_[group_[i]];
      i = group_[i];
    }

    return i;
  }


  bool join(const T x, const T y) noexcept {
    assert(x < group_.size());
    assert(y < group_.size());

    const auto gx = find(x);
    const auto gy = find(y);

    if (gx == gy) {
      return false;
    }

    // Located in different groups, merge them into the largest group
    const auto rx = rank_[gx];
    const auto ry = rank_[gy];
    const auto newRank = rx + ry;

    if (rx > ry) {
      group_[gy] = gx;
    } else {
      group_[gx] = gy;
    }

    rank_[gy] = newRank;
    rank_[gx] = newRank;

    return true;
  }


  bool connected(const T x, const T y) const noexcept {
    const auto gx = find(x);
    const auto gy = find(y);

    return gx == gy;
  }


  size_t rank(const T x) const noexcept {
    return ranks_[find(x)];
  }
};

}  // namespace alg