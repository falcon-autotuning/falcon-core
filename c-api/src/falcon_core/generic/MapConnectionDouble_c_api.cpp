#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapConnectionHandledouble = falcon_core::generic::Map<falcon_core::physics::device_structures::Connection, double>;
DEFINE_C_API_COPY_TEMPLATE(MapConnectionDouble, MACROMapConnectionHandledouble)
DEFINE_C_API_DESTROY_TEMPLATE(MapConnectionDouble, MACROMapConnectionHandledouble);
DEFINE_C_API_EQUAL_TEMPLATE(MapConnectionDouble, MACROMapConnectionHandledouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapConnectionDouble, MACROMapConnectionHandledouble);
DEFINE_C_API_TO_JSON_TEMPLATE(MapConnectionDouble, MACROMapConnectionHandledouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapConnectionDouble, MACROMapConnectionHandledouble);

MapConnectionDoubleHandle MapConnectionDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>(std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>>()); 
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
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,double>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection, double>(
        std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,double>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapConnectionDouble_insert_or_assign(MapConnectionDoubleHandle handle,  ConnectionHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionDouble_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        insert_or_assign(correct_key,correct_value);
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
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        insert(correct_key,correct_value);
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
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->at(correct_key);
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
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapConnectionDouble_size(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapConnectionDouble_empty(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapConnectionDouble_clear(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        clear();
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
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListConnectionHandle MapConnectionDouble_keys(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle MapConnectionDouble_values(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle);
    return new falcon_core::generic::ListSP<double>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionDoubleHandle MapConnectionDouble_items(MapConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionDouble_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,double>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,double>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
