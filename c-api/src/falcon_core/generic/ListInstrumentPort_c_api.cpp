#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListInstrumentPort_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListInstrumentPortHandle= falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>;
DEFINE_C_API_COPY_TEMPLATE(ListInstrumentPort, MACROListInstrumentPortHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListInstrumentPort, MACROListInstrumentPortHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListInstrumentPort, MACROListInstrumentPortHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListInstrumentPort, MACROListInstrumentPortHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListInstrumentPort, MACROListInstrumentPortHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListInstrumentPort, MACROListInstrumentPortHandle);
ListInstrumentPortHandle ListInstrumentPort_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>(std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>());
    FALCON_C_API_END(nullptr)
}

ListInstrumentPortHandle ListInstrumentPort_fill_value(size_t count, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>(
        std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListInstrumentPortHandle ListInstrumentPort_create(InstrumentPortHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListInstrumentPort_create");
}
    std::vector<falcon_core::instrument_interfaces::names::InstrumentPortSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>(
        std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListInstrumentPort_size(ListInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListInstrumentPort_empty(ListInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListInstrumentPort_erase_at(ListInstrumentPortHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListInstrumentPort_clear(ListInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListInstrumentPort_push_back(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListInstrumentPort_contains(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListInstrumentPort_index(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListInstrumentPort_items(ListInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListInstrumentPort_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

InstrumentPortHandle ListInstrumentPort_at(ListInstrumentPortHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(obj);
    FALCON_C_API_END(nullptr)
}

ListInstrumentPortHandle ListInstrumentPort_intersection(ListInstrumentPortHandle handle, ListInstrumentPortHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>(result);
    FALCON_C_API_END(nullptr)
}
}
