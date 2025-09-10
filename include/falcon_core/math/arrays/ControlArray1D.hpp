/**
 * @file ControlArray1D.hpp
 * @brief Defines a 1dimensional indpendant control vector for falcon.
 */

#pragma once

#include <stdexcept>

#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/Is1D.hpp"
namespace falcon_core::math::arrays {

/// @brief 1D control array, enforces 1D shape at construction.
class ControlArray1D : public ControlArray, Is1D<ControlArray> {
 public:
  ControlArray1D();
  ControlArray1D(const xt::xarray<double>& arr);
  ControlArray1D(xt::xarray<double>&& arr) noexcept;

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray>(this));
  }
};
}  // namespace falcon_core::math::arrays
