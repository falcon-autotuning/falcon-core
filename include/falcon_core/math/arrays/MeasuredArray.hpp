/**
 * @file MeasuredArray.hpp
 * @brief Defines the MeasuredArray template for FalconCore.
 */

#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/// @brief Array type for measured data, derived from BaseArray.
/// @tparam T Element type.
template <typename T>
class MeasuredArray : public BaseArray<T> {
 public:
  /// @brief Inherit constructors from BaseArray.
  using BaseArray<T>::BaseArray;

 private:
  friend class cereal::access;
  /// @brief Serialization method for cereal.
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseArray<T>>(this));
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::MeasuredArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::arrays::MeasuredArray<double>)
#endif
