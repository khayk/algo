#pragma once

#include <vector>
#include <queue>

namespace alg {

/**
 * @brief  You're given a list of n integers arr, which represent elements in a
 * queue (in order from front to back). You're also given an integer x, and must
 * perform x iterations of the following 3-step process:
 *
 * 1. Pop x elements from the front of queue (or, if it contains fewer than x
 *    elements, pop all of them)
 * 2. Of the elements that were popped, find the one with the largest value (if
 *    there are multiple such elements, take the one which had been popped the
 *    earliest), and remove it
 * 3. For each one of the remaining elements that were popped (in the order they
 *    had been popped), decrement its value by 1 if it's positive (otherwise, if
 *    its value is 0, then it's left unchanged), and then add it back to the queue
 *
 * Compute a list of x integers output, the ith of which is the 1-based index in
 * the original array of the element which had been removed in step 2 during the
 * ith iteration.
 *
 * Queue Removals
 *
 * @param arr
 * @param x
 *
 * @return The array of indices that will be removed
 *
 * @refs facebook
 */
std::vector<int> findPositions(const std::vector<int>& arr, int x) {
  std::vector<int> output;

  struct Data {
    int value;
    int index;
  };

  // Initialize queue with bookkeeping stuff
  std::queue<Data> q;
  std::queue<Data> tmp;
  int i = 0;
  for (const auto& a : arr) {
    q.push({a, ++i});
  }

  for (i = 0; i < x; ++i) {
    int toPop = x;
    Data largest = {-1, 0};

    while (!q.empty() && toPop > 0) {
      const auto& current = q.front();

      if (largest.value < current.value) {
        largest = current;
      }

      tmp.push(current);
      q.pop();
      --toPop;
    }

    while (!tmp.empty()) {
      if (tmp.front().value == largest.value) {
        largest.value = -1;
        output.push_back(largest.index);
      } else {
        if (tmp.front().value > 0) {
          --(tmp.front().value);
        }
        q.push(tmp.front());
      }

      tmp.pop();
    }
  }

  return output;
}

}  // namespace alg
