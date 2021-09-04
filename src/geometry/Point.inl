namespace alg {

template <typename Real>
inline Point2<Real>::Point2(Real x, Real y) noexcept {
  tuple_[0] = x;
  tuple_[1] = y;
}

template <typename Real>
inline Point2<Real>::Point2(const Tuple2<Real>& t) noexcept {
  tuple_[0] = t[0];
  tuple_[1] = t[1];
}

template <typename Real>
inline Real Point2<Real>::x() const noexcept {
  return tuple_[0];
}

template <typename Real>
inline Real Point2<Real>::y() const noexcept {
  return tuple_[1];
}

template <typename Real>
inline Real& Point2<Real>::x() noexcept {
  return tuple_[0];
}

template <typename Real>
inline Real& Point2<Real>::y() noexcept {
  return tuple_[1];
}

template <typename Real>
inline std::ostream& operator<<(std::ostream& out, const Point2<Real>& p) {
  out << '(' << p.x() << ", " << p.y() << ')';

  return out;
}

} // namespace alg