#pragma once

#include <vector>

namespace alg {

template <typename T>
using Array = std::vector<T>;

template <typename T>
using Matrix = Array<Array<T>>;

using ArrayInts = Array<int>;
using MatrixInts = Matrix<int>;

using ArrayChars = Array<char>;
using MatrixChars = Matrix<char>;

}  // namespace alg
