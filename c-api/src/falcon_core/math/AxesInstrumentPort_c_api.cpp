#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesInstrumentPort_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesInstrumentPortHandle AxesInstrumentPort_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>());
    FALCON_C_API_END(nullptr)
}

AxesInstrumentPortHandle AxesInstrumentPort_create(ListInstrumentPortHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesInstrumentPort_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(data);
    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(
            std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesInstrumentPort_destroy(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    FALCON_C_API_END()
}

size_t AxesInstrumentPort_size(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesInstrumentPort_empty(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesInstrumentPort_erase_at(AxesInstrumentPortHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesInstrumentPort_clear(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->clear();
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
            auto stored_obj = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(*static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->push_back(stored_obj);
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
            auto stored_obj = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(*static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->contains(stored_obj);
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
            auto stored_obj = std::make_shared<falcon_core::instrument_interfaces::names::InstrumentPort>(*static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->index(stored_obj);
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
    auto list = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::instrument_interfaces::names::InstrumentPort(*list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

InstrumentPortHandle AxesInstrumentPort_at(AxesInstrumentPortHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->at(idx);
    return new falcon_core::instrument_interfaces::names::InstrumentPort(*obj);
    FALCON_C_API_END(nullptr)
}

bool AxesInstrumentPort_equal(AxesInstrumentPortHandle a, AxesInstrumentPortHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesInstrumentPort_not_equal(AxesInstrumentPortHandle a, AxesInstrumentPortHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_not_equal");
}
    return !AxesInstrumentPort_equal(a, b);
    FALCON_C_API_END(false)
}

AxesInstrumentPortHandle AxesInstrumentPort_intersection(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>(*listB));
    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesInstrumentPort_to_json_string(AxesInstrumentPortHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesInstrumentPortHandle AxesInstrumentPort_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesInstrumentPort_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>::from_json_string<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
