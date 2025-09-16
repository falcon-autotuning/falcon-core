#include <falcon_core/communications/messages/MeasurementResponse.hpp>

namespace falcon_core::communications::messages {

MeasurementResponse::MeasurementResponse() = default;
MeasurementResponse::MeasurementResponse(
    const math::arrays::LabelledMeasuredArraysSP& arrays)
    : _arrays(arrays) {}

const math::arrays::LabelledMeasuredArraysSP& MeasurementResponse::arrays()
    const {
  return _arrays;
}

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementResponse)
