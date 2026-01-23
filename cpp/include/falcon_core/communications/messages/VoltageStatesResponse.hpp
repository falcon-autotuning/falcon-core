#pragma once

#include <falcon_core/communications/messages/BaseMessage.hpp>
#include <falcon_core/communications/voltage_states/DeviceVoltageStates.hpp>

#include "falcon_core/export.h"

namespace falcon_core {
namespace communications {
namespace messages {

class FALCON_CORE_CPP_API VoltageStatesResponse : public BaseMessage {
  communications::voltage_states::DeviceVoltageStatesSP _states;
  mutable std::shared_timed_mutex                       _mu_states;

 public:
  VoltageStatesResponse(const VoltageStatesResponse& other);
  VoltageStatesResponse& operator=(const VoltageStatesResponse& other);
  VoltageStatesResponse(
      const std::string&                                           message,
      const communications::voltage_states::DeviceVoltageStatesSP& states);

  const communications::voltage_states::DeviceVoltageStatesSP& states() const;
  bool operator==(const VoltageStatesResponse& other) const;
  bool operator!=(const VoltageStatesResponse& other) const;

 protected:
  VoltageStatesResponse();
  friend class cereal::access;
  template <class Archive>
  inline void serialize(Archive& ar) {
    std::shared_lock<std::shared_timed_mutex> lock_s(_mu_states);
    ar(cereal::base_class<BaseMessage>(this), _states);
  }
};
using VoltageStatesResponseSP = std::shared_ptr<VoltageStatesResponse>;
}  // namespace messages
}  // namespace communications
}  // namespace falcon_core
