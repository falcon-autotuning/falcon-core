#include <falcon_core/communications/messages/MeasurementResponse.hpp>
#include <stdexcept>

#include "falcon_core/communications/messages/BaseMessage.hpp"
#include "falcon_core/math/arrays/LabelledMeasuredArray.hpp"

namespace falcon_core {
namespace communications {
namespace messages {

MeasurementResponse::MeasurementResponse() = default;
MeasurementResponse::MeasurementResponse(
    const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
        arrays)
    : _arrays(arrays), BaseMessage() {
  if (!arrays) {
    throw std::invalid_argument(
        "MeasurementResponse: The arrays must not be null.");
  }
}

const math::arrays::LabelledArraysSP<math::arrays::LabelledMeasuredArray>&
MeasurementResponse::arrays() const {
  return _arrays;
}
bool MeasurementResponse::operator==(const MeasurementResponse& other) const {
  return (*arrays() == *other.arrays()) && BaseMessage::operator==(other);
}
bool MeasurementResponse::operator!=(const MeasurementResponse& other) const {
  return !(*this == other);
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::MeasurementResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::MeasurementResponse)
