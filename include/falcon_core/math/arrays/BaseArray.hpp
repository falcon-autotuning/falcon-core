/**
 * @file BaseArray.hpp
 * @brief Defines the BaseArray template for FalconCore.
 */

#pragma once

#include <memory>

#include "falcon_core/generic/FArray.hpp"

namespace falcon_core::math::arrays {

template <typename T>
class BaseArray : public generic::FArray<T> {
 public:
  BaseArray() = default;
  BaseArray(const xt::xarray<T>& arr) : generic::FArray<T>(arr) {}
  BaseArray(xt::xarray<T>&& arr) noexcept : generic::FArray<T>(arr) {}
  explicit BaseArray(const std::vector<size_t>& shape)
      : generic::FArray<T>(shape) {}
};

template <typename T>
using BaseArraySP = std::shared_ptr<BaseArray<T>>;

}  // namespace falcon_core::math::arrays
