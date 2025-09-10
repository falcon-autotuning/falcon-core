/**
 * @file MeasuredArray1D.hpp
 * @brief An array of 1D measured data.
 */

#pragma once

#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core::math::arrays {

class MeasuredArray1D : public MeasuredArray, Is1D<MeasuredArray> {
 public:
  MeasuredArray1D();
  MeasuredArray1D(const xt::xarray<double>& arr);
  MeasuredArray1D(xt::xarray<double>&& arr) noexcept;
  /**
   * @brief Smooth the data using a simple moving average with the specified
   * window size.
   * @param window_size The size of the moving average window. Must be a
   * positive odd
   */
  void smooth(const size_t window_size);

 private:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<MeasuredArray>(this));
  }
};
using MeasuredArray1DSP = std::shared_ptr<MeasuredArray1D>;
}  // namespace falcon_core::math::arrays
