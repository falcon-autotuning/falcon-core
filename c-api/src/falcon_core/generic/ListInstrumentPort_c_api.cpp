#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>

ListInstrumentPortHandle ListInstrumentPort_create_empty() {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>());
}

ListInstrumentPortHandle ListInstrumentPort_fill_value(size_t count, InstrumentPortHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(count, stored_obj));
}

ListInstrumentPortHandle ListInstrumentPort_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(count));
}

ListInstrumentPortHandle ListInstrumentPort_create(InstrumentPortHandle* data, size_t count) {
    std::vector<falcon_core::instrument_interfaces::names::InstrumentPortSP> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListInstrumentPort_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(data[i]), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(vec));
}

void ListInstrumentPort_destroy(ListInstrumentPortHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListInstrumentPort_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
}

size_t ListInstrumentPort_size(ListInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->size();
}

bool ListInstrumentPort_empty(ListInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->empty();
}

void ListInstrumentPort_erase_at(ListInstrumentPortHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->erase_at(idx);
}

void ListInstrumentPort_clear(ListInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->clear();
}

void ListInstrumentPort_push_back(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->push_back(stored_obj);
}

bool ListInstrumentPort_contains(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->contains(stored_obj);
}

size_t ListInstrumentPort_index(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListInstrumentPort_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->index(stored_obj);
}

size_t ListInstrumentPort_items(ListInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListInstrumentPort_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::instrument_interfaces::names::InstrumentPort(*list->items()[i]);
}
    return n;
}

InstrumentPortHandle ListInstrumentPort_at(ListInstrumentPortHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->at(idx);
    return new falcon_core::instrument_interfaces::names::InstrumentPort(*obj);
}

bool ListInstrumentPort_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(b);
    return *listA == *listB;
}

bool ListInstrumentPort_not_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_not_equal");
}
    return !ListInstrumentPort_equal(a, b);
}

ListInstrumentPortHandle ListInstrumentPort_intersection(ListInstrumentPortHandle handle, ListInstrumentPortHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(*listB));
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(*result);
}

StringHandle      ListInstrumentPort_to_json_string(ListInstrumentPortHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInstrumentPort_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListInstrumentPortHandle ListInstrumentPort_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListInstrumentPort_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>::from_json_string<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(json->raw);
  return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(*ptr);
}
