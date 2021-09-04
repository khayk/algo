#include "Geometry.h"
#include "Math.h"

namespace alg {

template <typename Real>
bool contains(const Line2<Real>& l, const Vector2<Real>& v)
{
  const Vector2<Real> a = v - l.orig;

  return fabs(l.dir.cross(a)) < Math<Real>::kZeroTolerance;
}

template <typename Real>
bool contains(const Line2<Real>& l, const Point2<Real>& p)
{
  return contains(l, Vector2<Real>(p));
}

//template <typename Real>
//IntersectionType intersect(const Line2<Real>& l0, const Line2<Real> l1,
//  Point2<Real>& p)
//{
//
//}

template bool contains(const Line2d&, const Vector2d&);

}  // namespace alg