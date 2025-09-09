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
// class ControlArray1D : public ControlArray<double> {
//  public:
//   ControlArray1D(const typename ControlArray<double>::MatrixType& data);
//
//  private:
//   friend class cereal::access;
//   ControlArray1D();
//   template <class Archive>
//   void serialize(Archive& ar);
// };
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
