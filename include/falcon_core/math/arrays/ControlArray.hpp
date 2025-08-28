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
  ControlArray();
  ControlArray(const ControlArray& other);
  ControlArray(const typename BaseArray<T>::MatrixType& data);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
