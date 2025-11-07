#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>();
}

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_fill_value(size_t count, PairInstrumentPortPortTransformHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value));
    
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(
        count, stored_obj);
}
 

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairInstrumentPortPortTransform_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(data[i]))); 
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(vec);
}

void ListPairInstrumentPortPortTransform_destroy(ListPairInstrumentPortPortTransformHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
}

size_t ListPairInstrumentPortPortTransform_size(ListPairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->size();
}

bool ListPairInstrumentPortPortTransform_empty(ListPairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->empty();
}

void ListPairInstrumentPortPortTransform_erase_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->erase_at(idx);
}

void ListPairInstrumentPortPortTransform_clear(ListPairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->clear();
}

void ListPairInstrumentPortPortTransform_push_back(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value));
    
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->push_back(stored_obj);
}

bool ListPairInstrumentPortPortTransform_contains(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->contains(stored_obj);
}

size_t ListPairInstrumentPortPortTransform_index(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = std::make_shared<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value));
    
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->index(stored_obj);
}

size_t ListPairInstrumentPortPortTransform_items(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInstrumentPortPortTransform_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(*list->items()[i]);
}
    return n;
}

PairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(*obj);
}

bool ListPairInstrumentPortPortTransform_equal(ListPairInstrumentPortPortTransformHandle a, ListPairInstrumentPortPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(b);
    return *listA == *listB;
}

bool ListPairInstrumentPortPortTransform_not_equal(ListPairInstrumentPortPortTransformHandle a, ListPairInstrumentPortPortTransformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_not_equal");
}
    return !ListPairInstrumentPortPortTransform_equal(a, b);
}

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_intersection(ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*result);
}

StringHandle      ListPairInstrumentPortPortTransform_to_json_string(ListPairInstrumentPortPortTransformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairInstrumentPortPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(*ptr);
}
