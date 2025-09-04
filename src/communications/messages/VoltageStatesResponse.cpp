#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>

namespace falcon_core {
namespace communications {
namespace messages {

VoltageStatesResponse::VoltageStatesResponse() = default;
VoltageStatesResponse::VoltageStatesResponse(const std::string& message, const std::shared_ptr<communications::voltage_states::DeviceVoltageStates>& states)
    : BaseMessage(message), _states(states) {}

const std::shared_ptr<communications::voltage_states::DeviceVoltageStates>& VoltageStatesResponse::states() const {
  return _states;
}

template <class Archive>
void VoltageStatesResponse::serialize(Archive& ar) {
  ar(cereal::base_class<BaseMessage>(this), _states);
}

template void VoltageStatesResponse::serialize<cereal::JSONOutputArchive>(cereal::JSONOutputArchive& ar);
template void VoltageStatesResponse::serialize<cereal::JSONInputArchive>(cereal::JSONInputArchive& ar);

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core

CEREAL_REGISTER_TYPE(falcon_core::communications::messages::VoltageStatesResponse)
