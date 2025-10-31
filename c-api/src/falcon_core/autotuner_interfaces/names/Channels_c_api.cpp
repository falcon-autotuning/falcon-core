#include "falcon_core/autotuner_interfaces/names/Channels_c_api.h"

#include <falcon_core/autotuner_interfaces/names/Channels.hpp>
#include <string>

#include "falcon_core/generic/String_c_api.h"
using namespace falcon_core::autotuner_interfaces::names;

extern "C" {

ChannelsHandle Channels_create_empty() { return new Channels(Channels()); }

ChannelsHandle Channels_create(ListChannelHandle items) {
  falcon_core::generic::ListSP<Channel> item_list =
      std::make_shared<falcon_core::generic::List<Channel>>(
          *static_cast<falcon_core::generic::List<Channel>*>(items));
  return new Channels(item_list->items());
}

void Channels_destroy(ChannelsHandle handle) {
  delete static_cast<Channels*>(handle);
}

ChannelsHandle Channels_intersection(ChannelsHandle handle,
                                     ChannelsHandle other) {
  Channels   self  = *static_cast<Channels*>(handle);
  ChannelsSP oself = std::make_shared<Channels>(*static_cast<Channels*>(other));
  return new Channels(self.intersection(oself)->items());
}

void Channels_push_back(ChannelsHandle handle, ChannelHandle value) {
  Channels self = *static_cast<Channels*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_value =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              value));
  self.push_back(real_value);
}

size_t Channels_size(ChannelsHandle handle) {
  Channels self = *static_cast<Channels*>(handle);
  return self.size();
}

bool Channels_empty(ChannelsHandle handle) {
  Channels self = *static_cast<Channels*>(handle);
  return self.empty();
}

void Channels_erase_at(ChannelsHandle handle, size_t idx) {
  Channels self = *static_cast<Channels*>(handle);
  self.erase_at(idx);
}

void Channels_clear(ChannelsHandle handle) {
  Channels self = *static_cast<Channels*>(handle);
  self.clear();
}

ChannelHandle Channels_at(ChannelsHandle handle, size_t idx) {
  Channels self = *static_cast<Channels*>(handle);
  return new Channel(*self.at(idx));
}

ListStringHandle Channels_items(ChannelsHandle handle) {
  Channels self            = *static_cast<Channels*>(handle);
  auto     list_of_strings = new falcon_core::generic::List<std::string>();
  for (const auto& channel : self.items()) {
    std::string name = channel->name();
    list_of_strings->push_back(name);
  }
  return list_of_strings;
}

bool Channels_contains(ChannelsHandle handle, ChannelHandle value) {
  Channels self = *static_cast<Channels*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_value =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              value));
  return self.contains(real_value);
}

size_t Channels_index(ChannelsHandle handle, ChannelHandle value) {
  Channels self = *static_cast<Channels*>(handle);
  falcon_core::autotuner_interfaces::names::ChannelSP real_value =
      std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(
          *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(
              value));
  return self.index(real_value);
}

bool Channels_equal(ChannelsHandle a, ChannelsHandle b) {
  Channels self_a = *static_cast<Channels*>(a);
  Channels self_b = *static_cast<Channels*>(b);
  return self_a == self_b;
}

bool Channels_not_equal(ChannelsHandle a, ChannelsHandle b) {
  Channels self_a = *static_cast<Channels*>(a);
  Channels self_b = *static_cast<Channels*>(b);
  return self_a != self_b;
}

StringHandle Channels_to_json_string(ChannelsHandle handle) {
  Channels    self = *static_cast<Channels*>(handle);
  std::string json = self.to_json_string();
  return String_create(json.c_str(), json.size());
}

ChannelsHandle Channels_from_json_string(StringHandle json) {
  std::string raw_json(json->raw);
  auto        ptr = Channels::from_json_string<Channels>(raw_json);
  return new Channels(*ptr);
}

#ifdef __cplusplus
}
#endif
