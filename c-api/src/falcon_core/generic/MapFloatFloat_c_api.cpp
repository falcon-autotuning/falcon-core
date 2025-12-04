#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapFloatFloat_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapFloatFloatHandle MapFloatFloat_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<float,float>(); 
    FALCON_C_API_END(nullptr)
}

MapFloatFloatHandle MapFloatFloat_create( PairFloatFloatHandle* data, size_t count) {
    FALCON_C_API_BEGIN
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
    FALCON_C_API_END(nullptr)
}

void MapFloatFloat_destroy(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_destroy");
}
    delete static_cast<falcon_core::generic::Map<float, float>*>(handle);
    FALCON_C_API_END()
}

void MapFloatFloat_insert_or_assign(MapFloatFloatHandle handle,  float key,  float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_insert_or_assign");
}
    auto correct_key = key;
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<float,float>*>(handle)->insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapFloatFloat_insert(MapFloatFloatHandle handle,  float key,  float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_insert");
}
    auto correct_key = key;
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<float,float>*>(handle)->insert(correct_key,correct_value);
    FALCON_C_API_END()
}

float MapFloatFloat_at(MapFloatFloatHandle handle,  float key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_at");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->at(correct_key);
    FALCON_C_API_END(0.0)
}

void MapFloatFloat_erase(MapFloatFloatHandle handle,  float key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_erase");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapFloatFloat_size(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_size");
}
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapFloatFloat_empty(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_empty");
}
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapFloatFloat_clear(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_clear");
}
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->clear();
    FALCON_C_API_END()
}

bool MapFloatFloat_contains(MapFloatFloatHandle handle, float key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_contains");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<float,float>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListFloatHandle MapFloatFloat_keys(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_keys");
}
    auto map = static_cast<falcon_core::generic::Map<float,float>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<float>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListFloatHandle MapFloatFloat_values(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_values");
}
    auto map = static_cast<falcon_core::generic::Map<float,float>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<float>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairFloatFloatHandle MapFloatFloat_items(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_items");
}
    auto map = static_cast<falcon_core::generic::Map<float,float>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<float,float>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<float,float>>(*items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapFloatFloat_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<float,float>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<float,float>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapFloatFloat_not_equal(MapFloatFloatHandle a, MapFloatFloatHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_not_equal");
}
    return !MapFloatFloat_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapFloatFloat_to_json_string(MapFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapFloatFloat_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<float,float>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapFloatFloatHandle MapFloatFloat_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapFloatFloat_from_json_string");
}
  auto ptr = falcon_core::generic::Map<float,float>::from_json_string<falcon_core::generic::Map<float,float>>(json->raw);
  return new falcon_core::generic::Map<float,float>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
