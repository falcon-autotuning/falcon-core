#include "falcon_core/communications/messages/StandardRequest_c_api.h"

#include <falcon_core/generic/String_c_api.h>

#include <falcon_core/communications/messages/StandardRequest.hpp>
#include <string>

using namespace falcon_core;
using namespace falcon_core::communications::messages;

StandardRequestHandle StandardRequest_create(StringHandle message) {
  if (!message) {
    throw std::invalid_argument("Null handle passed to StandardRequest_create");
  }
  std::string real_message = std::string(message->raw, message->length);
  return new StandardRequest(StandardRequest(real_message));
}

void StandardRequest_destroy(StandardRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_destroy");
  }
  delete static_cast<StandardRequest*>(handle);
}

StringHandle StandardRequest_message(StandardRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_message");
  }
  StandardRequest* standard_request = static_cast<StandardRequest*>(handle);
  std::string      msg              = standard_request->message();
  return String_create(msg.c_str(), msg.size());
}

bool StandardRequest_equal(StandardRequestHandle handle,
                           StandardRequestHandle other) {
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
}

bool StandardRequest_not_equal(StandardRequestHandle handle,
                               StandardRequestHandle other) {
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
}

StringHandle StandardRequest_to_json_string(StandardRequestHandle handle) {
  if (!handle) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_to_json_string");
  }
  StandardRequest* standard_request = static_cast<StandardRequest*>(handle);
  std::string      json             = standard_request->to_json_string();
  return String_create(json.c_str(), json.size());
}

StandardRequestHandle StandardRequest_from_json_string(StringHandle json) {
  if (!json) {
    throw std::invalid_argument(
        "Null handle passed to StandardRequest_from_json_string");
  }
  std::string real_json = std::string(json->raw, json->length);
  return new StandardRequest(
      *StandardRequest::from_json_string<StandardRequest>(real_json));
}
