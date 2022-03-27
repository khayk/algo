#include "Problems.h"
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

}  // namespace alg