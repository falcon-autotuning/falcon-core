#include "falcon-core/communications/messages/SettingResponse_c_api.h"

#include <falcon-core/communications/messages/SettingResponse.hpp>
#include <string>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {

DEFINE_C_API_COPY(SettingResponse);
DEFINE_C_API_DESTROY(SettingResponse);
DEFINE_C_API_EQUAL(SettingResponse);
DEFINE_C_API_NOT_EQUAL(SettingResponse);
DEFINE_C_API_TO_JSON(SettingResponse);
DEFINE_C_API_FROM_JSON(SettingResponse);

SettingResponseHandle
SettingResponse_create(StringHandle message,
                       MapInstrumentPortQuantityHandle getters) {
  FALCON_C_API_BEGIN

  if (!message) {
    throw std::invalid_argument(
        "Null handle passed to SettingResponse_create: message");
  }

  if (!getters) {
    throw std::invalid_argument(
        "Null handle passed to SettingResponse_create: getters");
  }

  std::string real_message(message->raw, message->length);

  generic::MapSP<instrument_interfaces::names::InstrumentPort, math::Quantity>
      real_getters = *static_cast<generic::MapSP<
          instrument_interfaces::names::InstrumentPort, math::Quantity> *>(
          getters);

  return new SettingResponseSP(
      std::make_shared<SettingResponse>(real_message, real_getters));

  FALCON_C_API_END(nullptr)
}

MapInstrumentPortQuantityHandle
SettingResponse_getters(SettingResponseHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to SettingResponse_getters");
  }

  SettingResponseSP response = *static_cast<SettingResponseSP *>(handle);

  return new generic::MapSP<instrument_interfaces::names::InstrumentPort,
                            math::Quantity>(response->getters());

  FALCON_C_API_END(nullptr)
}

StringHandle SettingResponse_message(SettingResponseHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to SettingResponse_message");
  }

  SettingResponseSP response = *static_cast<SettingResponseSP *>(handle);

  std::string message = response->message();

  return String_create(message.c_str(), message.size());

  FALCON_C_API_END(nullptr)
}

} // extern "C"
