#include "falcon_core/communications/messages/VoltageStatesResponse_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <string>

using namespace falcon_core;
using namespace falcon_core::communications::messages;

VoltageStatesResponseHandle VoltageStatesResponse_create(
    StringHandle message, DeviceVoltageStatesHandle states) {
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
      std::make_shared<communications::voltage_states::DeviceVoltageStates>(
          *static_cast<communications::voltage_states::DeviceVoltageStates*>(
              states));
  return new VoltageStatesResponse(VoltageStatesResponse(msg_str, states_sp));
}

void VoltageStatesResponse_destroy(VoltageStatesResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_destroy");
  }
  delete static_cast<VoltageStatesResponse*>(handle);
}

StringHandle VoltageStatesResponse_message(VoltageStatesResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_message");
  }
  auto        response = static_cast<VoltageStatesResponse*>(handle);
  std::string msg_str  = response->message();
  return String_create(msg_str.c_str(), msg_str.size());
}

DeviceVoltageStatesHandle VoltageStatesResponse_states(
    VoltageStatesResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_states");
  }
  auto response = static_cast<VoltageStatesResponse*>(handle);
  return new communications::voltage_states::DeviceVoltageStates(
      *(response->states()));
}

bool VoltageStatesResponse_equal(VoltageStatesResponseHandle handle,
                                 VoltageStatesResponseHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_equal");
  }
  return *(static_cast<VoltageStatesResponse*>(handle)) ==
         *(static_cast<VoltageStatesResponse*>(other));
}

bool VoltageStatesResponse_not_equal(VoltageStatesResponseHandle handle,
                                     VoltageStatesResponseHandle other) {
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_not_equal");
  }
  return *(static_cast<VoltageStatesResponse*>(handle)) !=
         *(static_cast<VoltageStatesResponse*>(other));
}

StringHandle VoltageStatesResponse_to_json_string(
    VoltageStatesResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_to_json_string");
  }
  auto        response = static_cast<VoltageStatesResponse*>(handle);
  std::string json_str = response->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
}

VoltageStatesResponseHandle VoltageStatesResponse_from_json_string(
    StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "VoltageStatesResponse_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      VoltageStatesResponse::from_json_string<VoltageStatesResponse>(raw_json);
  return new VoltageStatesResponse(*ptr);
}
