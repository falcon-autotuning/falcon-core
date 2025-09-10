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
  MeasuredArray() : BaseArray<T>() {}
  MeasuredArray(const xt::xarray<T>& arr) : BaseArray<T>(arr) {}
  MeasuredArray(xt::xarray<T>&& arr) noexcept : BaseArray<T>(arr) {}

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseArray<T>>(this));
  }
};

template <typename T>
using MeasuredArraySP = std::shared_ptr<MeasuredArray<T>>;

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
