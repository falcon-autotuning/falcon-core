#include "falcon_core/communications/messages/StandardResponse_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/StandardResponse.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
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

void StandardResponse_destroy(StandardResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_destroy");
  }
  delete static_cast<StandardResponseSP*>(handle);
  FALCON_C_API_END()
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

bool StandardResponse_equal(StandardResponseHandle handle,
                            StandardResponseHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to StandardResponse_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to StandardResponse_equal");
  }
  StandardResponseSP response  = *static_cast<StandardResponseSP*>(handle);
  StandardResponseSP oresponse = *static_cast<StandardResponseSP*>(other);
  return (*response) == (*oresponse);
  FALCON_C_API_END(false)
}

bool StandardResponse_not_equal(StandardResponseHandle handle,
                                StandardResponseHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_not_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to StandardResponse_not_equal");
  }
  StandardResponseSP response  = *static_cast<StandardResponseSP*>(handle);
  StandardResponseSP oresponse = *static_cast<StandardResponseSP*>(other);
  return (*response) != (*oresponse);
  FALCON_C_API_END(false)
}

StringHandle StandardResponse_to_json_string(StandardResponseHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_to_json_string");
  }
  StandardResponseSP response = *static_cast<StandardResponseSP*>(handle);
  std::string        json     = response->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

StandardResponseHandle StandardResponse_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_from_json_string");
  }
  std::string json_str = std::string(json->raw, json->length);
  return new StandardResponseSP(
      StandardResponse::from_json_string<StandardResponse>(json_str));
  FALCON_C_API_END(nullptr)
}
}
