#pragma once

#include <string>

namespace alg {

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

/**
 * @brief  Returns an encryped version of s.
 *
 * When you encrypt a string S, you start with an initially-empty resulting
 * string R and append characters to it as follows:
 *
 * 1. Append the middle character of S (if S has even length, then we define the
 *    middle character as the left-most of the two central characters)
 * 2. Append the encrypted version of the substring of S that's to the left of
 *    the middle character (if non-empty)
 * 3. Append the encrypted version of the substring of S that's to the right of
 *    the middle character (if non-empty)
 *
 * @param s An input string
 * @return An encrypted version of the string
 *
 * @refs facebook
 */
std::string findEncryptedWord(const std::string& s) {
  std::string result;
  result.reserve(s.size());
  encryptWordHelper(s, result);

  return result;
}

}  // namespace alg
