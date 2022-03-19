#include "Problems.h"

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

      if (rows[i][num]) return false;
      rows[i][num] = true;

      if (cols[j][num]) return false;
      cols[j][num] = true;

      if (squares[squareRow][squareCol][num]) return false;
      squares[squareRow][squareCol][num] = true;
    }
  }

  return true;
}

}  // namespace alg