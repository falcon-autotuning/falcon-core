/**
 * @file LabelledControlArray.hpp
 * @brief Defines the a control array with a label.
 */

#pragma once

#include "cereal/types/base_class.hpp"
#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/math/arrays/ControlArray.hpp"
#include "falcon_core/math/arrays/IsLabelled.hpp"
namespace falcon_core {
namespace math {
namespace arrays {

/**
 * @brief An array with a context label attached.
 */
class LabelledControlArray : public ControlArray, public IsLabelled<double> {
 public:
  /**
   * @brief Construct a new Labelled Control Array object.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledControlArray(
      const arrays::ControlArraySP&                               array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  /**
   * @brief Another constructor for a new Labelled Control Array object using a
   * BaseArray.
   * @param array The control array.
   * @param label The acquisition context label.
   */
  LabelledControlArray(
      const generic::FArraySP<double>&                            array,
      const autotuner_interfaces::contexts::AcquisitionContextSP& label);
  /**
   * @brief Constructs a new LabelledControlArray object using a BaseArray.
   * @param array The control array.
   * @param port The instrument port to create the label from.
   */
  LabelledControlArray(
      const generic::FArraySP<double>&                      array,
      const instrument_interfaces::names::InstrumentPortSP& port);

  LabelledControlArray(const LabelledControlArray&)                = default;
  LabelledControlArray(LabelledControlArray&&) noexcept            = default;
  LabelledControlArray& operator=(const LabelledControlArray&)     = default;
  LabelledControlArray& operator=(LabelledControlArray&&) noexcept = default;
  // Arithmetic operators
  std::shared_ptr<LabelledControlArray> operator+(const double other) const;

  std::shared_ptr<LabelledControlArray> operator+(const int other) const;

  std::shared_ptr<LabelledControlArray> operator+(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> operator+(
      const std::shared_ptr<FArray>& other) const;

  std::shared_ptr<LabelledControlArray> operator-(const double other) const;

  std::shared_ptr<LabelledControlArray> operator-(const int other) const;

  std::shared_ptr<LabelledControlArray> operator-(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> operator-(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledControlArray> operator-() const;

  std::shared_ptr<LabelledControlArray> operator*(const double other) const;

  std::shared_ptr<LabelledControlArray> operator*(const int other) const;

  std::shared_ptr<LabelledControlArray> operator/(const double other) const;

  std::shared_ptr<LabelledControlArray> operator/(const int other) const;

  std::shared_ptr<LabelledControlArray> operator^(const double other) const;

  std::shared_ptr<LabelledControlArray> abs() const;

  std::shared_ptr<LabelledControlArray> min(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> min(
      const std::shared_ptr<FArray<double>>& other) const;

  std::shared_ptr<LabelledControlArray> max(
      const std::shared_ptr<LabelledControlArray>& other) const;

  std::shared_ptr<LabelledControlArray> max(
      const std::shared_ptr<FArray<double>>& other) const;

  /**
   * @brief Return a new Array with the given shape.
   * @param shape The new shape.
   * @return A reshaped LabelledControlArray.
   */
  std::shared_ptr<LabelledControlArray> reshape(
      const std::vector<size_t>& shape) const;
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped LabelledControlArray.
   */
  std::shared_ptr<LabelledControlArray> flip(size_t axis) const;
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
  bool operator==(const LabelledControlArray& other) const;
  bool operator!=(const LabelledControlArray& other) const;

 protected:
  LabelledControlArray();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<ControlArray>(this), _label);
  }
};
using LabelledControlArraySP = std::shared_ptr<LabelledControlArray>;
}  // namespace arrays
}  // namespace math
}  // namespace falcon_core
