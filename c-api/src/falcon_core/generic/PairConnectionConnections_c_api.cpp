#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second) {
    FALCON_C_API_BEGIN
    
                if (!first) {
                throw std::invalid_argument("Null value passed to PairConnectionConnections_create");
                }
                auto first_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(first);
    
                if (!second) {
                throw std::invalid_argument("Null value passed to PairConnectionConnections_create");
                }
                auto second_obj= *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(second);
    return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(
        std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>
            (first_obj, second_obj));
    FALCON_C_API_END(nullptr)
}

void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_destroy");
}
    delete static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    FALCON_C_API_END()
}

ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_first");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(pair->first());
    FALCON_C_API_END(nullptr)
}

ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_second");
}
    auto pair = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connections>(pair->second());
    FALCON_C_API_END(nullptr)
}

bool PairConnectionConnections_equal(PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(other);
    return *pair_a == *pair_b;
    FALCON_C_API_END(false)
}

bool PairConnectionConnections_not_equal(PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_not_equal");
}
    auto pair_a = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(handle);
    auto pair_b = *static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(other);
    return *pair_a != *pair_b;
    FALCON_C_API_END(false)
}

StringHandle      PairConnectionConnections_to_json_string(PairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to PairConnectionConnections_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

PairConnectionConnectionsHandle PairConnectionConnections_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to PairConnectionConnections_from_json_string");
}
  auto ptr = falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>::from_json_string<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>>(json->raw);
  return new falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,falcon_core::physics::device_structures::Connections>(ptr);
    FALCON_C_API_END(nullptr)
}
}
