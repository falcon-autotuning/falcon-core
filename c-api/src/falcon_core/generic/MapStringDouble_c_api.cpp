#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapStringDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapStringDoubleHandle MapStringDouble_create_empty() {
    return new falcon_core::generic::Map<std::string,double>(
            falcon_core::generic::Map<std::string,double>());
}

MapStringDoubleHandle MapStringDouble_create(const PairStringDoubleHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<std::string,double>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<std::string,double>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<std::string,double>(
            falcon_core::generic::Map<std::string,double>(vec));
}

void MapStringDouble_destroy(MapStringDoubleHandle handle) {
    delete static_cast<falcon_core::generic::Map<std::string, double>*>(handle);
}

void MapStringDouble_insert_or_assign(MapStringDoubleHandle handle, const char* key, const double value) {
    auto temp_key = *static_cast<std::string*>(key);
auto correct_key = std::make_shared<std::string>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapStringDouble_insert(MapStringDoubleHandle handle, const char* key, const double value) {
    auto temp_key = *static_cast<std::string*>(key);
auto correct_key = std::make_shared<std::string>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->insert(correct_key,correct_value);
}

double MapStringDouble_at(MapStringDoubleHandle handle, const char* key) {
    auto temp_key = *static_cast<std::string*>(key);
auto correct_key = std::make_shared<std::string>(temp_key);
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->at(correct_key);
}

void MapStringDouble_erase(MapStringDoubleHandle handle, const char* key) {
    auto temp_key = *static_cast<std::string*>(key);
auto correct_key = std::make_shared<std::string>(temp_key);
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->erase(correct_key);
}

size_t MapStringDouble_size(MapStringDoubleHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->size();
}

bool MapStringDouble_empty(MapStringDoubleHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->empty();
}


void MapStringDouble_clear(MapStringDoubleHandle handle) {
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->clear();
}

bool MapStringDouble_contains(MapStringDoubleHandle handle, char* key) {
    auto temp_key = *static_cast<std::string*>(key);
auto correct_key = std::make_shared<std::string>(temp_key);
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->contains(correct_key);
}

ListStringHandle MapStringDouble_keys(MapStringDoubleHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,double>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<std::string>(*keys_sp);
}

ListDoubleHandle MapStringDouble_values(MapStringDoubleHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,double>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<double>(*values_sp);
}

ListPairStringDoubleHandle MapStringDouble_items(MapStringDoubleHandle handle) {
    auto map = static_cast<falcon_core::generic::Map<std::string,double>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<std::string,double>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string,double>>(items_sp);
}

bool MapStringDouble_equal(MapStringDoubleHandle a, MapStringDoubleHandle b) {
    auto listA = static_cast<falcon_core::generic::Map<std::string,double>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<std::string,double>*>(b);
    return *listA == *listB;
}

bool MapStringDouble_not_equal(MapStringDoubleHandle a, MapStringDoubleHandle b) {
    return !MapStringDouble_equal(a, b);
}

const char*      MapStringDouble_to_json_string(MapStringDoubleHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->to_json_string();
  return json.c_str();
}
MapStringDoubleHandle MapStringDouble_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::Map<std::string,double>::from_json_string<falcon_core::generic::Map<std::string,double>>(std::string(json));
  return new falcon_core::generic::Map<std::string,double>(*ptr);
}
