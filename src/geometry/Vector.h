#pragma once

namespace alg {

template <typename Real>
class Vector2 {
  Real tuple_[2]{};

 public:
  static const Real EPSILON;

  Vector2() = default;

  Vector2(Real x, Real y) {
    tuple_[0] = x;
    tuple_[1] = y;
  }

  Vector2(const Vector2& v) = default;

  Real x() const noexcept {
    return tuple_[0];
  }

  Real y() const noexcept {
    return tuple_[1];
  }

  Real& x() noexcept {
    return tuple_[0];
  }

  Real& y() noexcept {
    return tuple_[1];
  }

  Vector2& operator+=(const Vector2& v) noexcept {
    x() += v.x();
    y() += v.y();

    return *this;
  }

  Vector2& operator-=(const Vector2& v) noexcept {
    x() -= v.x();
    y() -= v.y();

    return *this;
  }

  template <typename U>
  Vector2& operator*=(const U scalar) noexcept {
    x() *= scalar;
    y() *= scalar;

    return *this;
  }

  template <typename U>
  Vector2& operator/=(const U scalar) {
    if (std::abs(scalar) <= Vector2::EPSILON) {
      throw std::runtime_error("Division to zero");
    }

    x() /= scalar;
    y() /= scalar;

    return *this;
  }

  Real length() const noexcept {
    return std::sqrt(squaredLength());
  }

  Real squaredLength() const noexcept {
    return x() * x() + y() * y();
  }

  Real dot(const Vector2& v) const noexcept {
    return x() * v.x() + y() * v.y();
  }

  Real cross(const Vector2& v) const noexcept {
    return x() * v.y() - y() * v.x();
  };

  Vector2& normalize() noexcept {
    const auto l = length();

    if (std::abs(l) > Vector2::EPSILON) {
      x() /= l;
      y() /= l;
    }

    return *this;
  }
};


template <typename Real>
inline Vector2<Real> operator+(const Vector2<Real>& p,
                               const Vector2<Real>& q) noexcept {
  Vector2<Real> r = p;
  r += q;

  return r;
}


template <typename Real>
inline Vector2<Real> operator-(const Vector2<Real>& p,
                               const Vector2<Real>& q) noexcept {
  Vector2<Real> r = p;
  r -= q;

  return r;
}


template <typename Real, typename U>
inline Vector2<Real> operator*(const Vector2<Real>& p,
                               const U scalar) noexcept {
  Vector2<Real> r = p;
  r *= scalar;

  return r;
}


template <typename Real, typename U>
inline Vector2<Real> operator*(const U scalar,
                               const Vector2<Real>& p) noexcept {
  Vector2<Real> r = p;
  r *= scalar;

  return r;
}

}  // namespace alg
