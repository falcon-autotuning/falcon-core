#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
class MeasuredArray : public BaseArray<T> {
 public:
  using BaseArray<T>::BaseArray;
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
