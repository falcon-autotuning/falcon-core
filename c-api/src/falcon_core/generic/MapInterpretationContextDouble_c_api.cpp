#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInterpretationContextDouble_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>()); 
    FALCON_C_API_END(nullptr)
}

MapInterpretationContextDoubleHandle MapInterpretationContextDouble_create( PairInterpretationContextDoubleHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapInterpretationContextDouble_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>(
        std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapInterpretationContextDouble_destroy(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_destroy");
}
    delete static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, double>*>(handle);
    FALCON_C_API_END()
}

void MapInterpretationContextDouble_insert_or_assign(MapInterpretationContextDoubleHandle handle,  InterpretationContextHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextDouble_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapInterpretationContextDouble_insert(MapInterpretationContextDoubleHandle handle,  InterpretationContextHandle key,  double value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextDouble_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    auto correct_value = value;
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

double MapInterpretationContextDouble_at(MapInterpretationContextDoubleHandle handle,  InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextDouble_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->at(correct_key);
    FALCON_C_API_END(0.0)
}

void MapInterpretationContextDouble_erase(MapInterpretationContextDoubleHandle handle,  InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextDouble_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapInterpretationContextDouble_size(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapInterpretationContextDouble_empty(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapInterpretationContextDouble_clear(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapInterpretationContextDouble_contains(MapInterpretationContextDoubleHandle handle, InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextDouble_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListInterpretationContextHandle MapInterpretationContextDouble_keys(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListDoubleHandle MapInterpretationContextDouble_values(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    return new falcon_core::generic::ListSP<double>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextDoubleHandle MapInterpretationContextDouble_items(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapInterpretationContextDouble_equal(MapInterpretationContextDoubleHandle handle, MapInterpretationContextDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_equal");
}
    auto listA = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    auto listB = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapInterpretationContextDouble_not_equal(MapInterpretationContextDoubleHandle handle, MapInterpretationContextDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle);
    auto listB = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

StringHandle      MapInterpretationContextDouble_to_json_string(MapInterpretationContextDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextDouble_to_json_string");
}
std::string json = (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>*>(handle))->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapInterpretationContextDoubleHandle MapInterpretationContextDouble_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapInterpretationContextDouble_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>::from_json_string<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>>(json->raw);
  return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,double>(ptr);
    FALCON_C_API_END(nullptr)
}
}
