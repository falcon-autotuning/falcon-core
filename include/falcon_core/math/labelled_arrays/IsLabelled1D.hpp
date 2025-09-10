/**
 * @file IsLabelled1D.hpp
 * @brief Mixin for 1D labelled arrays.
 */

#pragma once

#include <stdexcept>

#include "falcon_core/math/arrays/BaseArray.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

/// @brief Mixin for 1D labelled arrays.
/// @tparam Derived The derived class type (must provide get_array()).
template <class Derived>
class IsLabelled1D {
 public:
  /// @brief Get the starting value of the 1D array.
  /// @throws std::runtime_error if array is not 1D.
  double get_start() const {
    const auto &array = static_cast<const Derived *>(this)->get_array();
    if (array.dimension() != 1) {
      throw std::runtime_error("Array is not 1D");
    }
    return array.data()[0];
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
