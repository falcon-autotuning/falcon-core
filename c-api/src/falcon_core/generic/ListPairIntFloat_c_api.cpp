#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairIntFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairIntFloatHandle= falcon_core::generic::List<falcon_core::generic::Pair<int, float>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairIntFloat, MACROListPairIntFloatHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairIntFloat, MACROListPairIntFloatHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairIntFloat, MACROListPairIntFloatHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairIntFloat, MACROListPairIntFloatHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairIntFloat, MACROListPairIntFloatHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairIntFloat, MACROListPairIntFloatHandle);
ListPairIntFloatHandle ListPairIntFloat_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>>());
    FALCON_C_API_END(nullptr)
}

ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, float>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairIntFloatHandle ListPairIntFloat_create(PairIntFloatHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairIntFloat_create");
}
    std::vector<falcon_core::generic::PairSP<int, float>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<int, float>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<int, float>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairIntFloat_size(ListPairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairIntFloat_empty(ListPairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairIntFloat_clear(ListPairIntFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, float>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, float>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairIntFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<int, float>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairIntFloat_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<int, float>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<int, float>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairIntFloat_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<int, float>>(result);
    FALCON_C_API_END(nullptr)
}
}
