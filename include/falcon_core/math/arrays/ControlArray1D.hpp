/**
 * @file ControlArray1D.hpp
 * @brief Defines the ControlArray1D class for FalconCore.
 */

#pragma once

#include <stdexcept>

#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

/// @brief 1D control array, enforces 1D shape at construction.
class ControlArray1D : public ControlArray<double> {
 public:
  ControlArray1D(const xt::xarray<double>& data) : ControlArray<double>(data) {
    if (this->xtensor().dimension() != 1) {
      throw std::invalid_argument("ControlArray1D must be 1-dimensional.");
    }
  }
  ControlArray1D() = default;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray<double>>(this));
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::arrays::ControlArray1D)
