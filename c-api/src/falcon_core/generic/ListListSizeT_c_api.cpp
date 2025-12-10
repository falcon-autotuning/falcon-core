#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListListSizeT_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListListSizeTHandle= falcon_core::generic::List<falcon_core::generic::List<size_t>>;
DEFINE_C_API_COPY_TEMPLATE(ListListSizeT, MACROListListSizeTHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListListSizeT, MACROListListSizeTHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListListSizeT, MACROListListSizeTHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListListSizeT, MACROListListSizeTHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListListSizeT, MACROListListSizeTHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListListSizeT, MACROListListSizeTHandle);
ListListSizeTHandle ListListSizeT_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::List<size_t>>>());
    FALCON_C_API_END(nullptr)
}

ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::List<size_t>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::List<size_t>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListListSizeT_create");
}
    std::vector<falcon_core::generic::ListSP<size_t>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::List<size_t>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::List<size_t>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListListSizeT_size(ListListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListListSizeT_empty(ListListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListListSizeT_clear(ListListSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::List<size_t>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::List<size_t>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListListSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::List<size_t>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListListSizeT_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::List<size_t>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListListSizeT_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::List<size_t>>(obj);
    FALCON_C_API_END(nullptr)
}

ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListListSizeT_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::List<size_t>>(result);
    FALCON_C_API_END(nullptr)
}
}
