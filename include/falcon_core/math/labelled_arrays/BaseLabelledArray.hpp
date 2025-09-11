/**
 * @file BaseLabelledArray.hpp
 * @brief Defines the BaseLabelledArray template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/List.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
namespace falcon_core::math::labelled_arrays {

/// @brief Associates an array with a label.
/// @tparam ArrayType datatype of the array.
template <typename ArrayType>
class BaseLabelledArray : public generic::Song {
 protected:
  std::shared_ptr<ArrayType>                           _array;
  autotuner_interfaces::contexts::AcquisitionContextSP _label;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(_array, _label);
  }

 public:
  BaseLabelledArray() = default;
  BaseLabelledArray(std::shared_ptr<ArrayType>                           array,
                    autotuner_interfaces::contexts::AcquisitionContextSP label)
      : _array(array), _label(label) {}
  BaseLabelledArray(
      std::shared_ptr<ArrayType>                                  array,
      falcon_core::instrument_interfaces::names::InstrumentPortSP label)
      : _array(array),
        _label(std::make_shared<
               autotuner_interfaces::contexts::AcquisitionContext>(label)) {}

  const std::shared_ptr<ArrayType>& array() const { return _array; }

  const autotuner_interfaces::contexts::AcquisitionContextSP& label() const {
    return _label;
  }
  const physics::device_structures::BaseConnectionSP connection() const {
    return label()->connection();
  }
  const instrument_interfaces::Instrument instrument_type() const {
    return label()->instrument_type();
  }
  const physics::units::SymbolUnitSP units() const { return label()->units(); }

  bool operator==(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    return (_array && other->_array && (*_array == *(other->_array))) &&
           label() == other->label();
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator+(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    if (label() == other->label()) {
      return std::make_shared<BaseLabelledArray<ArrayType>>(
          _array + *(other->_array), this->label());
    } else {
      throw std::runtime_error(
          "Cannot add labelled arrays with different labels.");
    }
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator+(
      const int other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array + other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator+(
      const double other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array + other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator-() const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(-_array,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator-(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    if (label() == other->label()) {
      return std::make_shared<BaseLabelledArray<ArrayType>>(
          _array - *(other->_array), this->label());
    } else {
      throw std::runtime_error(
          "Cannot subtract labelled arrays with different labels.");
    }
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator-(
      const int other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array - other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator-(
      const double other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array - other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator^(
      const int other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array ^ other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator*(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    autotuner_interfaces::contexts::AcquisitionContextSP label = this->label();
    label->units() *= other.label()->units();
    return std::make_shared<BaseLabelledArray<ArrayType>>(
        _array * *(other->_array), label);
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator*(
      const int other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array * other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator*(
      const double other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array * other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator/(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    autotuner_interfaces::contexts::AcquisitionContextSP label = this->label();
    label->units() /= other.label()->units();
    return std::make_shared<BaseLabelledArray<ArrayType>>(
        _array / *(other->_array), label);
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator/(
      const int other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array / other,
                                                          this->label());
  }
  std::shared_ptr<BaseLabelledArray<ArrayType>> operator/(
      const double other) const {
    return std::make_shared<BaseLabelledArray<ArrayType>>(_array / other,
                                                          this->label());
  }
  /**
   * @brief Get the sum of squares of the data.
   */
  double get_sum_of_squares() const { return _array->get_sum_of_squares(); }
  bool   operator>(const double value) const { return *_array > value; }
  bool   operator<(const double value) const { return *_array < value; }
  /**
   * @brief Remove an offset from the data.
   * @param offset The offset to remove.
   */
  void remove_offset(const double offset) { _array->remove_offset(offset); }
  /**
   * @brief Return the maximum value in the array.
   */
  ArrayType max() const { return _array->max(); }
  /**
   * @brief Return the minimum value in the array.
   */
  ArrayType min() const { return _array->min(); }
  /**
   * @brief Return the sum of the data.
   */
  ArrayType sum() const { return _array->sum(); }
  /**
   * @brief Flip the data along the given axis.
   * @param axis The axis to flip.
   * @return A flipped BaseLabelledArray.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> flip(size_t axis) const {
    return _array->flip(axis);
  }
  /**
   * @brief Return the gradient of the data along all axes.
   */
  generic::ListSP<std::shared_ptr<BaseLabelledArray<ArrayType>>> gradient()
      const {
    auto grads = _array->gradient();
    auto list  = std::make_shared<
         generic::List<std::shared_ptr<BaseLabelledArray<ArrayType>>>>();
    for (const auto& grad : *grads) {
      list->push_back(std::make_shared<BaseLabelledArray<ArrayType>>(
          std::make_shared<ArrayType>(grad), this->label()));
    }
    return list;
  }
  /**
   * @brief Return the gradient of the data along a given axis.
   * @param axis The axis to compute the gradient.
   * @return The gradient BaseLabelledArray.
   */
  std::shared_ptr<BaseLabelledArray<ArrayType>> gradient(size_t axis) const {
    auto grad = _array->gradient(axis);
    return std::make_shared<BaseLabelledArray<ArrayType>>(
        std::make_shared<ArrayType>(*grad), this->label());
  }
};
}  // namespace falcon_core::math::labelled_arrays
