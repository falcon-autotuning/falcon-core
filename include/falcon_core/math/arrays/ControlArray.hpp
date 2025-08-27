/**
 * @file ControlArray.hpp
 * @brief Defines the ControlArray template for FalconCore.
 */

#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/// @brief Array type for control data, derived from BaseArray.
/// @tparam T Element type.
template <typename T>
class ControlArray : public BaseArray<T> {
 public:
  /// @brief Default constructor.
  ControlArray() : BaseArray<T>() {}
  /// @brief Copy constructor.
  ControlArray(const ControlArray& other) : BaseArray<T>(other) {}
  /// @brief Construct from matrix data.
  ControlArray(const typename BaseArray<T>::MatrixType& data)
      : BaseArray<T>(data) {}

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
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<float>)
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseArray<float>,
    falcon_core::math::arrays::ControlArray<float>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::math::arrays::BaseArray<double>,
    falcon_core::math::arrays::ControlArray<double>)
#endif
