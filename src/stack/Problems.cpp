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


std::vector<int> countSubarrays(const std::vector<int>& arr) {
  std::stack<int> s;
  std::vector<int> ans(arr.size(), 0);
  std::vector<int> tmp = ans;

  auto n = static_cast<int>(arr.size());

  for (int i = 0; i < n; ++i) {
    while (!s.empty() && arr[s.top()] <= arr[i]) {
      ans[i] += ans[s.top()];
      s.pop();
    }

    s.push(i);
    ++ans[i];
  }

  // clear stack
  while (!s.empty()) {
    s.pop();
  }

  for (int i = n - 1; i >= 0; --i) {
    while (!s.empty() && arr[s.top()] <= arr[i]) {
      tmp[i] += tmp[s.top()];
      ans[i] += tmp[s.top()];
      s.pop();
    }

    s.push(i);
    ++tmp[i];
  }

  return ans;
}


// Put helper function inside namespace to prevent us from linking issues in the
// long run
namespace {

bool isOpeningBracket(const char bracket) {
  switch (bracket) {
    case '(':
    case '{':
    case '[':
      return true;
    default:
      return false;
  }
}

char matchingPair(const char bracket) {
  switch (bracket) {
    case '(':
      return ')';
    case '{':
      return '}';
    case '[':
      return ']';
    default:
      return bracket;
  }
}

} // namespace


bool isBracketsBalanced(const std::string_view str) {
  std::stack<char> openings;

  for (const auto ch : str) {
    if (isOpeningBracket(ch)) {
      openings.push(ch);
    } else {
      if (openings.empty() || ch != matchingPair(openings.top())) {
        return false;
      }

      openings.pop();
    }
  }

  return openings.empty();
}


}  // namespace alg