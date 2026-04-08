#include <falcon-core/generic/List.hpp>
#include "falcon-core/generic/ListPairIntInt_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/Pair.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairIntIntHandle= falcon_core::generic::List<falcon_core::generic::Pair<int, int>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairIntInt, MACROListPairIntIntHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairIntInt, MACROListPairIntIntHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairIntInt, MACROListPairIntIntHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairIntInt, MACROListPairIntIntHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairIntInt, MACROListPairIntIntHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairIntInt, MACROListPairIntIntHandle);
ListPairIntIntHandle ListPairIntInt_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>());
    FALCON_C_API_END(nullptr)
}

ListPairIntIntHandle ListPairIntInt_fill_value(size_t count, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairIntIntHandle ListPairIntInt_create(PairIntIntHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairIntInt_create");
}
    std::vector<falcon_core::generic::PairSP<int, int>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, int>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairIntInt_size(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairIntInt_empty(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairIntInt_erase_at(ListPairIntIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairIntInt_clear(ListPairIntIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairIntInt_push_back(ListPairIntIntHandle handle, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairIntInt_contains(ListPairIntIntHandle handle, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairIntInt_index(ListPairIntIntHandle handle, PairIntIntHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntInt_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, int>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairIntInt_items(ListPairIntIntHandle handle, PairIntIntHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairIntInt_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<int, int>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairIntIntHandle ListPairIntInt_at(ListPairIntIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<int, int>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairIntIntHandle ListPairIntInt_intersection(ListPairIntIntHandle handle, ListPairIntIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairIntInt_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, int>>(result);
    FALCON_C_API_END(nullptr)
}
}
