#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>

PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairChannelConnections_create");
                }
                auto first_obj= std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(static_cast<falcon_core::autotuner_interfaces::names::Channel*>(first),[](falcon_core::autotuner_interfaces::names::Channel*) {});
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairChannelConnections_create");
                }
                auto second_obj= std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(second),[](falcon_core::physics::device_structures::Connections*) {});
    return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>(first_obj, second_obj);
}

void PairChannelConnections_destroy(PairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(handle);
}

ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::autotuner_interfaces::names::Channel(*pair->first());
}

ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::physics::device_structures::Connections(*pair->second());
}

bool PairChannelConnections_equal(PairChannelConnectionsHandle a, PairChannelConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(b);
    return *pair_a == *pair_b;
}

bool PairChannelConnections_not_equal(PairChannelConnectionsHandle a, PairChannelConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairChannelConnections_to_json_string(PairChannelConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairChannelConnections_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairChannelConnectionsHandle PairChannelConnections_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairChannelConnections_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>::from_json_string<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>(*ptr);
}
