#include "falcon_core/communications/messages/StandardResponse_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/StandardResponse.hpp>
#include <string>

using namespace falcon_core;
using namespace falcon_core::communications::messages;

StandardResponseHandle StandardResponse_create(StringHandle message) {
  if (!message) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_create");
  }
  std::string real_message = std::string(message->raw, message->length);
  return new StandardResponse(StandardResponse(real_message));
}

void StandardResponse_destroy(StandardResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_destroy");
  }
  delete static_cast<StandardResponse*>(handle);
}

StringHandle StandardResponse_message(StandardResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_message");
  }
  StandardResponse* response = static_cast<StandardResponse*>(handle);
  std::string       msg      = response->message();
  return String_create(msg.c_str(), msg.size());
}

bool StandardResponse_equal(StandardResponseHandle handle,
                            StandardResponseHandle other) {
  if (!handle) {
    throw std::invalid_argument("Null handle passed to StandardResponse_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to StandardResponse_equal");
  }
  StandardResponse* response  = static_cast<StandardResponse*>(handle);
  StandardResponse* oresponse = static_cast<StandardResponse*>(other);
  return (*response) == (*oresponse);
}

bool StandardResponse_not_equal(StandardResponseHandle handle,
                                StandardResponseHandle other) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_not_equal");
  }
  if (!other) {
    throw std::invalid_argument(
        "Null other handle passed to StandardResponse_not_equal");
  }
  StandardResponse* response  = static_cast<StandardResponse*>(handle);
  StandardResponse* oresponse = static_cast<StandardResponse*>(other);
  return (*response) != (*oresponse);
}

StringHandle StandardResponse_to_json_string(StandardResponseHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_to_json_string");
  }
  StandardResponse* response = static_cast<StandardResponse*>(handle);
  std::string       json     = response->to_json_string();
  return String_create(json.c_str(), json.size());
}

StandardResponseHandle StandardResponse_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to StandardResponse_from_json_string");
  }
  std::string json_str = std::string(json->raw, json->length);
  return new StandardResponse(
      *StandardResponse::from_json_string<StandardResponse>(json_str));
}
