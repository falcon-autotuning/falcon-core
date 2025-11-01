#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesInstrumentPort_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>

AxesInstrumentPortHandle AxesInstrumentPort_create_empty() {
    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>());
}

AxesInstrumentPortHandle AxesInstrumentPort_create_raw(const InstrumentPortHandle* data, size_t count) {
    std::vector<falcon_core::instrument_interfaces::names::InstrumentPortSP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesInstrumentPort_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(data[i]), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(vec));
}

AxesInstrumentPortHandle AxesInstrumentPort_create(ListInstrumentPortHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesInstrumentPort_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(data);
    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(
            std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(list));
}

void AxesInstrumentPort_destroy(AxesInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
}

size_t AxesInstrumentPort_size(AxesInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->size();
}

bool AxesInstrumentPort_empty(AxesInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->empty();
}

void AxesInstrumentPort_erase_at(AxesInstrumentPortHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->erase_at(idx);
}

void AxesInstrumentPort_clear(AxesInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->clear();
}

void AxesInstrumentPort_push_back(AxesInstrumentPortHandle handle, InstrumentPortHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesInstrumentPort_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->push_back(stored_obj);
}

bool AxesInstrumentPort_contains(AxesInstrumentPortHandle handle, InstrumentPortHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesInstrumentPort_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->contains(stored_obj);
}

size_t AxesInstrumentPort_index(AxesInstrumentPortHandle handle, InstrumentPortHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesInstrumentPort_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->index(stored_obj);
}

size_t AxesInstrumentPort_items(AxesInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size) {
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
}

InstrumentPortHandle AxesInstrumentPort_at(AxesInstrumentPortHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->at(idx);
    return new falcon_core::instrument_interfaces::names::InstrumentPort(*obj);
}

bool AxesInstrumentPort_equal(AxesInstrumentPortHandle a, AxesInstrumentPortHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(b);
    return *listA == *listB;
}

bool AxesInstrumentPort_not_equal(AxesInstrumentPortHandle a, AxesInstrumentPortHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_not_equal");
}
    return !AxesInstrumentPort_equal(a, b);
}

AxesInstrumentPortHandle AxesInstrumentPort_intersection(AxesInstrumentPortHandle handle, AxesInstrumentPortHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>(*listB));
    return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(result);
}

StringHandle      AxesInstrumentPort_to_json_string(AxesInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesInstrumentPort_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesInstrumentPortHandle AxesInstrumentPort_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesInstrumentPort_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>::from_json_string<falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::instrument_interfaces::names::InstrumentPort>(*ptr);
}
