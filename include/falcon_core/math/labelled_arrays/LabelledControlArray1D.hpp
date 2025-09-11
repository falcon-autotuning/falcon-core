/**
 * @file LabelledControlArray1D.hpp
 * @brief Defines the LabelledControlArray1D class for FalconCore.
 */

#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/ControlArray1D.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"
#include "falcon_core/math/labelled_arrays/LabelledControlArray.hpp"
namespace falcon_core::math::labelled_arrays {

/// @brief 1D control array with instrument port label.
class LabelledControlArray1D : public LabelledControlArray,
                               public IsLabelled1D<LabelledControlArray> {
 public:
  LabelledControlArray1D(
      arrays::ControlArraySP                               array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  LabelledControlArray1D(
      arrays::ControlArray1DSP                             array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  LabelledControlArray1D(
      arrays::BaseArraySP<array_type>                      array,
      autotuner_interfaces::contexts::AcquisitionContextSP label);
  arrays::ControlArray1DSP array() const;

 private:
  friend class cereal::access;
  LabelledControlArray1D() = default;
  template <class Archive>
  void serialize(Archive& ar);
};
}  // namespace falcon_core::math::labelled_arrays
