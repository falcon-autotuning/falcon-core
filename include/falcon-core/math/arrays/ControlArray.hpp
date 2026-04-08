/**
 * @file ControlArray.hpp
 * @brief Defines the ControlArray for control independant axis data for falcon.
 */

#pragma once

#include "falcon-core/export.h"
#include "falcon-core/math/arrays/IsControl.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

/**
 * @brief Array type for control independant axis data
 */
class FALCON_CORE_CPP_API ControlArray : public generic::FArray<double>,
                                         public IsControl<double> {
 protected:
  friend class cereal::access;
  ControlArray();
  template <class Archive>
  inline void serialize(Archive& ar) {
    ar(cereal::base_class<FArray<double>>(this),
       principle_dimension(),
       alignment());
  }

 public:
  ControlArray(const ControlArray& other);
  ControlArray& operator=(const ControlArray& other);
  ControlArray(const xt::xarray<double>& arr);
  ControlArray(const generic::FArraySP<double>& arr);
  ControlArray(xt::xarray<double>&& arr) noexcept;
  // Arithmetic operators
  std::shared_ptr<ControlArray> operator+(const double other) const;

  std::shared_ptr<ControlArray> operator+(const int other) const;

  std::shared_ptr<ControlArray> operator+(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<ControlArray> operator-(const double other) const;

  std::shared_ptr<ControlArray> operator-(const int other) const;

  std::shared_ptr<ControlArray> operator-(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<ControlArray> operator-() const;

  std::shared_ptr<ControlArray> operator*(const double other) const;

  std::shared_ptr<ControlArray> operator*(const int other) const;

  std::shared_ptr<ControlArray> operator/(const double other) const;

  std::shared_ptr<ControlArray> operator/(const int other) const;

  std::shared_ptr<ControlArray> operator^(const double other) const;

  std::shared_ptr<ControlArray> abs() const;
  /**
   * @brief Return the minimum value of the array.
   */
  double min() const override;

  std::shared_ptr<ControlArray> min(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> min(
      const std::shared_ptr<FArray<double>>& other) const;
  /**
   * @brief Return the maximum value of the array.
   */
  double max() const override;

  std::shared_ptr<ControlArray> max(
      const std::shared_ptr<ControlArray>& other) const;

  std::shared_ptr<ControlArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped ControlArray.
   */
  std::shared_ptr<ControlArray> reshape(const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped ControlArray.
   */
  std::shared_ptr<ControlArray> flip(size_t axis) const;
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
  generic::FArraySP<double> gradient(size_t axis) const override;
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
  generic::ListSP<generic::FArray<double>> gradient() const override;
};
using ControlArraySP = std::shared_ptr<ControlArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
