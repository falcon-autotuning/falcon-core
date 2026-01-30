#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairSizeTSizeT_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairSizeTSizeTHandle= falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairSizeTSizeT, MACROListPairSizeTSizeTHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairSizeTSizeT, MACROListPairSizeTSizeTHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairSizeTSizeT, MACROListPairSizeTSizeTHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairSizeTSizeT, MACROListPairSizeTSizeTHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairSizeTSizeT, MACROListPairSizeTSizeTHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairSizeTSizeT, MACROListPairSizeTSizeTHandle);
ListPairSizeTSizeTHandle ListPairSizeTSizeT_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>>());
    FALCON_C_API_END(nullptr)
}

ListPairSizeTSizeTHandle ListPairSizeTSizeT_fill_value(size_t count, PairSizeTSizeTHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairSizeTSizeTHandle ListPairSizeTSizeT_create(PairSizeTSizeTHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairSizeTSizeT_create");
}
    std::vector<falcon_core::generic::PairSP<size_t, size_t>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<size_t, size_t>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairSizeTSizeT_size(ListPairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairSizeTSizeT_empty(ListPairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairSizeTSizeT_erase_at(ListPairSizeTSizeTHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairSizeTSizeT_clear(ListPairSizeTSizeTHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairSizeTSizeT_push_back(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairSizeTSizeT_contains(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairSizeTSizeT_index(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairSizeTSizeT_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairSizeTSizeT_items(ListPairSizeTSizeTHandle handle, PairSizeTSizeTHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairSizeTSizeT_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairSizeTSizeTHandle ListPairSizeTSizeT_at(ListPairSizeTSizeTHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<size_t, size_t>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairSizeTSizeTHandle ListPairSizeTSizeT_intersection(ListPairSizeTSizeTHandle handle, ListPairSizeTSizeTHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairSizeTSizeT_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<size_t, size_t>>(result);
    FALCON_C_API_END(nullptr)
}
}
