/**
 * @file BaseLabelledArray.hpp
 * @brief Defines the BaseLabelledArray template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

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
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
