/**
 * @file LabelledMeasuredArray.hpp
 * @brief Defines the a control array with a label.
 */

#pragma once

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

/**
 * @brief An array with a context label attached.
 */
class LabelledMeasuredArray : public MeasuredArray, public IsLabelled<double> {
 public:
  /**
   * @brief Construct a new Labelled Measured Array object.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledMeasuredArray(
      const arrays::MeasuredArraySP&                              array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  /**
   * @brief Another constructor for a new Labelled Measured Array object using a
   * BaseArray.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledMeasuredArray(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  /**
   * @brief Constructs a new LabelledMeasuredArray object using a BaseArray.
   * @param array The control array.
   * @param port The instrument port to create the label from.
   */
  LabelledMeasuredArray(
      const generic::FArraySP<double>&                      array,
      const instrument_interfaces::names::InstrumentPortSP& port);

  LabelledMeasuredArray(const LabelledMeasuredArray&)                = default;
  LabelledMeasuredArray(LabelledMeasuredArray&&) noexcept            = default;
  LabelledMeasuredArray& operator=(const LabelledMeasuredArray&)     = default;
  LabelledMeasuredArray& operator=(LabelledMeasuredArray&&) noexcept = default;
  // Arithmetic operators
  std::shared_ptr<LabelledMeasuredArray> operator+(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator+(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator+(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator-() const;

  std::shared_ptr<LabelledMeasuredArray> operator*(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator*(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator*(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator*(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(const int other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator/(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledMeasuredArray> operator^(const double other) const;

  std::shared_ptr<LabelledMeasuredArray> abs() const;
  /**
   * @brief Return the minimum value of the array.
   */
  double min() const;

  std::shared_ptr<LabelledMeasuredArray> min(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> min(
      const std::shared_ptr<FArray<double>>& other) const;
  /**
   * @brief Return the maximum value of the array.
   */
  double max() const;

  std::shared_ptr<LabelledMeasuredArray> max(
      const std::shared_ptr<LabelledMeasuredArray>& other) const;

  std::shared_ptr<LabelledMeasuredArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped LabelledMeasuredArray.
   */
  std::shared_ptr<LabelledMeasuredArray> reshape(
      const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped LabelledMeasuredArray.
   */
  std::shared_ptr<LabelledMeasuredArray> flip(size_t axis) const;
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
  bool operator==(const LabelledMeasuredArray& other) const;
  bool operator!=(const LabelledMeasuredArray& other) const;

 protected:
  LabelledMeasuredArray();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<MeasuredArray>(this), _label);
  }
};
using LabelledMeasuredArraySP = std::shared_ptr<LabelledMeasuredArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
