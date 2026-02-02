#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListPairFloatFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairFloatFloatHandle= falcon_core::generic::List<falcon_core::generic::Pair<float, float>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairFloatFloat, MACROListPairFloatFloatHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairFloatFloat, MACROListPairFloatFloatHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairFloatFloat, MACROListPairFloatFloatHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairFloatFloat, MACROListPairFloatFloatHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairFloatFloat, MACROListPairFloatFloatHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairFloatFloat, MACROListPairFloatFloatHandle);
ListPairFloatFloatHandle ListPairFloatFloat_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>());
    FALCON_C_API_END(nullptr)
}

ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<float, float>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairFloatFloatHandle ListPairFloatFloat_create(PairFloatFloatHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairFloatFloat_create");
}
    std::vector<falcon_core::generic::PairSP<float, float>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<float, float>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<float, float>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<float, float>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<float, float>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairFloatFloat_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<float, float>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairFloatFloat_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<float, float>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<float, float>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairFloatFloat_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<float, float>>(result);
    FALCON_C_API_END(nullptr)
}
}
