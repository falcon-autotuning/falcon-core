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
  using BaseArray<T>::BaseArray;
  using BaseArray<T>::xtensor;
  using BaseArray<T>::operator==;
  using BaseArray<T>::operator!=;
  using BaseArray<T>::operator+=;
  using BaseArray<T>::operator-=;
  using BaseArray<T>::operator*=;
  using BaseArray<T>::operator/=;
  using BaseArray<T>::shape;
  using BaseArray<T>::size;
  using BaseArray<T>::dimension;
  using BaseArray<T>::data;
  using BaseArray<T>::begin;
  using BaseArray<T>::end;
  using BaseArray<T>::cbegin;
  using BaseArray<T>::cend;
  using BaseArray<T>::view;
  using BaseArray<T>::operator();

  // Add any control-specific methods if needed
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

// Cereal registration for ControlArray<double>
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray<double>)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::math::arrays::BaseArray<double>, falcon_core::math::arrays::ControlArray<double>)
