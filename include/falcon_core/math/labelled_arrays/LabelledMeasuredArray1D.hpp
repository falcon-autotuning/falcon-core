#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

class LabelledMeasuredArray1D
    : public BaseLabelledArray<arrays::MeasuredArray1D>,
      public IsLabelled1D<LabelledMeasuredArray1D> {
 public:
  using LabelType = instrument_interfaces::names::InstrumentPort;

  LabelledMeasuredArray1D(std::shared_ptr<arrays::MeasuredArray1D> array,
                          std::shared_ptr<LabelType> label)
      : BaseLabelledArray<arrays::MeasuredArray1D>(array, label) {}

  const arrays::MeasuredArray1D& get_array() const {
    if (!this->_array) {
      throw std::runtime_error("Array is null");
    }
    return *(this->_array);
  }

 private:
  friend class cereal::access;
  LabelledMeasuredArray1D() = default;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArray<arrays::MeasuredArray1D>>(this));
  }
};

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
