#include "falcon_core/communications/messages/StandardRequest_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/StandardRequest.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"

using namespace falcon_core;
using namespace falcon_core::communications::messages;

extern "C" {
StandardRequestHandle StandardRequest_create(StringHandle message) {
  FALCON_C_API_BEGIN
  if (!message) {
    throw std::invalid_argument("Null handle passed to StandardRequest_create");
  }
  std::string real_message = std::string(message->raw, message->length);
  return new StandardRequest(StandardRequest(real_message));
  FALCON_C_API_END(nullptr)
}

void StandardRequest_destroy(StandardRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_destroy");
  }
  delete static_cast<StandardRequest*>(handle);
  FALCON_C_API_END()
}

StringHandle StandardRequest_message(StandardRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_message");
  }
  StandardRequest* standard_request = static_cast<StandardRequest*>(handle);
  std::string      msg              = standard_request->message();
  return String_create(msg.c_str(), msg.size());
  FALCON_C_API_END(nullptr)
}

bool StandardRequest_equal(StandardRequestHandle handle,
                           StandardRequestHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Null handle passed to StandardRequest_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to StandardRequest_equal");
  }
  StandardRequest* standard_request = static_cast<StandardRequest*>(handle);
  StandardRequest* other_request    = static_cast<StandardRequest*>(other);
  return (*standard_request) == (*other_request);
  FALCON_C_API_END(false)
}

bool StandardRequest_not_equal(StandardRequestHandle handle,
                               StandardRequestHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_not_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to StandardRequest_not_equal");
  }
  StandardRequest* standard_request = static_cast<StandardRequest*>(handle);
  StandardRequest* other_request    = static_cast<StandardRequest*>(other);
  return (*standard_request) != (*other_request);
  FALCON_C_API_END(false)
}

StringHandle StandardRequest_to_json_string(StandardRequestHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_to_json_string");
  }
  StandardRequest* standard_request = static_cast<StandardRequest*>(handle);
  std::string      json             = standard_request->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

StandardRequestHandle StandardRequest_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_from_json_string");
  }
  std::string real_json = std::string(json->raw, json->length);
  return new StandardRequest(
      *StandardRequest::from_json_string<StandardRequest>(real_json));
  FALCON_C_API_END(nullptr)
}
}
