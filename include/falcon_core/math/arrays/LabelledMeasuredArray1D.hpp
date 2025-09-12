/**
 * @file LabelledMeasuredArray1D.hpp
 * @brief Defines the LabelledMeasuredArray1D class for FalconCore.
 */

#pragma once

#include "falcon_core/math/arrays/Is1D.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"
#include "falcon_core/math/arrays/MeasuredArray1D.hpp"
namespace falcon_core::math::arrays {

/// @brief 1D control array with a label.
class LabelledMeasuredArray1D : public LabelledMeasuredArray,
                                public Is1D<double> {
 public:
  /**
   * @brief Construct a new Labelled Measured Array object.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledMeasuredArray1D(
      const arrays::MeasuredArraySP&                              array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  /**
   * @brief Construct a new Labelled Measured Array object.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledMeasuredArray1D(
      const arrays::MeasuredArray1DSP&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  /**
   * @brief Construct a new Labelled Measured Array object.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledMeasuredArray1D(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  LabelledMeasuredArray1D(const LabelledMeasuredArray1D&)            = default;
  LabelledMeasuredArray1D(LabelledMeasuredArray1D&&) noexcept        = default;
  LabelledMeasuredArray1D& operator=(const LabelledMeasuredArray1D&) = default;
  LabelledMeasuredArray1D& operator=(LabelledMeasuredArray1D&&) noexcept =
      default;
  // Arithmetic operators
  std::shared_ptr<LabelledMeasuredArray1D> operator+(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator+(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator+(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator-() const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(const int other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> operator^(const double other) const;

  std::shared_ptr<LabelledMeasuredArray1D> abs() const;

  std::shared_ptr<LabelledMeasuredArray1D> min(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> min(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> max(
      const std::shared_ptr<LabelledMeasuredArray1D>& other) const;

  std::shared_ptr<LabelledMeasuredArray1D> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped LabelledMeasuredArray1D.
   */
  std::shared_ptr<LabelledMeasuredArray1D> reshape(
      const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped LabelledMeasuredArray1D.
   */
  std::shared_ptr<LabelledMeasuredArray1D> flip(size_t axis) const;
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
  LabelledMeasuredArray1D();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<LabelledMeasuredArray>(this));
  }
};
using LabelledMeasuredArray1DSP = std::shared_ptr<LabelledMeasuredArray1D>;
}  // namespace falcon_core::math::arrays
