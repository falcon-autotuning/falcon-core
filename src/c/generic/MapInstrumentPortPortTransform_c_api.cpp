#include <falcon-core/generic/Map.hpp>
#include "falcon-core/generic/MapInstrumentPortPortTransform_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/Pair.hpp>
#include <falcon-core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon-core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include <falcon-core/instrument_interfaces/Waveform.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROMapInstrumentPortHandlePortTransformHandle = falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>;
DEFINE_C_API_COPY_TEMPLATE(MapInstrumentPortPortTransform, MACROMapInstrumentPortHandlePortTransformHandle)
DEFINE_C_API_DESTROY_TEMPLATE(MapInstrumentPortPortTransform, MACROMapInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_EQUAL_TEMPLATE(MapInstrumentPortPortTransform, MACROMapInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(MapInstrumentPortPortTransform, MACROMapInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(MapInstrumentPortPortTransform, MACROMapInstrumentPortHandlePortTransformHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(MapInstrumentPortPortTransform, MACROMapInstrumentPortHandlePortTransformHandle);

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(std::make_shared<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>()); 
    FALCON_C_API_END(nullptr)
}

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create( PairInstrumentPortPortTransformHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapInstrumentPortPortTransform_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(data[i]));
    }
    return new falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        std::make_shared<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(vec));
    FALCON_C_API_END(nullptr)
}

void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle,  InstrumentPortHandle key,  PortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_value = *static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransformSP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        insert_or_assign(correct_key,correct_value);
    FALCON_C_API_END()
}

void MapInstrumentPortPortTransform_insert(MapInstrumentPortPortTransformHandle handle,  InstrumentPortHandle key,  PortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_insert");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_value = *static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransformSP*>(value);
    (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        insert(correct_key,correct_value);
    FALCON_C_API_END()
}

PortTransformHandle MapInstrumentPortPortTransform_at(MapInstrumentPortPortTransformHandle handle,  InstrumentPortHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    return new falcon_core::instrument_interfaces::port_transforms::PortTransformSP((*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->at(correct_key));
    FALCON_C_API_END(nullptr)
}

void MapInstrumentPortPortTransform_erase(MapInstrumentPortPortTransformHandle handle,  InstrumentPortHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        erase(correct_key);
    FALCON_C_API_END()
}

size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_size");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        size();
    FALCON_C_API_END(0)
}

bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_empty");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        empty();
    FALCON_C_API_END(false)
}

void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_clear");
}
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        clear();
    FALCON_C_API_END()
}

bool MapInstrumentPortPortTransform_contains(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto correct_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPortSP*>(key);
    return (*static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->
        contains(correct_key);
    FALCON_C_API_END(false)
}

ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_keys");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>(map->keys());
    FALCON_C_API_END(nullptr)
}

ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_values");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>(map->values());
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_items");
}
    auto map = *static_cast<falcon_core::generic::MapSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>> items_sp = map->items(); 
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(items_sp);
    FALCON_C_API_END(nullptr)
}
}
