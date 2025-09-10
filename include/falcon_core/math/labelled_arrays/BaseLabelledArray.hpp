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
  const physics::device_structures::BaseConnection connection() const {
    return label()->connection();
  }
  const instrument_interfaces::Instrument instrument_type() const {
    return label()->instrument_type();
  }
  const physics::units::SymbolUnit units() const { return label()->units(); }

  bool operator==(
      const std::shared_ptr<BaseLabelledArray<ArrayType>>& other) const {
    return (_array && other->_array && (*_array == *(other->_array))) &&
           label() == other->label();
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
