#include "Problems.h"
#include <unordered_map>
#include <stack>

namespace alg {

namespace {

using HashMapIntBool = std::unordered_map<int, bool>;

void encryptWordHelper(const std::string_view s, std::string& result) {
  if (s.size() <= 2) {
    result.append(s);
    return;
  }

  size_t middle = s.size() / 2;
  if (s.size() % 2 == 0) {
    --middle;
  }

  result.push_back(s[middle]);
  encryptWordHelper(s.substr(0, middle), result);
  encryptWordHelper(s.substr(middle + 1), result);
}


bool getChangeHalper(const int targetMoney,
                     const std::vector<int>& denominations,
                     HashMapIntBool& memo) {
  std::stack<int> s;

  s.push(targetMoney);

  while (!s.empty()) {
    int remnant = s.top();

    if (remnant == 0) {
      memo[remnant] = true;
      return true;
    }

    if (const auto it = memo.find(remnant); it != memo.end()) {
      return it->second;
    }

    memo[remnant] = false;

    for (const auto& denom : denominations) {
      if (remnant < denom) {
        continue;
      }

      if (remnant % denom == 0) {
        return true;
      }

      s.push(remnant - denom);
    }

    s.pop();
  }

  return false;
}


} // namespace

std::string findEncryptedWord(const std::string& s) {
  std::string result;
  result.reserve(s.size());
  encryptWordHelper(s, result);

  return result;
}


bool canGetExactChange(const int targetMoney,
                       const std::vector<int>& denominations) {
  HashMapIntBool memo;

  return getChangeHalper(targetMoney, denominations, memo);
}


}  // namespace alg