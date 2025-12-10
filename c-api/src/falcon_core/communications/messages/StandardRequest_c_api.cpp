#include "falcon_core/communications/messages/StandardRequest_c_api.h"

#include <falcon_core/communications/messages/StandardRequest.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
DEFINE_C_API_COPY(StandardRequest);
DEFINE_C_API_DESTROY(StandardRequest);
DEFINE_C_API_EQUAL(StandardRequest);
DEFINE_C_API_NOT_EQUAL(StandardRequest);
DEFINE_C_API_TO_JSON(StandardRequest);
DEFINE_C_API_FROM_JSON(StandardRequest);
StandardRequestHandle StandardRequest_create(StringHandle message) {
  FALCON_C_API_BEGIN
  if (!message) {
    throw std::invalid_argument("Null handle passed to StandardRequest_create");
  }
  std::string real_message = std::string(message->raw, message->length);
  return new StandardRequestSP(std::make_shared<StandardRequest>(real_message));
  FALCON_C_API_END(nullptr)
}

StringHandle StandardRequest_message(StandardRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_message");
  }
  StandardRequestSP standard_request = *static_cast<StandardRequestSP*>(handle);
  std::string       msg              = standard_request->message();
  return String_create(msg.c_str(), msg.size());
  FALCON_C_API_END(nullptr)
}
}
