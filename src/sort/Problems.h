#pragma once

#include <limits>
#include <vector>
#include <tuple>

namespace alg {

/**
 * @brief  Partitions a given vector by the random pivot in the range [l, h]
 *
 * @param v  An input array
 * @param l  The start of the range (lower one)
 * @param h  The end of the range (bigger one)
 *
 * @return  An index (i), where all elements in the [l, i) are smaller then v[i]
 *          and all elements in (i, h] are not smaller then v[i]
 */
template <typename T>
size_t partition(std::vector<T>& v, size_t l, size_t h) {
  if (l >= h) return l;

  // select a random pivot
  size_t firstHigh = l;
  size_t p = l + rand() % (h - l);
  std::swap(v[p], v[h]);
  p = h;

  for (auto i = l; i < h; ++i) {
    if (v[i] < v[p]) {
      std::swap(v[firstHigh], v[i]);
      ++firstHigh;
    }
  }

  std::swap(v[p], v[firstHigh]);

  return firstHigh;
}


/**
 * @brief  Returns a k-th smallest element in the array. The elements of the
 * array can be moved from their's original positions. The complexity of this
 * algorithm is O(n)
 *
 * @param v  An input array
 * @param k  The value of k
 *
 * @return  k-th smallest element.
 */
template <typename T>
T kthElement(std::vector<T>& v, size_t k) {
  if (k >= v.size())
    throw std::system_error(std::make_error_code(std::errc::invalid_argument));

  size_t n = v.size();
  size_t l = 0;
  size_t h = v.size() - 1;

  while (n != k) {
    n = partition(v, l, h);

    if (n < k) {
      l = n + 1;
    } else if (n > k) {
      h = n - 1;
    }
  }

  return v[k];
}


/**
 * @brief  Let S be an unsorted array of n integers. Give an algorithm that finds
 * the pair x, y from S that maximizes |x - y|. Your algorithm must run in O(n)
 * worst-case time.
 *
 * @param v An input array
 *
 * @refs skiena 4-2,
 *
 * @return x and y elements
 */
template <typename T>
std::tuple<T, T> maxDifference(const std::vector<T>& v) {
  T min = std::numeric_limits<T>::max();
  T max = std::numeric_limits<T>::min();

  for (const auto& e : v) {
    if (e < min) min = e;
    if (e > max) max = e;
  }

  return std::make_tuple(max, min);
}


/**
 * @brief  Give an efficient algorithm to take the array of citation counts
 * (each count is a non-negative integer) of a researcher's papers, and compute
 * the researcher's h-index. By definition, a scientist has index h if h of his
 * or her n papers have been cited at least h times, while the other n - h
 * papers each have no more than h citations.
 *
 * @param citations  citation counts, array of non-negative integers
 *
 * @refs skiena 4-7, leetcode 274,
 *
 * @return h-index of the researcher
 */
uint32_t computeHIndex(std::vector<uint32_t>& citations);


/**
 * @brief  Design an O(n) algorithm that, given a list of n elements, finds all
 * the elements that appear more than n/2 times in the list. If such an element
 * doesn't exists, returns the minimum value of type T.
 *
 * @return The element, that appears more then n/2 times
 */
template <typename T>
T majorityElement(const std::vector<T>& elems)
{
  T candidate = 0;
  size_t count = 0;

  for (const auto& e : elems) {
    if (count == 0) {
      candidate = e;
    }

    if (candidate == e) {
      ++count;
    } else {
      --count;
    }
  }

  count = std::count(std::begin(elems), std::end(elems), candidate);

  if (static_cast<size_t>(count) > elems.size() / 2) {
    return candidate;
  }

  return std::numeric_limits<T>::min();
}


/**
 * @brief  Design an O(n) algorithm that, given a list of n elements, finds all
 * the elements that appear more than n/4 times.
 *
 * @return The element, that appears more then n/4 times
 */
template <typename T>
std::vector<T> quarterElements(const std::vector<T>& elems) {
  std::vector<T> v = elems;
  std::vector<T> out;

  auto select = [&out, &v](T candidate) {
    auto count = std::count(std::begin(v), std::end(v), candidate);

    if (static_cast<size_t>(count) > v.size() / 4) {
      if (std::find(std::begin(out), std::end(out), candidate) ==
          std::end(out)) {
        out.push_back(candidate);
      }
    }
  };

  // There can be 3 candidates, check all of them
  auto p1 = kthElement(v, 1 * v.size() / 4);
  select(p1);

  auto p2 = kthElement(v, 2 * v.size() / 4);
  select(p2);

  auto p3 = kthElement(v, 3 * v.size() / 4);
  select(p3);

  return out;
}


}  // namespace alg