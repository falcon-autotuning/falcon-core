#pragma once

#include <stdexcept>

#include "falcon_core/math/arrays/ControlArray.hpp"

namespace falcon_core {
namespace math {
namespace arrays {

class ControlArray1D : public ControlArray<double> {
 public:
  using ControlArray<double>::ControlArray;

  ControlArray1D(const typename ControlArray<double>::MatrixType &data)
      : ControlArray<double>(data) {
    if (!is_1d()) {
      throw std::invalid_argument(
          "Data for ControlArray1D must be 1-dimensional.");
    }
  }
};
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
