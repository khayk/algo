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
 */
bool validateStackSequences(const std::vector<int>& pushed,
                            const std::vector<int>& popped);

}  // namespace alg