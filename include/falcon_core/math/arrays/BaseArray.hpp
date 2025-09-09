/**
 * @file BaseArray.hpp
 * @brief Defines the BaseArray template for FalconCore.
 */

#pragma once

#include "falcon_core/generic/FArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

template <typename T>
class BaseArray : public FArray<T> {
 public:
  using FArray<T>::FArray;
  using FArray<T>::xtensor;
  using FArray<T>::operator==;
  using FArray<T>::operator!=;
  using FArray<T>::operator+=;
  using FArray<T>::operator-=;
  using FArray<T>::operator*=;
  using FArray<T>::operator/=;
  using FArray<T>::shape;
  using FArray<T>::size;
  using FArray<T>::dimension;
  using FArray<T>::data;
  using FArray<T>::begin;
  using FArray<T>::end;
  using FArray<T>::cbegin;
  using FArray<T>::cend;
  using FArray<T>::view;
  using FArray<T>::operator();

  // Add any additional methods for compatibility if needed
};

template <typename T>
using BaseArraySP = std::shared_ptr<BaseArray<T>>;

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
