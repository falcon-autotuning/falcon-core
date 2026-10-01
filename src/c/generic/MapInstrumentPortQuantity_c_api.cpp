#include <falcon-core/generic/Map.hpp>
#include "falcon-core/generic/MapInstrumentPortQuantity_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/Pair.hpp>
#include <falcon-core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon-core/math/Quantity.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapInstrumentPortHandleQuantityHandle = falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(MapInstrumentPortQuantity, MACROMapInstrumentPortHandleQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(MapInstrumentPortQuantity, MACROMapInstrumentPortHandleQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(MapInstrumentPortQuantity, MACROMapInstrumentPortHandleQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapInstrumentPortQuantity, MACROMapInstrumentPortHandleQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(MapInstrumentPortQuantity, MACROMapInstrumentPortHandleQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapInstrumentPortQuantity, MACROMapInstrumentPortHandleQuantityHandle);

MapInstrumentPortQuantityHandle MapInstrumentPortQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>(std::make_shared<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>>()); 
    FALCON_C_API_END(nullptr)
}

MapInstrumentPortQuantityHandle MapInstrumentPortQuantity_create( PairInstrumentPortQuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapInstrumentPortQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapInstrumentPortQuantity_insert_or_assign(MapInstrumentPortQuantityHandle handle,  InstrumentPortHandle key,  QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInstrumentPortQuantity_at");
            }
            auto correct_value = *static_cast<falcon_core::math::QuantitySP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapInstrumentPortQuantity_insert(MapInstrumentPortQuantityHandle handle,  InstrumentPortHandle key,  QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInstrumentPortQuantity_at");
            }
            auto correct_value = *static_cast<falcon_core::math::QuantitySP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

QuantityHandle MapInstrumentPortQuantity_at(MapInstrumentPortQuantityHandle handle,  InstrumentPortHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    return new falcon_core::math::QuantitySP((*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapInstrumentPortQuantity_erase(MapInstrumentPortQuantityHandle handle,  InstrumentPortHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapInstrumentPortQuantity_size(MapInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapInstrumentPortQuantity_empty(MapInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapInstrumentPortQuantity_clear(MapInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapInstrumentPortQuantity_contains(MapInstrumentPortQuantityHandle handle, InstrumentPortHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortQuantity_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListInstrumentPortHandle MapInstrumentPortQuantity_keys(MapInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListQuantityHandle MapInstrumentPortQuantity_values(MapInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortQuantityHandle MapInstrumentPortQuantity_items(MapInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortQuantity_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::math::Quantity>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
