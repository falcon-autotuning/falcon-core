#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
class MeasuredArray : public BaseArray<T> {
 public:
  using BaseArray<T>::BaseArray;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseArray<T>>(this));
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::arrays::MeasuredArray<double>)
