#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapChannelConnections_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapChannelConnectionsHandle MapChannelConnections_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>(); 
    FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle MapChannelConnections_create(const PairChannelConnectionsHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapChannelConnections_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>
        (*static_cast<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>(vec);
    FALCON_C_API_END(nullptr)
}

void MapChannelConnections_destroy(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel, falcon_core::physics::device_structures::Connections>*>(handle);
    FALCON_C_API_END()
}

void MapChannelConnections_insert_or_assign(MapChannelConnectionsHandle handle, const ChannelHandle key, const ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(temp_key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapChannelConnections_at");
            }
            auto temp_value = *static_cast<falcon_core::physics::device_structures::Connections*>(value);
auto correct_value = std::make_shared<falcon_core::physics::device_structures::Connections>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapChannelConnections_insert(MapChannelConnectionsHandle handle, const ChannelHandle key, const ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(temp_key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapChannelConnections_at");
            }
            auto temp_value = *static_cast<falcon_core::physics::device_structures::Connections*>(value);
auto correct_value = std::make_shared<falcon_core::physics::device_structures::Connections>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->insert(correct_key,correct_value);
    FALCON_C_API_END()
}

ConnectionsHandle MapChannelConnections_at(MapChannelConnectionsHandle handle, const ChannelHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(temp_key);
    return new falcon_core::physics::device_structures::Connections(*static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapChannelConnections_erase(MapChannelConnectionsHandle handle, const ChannelHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapChannelConnections_at");
            }
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapChannelConnections_size(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapChannelConnections_empty(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapChannelConnections_clear(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->clear();
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
            auto temp_key = *static_cast<falcon_core::autotuner_interfaces::names::Channel*>(key);
auto correct_key = std::make_shared<falcon_core::autotuner_interfaces::names::Channel>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListChannelHandle MapChannelConnections_keys(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListConnectionsHandle MapChannelConnections_values(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairChannelConnectionsHandle MapChannelConnections_items(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>(items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapChannelConnections_equal(MapChannelConnectionsHandle a, MapChannelConnectionsHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapChannelConnections_not_equal(MapChannelConnectionsHandle a, MapChannelConnectionsHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_not_equal");
}
    return !MapChannelConnections_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapChannelConnections_to_json_string(MapChannelConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapChannelConnections_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapChannelConnectionsHandle MapChannelConnections_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapChannelConnections_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Channel,falcon_core::physics::device_structures::Connections>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
