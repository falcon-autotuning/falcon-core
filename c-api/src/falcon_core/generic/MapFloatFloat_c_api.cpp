#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapFloatFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapFloatFloatHandle MapFloatFloat_create_empty() {
    return new falcon_core::generic::Map<float,float>(); 
}

MapFloatFloatHandle MapFloatFloat_create(const PairFloatFloatHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapFloatFloat_create");
}
    std::vector<falcon_core::generic::PairSP<float,float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<float,float>>
        (*static_cast<falcon_core::generic::Pair<float,float>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<float,float>(vec);
}

void MapFloatFloat_destroy(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_destroy");
}
    delete static_cast<falcon_core::generic::Map<float, float>*>(handle);
}

void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle, const float key, const float value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_insert_or_assign");
}
    auto correct_key = key;
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<float,float>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapFloatFloat_insert(MapFloatFloatHandle handle, const float key, const float value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_insert");
}
    auto correct_key = key;
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<float,float>*>(handle)->insert(correct_key,correct_value);
}

float MapFloatFloat_at(MapFloatFloatHandle handle, const float key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_at");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->at(correct_key);
}

void MapFloatFloat_erase(MapFloatFloatHandle handle, const float key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_erase");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->erase(correct_key);
}

size_t MapFloatFloat_size(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_size");
}
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->size();
}

bool MapFloatFloat_empty(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_empty");
}
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->empty();
}


void MapFloatFloat_clear(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_clear");
}
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->clear();
}

bool MapFloatFloat_contains(MapFloatFloatHandle handle, float key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_contains");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->contains(correct_key);
}

ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_keys");
}
    auto map = static_cast<falcon_core::generic::Map<float,float>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<float>(*keys_sp);
}

ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_values");
}
    auto map = static_cast<falcon_core::generic::Map<float,float>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<float>(*values_sp);
}

ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_items");
}
    auto map = static_cast<falcon_core::generic::Map<float,float>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<float,float>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<float,float>>(items_sp);
}

bool MapFloatFloat_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<float,float>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<float,float>*>(b);
    return *listA == *listB;
}

bool MapFloatFloat_not_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_not_equal");
}
    return !MapFloatFloat_equal(a, b);
}

StringHandle      MapFloatFloat_to_json_string(MapFloatFloatHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<float,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MapFloatFloatHandle MapFloatFloat_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to MapFloatFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Map<float,float>::from_json_string<falcon_core::generic::Map<float,float>>(json->raw);
  return new falcon_core::generic::Map<float,float>(*ptr);
}
