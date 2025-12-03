/**
 * @file ControlArray1D.hpp
 * @brief Defines a 1dimensional indpendant control vector for falcon.
 */

#pragma once

#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/Is1D.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

/// @brief 1D control array, enforces 1D shape at construction.
class ControlArray1D : public ControlArray, public Is1D<double> {
 protected:
  friend class cereal::access;
  ControlArray1D();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray>(this),
       principle_dimension(),
       alignment());
  }

 public:
  ControlArray1D(const xt::xarray<double>& arr);
  ControlArray1D(const generic::FArraySP<double>& arr);
  ControlArray1D(const ControlArraySP& arr);
  ControlArray1D(xt::xarray<double>&& arr) noexcept;
  // Arithmetic operators
  std::shared_ptr<ControlArray1D> operator+(const double other) const;

  std::shared_ptr<ControlArray1D> operator+(const int other) const;

  std::shared_ptr<ControlArray1D> operator+(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<ControlArray1D> operator-(const double other) const;

  std::shared_ptr<ControlArray1D> operator-(const int other) const;

  std::shared_ptr<ControlArray1D> operator-(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray1D> operator-() const;

  std::shared_ptr<ControlArray1D> operator*(const double other) const;

  std::shared_ptr<ControlArray1D> operator*(const int other) const;

  std::shared_ptr<ControlArray1D> operator/(const double other) const;

  std::shared_ptr<ControlArray1D> operator/(const int other) const;

  std::shared_ptr<ControlArray1D> operator^(const double other) const;

  std::shared_ptr<ControlArray1D> abs() const;
  /**
   * @brief Return the minimum value of the array.
   */
  double min() const;

  std::shared_ptr<ControlArray1D> min(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;
  /**
   * @brief Return the maximum value of the array.
   */
  double max() const;

  std::shared_ptr<ControlArray1D> max(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped ControlArray1D.
   */
  std::shared_ptr<ControlArray1D> reshape(
      const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped ControlArray1D1D.
   */
  std::shared_ptr<ControlArray1D> flip(size_t axis) const;
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
using ControlArray1DSP = std::shared_ptr<ControlArray1D>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
