#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInstrumentPortPortTransform_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(); 
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
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>
        (*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(
            data[i])));
    }
    return new falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(vec);
    FALCON_C_API_END(nullptr)
}

void MapInstrumentPortPortTransform_destroy(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    FALCON_C_API_END()
}

void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle,  InstrumentPortHandle key,  PortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_insert_or_assign");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInstrumentPortPortTransform_at");
            }
            auto temp_value = *static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(value);
auto correct_value = std::make_shared<falcon_core::instrument_interfaces::port_transforms::PortTransform>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->insert_or_assign(correct_key,correct_value);
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
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    
            if (!value) {
            throw std::invalid_argument("Null value passed to MapInstrumentPortPortTransform_at");
            }
            auto temp_value = *static_cast<falcon_core::instrument_interfaces::port_transforms::PortTransform*>(value);
auto correct_value = std::make_shared<falcon_core::instrument_interfaces::port_transforms::PortTransform>(temp_value);
    static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->insert(correct_key,correct_value);
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
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    return new falcon_core::instrument_interfaces::port_transforms::PortTransform(*static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->at(correct_key));
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
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->erase(correct_key);
    FALCON_C_API_END()
}

size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->clear();
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
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->contains(correct_key);
    FALCON_C_API_END(false)
}

ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(*keys_sp);
    FALCON_C_API_END(nullptr)
}

ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(*values_sp);
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(items_sp);
    FALCON_C_API_END(nullptr)
}

bool MapInstrumentPortPortTransform_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool MapInstrumentPortPortTransform_not_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_not_equal");
}
    return !MapInstrumentPortPortTransform_equal(a, b);
    FALCON_C_API_END(false)
}

StringHandle      MapInstrumentPortPortTransform_to_json_string(MapInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to MapInstrumentPortPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>::from_json_string<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
