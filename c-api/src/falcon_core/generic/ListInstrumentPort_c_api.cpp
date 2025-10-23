#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include <falcon_core/instrument_interfaces/names/InstrumentPort.hpp>

ListInstrumentPortHandle ListInstrumentPort_create_empty() {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>());
}

ListInstrumentPortHandle ListInstrumentPort_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(count));
}

void ListInstrumentPort_destroy(ListInstrumentPortHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
}

size_t ListInstrumentPort_size(ListInstrumentPortHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->size();
}

bool ListInstrumentPort_empty(ListInstrumentPortHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->empty();
}

void ListInstrumentPort_erase_at(ListInstrumentPortHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->erase_at(idx);
}

void ListInstrumentPort_clear(ListInstrumentPortHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->clear();
}

bool ListInstrumentPort_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b) {
    auto& listA = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>*>(a);
    auto& listB = *static_cast<std::shared_ptr<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>*>(b);
    return *listA == *listB;
}

bool ListInstrumentPort_not_equal(ListInstrumentPortHandle a, ListInstrumentPortHandle b) {
    return !ListInstrumentPort_equal(a, b);
}

ListInstrumentPortHandle ListInstrumentPort_intersection(ListInstrumentPortHandle handle, ListInstrumentPortHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>>(*listB));
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(*result);
}

ListInstrumentPortHandle ListInstrumentPort_fill_value(size_t count, InstrumentPortHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(count, stored_obj));
}

ListInstrumentPortHandle ListInstrumentPort_create(const InstrumentPortHandle* data, size_t count) {
    std::vector<falcon_core::instrument_interfaces::names::InstrumentPortSP> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(data[i]), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>(vec));
}

void ListInstrumentPort_push_back(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->push_back(stored_obj);
}

InstrumentPortHandle ListInstrumentPort_at(ListInstrumentPortHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->at(idx);
    return new falcon_core::instrument_interfaces::names::InstrumentPort(*obj);
}

size_t ListInstrumentPort_items(ListInstrumentPortHandle handle, InstrumentPortHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::instrument_interfaces::names::InstrumentPort(*list->items()[i]);
    }
    return n;
}

bool ListInstrumentPort_contains(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->contains(stored_obj);
}

size_t ListInstrumentPort_index(ListInstrumentPortHandle handle, InstrumentPortHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::names::InstrumentPort>(static_cast<falcon_core::instrument_interfaces::names::InstrumentPort*>(value), [](falcon_core::instrument_interfaces::names::InstrumentPort*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::names::InstrumentPort>*>(handle)->index(stored_obj);
}
