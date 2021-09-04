#pragma once

#include "Line.h"

namespace alg {

enum IntersectionType { kEmpty, kPoint, kSegment, kRay, kLine };

template <typename Real>
bool contains(const Line2<Real>& l, const Vector2<Real>& v);

template <typename Real>
bool contains(const Line2<Real>& l, const Point2<Real>& p);

template <typename Real>
IntersectionType intersect(const Line2<Real>& l0, const Line2<Real> l1,
                           Point2<Real>& p);

}  // namespace alg
