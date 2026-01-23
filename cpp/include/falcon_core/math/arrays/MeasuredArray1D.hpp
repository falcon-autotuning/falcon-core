/**
 * @file MeasuredArray1D.hpp
 * @brief Defines the MeasuredArray1D template for FalconCore.
 */

#pragma once

#include "falcon_core/export.h"
#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

/**
 * @brief Array type for measured data, derived from BaseArray.
 */
class FALCON_CORE_CPP_API MeasuredArray1D : public MeasuredArray,
                                            public Is1D<double> {
 public:
  using value_type = double;
  MeasuredArray1D();
  MeasuredArray1D(const generic::FArraySP<double>& arr);
  MeasuredArray1D(const MeasuredArraySP& arr);
  MeasuredArray1D(const xt::xarray<double>& arr);
  MeasuredArray1D(xt::xarray<double>&& arr) noexcept;
  static std::shared_ptr<MeasuredArray1D> zeros(
      const std::vector<size_t>& shape) {
    return std::make_shared<MeasuredArray1D>(xt::zeros<double>(shape));
  }
  static std::shared_ptr<MeasuredArray1D> empty(
      const std::vector<size_t>& shape) {
    return std::make_shared<MeasuredArray1D>(xt::empty<double>(shape));
  }
  // Arithmetic operators
  std::shared_ptr<MeasuredArray1D> operator+(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator+(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator+(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<MeasuredArray1D> operator-(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator-(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator-(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> operator-() const;

  std::shared_ptr<MeasuredArray1D> operator*(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator*(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator*(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> operator/(const double other) const;

  std::shared_ptr<MeasuredArray1D> operator/(const int other) const;

  std::shared_ptr<MeasuredArray1D> operator/(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray1D> operator^(const double other) const;

  std::shared_ptr<MeasuredArray1D> abs() const;
  /**
   * @brief Return the minimum value of the array.
   */
  double min() const;

  std::shared_ptr<MeasuredArray1D> min(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;
  /**
   * @brief Return the maximum value of the array.
   */
  double max() const;

  std::shared_ptr<MeasuredArray1D> max(
      const std::shared_ptr<MeasuredArray1D>& other) const;

  std::shared_ptr<MeasuredArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped MeasuredArray1D.
   */
  std::shared_ptr<MeasuredArray1D> reshape(
      const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped MeasuredArray1D.
   */
  std::shared_ptr<MeasuredArray1D> flip(size_t axis) const;
  /**
   * @brief Return the gradient of the data along a given axis.
   *
   * Computes the gradient along the specified axis using finite differences:
   * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
   * - For boundary points, uses forward (first element) or backward (last
   * element) difference.
   *
   * @param axis The axis to compute the gradient.
   * @return The gradient FArray.
   */
  generic::FArraySP<double> gradient(size_t axis) const;
  /**
   * @brief Return the gradient of the data along all axes.
   *
   * Computes the gradient for each axis of the array using finite differences:
   * - For interior points, uses central difference: (f(x+1) - f(x-1)) / 2
   * - For boundary points, uses forward (first element) or backward (last
   * element) difference.
   *
   * @return A vector of FArray gradients (one for each axis).
   */
  generic::ListSP<generic::FArray<double>> gradient() const;

 protected:
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    ar(cereal::base_class<MeasuredArray>(this));
  }
};
using MeasuredArray1DSP = std::shared_ptr<MeasuredArray1D>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
