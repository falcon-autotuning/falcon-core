#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListChannel_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>

ListChannelHandle ListChannel_create_empty() {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>());
}

ListChannelHandle ListChannel_fill_value(size_t count, ChannelHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(static_cast<falcon_core::autotuner_interfaces::names::Channel*>(value), [](falcon_core::autotuner_interfaces::names::Channel*) {} );
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(
        count, stored_obj);
}

ListChannelHandle ListChannel_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(count));
}

ListChannelHandle ListChannel_create(ChannelHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListChannel_create");
}
    std::vector<falcon_core::autotuner_interfaces::names::ChannelSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(static_cast<falcon_core::autotuner_interfaces::names::Channel*>(data[i]), [](falcon_core::autotuner_interfaces::names::Channel*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(
        falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(vec));
}

void ListChannel_destroy(ListChannelHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListChannel_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle);
}

size_t ListChannel_size(ListChannelHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->size();
}

bool ListChannel_empty(ListChannelHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->empty();
}

void ListChannel_erase_at(ListChannelHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->erase_at(idx);
}

void ListChannel_clear(ListChannelHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->clear();
}

void ListChannel_push_back(ListChannelHandle handle, ChannelHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(static_cast<falcon_core::autotuner_interfaces::names::Channel*>(value), [](falcon_core::autotuner_interfaces::names::Channel*) {} );
    static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->push_back(stored_obj);
}

bool ListChannel_contains(ListChannelHandle handle, ChannelHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(static_cast<falcon_core::autotuner_interfaces::names::Channel*>(value), [](falcon_core::autotuner_interfaces::names::Channel*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->contains(stored_obj);
}

size_t ListChannel_index(ListChannelHandle handle, ChannelHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(static_cast<falcon_core::autotuner_interfaces::names::Channel*>(value), [](falcon_core::autotuner_interfaces::names::Channel*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->index(stored_obj);
}

size_t ListChannel_items(ListChannelHandle handle, ChannelHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListChannel_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::names::Channel(*list->items()[i]);
}
    return n;
}

ChannelHandle ListChannel_at(ListChannelHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::names::Channel(*obj);
}

bool ListChannel_equal(ListChannelHandle a, ListChannelHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListChannel_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(b);
    return *listA == *listB;
}

bool ListChannel_not_equal(ListChannelHandle a, ListChannelHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListChannel_not_equal");
}
    return !ListChannel_equal(a, b);
}

ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListChannel_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>>(*listB));
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(*result);
}

StringHandle      ListChannel_to_json_string(ListChannelHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListChannelHandle ListChannel_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListChannel_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>::from_json_string<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>>(json->raw);
  return new falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>(*ptr);
}
