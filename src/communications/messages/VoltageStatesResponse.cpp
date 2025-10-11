#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <stdexcept>

#include "falcon_core/communications/messages/BaseMessage.hpp"

namespace falcon_core {
namespace communications {
namespace messages {

VoltageStatesResponse::VoltageStatesResponse() = default;
VoltageStatesResponse::VoltageStatesResponse(
    const std::string&                                           message,
    const communications::voltage_states::DeviceVoltageStatesSP& states)
    : BaseMessage(message), _states(states) {
  if (!states) {
    throw std::invalid_argument(
        "VoltageStatesResponse: The states must not be null.");
  }
}

const communications::voltage_states::DeviceVoltageStatesSP&
VoltageStatesResponse::states() const {
  return _states;
}
bool VoltageStatesResponse::operator==(
    const VoltageStatesResponse& other) const {
  return (*states() == *other.states()) && BaseMessage::operator==(other);
}
bool VoltageStatesResponse::operator!=(
    const VoltageStatesResponse& other) const {
  return !(*this == other);
}

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(
    falcon_core::communications::messages::VoltageStatesResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::VoltageStatesResponse)
