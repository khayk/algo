#include <limits>
#include <cmath>
#include <ostream>

namespace alg {

template <typename Real>
inline Vector2<Real>::Vector2(Real x, Real y) noexcept {
  tuple_[0] = x;
  tuple_[1] = y;
}

template <typename Real>
inline Vector2<Real>::Vector2(const Tuple2<Real>& t) noexcept {
  tuple_[0] = t[0];
  tuple_[1] = t[1];
}

template <typename Real>
inline Real Vector2<Real>::x() const noexcept {
  return tuple_[0];
}

template <typename Real>
inline Real Vector2<Real>::y() const noexcept {
  return tuple_[1];
}

template <typename Real>
inline Real& Vector2<Real>::x() noexcept {
  return tuple_[0];
}

template <typename Real>
inline Real& Vector2<Real>::y() noexcept {
  return tuple_[1];
}

template <typename Real>
inline Vector2<Real> Vector2<Real>::operator+(
    const Vector2<Real>& v) const noexcept {
  return Vector2<Real>(x() + v.x(), y() + v.y());
}

template <typename Real>
inline Vector2<Real> Vector2<Real>::operator-(
    const Vector2& v) const noexcept {
  return Vector2(x() - v.x(), y() - v.y());
}

template <typename Real>
inline Vector2<Real> Vector2<Real>::operator*(Real scalar) const noexcept {
  return Vector2(scalar * x(), scalar * y());
}

template <typename Real>
inline Vector2<Real> Vector2<Real>::operator/(Real scalar) const noexcept {
  Vector2 result(x(), y());
  result /= scalar;

  return result;
}

template <typename Real>
inline Vector2<Real> Vector2<Real>::operator-() const noexcept {
  return Vector2(-x(), -y());
}

template <typename Real>
inline Vector2<Real>& Vector2<Real>::operator+=(const Vector2& v) noexcept {
  x() += v.x();
  y() += v.y();

  return *this;
}

template <typename Real>
inline Vector2<Real>& Vector2<Real>::operator-=(const Vector2& v) noexcept {
  x() -= v.x();
  y() -= v.y();

  return *this;
}

template <typename Real>
inline Vector2<Real>& Vector2<Real>::operator*=(const Real scalar) noexcept {
  x() *= scalar;
  y() *= scalar;

  return *this;
}

template <typename Real>
inline Vector2<Real>& Vector2<Real>::operator/=(const Real scalar) noexcept {
  if (scalar != static_cast<Real>(0)) {
    const Real invScalar = (static_cast<Real>(1)) / scalar;
    x() *= invScalar;
    y() *= invScalar;
  } else {
    x() = std::numeric_limits<Real>::max();
    y() = std::numeric_limits<Real>::max();
  }

  return *this;
}

template <typename Real>
inline Real Vector2<Real>::length() const noexcept {
  return std::sqrt(squaredLength());
}

template <typename Real>
inline Real Vector2<Real>::squaredLength() const noexcept {
  return x() * x() + y() * y();
}

template <typename Real>
inline Real Vector2<Real>::dot(const Vector2& v) const noexcept {
  return x() * v.x() + y() * v.y();
}

template <typename Real>
inline Real Vector2<Real>::cross(const Vector2& v) const noexcept {
  return x() * v.y() - y() * v.x();
};

template <typename Real>
inline Vector2<Real>& Vector2<Real>::normalize() noexcept {
  const auto l = length();

  if (l != static_cast<Real>(0)) {
    x() /= l;
    y() /= l;
  }

  return *this;
}

template <typename Real>
inline Vector2<Real> Vector2<Real>::perp() const noexcept {
  return Vector2(y(), -x());
}

template <typename Real>
inline Vector2<Real> operator*(const Real scalar,
                               const Vector2<Real>& p) noexcept {
  return p * scalar;
}

template <typename Real>
inline std::ostream& operator<<(std::ostream& out, const Vector2<Real>& v) {
  out << '(' << v.x() << ", " << v.y() << ')';
  return out;
}

}  // namespace alg