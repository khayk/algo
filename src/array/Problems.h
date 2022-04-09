#pragma once

#include <vector>
#include <array>
#include <type_traits>
#include <queue>

namespace alg {

/**
 * @brief  Given an array of n numbers, the task is to calculate the maximum
 *         subarray sum, i.e., the largest possible sum of a sequence of
 *         consecutive values in the array
 *
 * @param a  An input array
 *
 * @return  The resulting sum
 */

template <typename T>
int maximumSubarraySum(const std::vector<T>& arr) {
  static_assert(std::is_integral_v<T>, "T must integer type");

  T best{}, sum{};

  for (const auto& a: arr) {
    sum = std::max(a, sum + a);
    best = std::max(best, sum);
  }

  return best;
}


/**
 * @brief  Is valid sudoku
 * @param board The board of size 9x9 with some numbers.
 * @return true, if the invariance of the sudoku rules is not violated, otherwise false
 */
bool isValidSudoku(const std::vector<std::vector<char>>& board);


/**
 * @brief Get access to the underlying conteainer used by a priority queue
 */
template <class T, class S, class C>
const S& underlyingContainer(std::priority_queue<T, S, C>& q) {

  struct RevealInternals : private std::priority_queue<T, S, C> {
    static const S& container(std::priority_queue<T, S, C>& q) {
      return q.*&RevealInternals::c;
    }
  };

  return RevealInternals::container(q);
}


/**
 * @brief  Given a list of n integers arr[0..(n-1)]. Compute a list
 * output[0..(n-1)] such that, for each index i (between 0 and n-1, inclusive),
 * output[i] is equal to the product of the three largest elements out of
 * arr[0..i] (or equal to -1 if i < 2, as arr[0..i] then includes fewer than
 * three elements)
 *
 * @ref @facebook (Largest Triple Products)
 *
 * @param arr An input array
 *
 * @return A list of n integers output[0..(n-1)], as described above.
 */
template <typename T,
          typename = std::enable_if_t<std::is_arithmetic_v<T>>>
std::vector<T> largestTripleProducts(const std::vector<T>& arr) {
  // Priority queue, to hold top max 3 elements, descovered at the given time
  std::priority_queue<T, std::vector<T>, std::greater<T>> mq;
  std::vector<T> out;
  out.reserve(arr.size());

  const std::vector<T>& c = underlyingContainer(mq);

  for (const auto& a : arr) {
    mq.push(a);

    if (mq.size() > 3) {
      // During the pop, we will remove the smallest element,
      // leaving 3 largest elements discovered so far
      mq.pop();
    }

    T product = -1;

    if (mq.size() > 2) {
      product = static_cast<T>(1);

      for (const auto& x : c) {
        product *= x;
      }
    }

    out.push_back(product);
  }

  return out;
}


/**
 * @brief  A family of frogs in a pond are traveling towards dry land to
 *         hibernate. They hope to do so by hopping across a trail of N lily
 * pads, numbered from 1 to N in order.  There are F frogs, numbered from 1 to
 * F. Frog [i] is currently perched atop lily pad P[i]. No two frogs are
 * currently on the  same lily pad. Lily pad N is right next to the shore, and
 * none of the frogs are  initially on lily pad N. Each second, one frog may hop
 * along the trail towards lily pad N. When a frog hops, it moves to the nearest
 * lily pad after its current lily pad which is not currently occupied by
 * another frog (hopping over any other frogs on intermediate lily pads along
 * the way). If this causes it to reach lily pad NN, it will immediately exit
 * onto the shore. Multiple frogs may not simultaneously hop during the same
 * second.
 *
 * @param numPads  Number of total pads (2 <= N <= 10^12)
 * @param frogs  Pads number where frog i resides initially (1 <= F <= 500000)
 *
 * @return  Minimum number of seconds required for all frogs to reach the shore
 *
 * @ref @facebook
 */
int64_t minimumHops(int64_t numPads, std::vector<int64_t> frogs);

}  // namespace alg