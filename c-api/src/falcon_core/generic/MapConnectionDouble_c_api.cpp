#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapConnectionDoubleHandle MapConnectionDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>(); 
    FALCON_C_API_END(nullptr)
}

MapConnectionDoubleHandle MapConnectionDouble_create( PairConnectionDoubleHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapConnectionDouble_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,double>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>>
        (*static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>(vec);
    FALCON_C_API_END(nullptr)
}

void MapConnectionDouble_destroy(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection, double>*>(handle);
    FALCON_C_API_END()
}

void MapConnectionDouble_insert_or_assign(MapConnectionDoubleHandle handle,  ConnectionHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionDouble_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapConnectionDouble_insert(MapConnectionDoubleHandle handle,  ConnectionHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionDouble_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    auto correct_value = value;
    static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->insert(correct_key,correct_value);
    FALCON_C_API_END()
}

double MapConnectionDouble_at(MapConnectionDoubleHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionDouble_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->at(correct_key);
    FALCON_C_API_END(0.0)
}

void MapConnectionDouble_erase(MapConnectionDoubleHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionDouble_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapConnectionDouble_size(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapConnectionDouble_empty(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapConnectionDouble_clear(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->clear();
    FALCON_C_API_END()
}

bool MapConnectionDouble_contains(MapConnectionDoubleHandle handle, ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionDouble_at");
            }
            auto temp_key = *static_cast<falcon_core::physics::device_structures::Connection*>(key);
auto correct_key = std::make_shared<falcon_core::physics::device_structures::Connection>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListConnectionHandle MapConnectionDouble_keys(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle MapConnectionDouble_values(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<double>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairConnectionDoubleHandle MapConnectionDouble_items(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>>(*items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapConnectionDouble_equal(MapConnectionDoubleHandle a, MapConnectionDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapConnectionDouble_not_equal(MapConnectionDoubleHandle a, MapConnectionDoubleHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_not_equal");
}
    return !MapConnectionDouble_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapConnectionDouble_to_json_string(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapConnectionDoubleHandle MapConnectionDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapConnectionDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>::from_json_string<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
