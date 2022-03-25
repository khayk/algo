#pragma once

#include <string>
#include <array>

namespace alg {

/**
 * @brief  You are given two strings s and t. You can select any substring of
 * string `s` and rearrange the characters of the selected substring. Determine
 * the minimum length of the substring of `s` such that string `t` is a
 * substring of the selected substring.
 *
 * @param s  Non-empty string
 * @param t  Non-empty string
 *
 * The length of the strings is less than 1,000,000 characters each
 *
 * @return The minimum length of the substring of `s`. If it is not possible,
 *         return -1
 */
int minimumLengthSubstring(const std::string_view s, const std::string_view t);

}  // namespace alg