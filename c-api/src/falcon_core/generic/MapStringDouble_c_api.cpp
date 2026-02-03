#include <falcon_core\generic/Map.hpp>
#include "falcon_core\generic\MapStringDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapStringHandledouble = falcon_core::generic::Map<std::string, double>;
DEFINE_C_API_COPY_TEMPLATE(MapStringDouble, MACROMapStringHandledouble)
DEFINE_C_API_DESTROY_TEMPLATE(MapStringDouble, MACROMapStringHandledouble);
DEFINE_C_API_EQUAL_TEMPLATE(MapStringDouble, MACROMapStringHandledouble);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapStringDouble, MACROMapStringHandledouble);
DEFINE_C_API_TO_JSON_TEMPLATE(MapStringDouble, MACROMapStringHandledouble);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapStringDouble, MACROMapStringHandledouble);

MapStringDoubleHandle MapStringDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<std::string,double>(std::make_shared<falcon_core::generic::Map<std::string,double>>()); 
    FALCON_C_API_END(nullptr)
}

MapStringDoubleHandle MapStringDouble_create( PairStringDoubleHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapStringDouble_create");
}
    std::vector<falcon_core::generic::PairSP<std::string,double>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<std::string,double>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<std::string, double>(
        std::make_shared<falcon_core::generic::Map<std::string,double>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapStringDouble_insert_or_assign(MapStringDoubleHandle handle,  StringHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapStringDouble_insert(MapStringDoubleHandle handle,  StringHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

double MapStringDouble_at(MapStringDoubleHandle handle,  StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->at(correct_key);
    FALCON_C_API_END(0.0)
}

void MapStringDouble_erase(MapStringDoubleHandle handle,  StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapStringDouble_size(MapStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_size");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapStringDouble_empty(MapStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapStringDouble_clear(MapStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapStringDouble_contains(MapStringDoubleHandle handle, StringHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null string handle passed to MapStringDouble_at");
                                           }
            auto correct_key = std::string(key->raw, key->length);
    return (*static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListStringHandle MapStringDouble_keys(MapStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle);
    return new falcon_core::generic::ListSP<std::string>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle MapStringDouble_values(MapStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle);
    return new falcon_core::generic::ListSP<double>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairStringDoubleHandle MapStringDouble_items(MapStringDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapStringDouble_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<std::string,double>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string,double>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<std::string,double>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
