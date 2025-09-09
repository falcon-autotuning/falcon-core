/**
 * @file BaseLabelledArray.hpp
 * @brief Defines the BaseLabelledArray template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>
#include <stdexcept>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/BaseArray.hpp"
namespace falcon_core {
namespace math {
namespace labelled_arrays {

/// @brief Associates an array with a label.
/// @tparam ArrayType Type of the array.
template <typename ArrayType>
class BaseLabelledArray : public math::arrays::BaseArray<ArrayType> {
  autotuner_interfaces::contexts::AcquisitionContextSP _label;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<math::arrays::BaseArray<ArrayType>>(this), _label);
  }

 public:
  BaseLabelledArray() = default;
  BaseLabelledArray(math::arrays::BaseArraySP<ArrayType>                 array,
                    autotuner_interfaces::contexts::AcquisitionContextSP label)
      : _label(label), math::arrays::BaseArray<ArrayType>(array.data()) {}
  BaseLabelledArray(
      math::arrays::BaseArraySP<ArrayType>                        array,
      falcon_core::instrument_interfaces::names::InstrumentPortSP label)
      : math::arrays::BaseArray<ArrayType>(array.data()),
        _label(std::make_shared<
               autotuner_interfaces::contexts::AcquisitionContext>(label)) {}
  /**
   * @brief Return the label.
   */
  const autotuner_interfaces::contexts::AcquisitionContextSP& label() const {
    return _label;
  }
  /**
   * @brief Return the connection.
   */
  const physics::device_structures::BaseConnection connection() const {
    return label().connection();
  }
  /**
   * @brief Return the instrument type.
   */
  const instrument_interfaces::Instrument instrument_type() const {
    return label().instrument_type();
  }
  /**
   * @brief Return the units.
   */
  const physics::units::SymbolUnit units() const { return label().units(); }
  /**
   * @brief Check if the data is equal to the other data.
   */
  bool const operator==(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    return arrays::BaseArray<ArrayType>::operator==(other) &&
           label() == other->label();
  }
  /**
   * @brief Add the data to the other data.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator+(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    if (label() != other->label()) {
      throw std::runtime_error(
          "Cannot add two labelled arrays with different labels");
    }
    return std::make_shared<BaseLabelledArray<ArrayType>>(BaseLabelledArray(
        arrays::BaseArray<ArrayType>::operator+(other), label()));
  }
  /**
   * @brief Negate the data by multiplying by -1.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator-() const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(
        BaseLabelledArray(arrays::BaseArray<ArrayType>::operator-(), label()));
  }
  /**
   * @brief Subtract the other data from the data.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator-(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    if (label() != other->label()) {
      throw std::runtime_error(
          "Cannot add two labelled arrays with different labels");
    }
    return std::make_shared<BaseLabelledArray<ArrayType>>(BaseLabelledArray(
        arrays::BaseArray<ArrayType>::operator-(other), label()));
  }
  /**
   * @brief Raise the data to the power.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator^(
      const double power) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(BaseLabelledArray(
        arrays::BaseArray<ArrayType>::operator^(power), label()));
  }
  /**
   * @brief Raise the data to the power.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator^(
      const int power) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(BaseLabelledArray(
        arrays::BaseArray<ArrayType>::operator^(power), label()));
  }
  /**
   * @brief Multiply the other data by the data.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator*(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    if (label() != other->label()) {
      throw std::runtime_error(
          "Cannot add two labelled arrays with different labels");
    }
    return std::make_shared<BaseLabelledArray<ArrayType>>(BaseLabelledArray(
        arrays::BaseArray<ArrayType>::operator*(other), label()));
  }
  /**
   * @brief Divide the data by the other data.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> const operator/(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    if (label() != other->label()) {
      throw std::runtime_error(
          "Cannot add two labelled arrays with different labels");
    }
    return std::make_shared<BaseLabelledArray<ArrayType>>(BaseLabelledArray(
        arrays::BaseArray<ArrayType>::operator/(other), label()));
  }
  /**
   * @brief Gets the sum of the squares referenced to 0.
   */
  double get_sum_of_squares() const {
    return this->data().get_sum_of_squares();
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
