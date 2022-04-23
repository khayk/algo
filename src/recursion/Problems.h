#pragma once

#include <string>
#include <vector>

namespace alg {

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
 */
std::string findEncryptedWord(const std::string& s);


/**
 * @brief  Given a list of the available denominations, determine if it's
 * possible to receive exact change for an amount of money targetMoney.
 *
 * @param targetMoney  The target money
 * @param denominations  The denomirations
 *
 * 1 <= |denominations| <= 100
 * 1 <= denominations[i] <= 10,000
 * 1 <= targetMoney <= 1,000,000
 *
 * @return true if it's possible to receive exactly targetMoney given the
 * available denominations, and false if not.
 */
bool canGetExactChange(const int targetMoney, const std::vector<int>& denominations);

}  // namespace alg
