#include "Geometry.h"
#include "Math.h"
#include <cmath>

namespace alg {

template <typename Real>
Vector2<Real> rotate(const Vector2<Real>& v, Real theta) {
  Real rad = Math<Real>::kDegToRad * theta;  // multiply theta with PI / 180.0

  return Vector2<Real>(v.x() * cos(rad) - v.y() * sin(rad),
                       v.x() * sin(rad) + v.y() * cos(rad));
}


template <typename Real>
bool contains(const Line2<Real>& l, const Vector2<Real>& v)
{
  const Vector2<Real> a = v - l.orig;

  return fabs(l.dir.cross(a)) < Math<Real>::kZeroTolerance;
}


template <typename Real>
IntersectionType intersect(const Line2<Real>& l0, const Line2<Real> l1,
  Vector2<Real>& p)
{
  IntersectionType type{IntersectionType::kEmpty};

  return type;
}

// Force template instantiation for the type double
template bool contains(const Line2d&, const Vector2d&);
template Vector2d rotate(const Vector2d& v, double theta);

}  // namespace alg