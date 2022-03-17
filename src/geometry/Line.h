#pragma once

#include "Vector.h"

namespace alg {

template <typename Real>
class Line2 {
 public:
  /**
   * @brief  The line is represented as P+t*D where P is the line origin, D is a
   *         unit-length direction vector, and t is any real number. The user
   *         must ensure that D is indeed unit length.
   */
  Line2() noexcept = default;
  Line2(Vector2<Real> origin, Vector2<Real> direction);

  Vector2<Real> orig;
  Vector2<Real> dir;
};

using Line2f = Line2<float>;
using Line2d = Line2<double>;

}  // namespace alg

#include "Line.inl"