#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapConnectionFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapConnectionHandlefloat = falcon_core::generic::Map<falcon_core::physics::device_structures::Connection, float>;
DEFINE_C_API_COPY_TEMPLATE(MapConnectionFloat, MACROMapConnectionHandlefloat)
DEFINE_C_API_DESTROY_TEMPLATE(MapConnectionFloat, MACROMapConnectionHandlefloat);
DEFINE_C_API_EQUAL_TEMPLATE(MapConnectionFloat, MACROMapConnectionHandlefloat);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapConnectionFloat, MACROMapConnectionHandlefloat);
DEFINE_C_API_TO_JSON_TEMPLATE(MapConnectionFloat, MACROMapConnectionHandlefloat);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapConnectionFloat, MACROMapConnectionHandlefloat);

MapConnectionFloatHandle MapConnectionFloat_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>(std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>()); 
    FALCON_C_API_END(nullptr)
}

MapConnectionFloatHandle MapConnectionFloat_create( PairConnectionFloatHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapConnectionFloat_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection,float>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection, float>(
        std::make_shared<falcon_core::generic::Map<falcon_core::physics::device_structures::Connection,float>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapConnectionFloat_insert_or_assign(MapConnectionFloatHandle handle,  ConnectionHandle key,  float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapConnectionFloat_insert(MapConnectionFloatHandle handle,  ConnectionHandle key,  float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

float MapConnectionFloat_at(MapConnectionFloatHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->at(correct_key);
    FALCON_C_API_END(0.0)
}

void MapConnectionFloat_erase(MapConnectionFloatHandle handle,  ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapConnectionFloat_size(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapConnectionFloat_empty(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapConnectionFloat_clear(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapConnectionFloat_contains(MapConnectionFloatHandle handle, ConnectionHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapConnectionFloat_at");
            }
            auto correct_key = *static_cast<falcon_core::physics::device_structures::ConnectionSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListConnectionHandle MapConnectionFloat_keys(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListFloatHandle MapConnectionFloat_values(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle);
    return new falcon_core::generic::ListSP<float>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionFloatHandle MapConnectionFloat_items(MapConnectionFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapConnectionFloat_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::physics::device_structures::Connection,float>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection,float>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
