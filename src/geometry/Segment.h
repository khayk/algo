#pragma once

#include "Vector.h"

namespace alg {

template <typename Real>
class Segment {
 public:
  Segment(Vector2<Real> p0, Vector2<Real> p1);
  Segment(Vector2<Real> center, Vector2<Real> dir, Real extent);

 private:
  Vector2<Real> p0;
  Vector2<Real> p1;
};

}  // namespace alg