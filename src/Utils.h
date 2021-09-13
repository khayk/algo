#pragma once

#include "Types.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

namespace alg {

/**
 * @brief  Trims tailing whitespaces from the string
 *
 * @param str
 */
inline void trimRight(std::string& str) {
  while (!str.empty() && std::isspace(str.back())) {
    str.pop_back();
  }
}


/**
 * @brief  Retruns the number of characters to represent given number
 * @tparam T
 * @param number
 * @return
 */
template <typename T>
size_t numDigits(T number)
{
  size_t digits = 0;

  if (number < 0) {
    digits = 1;  // remove this line if '-' counts as a digit
  }

  do {
    number /= 10;
    ++digits;
  } while (number != 0);

  return digits;
}


template <typename T>
void output(const Array<T>& a, std::ostream& dest, size_t width = 0)
{
  if (a.size() >= 100) return;

  for (const auto& e : a) {
    if (width) {
      dest << std::setw(width) << e;
    } else {
      dest << e << ' ';
    }
  }

  dest << '\n';
}


template <typename T>
void output(const Array<T>& a, std::string& dest, size_t width = 0) {
  std::ostringstream oss;
  output(a, oss, width);
  dest = oss.str();
}


/**
 * @brief  Prints the given array on the console.
 *
 * @param a An input array
 * @param width Width of the field to put the number
 */
template <typename T>
void print(const Array<T>& a, size_t width = 0)
{
  output(a, std::cout, width);
}


/**
 * @brief  Prints the given matrix on the console.
 *
 * @param m
 */
template <typename T>
void print(const Matrix<T>& m, size_t width = 0) {
  if (m.size() > 30) return;

  if (!width) {
    T min = std::numeric_limits<T>::max();
    T max = std::numeric_limits<T>::min();

    for (const auto& a : m) {
      max = std::max(max, *std::max_element(std::begin(a), std::end(a)));
      min = std::min(min, *std::min_element(std::begin(a), std::end(a)));
    }

    width = std::max(numDigits(max), numDigits(min)) + 1;
  }

  for (const auto& a : m) {
    print(a, width);
  }
}

}  // namespace alg
