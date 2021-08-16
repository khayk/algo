#include "Math.h"
#include <float.h>
#include <cmath>

namespace alg {

// clang-format off
template <> const float Math<float>::kEpsilon = 1e-09f;
template <> const float Math<float>::kZeroTolerance = 1e-06f;
template <> const float Math<float>::kPi = static_cast<float>(4.0 * atan(1.0));
template <> const float Math<float>::kTwoPi = 2.0f * Math<float>::kPi;
template <> const float Math<float>::kHalfPi = 0.5f * Math<float>::kPi;
template <> const float Math<float>::kInvPi = 1.0f / Math<float>::kPi;
template <> const float Math<float>::kDegToRad = Math<float>::kPi / 180.0f;
template <> const float Math<float>::kRadToDeg = 180.0f / Math<float>::kPi;

template <> const double Math<double>::kEpsilon = 1e-12f;
template <> const double Math<double>::kZeroTolerance = 1e-08;
template <> const double Math<double>::kPi = static_cast<double>(4.0 * atan(1.0));
template <> const double Math<double>::kTwoPi = 2.0 * Math<double>::kPi;
template <> const double Math<double>::kHalfPi = 0.5 * Math<double>::kPi;
template <> const double Math<double>::kInvPi = 1.0 / Math<double>::kPi;
template <> const double Math<double>::kDegToRad = Math<double>::kPi / 180.0;
template <> const double Math<double>::kRadToDeg = 180.0 / Math<double>::kPi;
// clang-format on

}  // namespace alg
