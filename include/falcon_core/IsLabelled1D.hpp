#pragma once

#include "falcon_core/BaseArray.hpp"
#include <stdexcept>

namespace falcon_core {

// This is a mixin-like template class.
// The Derived class is expected to have a `get_array()` method.
template <class Derived> class IsLabelled1D {
public:
  double get_start() const {
    const auto &array = static_cast<const Derived *>(this)->get_array();
    if (!array.is_1d()) {
      throw std::runtime_error("Array is not 1D");
    }
    // Eigen vectors can be row or column vectors. data() gives linear access.
    return array.data()(0);
  }
};

} // namespace falcon_core
