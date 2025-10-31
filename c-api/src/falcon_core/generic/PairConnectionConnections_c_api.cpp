#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>

PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second) {
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionConnections_create");
                }
                auto first_obj= std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(first),[](falcon_core::physics::device_structures::Connection*) {});
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionConnections_create");
                }
                auto second_obj= std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(second),[](falcon_core::physics::device_structures::Connections*) {});
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(first_obj, second_obj);
}

void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_destroy");
}
    delete static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
}

ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_first");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::physics::device_structures::Connection(*pair->first());
}

ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_second");
}
    auto pair = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::physics::device_structures::Connections(*pair->second());
}

bool PairConnectionConnections_equal(PairConnectionConnectionsHandle a, PairConnectionConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(b);
    return *pair_a == *pair_b;
}

bool PairConnectionConnections_not_equal(PairConnectionConnectionsHandle a, PairConnectionConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_not_equal");
}
    auto pair_a = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(a);
    auto pair_b = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(b);
    return *pair_a != *pair_b;
}

StringHandle      PairConnectionConnections_to_json_string(PairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

PairConnectionConnectionsHandle PairConnectionConnections_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionConnections_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>>(json->raw);
  return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>(*ptr);
}
