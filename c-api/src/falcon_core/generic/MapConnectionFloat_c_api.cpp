#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>

MapConnectionFloatHandle MapConnectionFloat_create_empty() {
    return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(
            falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>());
}

MapConnectionFloatHandle MapConnectionFloat_create(const PairConnectionFloatHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapConnectionFloat_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(
            falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(vec));
}

void MapConnectionFloat_destroy(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection, float>*>(handle);
}

void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle, const ConnectionHandle key, const float value) {
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
}

void MapConnectionFloat_insert(MapConnectionFloatHandle handle, const ConnectionHandle key, const float value) {
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
}

float MapConnectionFloat_at(MapConnectionFloatHandle handle, const ConnectionHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->at(correct_key);
}

void MapConnectionFloat_erase(MapConnectionFloatHandle handle, const ConnectionHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->erase(correct_key);
}

size_t MapConnectionFloat_size(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->size();
}

bool MapConnectionFloat_empty(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->empty();
}


void MapConnectionFloat_clear(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->clear();
}

bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->contains(correct_key);
}

ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*keys_sp);
}

ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<float>(*values_sp);
}

ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>(items_sp);
}

bool MapConnectionFloat_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(b);
    return *listA == *listB;
}

bool MapConnectionFloat_not_equal(MapConnectionFloatHandle a, MapConnectionFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_not_equal");
}
    return !MapConnectionFloat_equal(a, b);
}

StringHandle      MapConnectionFloat_to_json_string(MapConnectionFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MapConnectionFloatHandle MapConnectionFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to MapConnectionFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>::from_json_string<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>(*ptr);
}
