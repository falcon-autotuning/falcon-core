#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairInstrumentPortPortTransform_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>>());
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_fill_value(size_t count, PairInstrumentPortPortTransformHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>SP*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_create(PairInstrumentPortPortTransformHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairInstrumentPortPortTransform_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>SP*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairInstrumentPortPortTransform_destroy(ListPairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairInstrumentPortPortTransform_size(ListPairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairInstrumentPortPortTransform_empty(ListPairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairInstrumentPortPortTransform_erase_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairInstrumentPortPortTransform_clear(ListPairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairInstrumentPortPortTransform_push_back(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>SP*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairInstrumentPortPortTransform_contains(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>SP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairInstrumentPortPortTransform_index(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>SP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairInstrumentPortPortTransform_items(ListPairInstrumentPortPortTransformHandle handle, PairInstrumentPortPortTransformHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInstrumentPortPortTransform_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>SP(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_at(ListPairInstrumentPortPortTransformHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairInstrumentPortPortTransform_equal(ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairInstrumentPortPortTransform_not_equal(ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_intersection(ListPairInstrumentPortPortTransformHandle handle, ListPairInstrumentPortPortTransformHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairInstrumentPortPortTransform_to_json_string(ListPairInstrumentPortPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortPortTransform_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortPortTransformHandle ListPairInstrumentPortPortTransform_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairInstrumentPortPortTransform_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::instrument_interfaces::port_transforms::PortTransform>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
