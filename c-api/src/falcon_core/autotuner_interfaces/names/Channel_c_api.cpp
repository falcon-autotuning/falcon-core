#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <string>

#include "falcon_core/Precompiled_c_api.h"

using namespace falcon_core::autotuner_interfaces::names;

extern "C" {
DEFINE_C_API_COPY(Channel);
DEFINE_C_API_DESTROY(Channel);
DEFINE_C_API_EQUAL(Channel);
DEFINE_C_API_NOT_EQUAL(Channel);
DEFINE_C_API_TO_JSON(Channel);
DEFINE_C_API_FROM_JSON(Channel);
ChannelHandle Channel_create(StringHandle name) {
  FALCON_C_API_BEGIN
  if (!name) {
    throw std::invalid_argument("Channel_create: name cannot be null");
  }
  std::string real_name(name->raw, name->length);
  return new ChannelSP(std::make_shared<Channel>(real_name));
  FALCON_C_API_END(nullptr)
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
}
