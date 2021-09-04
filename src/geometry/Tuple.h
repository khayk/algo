#pragma once

#include <iosfwd>

namespace alg {

template <typename T>
class Tuple2 {

 public:
  Tuple2() noexcept = default;
  Tuple2(const Tuple2& t) noexcept = default;
  ~Tuple2() = default;

  operator const T*() const noexcept;
  operator T*() noexcept;
  const T& operator[](int i) const noexcept;
  T& operator[](int i) noexcept;

  inline Tuple2& operator=(const Tuple2& other) noexcept;

  /**
   * @brief  Comparison.
   */
  bool operator<(const Tuple2<T>& other) const noexcept;
  bool operator>(const Tuple2<T>& other) const noexcept;
  bool operator==(const Tuple2<T>& other) const noexcept;
  bool operator!=(const Tuple2<T>& other) const noexcept;

 protected:
  T tuple_[2]{};
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Tuple2<T>& t);

}  // namespace alg

#include "Tuple.inl"