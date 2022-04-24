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

namespace {
using Group = std::vector<int>;

void combineFriends(const std::vector<int>& friends, size_t tableSize,
                    size_t pos, Group& group, std::vector<Group>& groups) {
  if (group.size() == tableSize) {
    groups.push_back(group);
  } else if (pos < friends.size()) {
    // leave
    combineFriends(friends, tableSize, pos + 1, group, groups);

    // take
    Group newGroup = group;
    newGroup.push_back(friends[pos]);

    combineFriends(friends, tableSize, pos + 1, newGroup, groups);
  }
}

}  // namespace

std::vector<std::vector<int>> findDinnerParties(const std::vector<int>& friends,
                                                size_t tableSize) {
  // Awesome implementation, see detailed explanation here
  // https://www.youtube.com/watch?v=3teHU4n-czU

  Group group;
  std::vector<Group> groups;
  combineFriends(friends, tableSize, 0, group, groups);

  return groups;
}

}  // namespace alg