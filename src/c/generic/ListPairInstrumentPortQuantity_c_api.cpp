#include <falcon-core/generic/List.hpp>
#include "falcon-core/generic/ListPairInstrumentPortQuantity_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/Pair.hpp>
#include <falcon-core/instrument_interfaces/names/InstrumentPort.hpp>
#include <falcon-core/math/Quantity.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairInstrumentPortQuantityHandle= falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairInstrumentPortQuantity, MACROListPairInstrumentPortQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairInstrumentPortQuantity, MACROListPairInstrumentPortQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairInstrumentPortQuantity, MACROListPairInstrumentPortQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairInstrumentPortQuantity, MACROListPairInstrumentPortQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairInstrumentPortQuantity, MACROListPairInstrumentPortQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairInstrumentPortQuantity, MACROListPairInstrumentPortQuantityHandle);
ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>>());
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_fill_value(size_t count, PairInstrumentPortQuantityHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_create(PairInstrumentPortQuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairInstrumentPortQuantity_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairInstrumentPortQuantity_size(ListPairInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairInstrumentPortQuantity_empty(ListPairInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairInstrumentPortQuantity_erase_at(ListPairInstrumentPortQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairInstrumentPortQuantity_clear(ListPairInstrumentPortQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairInstrumentPortQuantity_push_back(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairInstrumentPortQuantity_contains(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairInstrumentPortQuantity_index(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairInstrumentPortQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairInstrumentPortQuantity_items(ListPairInstrumentPortQuantityHandle handle, PairInstrumentPortQuantityHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairInstrumentPortQuantity_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_at(ListPairInstrumentPortQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairInstrumentPortQuantityHandle ListPairInstrumentPortQuantity_intersection(ListPairInstrumentPortQuantityHandle handle, ListPairInstrumentPortQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairInstrumentPortQuantity_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::instrument_interfaces::names::InstrumentPort, falcon_core::math::Quantity>>(result);
    FALCON_C_API_END(nullptr)
}
}
