#include "Vector.h"

namespace alg {

// clang-format off
template <> const Vector2<float> Vector2<float>::kZero(0.0f, 0.0f);
template <> const Vector2<float> Vector2<float>::kUnitX(1.0f, 0.0f);
template <> const Vector2<float> Vector2<float>::kUnitY(0.0f, 1.0f);
template <> const Vector2<float> Vector2<float>::kOne(1.0f, 1.0f);

template <> const Vector2<double> Vector2<double>::kZero(0.0, 0.0);
template <> const Vector2<double> Vector2<double>::kUnitX(1.0, 0.0);
template <> const Vector2<double> Vector2<double>::kUnitY(0.0, 1.0);
template <> const Vector2<double> Vector2<double>::kOne(1.0, 1.0);
// clang-format on

}  // namespace alg