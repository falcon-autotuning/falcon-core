/**
 * @file ControlArray1D.hpp
 * @brief Defines a 1dimensional indpendant control vector for falcon.
 */

#pragma once

#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/Is1D.hpp"
namespace falcon_core::math::arrays {

/// @brief 1D control array, enforces 1D shape at construction.
class ControlArray1D : public ControlArray, Is1D<ControlArray> {
 protected:
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray>(this),
       principle_dimension(),
       alignment());
  }

 public:
  ControlArray1D();
  ControlArray1D(const xt::xarray<double>& arr);
  ControlArray1D(const FArray<double>& arr);
  ControlArray1D(const ControlArray& arr);
  ControlArray1D(xt::xarray<double>&& arr) noexcept;
  ControlArray1D(const ControlArray1D&)                = default;
  ControlArray1D(ControlArray1D&&) noexcept            = default;
  ControlArray1D& operator=(const ControlArray1D&)     = default;
  ControlArray1D& operator=(ControlArray1D&&) noexcept = default;
  static std::shared_ptr<ControlArray1D> zeros(
      const std::vector<size_t>& shape) {
    return std::make_shared<ControlArray1D>(xt::zeros<double>(shape));
  }
  static std::shared_ptr<ControlArray1D> empty(
      const std::vector<size_t>& shape) {
    return std::make_shared<ControlArray1D>(xt::empty<double>(shape));
  }
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

  std::shared_ptr<ControlArray1D> operator*(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray1D> operator/(const double other) const;

  std::shared_ptr<ControlArray1D> operator/(const int other) const;

  std::shared_ptr<ControlArray1D> operator/(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray1D> operator^(const double other) const;

  std::shared_ptr<ControlArray1D> abs() const;

  std::shared_ptr<ControlArray1D> min(
      const std::shared_ptr<ControlArray1D>& other) const;

  std::shared_ptr<ControlArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;

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
}  // namespace falcon_core::math::arrays
