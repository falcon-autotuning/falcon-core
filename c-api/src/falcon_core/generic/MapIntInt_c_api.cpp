#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapIntInt_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapIntIntHandle MapIntInt_create_empty() {
    return new falcon_core::generic::Map<int,int>(
            falcon_core::generic::Map<int,int>());
}

MapIntIntHandle MapIntInt_create(const PairIntIntHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapIntInt_create");
}
    std::vector<falcon_core::generic::PairSP<int,int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<int,int>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<int,int>(
            falcon_core::generic::Map<int,int>(vec));
}

void MapIntInt_destroy(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_destroy");
}
    delete static_cast<falcon_core::generic::Map<int, int>*>(handle);
}

void MapIntInt_insert_or_assign(MapIntIntHandle handle, const int key, const int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_insert_or_assign");
}
    auto correct_key = key;
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<int,int>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapIntInt_insert(MapIntIntHandle handle, const int key, const int value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_insert");
}
    auto correct_key = key;
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<int,int>*>(handle)->insert(correct_key,correct_value);
}

int MapIntInt_at(MapIntIntHandle handle, const int key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_at");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<int,int>*>(handle)->at(correct_key);
}

void MapIntInt_erase(MapIntIntHandle handle, const int key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_erase");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<int,int>*>(handle)->erase(correct_key);
}

size_t MapIntInt_size(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_size");
}
    return static_cast<falcon_core::generic::Map<int,int>*>(handle)->size();
}

bool MapIntInt_empty(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_empty");
}
    return static_cast<falcon_core::generic::Map<int,int>*>(handle)->empty();
}


void MapIntInt_clear(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_clear");
}
    return static_cast<falcon_core::generic::Map<int,int>*>(handle)->clear();
}

bool MapIntInt_contains(MapIntIntHandle handle, int key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_contains");
}
    auto correct_key = key;
    return static_cast<falcon_core::generic::Map<int,int>*>(handle)->contains(correct_key);
}

ListIntHandle MapIntInt_keys(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_keys");
}
    auto map = static_cast<falcon_core::generic::Map<int,int>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<int>(*keys_sp);
}

ListIntHandle MapIntInt_values(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_values");
}
    auto map = static_cast<falcon_core::generic::Map<int,int>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<int>(*values_sp);
}

ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_items");
}
    auto map = static_cast<falcon_core::generic::Map<int,int>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<int,int>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<int,int>>(items_sp);
}

bool MapIntInt_equal(MapIntIntHandle a, MapIntIntHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapIntInt_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<int,int>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<int,int>*>(b);
    return *listA == *listB;
}

bool MapIntInt_not_equal(MapIntIntHandle a, MapIntIntHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapIntInt_not_equal");
}
    return !MapIntInt_equal(a, b);
}

StringHandle      MapIntInt_to_json_string(MapIntIntHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<int,int>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MapIntIntHandle MapIntInt_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to MapIntInt_from_json_string");
}
  auto ptr = falcon_core::generic::Map<int,int>::from_json_string<falcon_core::generic::Map<int,int>>(json->raw);
  return new falcon_core::generic::Map<int,int>(*ptr);
}
