#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapConnectionFloatHandle MapConnectionFloat_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(); 
    FALCON_C_API_END(nullptr)
}

MapConnectionFloatHandle MapConnectionFloat_create( PairConnectionFloatHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapConnectionFloat_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>
        (*static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(vec);
    FALCON_C_API_END(nullptr)
}

void MapConnectionFloat_destroy(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection, float>*>(handle);
    FALCON_C_API_END()
}

void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle,  ConnectionHandle key,  float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapConnectionFloat_insert(MapConnectionFloatHandle handle,  ConnectionHandle key,  float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->insert(correct_key,correct_value);
    FALCON_C_API_END()
}

float MapConnectionFloat_at(MapConnectionFloatHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->at(correct_key);
    FALCON_C_API_END(0.0)
}

void MapConnectionFloat_erase(MapConnectionFloatHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapConnectionFloat_size(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapConnectionFloat_empty(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapConnectionFloat_clear(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->clear();
    FALCON_C_API_END()
}

bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<float>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>(*items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapConnectionFloat_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapConnectionFloat_not_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_not_equal");
}
    return !MapConnectionFloat_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapConnectionFloat_to_json_string(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapConnectionFloatHandle MapConnectionFloat_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapConnectionFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>::from_json_string<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
