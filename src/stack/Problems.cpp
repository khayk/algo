#include "Problems.h"

#include <stack>

namespace alg {

bool validateStackSequences(const std::vector<int>& pushed,
                            const std::vector<int>& popped) {
  std::stack<int> s;
  size_t j = 0;

  for (const auto i : pushed) {
    s.push(i);

    while (!s.empty() && j < popped.size() && popped[j] == s.top()) {
      s.pop();
      ++j;
    }
  }

  return s.empty();
}

}  // namespace alg