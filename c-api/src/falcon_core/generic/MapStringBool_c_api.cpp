#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapStringBool_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapStringHandlebool = falcon_core::generic::Map<std::string, bool>;
DEFINE_C_API_COPY_TEMPLATE(MapStringBool, MACROMapStringHandlebool)
DEFINE_C_API_DESTROY_TEMPLATE(MapStringBool, MACROMapStringHandlebool);
DEFINE_C_API_EQUAL_TEMPLATE(MapStringBool, MACROMapStringHandlebool);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapStringBool, MACROMapStringHandlebool);
DEFINE_C_API_TO_JSON_TEMPLATE(MapStringBool, MACROMapStringHandlebool);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapStringBool, MACROMapStringHandlebool);

MapStringBoolHandle MapStringBool_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<std::string,bool>(std::make_shared<falcon_core::generic::Map<std::string,bool>>()); 
    FALCON_C_API_END(nullptr)
}

MapStringBoolHandle MapStringBool_create( PairStringBoolHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapStringBool_create");
}
    std::vector<falcon_core::generic::PairSP<std::string,bool>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<std::string,bool>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<std::string, bool>(
        std::make_shared<falcon_core::generic::Map<std::string,bool>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapStringBool_insert_or_assign(MapStringBoolHandle handle,  StringHandle key,  bool value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringBool_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapStringBool_insert(MapStringBoolHandle handle,  StringHandle key,  bool value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringBool_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

bool MapStringBool_at(MapStringBoolHandle handle,  StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringBool_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->at(correct_key);
    FALCON_C_API_END(false)
}

void MapStringBool_erase(MapStringBoolHandle handle,  StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringBool_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapStringBool_size(MapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_size");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapStringBool_empty(MapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapStringBool_clear(MapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapStringBool_contains(MapStringBoolHandle handle, StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringBool_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListStringHandle MapStringBool_keys(MapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle);
    return new falcon_core::generic::ListSP<std::string>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListBoolHandle MapStringBool_values(MapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle);
    return new falcon_core::generic::ListSP<bool>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairStringBoolHandle MapStringBool_items(MapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringBool_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,bool>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string,bool>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string,bool>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
