#pragma once

#include "Math.h"
#include "Tuple.h"

namespace alg {

template <typename Real>
class Vector2 : public Tuple2<Real> {
 public:
  Vector2() noexcept = default;
  Vector2(Real x, Real y) noexcept;
  Vector2(const Tuple2<Real>& t) noexcept;
  Vector2(const Vector2& v) noexcept = default;

  /** 
   * @brief  Coordinate access.
   */
  Real x() const noexcept;
  Real y() const noexcept;
  Real& x() noexcept;
  Real& y() noexcept;

  /** 
   * @brief  Arithmetic operations.
   */
  Vector2 operator+(const Vector2& v) const noexcept;
  Vector2 operator-(const Vector2& v) const noexcept;
  Vector2 operator*(Real scalar) const noexcept;
  Vector2 operator/(Real scalar) const noexcept;
  Vector2 operator-() const noexcept;

  /** 
   * @brief  Arithmetic updates.
   */
  Vector2& operator+=(const Vector2& v) noexcept;
  Vector2& operator-=(const Vector2& v) noexcept;
  Vector2& operator*=(const Real scalar) noexcept;
  Vector2& operator/=(const Real scalar) noexcept;

  /**
   * @brief  Vector operations.
   */
  Real length() const noexcept;
  Real squaredLength() const noexcept;
  Real dot(const Vector2& v) const noexcept;
  Real cross(const Vector2& v) const noexcept;
  Vector2& normalize() noexcept;
  Vector2 perp() const noexcept;

  static const Vector2 kZero;   //< (0, 0)
  static const Vector2 kUnitX;  //< (1, 0)
  static const Vector2 kUnitY;  //< (0, 1)
  static const Vector2 kOne;    //< (1, 1)

protected:
    using Tuple2<Real>::tuple_;
};

template <typename Real>
Vector2<Real> operator*(const Real scalar, const Vector2<Real>& v) noexcept;

template <typename Real>
std::ostream& operator<<(std::ostream& out, const Vector2<Real>& v);

/**
 * @brief  Rotate v by theta degrees CCW w.r.t origin (0, 0)
 */
template <typename Real>
Vector2<Real> rotate(const Vector2<Real>& v, Real theta);

typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

}  // namespace alg

#include "Vector.inl"