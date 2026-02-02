#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListChannel_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Channel.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListChannelHandle= falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>;
DEFINE_C_API_COPY_TEMPLATE(ListChannel, MACROListChannelHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListChannel, MACROListChannelHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListChannel, MACROListChannelHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListChannel, MACROListChannelHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListChannel, MACROListChannelHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListChannel, MACROListChannelHandle);
ListChannelHandle ListChannel_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>>());
    FALCON_C_API_END(nullptr)
}

ListChannelHandle ListChannel_fill_value(size_t count, ChannelHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListChannelHandle ListChannel_create(ChannelHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListChannel_create");
}
    std::vector<falcon_core::autotuner_interfaces::names::ChannelSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Channel>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListChannel_size(ListChannelHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListChannel_empty(ListChannelHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListChannel_erase_at(ListChannelHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListChannel_clear(ListChannelHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListChannel_push_back(ListChannelHandle handle, ChannelHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListChannel_contains(ListChannelHandle handle, ChannelHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListChannel_index(ListChannelHandle handle, ChannelHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListChannel_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListChannel_items(ListChannelHandle handle, ChannelHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListChannel_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ChannelHandle ListChannel_at(ListChannelHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListChannel_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::names::Channel>(obj);
    FALCON_C_API_END(nullptr)
}

ListChannelHandle ListChannel_intersection(ListChannelHandle handle, ListChannelHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListChannel_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Channel>(result);
    FALCON_C_API_END(nullptr)
}
}
