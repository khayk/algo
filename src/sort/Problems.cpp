#include "Problems.h"

#include <algorithm>
#include <numeric>
#include <queue>
#include <iostream>

namespace alg {

uint32_t computeHIndex(std::vector<uint32_t>& citations) {
  std::sort(std::begin(citations), std::end(citations), std::greater());
  uint32_t i = 0;

  while (i < citations.size()) {
    if (i >= citations[i]) {
      break;
    }
    ++i;
  }

  return i;
}


bool balancedSplitExists(const std::vector<int>& arr) {
  const auto sum = std::accumulate(arr.begin(), arr.end(), 0);

  if (sum % 2 != 0) {
    return false;
  }

  // A max queue, the largets element is on the top
  std::priority_queue<int> q(arr.begin(), arr.end());

  const auto target = sum / 2;
  auto smallest = std::numeric_limits<int>::max();
  int64_t currSum = 0;

  while (!q.empty() && currSum < target) {
    smallest = std::min(smallest, q.top());
    currSum += q.top();
    q.pop();
  }

  // This ensures, each element in the left side of the  split is smaller then
  // each element in the right
  if (!q.empty() && q.top() == smallest) {
    return false;
  }

  return currSum == target;
}


int64_t bucketId(int x, size_t w) {
  return x < 0 ? (x + 1) / w - 1 : x / w;
}


bool containsNearbyAlmostDuplicate(std::vector<int>& nums, size_t k, size_t t) {
  const auto w = static_cast<size_t>(static_cast<int64_t>(t) + 1);
  std::unordered_map<size_t, int> d;

  for (size_t i = 0; i < nums.size(); ++i) {
    auto m = bucketId(nums[i], w);

    // Check if bucket m is empty, each bucket may contain at most one element
    if (d.count(m) > 0) {
      return true;
    }

    // Check the neighbor buckets for almost duplicate
    auto it = d.find(m - 1);
    if (it != d.end() && abs(nums[i] - it->second) < w) {
      return true;
    }

    it = d.find(m + 1);
    if (it != d.end() && abs(nums[i] - it->second) < w) {
      return true;
    }

    // Now bucket m is empty and no almost duplicate in neighbor buckets
    d.emplace(m, static_cast<int64_t>(nums[i]));
    if (i >= k) {
      d.erase(bucketId(nums[i - k], w));
    }
  }

  return false;
}

}  // namespace alg