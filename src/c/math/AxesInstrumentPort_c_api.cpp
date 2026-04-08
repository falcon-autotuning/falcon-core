#include <falcon-core/math/Axes.hpp>
#include "falcon-core/math/AxesInstrumentPort_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/List.hpp>
#include <falcon-core/instrument_interfaces/names/InstrumentPort.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesInstrumentPortHandle= falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>;
DEFINE_C_API_COPY_TEMPLATE(AxesInstrumentPort, MACROAxesInstrumentPortHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesInstrumentPort, MACROAxesInstrumentPortHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesInstrumentPort, MACROAxesInstrumentPortHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesInstrumentPort, MACROAxesInstrumentPortHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesInstrumentPort, MACROAxesInstrumentPortHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesInstrumentPort, MACROAxesInstrumentPortHandle);
AxesInstrumentPortHandle AxesInstrumentPort_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>(
        std::make_shared<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>());
    FALCON_C_API_END(nullptr)
}

AxesInstrumentPortHandle AxesInstrumentPort_create(ListInstrumentPortHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesInstrumentPort_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>(
            std::make_shared<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesInstrumentPort_size(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesInstrumentPort_empty(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesInstrumentPort_erase_at(AxesInstrumentPortHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesInstrumentPort_clear(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesInstrumentPort_push_back(AxesInstrumentPortHandle handle, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesInstrumentPort_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesInstrumentPort_contains(AxesInstrumentPortHandle handle, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesInstrumentPort_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesInstrumentPort_index(AxesInstrumentPortHandle handle, InstrumentPortHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesInstrumentPort_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesInstrumentPort_items(AxesInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesInstrumentPort_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

InstrumentPortHandle AxesInstrumentPort_at(AxesInstrumentPortHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(obj);
    FALCON_C_API_END(nullptr)
}

AxesInstrumentPortHandle AxesInstrumentPort_intersection(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::instrument_interfaces::names::InstrumentPort>(std::make_shared<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>(result));
    FALCON_C_API_END(nullptr)
}
}
