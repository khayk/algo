#pragma once

#include "Line.h"

namespace alg {

/**
 * @brief  Rotate v by theta degrees CCW w.r.t origin (0, 0)
 *
 * @param v
 * @param theta
 *
 * @return
 */
template <typename Real>
Vector2<Real> rotate(const Vector2<Real>& v, Real theta);


/**
 * @brief  Return angle between vectors p and q in radians
 *
 * @param p
 * @param q
 *
 * @return
 */
template <typename Real>
Real angle(const Vector2<Real>& p, const Vector2<Real>& q);


/**
 * @brief  Returns true if `q` is on the left side of the `p`,
 *         otherwise false
 *
 * @param p
 * @param q
 */
template <typename Real>
bool ccw(const Vector2<Real>& p, const Vector2<Real>& q);

template <typename Real>
bool collinear(const Vector2<Real>& p, const Vector2<Real>& q,
               const Vector2<Real>& r);

enum IntersectionType { kEmpty, kPoint, kSegment, kRay, kLine };

template <typename Real>
bool contains(const Line2<Real>& l, const Vector2<Real>& v);

template <typename Real>
bool parallel(const Line2<Real>& l0, const Line2<Real> l1);

template <typename Real>
IntersectionType intersect(const Line2<Real>& l0, const Line2<Real> l1,
                           Vector2<Real>& p);

}  // namespace alg
