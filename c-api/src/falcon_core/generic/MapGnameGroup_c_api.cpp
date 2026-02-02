#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapGnameGroup_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include <falcon_core/physics/config/core/Group.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapGnameHandleGroupHandle = falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>;
DEFINE_C_API_COPY_TEMPLATE(MapGnameGroup, MACROMapGnameHandleGroupHandle)
DEFINE_C_API_DESTROY_TEMPLATE(MapGnameGroup, MACROMapGnameHandleGroupHandle);
DEFINE_C_API_EQUAL_TEMPLATE(MapGnameGroup, MACROMapGnameHandleGroupHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapGnameGroup, MACROMapGnameHandleGroupHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(MapGnameGroup, MACROMapGnameHandleGroupHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapGnameGroup, MACROMapGnameHandleGroupHandle);

MapGnameGroupHandle MapGnameGroup_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>(std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>()); 
    FALCON_C_API_END(nullptr)
}

MapGnameGroupHandle MapGnameGroup_create( PairGnameGroupHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapGnameGroup_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname, falcon_core::physics::config::core::Group>(
        std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapGnameGroup_insert_or_assign(MapGnameGroupHandle handle,  GnameHandle key,  GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapGnameGroup_at");
            }
            auto correct_value = *static_cast<falcon_core::physics::config::core::GroupSP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapGnameGroup_insert(MapGnameGroupHandle handle,  GnameHandle key,  GroupHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapGnameGroup_at");
            }
            auto correct_value = *static_cast<falcon_core::physics::config::core::GroupSP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

GroupHandle MapGnameGroup_at(MapGnameGroupHandle handle,  GnameHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(key);
    return new falcon_core::physics::config::core::GroupSP((*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapGnameGroup_erase(MapGnameGroupHandle handle,  GnameHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapGnameGroup_size(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapGnameGroup_empty(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapGnameGroup_clear(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapGnameGroup_contains(MapGnameGroupHandle handle, GnameHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapGnameGroup_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::names::GnameSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListGnameHandle MapGnameGroup_keys(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListGroupHandle MapGnameGroup_values(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::physics::config::core::Group>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairGnameGroupHandle MapGnameGroup_items(MapGnameGroupHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapGnameGroup_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::names::Gname,falcon_core::physics::config::core::Group>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
