#include "Problems.h"
#include "Types.h"

#include <algorithm>

namespace alg {

bool isValidSudoku(const std::vector<std::vector<char>>& board) {
  using masks = std::array<bool, 9>;

  std::array<std::array<masks, 3>, 3> squares{};
  std::array<masks, 9> rows{};
  std::array<masks, 9> cols{};

  for (size_t i = 0; i < 9; ++i) {
    for (size_t j = 0; j < 9; ++j) {
      const auto ch = board[i][j];

      if (ch == '.') continue;

      // again, we can validate if the ch is a digit
      const auto num = static_cast<size_t>(ch - '1');

      const auto squareRow = i / 3;
      const auto squareCol = j / 3;

      if (rows[i][num]) {
        return false;
      }

      rows[i][num] = true;

      if (cols[j][num]) return false;
      cols[j][num] = true;

      if (squares[squareRow][squareCol][num]) return false;
      squares[squareRow][squareCol][num] = true;
    }
  }

  return true;
}


int64_t minimumHops(int64_t numPads, std::vector<int64_t> frogs) {

  // Acheive increasing order for pads numbers
  std::sort(frogs.begin(), frogs.end());

  std::vector<int64_t> groups;
  std::vector<int64_t> spaces;

  int64_t minimumSeconds = 0;

  auto groupBegin = frogs[0];
  auto groupSize = 1;

  for (size_t i = 1; i < frogs.size(); ++i) {
    if (frogs[i] == frogs[i - 1] + 1) {
      ++groupSize;
    } else {
      groups.push_back(groupSize);
      spaces.push_back(frogs[i] - groupBegin - groupSize);
      groupBegin = frogs[i];
      groupSize = 1;
    }
  }

  groups.push_back(groupSize);
  spaces.push_back(numPads - groupBegin - groupSize);

  for (const auto sp : spaces) {
    minimumSeconds += sp;
  }

  for (const auto gr : groups) {
    minimumSeconds += gr;
  }

  return minimumSeconds;
}

namespace {

using Combinations = std::vector<ArrayInts>;

void combinationSum(const size_t i, const size_t k, const size_t n,
                    const size_t sum, ArrayInts& comb, Combinations& res) {
  if (sum > n || comb.size() > k) {
    return;
  }

  if (sum == n && comb.size() == k) {
    res.push_back(comb);
    return;
  }

  for (int j = i; j < 10; ++j) {
    if (sum + j > n) {
      break;
    }

    comb.push_back(j);
    combinationSum(j + 1, k, n, sum + j, comb, res);
    comb.pop_back();
  }
}

}  // namespace

Combinations combinationSum(size_t numsCount, size_t targetSum) {
  Combinations res;
  ArrayInts comb;
  size_t sum = 0;
  combinationSum(1, numsCount, targetSum, sum, comb, res);

  return res;
}

}  // namespace alg