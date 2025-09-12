/**
 * @file MeasuredArray.hpp
 * @brief Defines the MeasuredArray template for FalconCore.
 */

#pragma once

#include "falcon_core/generic/FArray.hpp"
namespace falcon_core::math::arrays {

/**
 * @brief Array type for measured data, derived from BaseArray.
 */
class MeasuredArray : public generic::FArray<double> {
 public:
  using value_type = double;
  MeasuredArray();
  MeasuredArray(const generic::FArraySP<double>& arr);
  MeasuredArray(const xt::xarray<double>& arr);
  MeasuredArray(xt::xarray<double>&& arr) noexcept;
  MeasuredArray(const MeasuredArray&)                = default;
  MeasuredArray(MeasuredArray&&) noexcept            = default;
  MeasuredArray& operator=(const MeasuredArray&)     = default;
  MeasuredArray& operator=(MeasuredArray&&) noexcept = default;
  static std::shared_ptr<MeasuredArray> zeros(
      const std::vector<size_t>& shape) {
    return std::make_shared<MeasuredArray>(xt::zeros<double>(shape));
  }
  static std::shared_ptr<MeasuredArray> empty(
      const std::vector<size_t>& shape) {
    return std::make_shared<MeasuredArray>(xt::empty<double>(shape));
  }
  // Arithmetic operators
  std::shared_ptr<MeasuredArray> operator+(const double other) const;

  std::shared_ptr<MeasuredArray> operator+(const int other) const;

  std::shared_ptr<MeasuredArray> operator+(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<MeasuredArray> operator-(const double other) const;

  std::shared_ptr<MeasuredArray> operator-(const int other) const;

  std::shared_ptr<MeasuredArray> operator-(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> operator-() const;

  std::shared_ptr<MeasuredArray> operator*(const double other) const;

  std::shared_ptr<MeasuredArray> operator*(const int other) const;

  std::shared_ptr<MeasuredArray> operator*(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> operator/(const double other) const;

  std::shared_ptr<MeasuredArray> operator/(const int other) const;

  std::shared_ptr<MeasuredArray> operator/(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> operator^(const double other) const;

  std::shared_ptr<MeasuredArray> abs() const;

  std::shared_ptr<MeasuredArray> min(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> min(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<MeasuredArray> max(
      const std::shared_ptr<MeasuredArray>& other) const;

  std::shared_ptr<MeasuredArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped MeasuredArray.
   */
  std::shared_ptr<MeasuredArray> reshape(
      const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped MeasuredArray.
   */
  std::shared_ptr<MeasuredArray> flip(size_t axis) const;
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
};
using MeasuredArraySP = std::shared_ptr<MeasuredArray>;
}  // namespace falcon_core::math::arrays
