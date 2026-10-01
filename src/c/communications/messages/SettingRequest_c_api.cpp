#include "falcon-core/communications/messages/SettingRequest_c_api.h"

#include <falcon-core/communications/messages/SettingRequest.hpp>
#include <string>

#include "falcon-core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {

DEFINE_C_API_COPY(SettingRequest);
DEFINE_C_API_DESTROY(SettingRequest);
DEFINE_C_API_EQUAL(SettingRequest);
DEFINE_C_API_NOT_EQUAL(SettingRequest);
DEFINE_C_API_TO_JSON(SettingRequest);
DEFINE_C_API_FROM_JSON(SettingRequest);

SettingRequestHandle
SettingRequest_create(StringHandle message, PortsHandle getters,
                      MapInstrumentPortQuantityHandle setters) {
  FALCON_C_API_BEGIN

  if (!message) {
    throw std::invalid_argument(
        "Null handle passed to SettingRequest_create: message");
  }

  if (!getters) {
    throw std::invalid_argument(
        "Null handle passed to SettingRequest_create: getters");
  }

  if (!setters) {
    throw std::invalid_argument(
        "Null handle passed to SettingRequest_create: setters");
  }

  std::string real_msg(message->raw, message->length);

  instrument_interfaces::names::PortsSP real_getters =
      *static_cast<instrument_interfaces::names::PortsSP *>(getters);

  generic::MapSP<instrument_interfaces::names::InstrumentPort, math::Quantity>
      real_setters = *static_cast<generic::MapSP<
          instrument_interfaces::names::InstrumentPort, math::Quantity> *>(
          setters);

  return new SettingRequestSP(
      std::make_shared<SettingRequest>(real_msg, real_getters, real_setters));

  FALCON_C_API_END(nullptr)
}

PortsHandle SettingRequest_getters(SettingRequestHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument("Null handle passed to SettingRequest_getters");
  }

  SettingRequestSP request = *static_cast<SettingRequestSP *>(handle);

  return new instrument_interfaces::names::PortsSP(request->getters());

  FALCON_C_API_END(nullptr)
}

MapInstrumentPortQuantityHandle
SettingRequest_setters(SettingRequestHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument("Null handle passed to SettingRequest_setters");
  }

  SettingRequestSP request = *static_cast<SettingRequestSP *>(handle);

  return new generic::MapSP<instrument_interfaces::names::InstrumentPort,
                            math::Quantity>(request->setters());

  FALCON_C_API_END(nullptr)
}

StringHandle SettingRequest_message(SettingRequestHandle handle) {
  FALCON_C_API_BEGIN

  if (!handle) {
    throw std::invalid_argument("Null handle passed to SettingRequest_message");
  }

  SettingRequestSP request = *static_cast<SettingRequestSP *>(handle);

  std::string message = request->message();

  return String_create(message.c_str(), message.size());

  FALCON_C_API_END(nullptr)
}

} // extern "C"
