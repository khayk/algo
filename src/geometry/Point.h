#pragma once

#include "Tuple.h"

namespace alg {

template <typename Real>
class Point2 {
 public:
  Point2() noexcept = default;
  Point2(Real x, Real y) noexcept;
  Point2(const Tuple2<Real>& t) noexcept;
  Point2(const Point2& p) noexcept = default;

  /**
   * @brief  Coordinate access.
   */
  Real x() const noexcept;
  Real y() const noexcept;
  Real& x() noexcept;
  Real& y() noexcept;

 protected:
  using Tuple2::tuple_;
};

template <typename Real>
std::ostream& operator<<(std::ostream& out, const Point2<Real>& v);

}  // namespace alg