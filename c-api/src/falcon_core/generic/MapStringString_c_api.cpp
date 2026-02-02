#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapStringString_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapStringHandleStringHandle = falcon_core::generic::Map<std::string, std::string>;
DEFINE_C_API_COPY_TEMPLATE(MapStringString, MACROMapStringHandleStringHandle)
DEFINE_C_API_DESTROY_TEMPLATE(MapStringString, MACROMapStringHandleStringHandle);
DEFINE_C_API_EQUAL_TEMPLATE(MapStringString, MACROMapStringHandleStringHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapStringString, MACROMapStringHandleStringHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(MapStringString, MACROMapStringHandleStringHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapStringString, MACROMapStringHandleStringHandle);

MapStringStringHandle MapStringString_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<std::string,std::string>(std::make_shared<falcon_core::generic::Map<std::string,std::string>>()); 
    FALCON_C_API_END(nullptr)
}

MapStringStringHandle MapStringString_create( PairStringStringHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapStringString_create");
}
    std::vector<falcon_core::generic::PairSP<std::string,std::string>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<std::string,std::string>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<std::string, std::string>(
        std::make_shared<falcon_core::generic::Map<std::string,std::string>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapStringString_insert_or_assign(MapStringStringHandle handle,  StringHandle key,  StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringString_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    
                if (!value) {
                throw std::invalid_argument("Null string handle passed to MapStringString_at");
                }
                auto correct_value = std::string(value->raw, value->length);
    (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapStringString_insert(MapStringStringHandle handle,  StringHandle key,  StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringString_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    
                if (!value) {
                throw std::invalid_argument("Null string handle passed to MapStringString_at");
                }
                auto correct_value = std::string(value->raw, value->length);
    (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

StringHandle MapStringString_at(MapStringStringHandle handle,  StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringString_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    
  auto string =
      (*static_cast<falcon_core::generic::MapSP<std::string, std::string>*>(handle))->at(correct_key);
  return String_create(string.data(), string.size());
            
    FALCON_C_API_END(nullptr)
}

void MapStringString_erase(MapStringStringHandle handle,  StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringString_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapStringString_size(MapStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_size");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapStringString_empty(MapStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapStringString_clear(MapStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapStringString_contains(MapStringStringHandle handle, StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringString_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListStringHandle MapStringString_keys(MapStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle);
    return new falcon_core::generic::ListSP<std::string>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListStringHandle MapStringString_values(MapStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle);
    return new falcon_core::generic::ListSP<std::string>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairStringStringHandle MapStringString_items(MapStringStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringString_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,std::string>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string,std::string>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string,std::string>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
