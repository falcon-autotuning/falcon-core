/**
 * @file MeasuredArray1D.hpp
 * @brief Defines the MeasuredArray1D class for FalconCore.
 */

#pragma once

#include "falcon_core/math/arrays/MeasuredArray.hpp"
#include <stdexcept>
#include <xtensor/xarray.hpp>

namespace falcon_core {
namespace math {
namespace arrays {

class MeasuredArray1D : public MeasuredArray<double> {
 public:
  MeasuredArray1D(const xt::xarray<double>& data) : MeasuredArray<double>(data) {
    if (this->xtensor().dimension() != 1) {
      throw std::invalid_argument("MeasuredArray1D must be 1-dimensional.");
    }
  }
  MeasuredArray1D() = default;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<MeasuredArray<double>>(this));
  }
};

}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
