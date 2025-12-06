#include "falcon_core/communications/messages/VoltageStatesResponse_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/VoltageStatesResponse.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
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

void VoltageStatesResponse_destroy(VoltageStatesResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_destroy");
  }
  delete static_cast<VoltageStatesResponseSP*>(handle);
  FALCON_C_API_END()
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

bool VoltageStatesResponse_equal(VoltageStatesResponseHandle handle,
                                 VoltageStatesResponseHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_equal");
  }
  return *(*static_cast<VoltageStatesResponseSP*>(handle)) ==
         *(*static_cast<VoltageStatesResponseSP*>(other));
  FALCON_C_API_END(false)
}

bool VoltageStatesResponse_not_equal(VoltageStatesResponseHandle handle,
                                     VoltageStatesResponseHandle other) {
  FALCON_C_API_BEGIN
  if (!handle || !other) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_not_equal");
  }
  return *(*static_cast<VoltageStatesResponseSP*>(handle)) !=
         *(*static_cast<VoltageStatesResponseSP*>(other));
  FALCON_C_API_END(false)
}

StringHandle VoltageStatesResponse_to_json_string(
    VoltageStatesResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to VoltageStatesResponse_to_json_string");
  }
  auto        response = *static_cast<VoltageStatesResponseSP*>(handle);
  std::string json_str = response->to_json_string();
  return String_create(json_str.c_str(), json_str.size());
  FALCON_C_API_END(nullptr)
}

VoltageStatesResponseHandle VoltageStatesResponse_from_json_string(
    StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null string handle passed to "
        "VoltageStatesResponse_from_json_string");
  }
  std::string raw_json(json->raw);
  auto        ptr =
      VoltageStatesResponse::from_json_string<VoltageStatesResponse>(raw_json);
  return new VoltageStatesResponseSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
