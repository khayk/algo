#pragma once

#include <vector>
#include <string>

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
 */
std::vector<int> countSubarrays(const std::vector<int>& arr);


/**
 * @brief  A bracket is any of the following characters: (, ), {, }, [, or ].
 *
 * A sequence of brackets is said to be balanced if the following conditions are
 * met:
 *    - The sequence is empty, or
 *    - The sequence is composed of two or more non-empty sequences, all of
 * which are balanced, or
 *    - The first and last brackets of the sequence are matching, and the
 * portion of the sequence without the first and last elements is balanced.
 *
 * Determine whether each sequence of brackets is balanced
 *
 * @param str  An input string
 *
 * @return  true If a string is balanced, otherwise, false
 */
bool isBracketsBalanced(const std::string_view str);


/**
 * @brief  Given a list logs, where logs[i] represents the i-th log message
 *         formatted as a string "{function_id}:{"start" | "end"}:{timestamp}"
 *
 * @param n  Number of function
 * @param logs  The log records
 *
 * Constraints:
 *
 *    1 <= n <= 100
 *    1 <= logs.length <= 500
 *    0 <= function_id < n
 *    0 <= timestamp <= 109
 *    No two start events will happen at the same timestamp.
 *    No two end events will happen at the same timestamp.
 *    Each function has an "end" log for each "start" log.
 *
 * @return  Return the exclusive time of each function in an array, where the
 *          value at the ith index represents the exclusive time for the function
 *          with ID i.
 */
std::vector<int> exclusiveTime(int n, const std::vector<std::string>& logs);

}  // namespace alg