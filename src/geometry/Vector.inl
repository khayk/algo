
template <typename Real>
inline Vector2<Real>::Vector2(Real x, Real y) {
  tuple_[0] = x;
  tuple_[1] = y;
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
bool Vector2<Real>::operator<(const Vector2& other) const noexcept {
  if (fabs(x() - other.x()) > Math<Real>::kEpsilon) {
    return x() < other.x();
  }

  return y() < other.y();
}

template <typename Real>
inline bool Vector2<Real>::operator==(const Vector2& other) const noexcept {
  return fabs(x() - other.x()) < Math<Real>::kEpsilon &&
         fabs(y() - other.y()) < Math<Real>::kEpsilon;
}

template <typename Real>
inline bool Vector2<Real>::operator!=(const Vector2<Real>& other) const noexcept {
  return !(*this).operator==(other);
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

template <typename Real>
inline Vector2<Real> rotate(const Vector2<Real>& v, Real theta) {
  Real rad = Math<Real>::kDegToRad * theta;  // multiply theta with PI / 180.0

  return Vector2<Real>(v.x() * cos(rad) - v.y() * sin(rad),
                       v.x() * sin(rad) + v.y() * cos(rad));
}

