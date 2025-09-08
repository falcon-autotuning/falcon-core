#pragma once

#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"
#include "falcon_core/math/arrays/MeasuredArray.hpp"
#include "falcon_core/math/labelled_arrays/BaseLabelledArray.hpp"
#include "falcon_core/math/labelled_arrays/IsLabelled1D.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {

class LabelledMeasuredArray1D
    : public BaseLabelledArray<arrays::MeasuredArray<double>>,
      public IsLabelled1D<LabelledMeasuredArray1D> {
 public:
  using LabelType = instrument_interfaces::names::InstrumentPort;

  LabelledMeasuredArray1D(std::shared_ptr<arrays::MeasuredArray<double>> array,
                          std::shared_ptr<LabelType>                     label);

  const arrays::MeasuredArray<double>& get_array() const;

 private:
  friend class cereal::access;
  LabelledMeasuredArray1D();
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseLabelledArray<arrays::MeasuredArray<double>>>(
        this));
  }
};

}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core
