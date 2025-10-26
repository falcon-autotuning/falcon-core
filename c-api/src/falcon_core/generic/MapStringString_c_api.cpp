#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapStringString_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapStringStringHandle MapStringString_create_empty() {
    return new falcon_core::generic::Map<std::string,std::string>(
            falcon_core::generic::Map<std::string,std::string>());
}

MapStringStringHandle MapStringString_create(const PairStringStringHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<std::string,std::string>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<std::string,std::string>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<std::string,std::string>(
            falcon_core::generic::Map<std::string,std::string>(vec));
}

void MapStringString_destroy(MapStringStringHandle handle) {
    delete static_cast<falcon_core::generic::Map<std::string, std::string>*>(handle);
}

void MapStringString_insert_or_assign(MapStringStringHandle handle, const StringHandle key, const StringHandle value) {
    auto correct_key = std::string(key->raw, key->length);
    auto correct_value = std::string(value->raw, value->length);
    static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapStringString_insert(MapStringStringHandle handle, const StringHandle key, const StringHandle value) {
    auto correct_key = std::string(key->raw, key->length);
    auto correct_value = std::string(value->raw, value->length);
    static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->insert(correct_key,correct_value);
}

StringHandle MapStringString_at(MapStringStringHandle handle, const StringHandle key) {
    auto correct_key = std::string(key->raw, key->length);
    
  auto string =
      static_cast<falcon_core::generic::Map<std::string, std::string>*>(handle)
          ->at(correct_key);
  return String_create(string.data(), string.size());
            
}

void MapStringString_erase(MapStringStringHandle handle, const StringHandle key) {
    auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->erase(correct_key);
}

size_t MapStringString_size(MapStringStringHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->size();
}

bool MapStringString_empty(MapStringStringHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->empty();
}


void MapStringString_clear(MapStringStringHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->clear();
}

bool MapStringString_contains(MapStringStringHandle handle, StringHandle key) {
    auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->contains(correct_key);
}

ListStringHandle MapStringString_keys(MapStringStringHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<std::string>(*keys_sp);
}

ListStringHandle MapStringString_values(MapStringStringHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<std::string>(*values_sp);
}

ListPairStringStringHandle MapStringString_items(MapStringStringHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<std::string,std::string>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string,std::string>>(items_sp);
}

bool MapStringString_equal(MapStringStringHandle a, MapStringStringHandle b) {
    auto listA = static_cast<falcon_core::generic::Map<std::string,std::string>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<std::string,std::string>*>(b);
    return *listA == *listB;
}

bool MapStringString_not_equal(MapStringStringHandle a, MapStringStringHandle b) {
    return !MapStringString_equal(a, b);
}

StringHandle      MapStringString_to_json_string(MapStringStringHandle handle) {
std::string json = static_cast<falcon_core::generic::Map<std::string,std::string>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}
MapStringStringHandle MapStringString_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::Map<std::string,std::string>::from_json_string<falcon_core::generic::Map<std::string,std::string>>(json->raw);
  return new falcon_core::generic::Map<std::string,std::string>(*ptr);
}
