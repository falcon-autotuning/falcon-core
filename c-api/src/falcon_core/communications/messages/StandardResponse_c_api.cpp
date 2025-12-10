#include "falcon_core/communications/messages/StandardResponse_c_api.h"

#include <falcon_core/communications/messages/StandardResponse.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
DEFINE_C_API_COPY(StandardResponse);
DEFINE_C_API_DESTROY(StandardResponse);
DEFINE_C_API_EQUAL(StandardResponse);
DEFINE_C_API_NOT_EQUAL(StandardResponse);
DEFINE_C_API_TO_JSON(StandardResponse);
DEFINE_C_API_FROM_JSON(StandardResponse);
StandardResponseHandle StandardResponse_create(StringHandle message) {
  FALCON_C_API_BEGIN
  if (!message) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_create");
  }
  std::string real_message = std::string(message->raw, message->length);
  return new StandardResponseSP(
      std::make_shared<StandardResponse>(real_message));
  FALCON_C_API_END(nullptr)
}

StringHandle StandardResponse_message(StandardResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_message");
  }
  StandardResponseSP response = *static_cast<StandardResponseSP*>(handle);
  std::string        msg      = response->message();
  return String_create(msg.c_str(), msg.size());
  FALCON_C_API_END(nullptr)
}
}
