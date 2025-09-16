#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>

namespace falcon_core::communications::messages {

VoltageStatesResponse::VoltageStatesResponse() = default;
VoltageStatesResponse::VoltageStatesResponse(
    const std::string&                                           message,
    const communications::voltage_states::DeviceVoltageStatesSP& states)
    : BaseMessage(message), _states(states) {}

const communications::voltage_states::DeviceVoltageStatesSP&
VoltageStatesResponse::states() const {
  return _states;
}

}  // namespace falcon_core::communications::messages

CEREAL_REGISTER_TYPE(
    falcon_core::communications::messages::VoltageStatesResponse)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    falcon_core::communications::messages::BaseMessage,
    falcon_core::communications::messages::VoltageStatesResponse)
