#include "Problems.h"

#include <unordered_set>

namespace alg {

size_t numberOfWays(const std::vector<int>& arr, int k) {
  std::unordered_multiset<int> hash;
  size_t pairs = 0;

  for (const auto& a : arr) {
    const auto count = hash.count(a);

    if (count > 0) {
      pairs += count;
    }

    hash.emplace(k - a);
  }

  return pairs;
}

}  // namespace alg