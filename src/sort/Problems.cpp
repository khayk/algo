#include "Problems.h"

#include <algorithm>
#include <numeric>
#include <queue>

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

}  // namespace alg