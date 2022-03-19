#pragma once

#include <vector>

namespace alg {

/**
 * @brief  Given a list of n integers arr[0..(n-1)], determine the number of
 *         different pairs of elements within it which sum to k. If an integer
 *         appears in the list multiple times, each copy is considered to be
 *         different; that is, two pairs are considered different if one pair
 *         includes  at least one array index which the other doesn't, even if
 *         they include the same values.
 *
 * @param arr An input array
 * @param k The sum of pairs
 *
 * @return The number of different pairs of elements which sum to k.
 *
 * @ref @facebook
 */
size_t numberOfWays(const std::vector<int>& arr, int k);

}  // namespace alg