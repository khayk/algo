#pragma once

namespace alg {

template <typename Real>
class Math {
 public:
  static const Real kEpsilon;
  static const Real kZeroTolerance;
  static const Real kPi;
  static const Real kTwoPi;
  static const Real kHalfPi;
  static const Real kInvPi;
  static const Real kDegToRad;
  static const Real kRadToDeg;
};

using Mathf = Math<float>;
using Mathd = Math<double>;

}  // namespace alg