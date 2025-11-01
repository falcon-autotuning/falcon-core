#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListWaveform_c_api.h"
#include <falcon_core/instrument_interfaces/Waveform.hpp>

ListWaveformHandle ListWaveform_create_empty() {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>());
}

ListWaveformHandle ListWaveform_fill_value(size_t count, WaveformHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListWaveform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::Waveform>(static_cast<falcon_core::instrument_interfaces::Waveform*>(value), [](falcon_core::instrument_interfaces::Waveform*) {} );
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(count, stored_obj));
}

ListWaveformHandle ListWaveform_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(count));
}

ListWaveformHandle ListWaveform_create(WaveformHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListWaveform_create");
}
    std::vector<falcon_core::instrument_interfaces::WaveformSP> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListWaveform_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::instrument_interfaces::Waveform>(static_cast<falcon_core::instrument_interfaces::Waveform*>(data[i]), [](falcon_core::instrument_interfaces::Waveform*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(
        falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(vec));
}

void ListWaveform_destroy(ListWaveformHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListWaveform_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle);
}

size_t ListWaveform_size(ListWaveformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->size();
}

bool ListWaveform_empty(ListWaveformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->empty();
}

void ListWaveform_erase_at(ListWaveformHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->erase_at(idx);
}

void ListWaveform_clear(ListWaveformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->clear();
}

void ListWaveform_push_back(ListWaveformHandle handle, WaveformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListWaveform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::Waveform>(static_cast<falcon_core::instrument_interfaces::Waveform*>(value), [](falcon_core::instrument_interfaces::Waveform*) {} );
    static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->push_back(stored_obj);
}

bool ListWaveform_contains(ListWaveformHandle handle, WaveformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListWaveform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::Waveform>(static_cast<falcon_core::instrument_interfaces::Waveform*>(value), [](falcon_core::instrument_interfaces::Waveform*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->contains(stored_obj);
}

size_t ListWaveform_index(ListWaveformHandle handle, WaveformHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListWaveform_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::instrument_interfaces::Waveform>(static_cast<falcon_core::instrument_interfaces::Waveform*>(value), [](falcon_core::instrument_interfaces::Waveform*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->index(stored_obj);
}

size_t ListWaveform_items(ListWaveformHandle handle, WaveformHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListWaveform_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::instrument_interfaces::Waveform(*list->items()[i]);
}
    return n;
}

WaveformHandle ListWaveform_at(ListWaveformHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->at(idx);
    return new falcon_core::instrument_interfaces::Waveform(*obj);
}

bool ListWaveform_equal(ListWaveformHandle a, ListWaveformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListWaveform_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(b);
    return *listA == *listB;
}

bool ListWaveform_not_equal(ListWaveformHandle a, ListWaveformHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListWaveform_not_equal");
}
    return !ListWaveform_equal(a, b);
}

ListWaveformHandle ListWaveform_intersection(ListWaveformHandle handle, ListWaveformHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListWaveform_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>>(*listB));
    return new falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(*result);
}

StringHandle      ListWaveform_to_json_string(ListWaveformHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListWaveform_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListWaveformHandle ListWaveform_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListWaveform_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>::from_json_string<falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>>(json->raw);
  return new falcon_core::generic::List<falcon_core::instrument_interfaces::Waveform>(*ptr);
}
