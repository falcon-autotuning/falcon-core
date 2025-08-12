#pragma once

#include "falcon_core/BaseLabelledArray.hpp"
#include "falcon_core/ControlArray1D.hpp"
#include "falcon_core/Gate.hpp"
#include "falcon_core/InstrumentPort.hpp"
#include "falcon_core/IsLabelled1D.hpp"
namespace falcon_core {

using LabelType = InstrumentPort<Gate>;

class LabelledControlArray1D
    : public BaseLabelledArray<ControlArray1D, LabelType>,
      public IsLabelled1D<LabelledControlArray1D> {
public:
  LabelledControlArray1D(std::shared_ptr<ControlArray1D> array,
                         std::shared_ptr<InstrumentPort<Gate>> label)
      : BaseLabelledArray<ControlArray1D, InstrumentPort<Gate>>(array, label) {}
  const ControlArray1D &get_array() const {
    if (!this->_array) {
      throw std::runtime_error("Array is null");
    }
    return *this->_array;
  }

  nlohmann::json to_json() const override {
    nlohmann::json j = this->to_json();
    add_metadata(j,
                 "falcon_core.math.labelled_arrays.labelled_control_array_1D",
                 "LabelledControlArray1D");
    return j;
  }
};

} // namespace falcon_core
