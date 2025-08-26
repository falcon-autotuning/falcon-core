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
  /// @brief Construct from matrix data, must be 1D.
  /// @throws std::invalid_argument if data is not 1D.
  ControlArray1D(const typename ControlArray<double>::MatrixType& data)
      : ControlArray<double>(data) {
    if (!this->is_1d()) {
      throw std::invalid_argument(
          "Data for ControlArray1D must be 1-dimensional.");
    }
  }

 private:
  friend class cereal::access;
  /// @brief Serialization method for cereal.
  ControlArray1D() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray<double>>(this));
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

#ifndef SWIG
using namespace falcon_core::math::arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song,
                                     falcon_core::math::arrays::ControlArray1D)
#endif
