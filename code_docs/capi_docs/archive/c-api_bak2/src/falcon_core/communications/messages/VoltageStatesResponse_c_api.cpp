#include "falcon_core/communications/messages/VoltageStatesResponse_c_api.h"

#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
DEFINE_C_API_COPY(VoltageStatesResponse);
DEFINE_C_API_DESTROY(VoltageStatesResponse);
DEFINE_C_API_EQUAL(VoltageStatesResponse);
DEFINE_C_API_NOT_EQUAL(VoltageStatesResponse);
DEFINE_C_API_TO_JSON(VoltageStatesResponse);
DEFINE_C_API_FROM_JSON(VoltageStatesResponse);
VoltageStatesResponseHandle VoltageStatesResponse_create(
    StringHandle message, DeviceVoltageStatesHandle states) {
  FALCON_C_API_BEGIN
  if (!message) {
    throw std::invalid_argument(
        "Null message handle passed to VoltageStatesResponse_create");
  }
  if (!states) {
    throw std::invalid_argument(
        "Null states handle passed to VoltageStatesResponse_create");
  }
  std::string msg_str = std::string(message->raw, message->length);
  communications::voltage_states::DeviceVoltageStatesSP states_sp =
      *static_cast<communications::voltage_states::DeviceVoltageStatesSP*>(
          states);
  return new VoltageStatesResponseSP(
      std::make_shared<VoltageStatesResponse>(msg_str, states_sp));
  FALCON_C_API_END(nullptr)
}

StringHandle VoltageStatesResponse_message(VoltageStatesResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_message");
  }
  auto        response = *static_cast<VoltageStatesResponseSP*>(handle);
  std::string msg_str  = response->message();
  return String_create(msg_str.c_str(), msg_str.size());
  FALCON_C_API_END(nullptr)
}

DeviceVoltageStatesHandle VoltageStatesResponse_states(
    VoltageStatesResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_states");
  }
  auto response = *static_cast<VoltageStatesResponseSP*>(handle);
  return new communications::voltage_states::DeviceVoltageStatesSP(
      (response->states()));
  FALCON_C_API_END(nullptr)
}
}
