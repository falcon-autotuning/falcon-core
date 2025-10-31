#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapStringDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>

MapStringDoubleHandle MapStringDouble_create_empty() {
    return new falcon_core::generic::Map<std::string,double>(
            falcon_core::generic::Map<std::string,double>());
}

MapStringDoubleHandle MapStringDouble_create(const PairStringDoubleHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapStringDouble_create");
}
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
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_destroy");
}
    delete static_cast<falcon_core::generic::Map<std::string, double>*>(handle);
}

void MapStringDouble_insert_or_assign(MapStringDoubleHandle handle, const StringHandle key, const double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->insert_or_assign(correct_key,correct_value);
}

void MapStringDouble_insert(MapStringDoubleHandle handle, const StringHandle key, const double value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->insert(correct_key,correct_value);
}

double MapStringDouble_at(MapStringDoubleHandle handle, const StringHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->at(correct_key);
}

void MapStringDouble_erase(MapStringDoubleHandle handle, const StringHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->erase(correct_key);
}

size_t MapStringDouble_size(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_size");
}
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->size();
}

bool MapStringDouble_empty(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_empty");
}
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->empty();
}


void MapStringDouble_clear(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_clear");
}
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->clear();
}

bool MapStringDouble_contains(MapStringDoubleHandle handle, StringHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->contains(correct_key);
}

ListStringHandle MapStringDouble_keys(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_keys");
}
    auto map = static_cast<falcon_core::generic::Map<std::string,double>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<std::string>(*keys_sp);
}

ListDoubleHandle MapStringDouble_values(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_values");
}
    auto map = static_cast<falcon_core::generic::Map<std::string,double>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<double>(*values_sp);
}

ListPairStringDoubleHandle MapStringDouble_items(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_items");
}
    auto map = static_cast<falcon_core::generic::Map<std::string,double>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<std::string,double>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<std::string,double>>(items_sp);
}

bool MapStringDouble_equal(MapStringDoubleHandle a, MapStringDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapStringDouble_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<std::string,double>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<std::string,double>*>(b);
    return *listA == *listB;
}

bool MapStringDouble_not_equal(MapStringDoubleHandle a, MapStringDoubleHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapStringDouble_not_equal");
}
    return !MapStringDouble_equal(a, b);
}

StringHandle      MapStringDouble_to_json_string(MapStringDoubleHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<std::string,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MapStringDoubleHandle MapStringDouble_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to MapStringDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Map<std::string,double>::from_json_string<falcon_core::generic::Map<std::string,double>>(json->raw);
  return new falcon_core::generic::Map<std::string,double>(*ptr);
}
