#include "falcon_core/math/labelled_arrays/LabelledMeasuredArray.hpp"

#include "falcon_core/autotuner_interfaces/contexts/AcquisitionContext.hpp"
#include "falcon_core/instrument_interfaces/names/InstrumentPort.hpp"

namespace falcon_core {
namespace math {
namespace labelled_arrays {
LabelledMeasuredArray::LabelledMeasuredArray() = default;
LabelledMeasuredArray::LabelledMeasuredArray(
    arrays::MeasuredArraySP<double>                      array,
    autotuner_interfaces::contexts::AcquisitionContextSP label)
    : BaseLabelledArray<arrays::MeasuredArray<double>>(array, label) {}
LabelledMeasuredArray::LabelledMeasuredArray(
    MatrixType array, instrument_interfaces::names::InstrumentPortSP label)
    : BaseLabelledArray<arrays::MeasuredArray<double>>(
          std::make_shared<arrays::MeasuredArray<double>>(array),
          std::make_shared<autotuner_interfaces::contexts::AcquisitionContext>(
              label)) {}

template <class Archive>
void LabelledMeasuredArray::serialize(Archive& ar) {
  ar(cereal::base_class<BaseLabelledArray<arrays::MeasuredArray<double>>>(
      this));
}
using LabelledMeasuredArraySP = std::shared_ptr<LabelledMeasuredArray>;
}  // namespace labelled_arrays
}  // namespace math
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::math::labelled_arrays::LabelledMeasuredArray)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::generic::Song,
    falcon_core::math::labelled_arrays::LabelledMeasuredArray)
