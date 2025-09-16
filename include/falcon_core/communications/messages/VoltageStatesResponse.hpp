#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>

namespace falcon_core::communications::messages {

class VoltageStatesResponse : public BaseMessage {
  communications::voltage_states::DeviceVoltageStatesSP _states;

 public:
  VoltageStatesResponse(
      const std::string&                                           message,
      const communications::voltage_states::DeviceVoltageStatesSP& states);

  const communications::voltage_states::DeviceVoltageStatesSP& states() const;

 protected:
  VoltageStatesResponse();
  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar) {
    ar(cereal::base_class<BaseMessage>(this), _states);
  }
};
using VoltageStatesResponseSP = std::shared_ptr<VoltageStatesResponse>;
}  // namespace falcon_core::communications::messages
