#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapIntInt_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapintint = falcon_core::generic::Map<int, int>;
DEFINE_C_API_COPY_TEMPLATE(MapIntInt, MACROMapintint)
DEFINE_C_API_DESTROY_TEMPLATE(MapIntInt, MACROMapintint);
DEFINE_C_API_EQUAL_TEMPLATE(MapIntInt, MACROMapintint);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapIntInt, MACROMapintint);
DEFINE_C_API_TO_JSON_TEMPLATE(MapIntInt, MACROMapintint);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapIntInt, MACROMapintint);

MapIntIntHandle MapIntInt_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<int,int>(std::make_shared<falcon_core::generic::Map<int,int>>()); 
    FALCON_C_API_END(nullptr)
}

MapIntIntHandle MapIntInt_create( PairIntIntHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapIntInt_create");
}
    std::vector<falcon_core::generic::PairSP<int,int>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<int,int>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<int, int>(
        std::make_shared<falcon_core::generic::Map<int,int>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapIntInt_insert_or_assign(MapIntIntHandle handle,  int key,  int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_insert_or_assign");
}
    auto correct_key = key;
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapIntInt_insert(MapIntIntHandle handle,  int key,  int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_insert");
}
    auto correct_key = key;
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

int MapIntInt_at(MapIntIntHandle handle,  int key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_at");
}
    auto correct_key = key;
    return (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->at(correct_key);
    FALCON_C_API_END(0)
}

void MapIntInt_erase(MapIntIntHandle handle,  int key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_erase");
}
    auto correct_key = key;
    return (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapIntInt_size(MapIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_size");
}
    return (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapIntInt_empty(MapIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapIntInt_clear(MapIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapIntInt_contains(MapIntIntHandle handle, int key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_contains");
}
    auto correct_key = key;
    return (*static_cast<falcon_core::generic::MapSP<int,int>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListIntHandle MapIntInt_keys(MapIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<int,int>*>(handle);
    return new falcon_core::generic::ListSP<int>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListIntHandle MapIntInt_values(MapIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<int,int>*>(handle);
    return new falcon_core::generic::ListSP<int>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairIntIntHandle MapIntInt_items(MapIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapIntInt_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<int,int>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<int,int>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int,int>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
