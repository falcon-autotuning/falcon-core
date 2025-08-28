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
    if (!array.is_1d()) {
      throw std::runtime_error("Array is not 1D");
    }
    // Eigen vectors can be row or column vectors. data() gives linear access.
    return array.data()(0);
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
