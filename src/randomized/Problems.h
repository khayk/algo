#pragma once

#include <string_view>

namespace alg {

/**
 * @brief  Given strings S and T of length n and m respectively, find the
 * shortest window in S that contains all the characters in T in expected
 * O(n + m) time.
 *
 * @param source Then input string where the lookup takes place
 * @param pattern The pattern to look for
 *
 * @refs skiena 6-5, leetcode minimum-window-substring,
 *
 * @return Pair or integer, one is an offset of the windows, the second
 * is the length in the original string. {-1, 0} will indicate not found.
 */
std::pair<size_t, size_t> minWindow(std::string_view source,
                                    std::string_view pattern);

}  // namespace alg
