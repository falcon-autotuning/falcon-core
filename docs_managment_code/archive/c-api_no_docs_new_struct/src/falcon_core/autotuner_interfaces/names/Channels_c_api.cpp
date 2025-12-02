#include "falcon_core/autotuner_interfaces/names/Channels_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Channels.hpp>
#include <string>

#include "falcon_core/generic/ErrorHandling_c_api.h"
#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::autotuner_interfaces::names;

extern "C" {
ChannelsHandle Channels_create_empty() {
  FALCON_C_API_BEGIN
  return new Channels(Channels());
  FALCON_C_API_END(nullptr)
}

ChannelsHandle Channels_create(ListChannelHandle items) {
  FALCON_C_API_BEGIN
  if (!items) {
    throw std::invalid_argument("Channels_create: items cannot be null");
  }
  falcon_core::generic::ListSP<Channel> item_list =
      std::make_shared<falcon_core::generic::List<Channel>>(
          *static_cast<falcon_core::generic::List<Channel>*>(items));
  return new Channels(item_list->items());
  FALCON_C_API_END(nullptr)
}

void Channels_destroy(ChannelsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_destroy: handle cannot be null");
  }
  delete static_cast<Channels*>(handle);
  FALCON_C_API_END()
}

ChannelsHandle Channels_intersection(ChannelsHandle handle,
                                     ChannelsHandle other) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_intersection: handle cannot be null");
  }
  if (!other) {
    throw std::invalid_argument("Channels_intersection: other cannot be null");
  }
  Channels   self  = *static_cast<Channels*>(handle);
  ChannelsSP oself = std::make_shared<Channels>(*static_cast<Channels*>(other));
  return new Channels(self.intersection(oself)->items());
  FALCON_C_API_END(nullptr)
}

void Channels_push_back(ChannelsHandle handle, ChannelHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_push_back: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Channels_push_back: value cannot be null");
  }
  Channels* self = static_cast<Channels*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_value =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              value));
  self->push_back(real_value);
  FALCON_C_API_END()
}

size_t Channels_size(ChannelsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_size: handle cannot be null");
  }
  Channels self = *static_cast<Channels*>(handle);
  return self.size();
  FALCON_C_API_END(0)
}

bool Channels_empty(ChannelsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_empty: handle cannot be null");
  }
  Channels self = *static_cast<Channels*>(handle);
  return self.empty();
  FALCON_C_API_END(false)
}

void Channels_erase_at(ChannelsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_erase_at: handle cannot be null");
  }
  Channels* self = static_cast<Channels*>(handle);
  self->erase_at(idx);
  FALCON_C_API_END()
}

void Channels_clear(ChannelsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_clear: handle cannot be null");
  }
  Channels* self = static_cast<Channels*>(handle);
  self->clear();
  FALCON_C_API_END()
}

ChannelHandle Channels_at(ChannelsHandle handle, size_t idx) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_at: handle cannot be null");
  }
  Channels self = *static_cast<Channels*>(handle);
  return new Channel(*self.at(idx));
  FALCON_C_API_END(nullptr)
}

ListStringHandle Channels_items(ChannelsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_items: handle cannot be null");
  }
  Channels self            = *static_cast<Channels*>(handle);
  auto     list_of_strings = new falcon_core::generic::List<std::string>();
  for (const auto& channel : self.items()) {
    std::string name = channel->name();
    list_of_strings->push_back(name);
  }
  return list_of_strings;
  FALCON_C_API_END(nullptr)
}

bool Channels_contains(ChannelsHandle handle, ChannelHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_contains: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Channels_contains: value cannot be null");
  }
  Channels self = *static_cast<Channels*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_value =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              value));
  return self.contains(real_value);
  FALCON_C_API_END(false)
}

size_t Channels_index(ChannelsHandle handle, ChannelHandle value) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument("Channels_index: handle cannot be null");
  }
  if (!value) {
    throw std::invalid_argument("Channels_index: value cannot be null");
  }
  Channels self = *static_cast<Channels*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_value =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              value));
  return self.index(real_value);
  FALCON_C_API_END(0)
}

bool Channels_equal(ChannelsHandle a, ChannelsHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Channels_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Channels_equal: b cannot be null");
  }
  Channels self_a = *static_cast<Channels*>(a);
  Channels self_b = *static_cast<Channels*>(b);
  return self_a == self_b;
  FALCON_C_API_END(false)
}

bool Channels_not_equal(ChannelsHandle a, ChannelsHandle b) {
  FALCON_C_API_BEGIN
  if (!a) {
    throw std::invalid_argument("Channels_not_equal: a cannot be null");
  }
  if (!b) {
    throw std::invalid_argument("Channels_not_equal: b cannot be null");
  }
  Channels self_a = *static_cast<Channels*>(a);
  Channels self_b = *static_cast<Channels*>(b);
  return self_a != self_b;
  FALCON_C_API_END(false)
}

StringHandle Channels_to_json_string(ChannelsHandle handle) {
  FALCON_C_API_BEGIN
  if (!handle) {
    throw std::invalid_argument(
        "Channels_to_json_string: handle cannot be null");
  }
  Channels    self = *static_cast<Channels*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
  FALCON_C_API_END(nullptr)
}

ChannelsHandle Channels_from_json_string(StringHandle json) {
  FALCON_C_API_BEGIN
  if (!json) {
    throw std::invalid_argument(
        "Channels_from_json_string: json cannot be null");
  }
  std::string raw_json(json->raw);
  auto        ptr = Channels::from_json_string<Channels>(raw_json);
  return new Channels(*ptr);
  FALCON_C_API_END(nullptr)
}
}
