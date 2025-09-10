/**
 * @file MeasuredArray.hpp
 * @brief Defines the MeasuredArray template for FalconCore.
 */

#pragma once

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/**
 * @brief Array type for measured data, derived from BaseArray.
 */
class MeasuredArray : public BaseArray<double> {
 public:
  MeasuredArray();
  MeasuredArray(const xt::xarray<double>& arr);
  MeasuredArray(xt::xarray<double>&& arr) noexcept;

 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseArray<double>>(this));
  }
};

using MeasuredArraySP = std::shared_ptr<MeasuredArray>;

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
