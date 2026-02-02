#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInterpretationContextQuantity_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/math/Quantity.hpp>
#include <falcon_core/autotuner_interfaces/interpretations/InterpretationContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapInterpretationContextHandleQuantityHandle = falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(MapInterpretationContextQuantity, MACROMapInterpretationContextHandleQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(MapInterpretationContextQuantity, MACROMapInterpretationContextHandleQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(MapInterpretationContextQuantity, MACROMapInterpretationContextHandleQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapInterpretationContextQuantity, MACROMapInterpretationContextHandleQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(MapInterpretationContextQuantity, MACROMapInterpretationContextHandleQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapInterpretationContextQuantity, MACROMapInterpretationContextHandleQuantityHandle);

MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>(std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>()); 
    FALCON_C_API_END(nullptr)
}

MapInterpretationContextQuantityHandle MapInterpretationContextQuantity_create( PairInterpretationContextQuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapInterpretationContextQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Map<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapInterpretationContextQuantity_insert_or_assign(MapInterpretationContextQuantityHandle handle,  InterpretationContextHandle key,  QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInterpretationContextQuantity_at");
            }
            auto correct_value = *static_cast<falcon_core::math::QuantitySP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapInterpretationContextQuantity_insert(MapInterpretationContextQuantityHandle handle,  InterpretationContextHandle key,  QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInterpretationContextQuantity_at");
            }
            auto correct_value = *static_cast<falcon_core::math::QuantitySP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

QuantityHandle MapInterpretationContextQuantity_at(MapInterpretationContextQuantityHandle handle,  InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    return new falcon_core::math::QuantitySP((*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapInterpretationContextQuantity_erase(MapInterpretationContextQuantityHandle handle,  InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapInterpretationContextQuantity_size(MapInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapInterpretationContextQuantity_empty(MapInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapInterpretationContextQuantity_clear(MapInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapInterpretationContextQuantity_contains(MapInterpretationContextQuantityHandle handle, InterpretationContextHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInterpretationContextQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::autotuner_interfaces::interpretations::InterpretationContextSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListInterpretationContextHandle MapInterpretationContextQuantity_keys(MapInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListQuantityHandle MapInterpretationContextQuantity_values(MapInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairInterpretationContextQuantityHandle MapInterpretationContextQuantity_items(MapInterpretationContextQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInterpretationContextQuantity_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::autotuner_interfaces::interpretations::InterpretationContext,falcon_core::math::Quantity>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
