/**
 * @file BaseLabelledArray.hpp
 * @brief Defines the BaseLabelledArray template for FalconCore.
 */

#pragma once

#include <cereal/types/memory.hpp>
#include <memory>

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/generic/Song.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

/// @brief Associates an array with a label.
/// @tparam ArrayType Type of the array.
template <typename ArrayType>
class BaseLabelledArray : public generic::Song {
  std::shared_ptr<ArrayType>                                          _array;
  std::shared_ptr<autotuner_interfaces::contexts::AcquisitionContext> _label;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<generic::Song>(this), _array, _label);
  }

 public:
  BaseLabelledArray() = default;
  BaseLabelledArray(
      std::shared_ptr<ArrayType>                                          array,
      std::shared_ptr<autotuner_interfaces::contexts::AcquisitionContext> label)
      : _array(array), _label(label) {}
  BaseLabelledArray(
      std::shared_ptr<ArrayType> array,
      std::shared_ptr <
          falcon_core::instrument_interfaces::names::InstrumentPort label)
      : _array(array),
        _label(std::make_shared<
               autotuner_interfaces::contexts::AcquisitionContext>(label)) {}

  /**
   * @brief Return the array.
   */
  const std::shared_ptr<ArrayType>& array() const { return _array; }
  /**
   * @brief Return the label.
   */
  const autotuner_interfaces::contexts::AcquisitionContextSP& label() const {
    return _label;
  }
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
