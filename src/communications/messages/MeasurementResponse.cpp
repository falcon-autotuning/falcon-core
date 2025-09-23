#include <falcon_core/communications/messages/MeasurementResponse.hpp>

#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

namespace falcon_core::communications::messages {

MeasurementResponse::MeasurementResponse() = default;
MeasurementResponse::MeasurementResponse(
    const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
        arrays)
    : _arrays(arrays) {}

const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
MeasurementResponse::arrays() const {
  return _arrays;
}

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementResponse)
