#include <falcon-core/generic/Map.hpp>
#include "falcon-core/generic/MapChannelConnections_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/Pair.hpp>
#include <falcon-core/autotuner_interfaces/names/Channel.hpp>
#include <falcon-core/physics/device_structures/Connections.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapChannelHandleConnectionsHandle = falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>;
DEFINE_C_API_COPY_TEMPLATE(MapChannelConnections, MACROMapChannelHandleConnectionsHandle)
DEFINE_C_API_DESTROY_TEMPLATE(MapChannelConnections, MACROMapChannelHandleConnectionsHandle);
DEFINE_C_API_EQUAL_TEMPLATE(MapChannelConnections, MACROMapChannelHandleConnectionsHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapChannelConnections, MACROMapChannelHandleConnectionsHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(MapChannelConnections, MACROMapChannelHandleConnectionsHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapChannelConnections, MACROMapChannelHandleConnectionsHandle);

MapChannelConnectionsHandle MapChannelConnections_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>(std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>()); 
    FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle MapChannelConnections_create( PairChannelConnectionsHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapChannelConnections_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>(
        std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapChannelConnections_insert_or_assign(MapChannelConnectionsHandle handle,  ChannelHandle key,  ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapChannelConnections_at");
            }
            auto correct_value = *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapChannelConnections_insert(MapChannelConnectionsHandle handle,  ChannelHandle key,  ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapChannelConnections_at");
            }
            auto correct_value = *static_cast<falcon_core::physics::device_structures::ConnectionsSP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

ConnectionsHandle MapChannelConnections_at(MapChannelConnectionsHandle handle,  ChannelHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(key);
    return new falcon_core::physics::device_structures::ConnectionsSP((*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapChannelConnections_erase(MapChannelConnectionsHandle handle,  ChannelHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapChannelConnections_size(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapChannelConnections_empty(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapChannelConnections_clear(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapChannelConnections_contains(MapChannelConnectionsHandle handle, ChannelHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::ChannelSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListChannelHandle MapChannelConnections_keys(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListConnectionsHandle MapChannelConnections_values(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairChannelConnectionsHandle MapChannelConnections_items(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
