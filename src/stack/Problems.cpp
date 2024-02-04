#include "Problems.h"

#include <stack>
#include <charconv>

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


std::vector<int> exclusiveTime(int n, const std::vector<std::string>& logs) {
  struct Log {
    int id{0};
    int timestamp{0};
  };

  auto parse = [](std::string_view s, bool& isEnd) {
    Log l;

    auto p = s.find_first_of(':', 0);
    auto tmp = s.substr(0, p);

    std::from_chars(tmp.data(), tmp.data() + tmp.size(), l.id);
    s.remove_prefix(p + 1);
    p = s.find_first_of(':', 0);
    tmp = s.substr(0, p);

    if (tmp == "end") {
      isEnd = true;
    }

    s.remove_prefix(p + 1);
    std::from_chars(s.data(), s.data() + s.size(), l.timestamp);

    return l;
  };

  std::stack<Log> st;
  std::vector<int> times(n, 0);

  for (const auto& log : logs) {
    bool isEnd = false;
    const auto l = parse(log, isEnd);

    if (!isEnd) {
      st.push(l);
    } else {
      int timeAdded = l.timestamp - st.top().timestamp + 1;
      times[l.id] += timeAdded;
      st.pop();

      if (!st.empty()) {
        times[st.top().id] -= timeAdded;
      }
    }
  }

  return times;
}


size_t largestRectangleInHistogram(const std::vector<size_t>& heights) {
  using ValueType = std::pair<size_t, size_t>;
  std::stack<ValueType, std::vector<ValueType>> s;
  size_t area = 0;

  for (size_t i = 0; i < heights.size(); ++i) {
    size_t start = i;
    while (!s.empty() && s.top().second > heights[i]) {
      auto [idx, height] = s.top();
      size_t width = i - idx;
      s.pop();

      area = std::max(area, height * width);
      start = idx;
    }

    s.emplace(start, heights[i]);
  }

  while (!s.empty()) {
    auto [idx, height] = s.top();
    size_t width = heights.size() - idx;
    s.pop();
    area = std::max(area, height * width);
  }

  return area;
}

}  // namespace alg