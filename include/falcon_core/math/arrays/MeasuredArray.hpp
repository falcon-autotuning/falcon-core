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

  // Add any measured-specific methods if needed
};

template <typename T>
using MeasuredArraySP = std::shared_ptr<MeasuredArray<T>>;

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
