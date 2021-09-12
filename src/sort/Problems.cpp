#include "Problems.h"

#include <algorithm>

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

}  // namespace alg