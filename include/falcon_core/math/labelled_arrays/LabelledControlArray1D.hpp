/**
 * @file LabelledControlArray1D.hpp
 * @brief Defines the LabelledControlArray1D class for FalconCore.
 */

#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include "falcon_core/physics/device_structures/BaseConnection.hpp"
namespace falcon_core {
namespace math {
namespace labelled_arrays {

/// @brief 1D control array with instrument port label.
class LabelledControlArray1D : public BaseLabelledArray<arrays::ControlArray1D>,
                               public IsLabelled1D<LabelledControlArray1D> {
 public:
  using LabelType = instrument_interfaces::names::InstrumentPort;

  LabelledControlArray1D(std::shared_ptr<arrays::ControlArray1D> array,
                         std::shared_ptr<LabelType>              label);

  const arrays::ControlArray1D& get_array() const;

 private:
  friend class cereal::access;
  LabelledControlArray1D();
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
