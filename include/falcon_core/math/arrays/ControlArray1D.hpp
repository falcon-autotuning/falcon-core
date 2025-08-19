#pragma once

#include <stdexcept>

#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

class ControlArray1D : public ControlArray<double> {
 public:
  using ControlArray<double>::ControlArray;

  ControlArray1D(const typename ControlArray<double>::MatrixType& data)
      : ControlArray<double>(data) {
    if (!this->is_1d()) {
      throw std::invalid_argument(
          "Data for ControlArray1D must be 1-dimensional.");
    }
  }

 private:
  friend class cereal::access;
  ControlArray1D() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray<double>>(this));
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core

using namespace falcon_core::math::arrays;
CEREAL_REGISTER_TYPE(falcon_core::math::arrays::ControlArray1D)
CEREAL_REGISTER_POLYMORPHIC_RELATION(falcon_core::generic::Song, falcon_core::math::arrays::ControlArray1D)
