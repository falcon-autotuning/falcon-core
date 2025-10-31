#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::autotuner_interfaces::names;

extern "C" {

ChannelHandle Channel_create(StringHandle name) {
  std::string real_name(name->raw, name->length);
  return new Channel(real_name);
}

void Channel_destroy(ChannelHandle handle) {
  Channel self = *static_cast<Channel*>(handle);
  delete static_cast<Channel*>(handle);
}

StringHandle Channel_name(ChannelHandle handle) {
  Channel self = *static_cast<Channel*>(handle);
  return String_create(self.name().c_str(), self.name().size());
}

bool Channel_equal(ChannelHandle a, ChannelHandle b) {
  Channel self_a = *static_cast<Channel*>(a);
  Channel self_b = *static_cast<Channel*>(b);
  return self_a == self_b;
}

bool Channel_not_equal(ChannelHandle a, ChannelHandle b) {
  Channel self_a = *static_cast<Channel*>(a);
  Channel self_b = *static_cast<Channel*>(b);
  return self_a != self_b;
}

StringHandle Channel_to_json_string(ChannelHandle handle) {
  Channel     self = *static_cast<Channel*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

ChannelHandle Channel_from_json_string(StringHandle json) {
  std::string json_str(json->raw);
  auto        ptr = Channel::from_json_string<Channel>(json_str);
  return new Channel(*ptr);
}

#ifdef __cplusplus
}
#endif
