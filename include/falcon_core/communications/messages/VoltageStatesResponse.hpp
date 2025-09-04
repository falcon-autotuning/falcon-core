#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>
#include <memory>

namespace falcon_core {
namespace communications {
namespace messages {

class VoltageStatesResponse : public BaseMessage {
 public:
  VoltageStatesResponse();
  VoltageStatesResponse(
      const std::string& message,
      const std::shared_ptr<
          communications::voltage_states::DeviceVoltageStates>& states);

  const std::shared_ptr<communications::voltage_states::DeviceVoltageStates>&
  states() const;

 private:
  std::shared_ptr<communications::voltage_states::DeviceVoltageStates> _states;

  friend class cereal::access;
  template <class Archive>
  void serialize(Archive& ar);
};

}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
