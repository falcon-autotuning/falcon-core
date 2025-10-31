#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/MapInstrumentPortPortTransform_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create_empty() {
    return new falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(
            falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>());
}

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_create(const PairInstrumentPortPortTransformHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data pointer passed to MapInstrumentPortPortTransform_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*reinterpret_cast<
                    std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(
            data[i]));
    }
    return new falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(
            falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(vec));
}

void MapInstrumentPortPortTransform_destroy(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_destroy");
}
    delete static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
}

void MapInstrumentPortPortTransform_insert_or_assign(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key, const PortTransformHandle value) {
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
}

void MapInstrumentPortPortTransform_insert(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key, const PortTransformHandle value) {
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
}

PortTransformHandle MapInstrumentPortPortTransform_at(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_at");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    return new falcon_core::instrument_interfaces::port_transforms::PortTransform(*static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->at(correct_key));
}

void MapInstrumentPortPortTransform_erase(MapInstrumentPortPortTransformHandle handle, const InstrumentPortHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_erase");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->erase(correct_key);
}

size_t MapInstrumentPortPortTransform_size(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_size");
}
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->size();
}

bool MapInstrumentPortPortTransform_empty(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_empty");
}
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->empty();
}


void MapInstrumentPortPortTransform_clear(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_clear");
}
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->clear();
}

bool MapInstrumentPortPortTransform_contains(MapInstrumentPortPortTransformHandle handle, InstrumentPortHandle key) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_contains");
}
    
            if (!key) {
            throw std::invalid_argument("Null key passed to MapInstrumentPortPortTransform_at");
            }
            auto temp_key = *static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(key);
auto correct_key = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(temp_key);
    return static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->contains(correct_key);
}

ListInstrumentPortHandle MapInstrumentPortPortTransform_keys(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_keys");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto keys_sp = map->keys(); // shared_ptr<falcon_core::generic::List<Key>>
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(*keys_sp);
}

ListPortTransformHandle MapInstrumentPortPortTransform_values(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_values");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto values_sp = map->values(); // shared_ptr<falcon_core::generic::List<Value>>
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>(*values_sp);
}

ListPairInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_items(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_items");
}
    auto map = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>> items_sp = map->items(); 
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(items_sp);
}

bool MapInstrumentPortPortTransform_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_equal");
}
    auto listA = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(a);
    auto listB = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(b);
    return *listA == *listB;
}

bool MapInstrumentPortPortTransform_not_equal(MapInstrumentPortPortTransformHandle a, MapInstrumentPortPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_not_equal");
}
    return !MapInstrumentPortPortTransform_equal(a, b);
}

StringHandle      MapInstrumentPortPortTransform_to_json_string(MapInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to MapInstrumentPortPortTransform_to_json_string");
}
std::string json = static_cast<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle)->to_json_string();
  return String_create(json.c_str(), json.size());
}

MapInstrumentPortPortTransformHandle MapInstrumentPortPortTransform_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to MapInstrumentPortPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>::from_json_string<falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>>(json->raw);
  return new falcon_core::generic::Map<falcon_core::instrument_interfaces::names::InstrumentPort,falcon_core::instrument_interfaces::port_transforms::PortTransform>(*ptr);
}
