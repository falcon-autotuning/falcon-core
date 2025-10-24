#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapStringBool_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapStringBoolHandle MapStringBool_create_empty() {
    return new falcon_core::generic::Map<std::string,bool>(
            falcon_core::generic::Map<std::string,bool>());
}

MapStringBoolHandle MapStringBool_create(const PairStringBoolHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<std::string,bool>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<std::string,bool>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<std::string,bool>(
            falcon_core::generic::Map<std::string,bool>(vec));
}

void MapStringBool_destroy(MapStringBoolHandle handle) {
    delete static_cast<falcon_core::generic::Map<std::string, bool>*>(handle);
}

void MapStringBool_insert_or_assign(MapStringBoolHandle handle, const StringHandle key, const bool value) {
    auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapStringBool_insert(MapStringBoolHandle handle, const StringHandle key, const bool value) {
    auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->insert(correct_key,correct_value);
}

bool MapStringBool_at(MapStringBoolHandle handle, const StringHandle key) {
    auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->at(correct_key);
}

void MapStringBool_erase(MapStringBoolHandle handle, const StringHandle key) {
    auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->erase(correct_key);
}

size_t MapStringBool_size(MapStringBoolHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->size();
}

bool MapStringBool_empty(MapStringBoolHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->empty();
}


void MapStringBool_clear(MapStringBoolHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->clear();
}

bool MapStringBool_contains(MapStringBoolHandle handle, StringHandle key) {
    auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->contains(correct_key);
}

ListStringHandle MapStringBool_keys(MapStringBoolHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,bool>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<std::string>(*keys_sp);
}

ListBoolHandle MapStringBool_values(MapStringBoolHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,bool>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<bool>(*values_sp);
}

ListPairStringBoolHandle MapStringBool_items(MapStringBoolHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,bool>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<std::string,bool>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string,bool>>(items_sp);
}

bool MapStringBool_equal(MapStringBoolHandle a, MapStringBoolHandle b) {
    auto listA = static_cast<falcon_core::generic::Map<std::string,bool>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<std::string,bool>*>(b);
    return *listA == *listB;
}

bool MapStringBool_not_equal(MapStringBoolHandle a, MapStringBoolHandle b) {
    return !MapStringBool_equal(a, b);
}

StringHandle      MapStringBool_to_json_string(MapStringBoolHandle handle) {
std::string json = static_cast<falcon_core::generic::Map<std::string,bool>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
MapStringBoolHandle MapStringBool_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Map<std::string,bool>::from_json_string<falcon_core::generic::Map<std::string,bool>>(json->raw);
  return new falcon_core::generic::Map<std::string,bool>(*ptr);
}
