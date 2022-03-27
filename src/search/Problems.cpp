#include "Problems.h"

#include <numeric>
#include <queue>
#include <cmath>

namespace alg {

int getBillionUsersDay(const std::vector<float>& growthRates) {
  const auto fn = [&growthRates](int days) {
    long double s = 0;

    for (const auto& v : growthRates) {
      long double x = v;
      s += std::pow(x, days);
    }

    return s;
  };

  long double target = 10e8;

  int maxDays = 1;
  while (fn(maxDays) < target) {
    maxDays *= 2;
  }

  int days = 0;

  for (int j = maxDays / 2; j > 0; j /= 2) {
    if (days + j < maxDays && fn(days + j) < target) {
      days += j;
    }
  }

  return days + 1;
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