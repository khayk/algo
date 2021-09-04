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

typedef Math<float> Mathf;
typedef Math<double> Mathd;

}  // namespace alg