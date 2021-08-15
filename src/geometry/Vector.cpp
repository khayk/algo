#include "Vector.h"

namespace alg {

template <>
const float Vector2<float>::EPSILON = 1e-06f;

template <>
const double Vector2<double>::EPSILON = 1e-08;

}  // namespace alg