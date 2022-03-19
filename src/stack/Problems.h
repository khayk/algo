#pragma once

#include <vector>

namespace alg {

/**
 * @brief Given two integer arrays pushed and popped each with distinct values.
 *
 * @param pushed  An array representing push sequence
 * @param popped  An array representing pop sequence
 *
 * @return true if this could have been the result of a sequence of push and pop
 *         operations on an initially empty stack, or false otherwise.
 *
 * @ref @leetcode, @medium
 */
bool validateStackSequences(const std::vector<int>& pushed,
                            const std::vector<int>& popped);


/**
 * @brief  You are given an array arr of N integers. For each index i, you are
 *         required to determine the number of contiguous subarrays that fulfill
 *         the following conditions:
 *
 * - The value at index i must be the maximum element in the contiguous subarrays,
 * - These contiguous subarrays must either start from or end on index i.
 *
 * The size of array is between [1, 10^6]
 *
 * @param arr Is a non-empty list of unique integers that range between 1 to 10^9
 *
 * @return An array where each index i contains an integer denoting the maximum
 *         number of contiguous subarrays of arr[i]
 *
 * @ref @facebook
 */
std::vector<int> countSubarrays(const std::vector<int>& arr);

}  // namespace alg