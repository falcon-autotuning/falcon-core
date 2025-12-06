#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::autotuner_interfaces::names;

extern "C" {
ChannelHandle Channel_create(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument("Channel_create: name cannot be null");
  }
  std::string real_name(name->raw, name->length);
  return new ChannelSP(std::make_shared<Channel>(real_name));
  FALCON_C_API_END(nullptr)
}

void Channel_destroy(ChannelHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channel_destroy: handle cannot be null");
  }
  delete static_cast<ChannelSP*>(handle);
  FALCON_C_API_END()
}

StringHandle Channel_name(ChannelHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channel_name: handle cannot be null");
  }
  ChannelSP self = *static_cast<ChannelSP*>(handle);
  return String_create(self->name().c_str(), self->name().size());
  FALCON_C_API_END(nullptr)
}

bool Channel_equal(ChannelHandle a, ChannelHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Channel_equal: handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Channel_equal: handle cannot be null");
  }
  ChannelSP self_a = *static_cast<ChannelSP*>(a);
  ChannelSP self_b = *static_cast<ChannelSP*>(b);
  return *self_a == *self_b;
  FALCON_C_API_END(false)
}

bool Channel_not_equal(ChannelHandle a, ChannelHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Channel_not_equal: handle cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Channel_not_equal: handle cannot be null");
  }
  ChannelSP self_a = *static_cast<ChannelSP*>(a);
  ChannelSP self_b = *static_cast<ChannelSP*>(b);
  return *self_a != *self_b;
  FALCON_C_API_END(false)
}

StringHandle Channel_to_json_string(ChannelHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Channel_to_json_string: handle cannot be null");
  }
  ChannelSP   self = *static_cast<ChannelSP*>(handle);
  std::string json = self->to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ChannelHandle Channel_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Channel_from_json_string: json cannot be null");
  }
  std::string json_str(json->raw);
  auto        ptr = Channel::from_json_string<Channel>(json_str);
  return new ChannelSP(ptr);
  FALCON_C_API_END(nullptr)
}
}
