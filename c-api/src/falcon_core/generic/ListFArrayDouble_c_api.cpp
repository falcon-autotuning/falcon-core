#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListFArrayDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/FArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListFArrayDoubleHandle= falcon_core::generic::List<falcon_core::generic::FArray<double>>;
DEFINE_C_API_COPY_TEMPLATE(ListFArrayDouble, MACROListFArrayDoubleHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListFArrayDouble, MACROListFArrayDoubleHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListFArrayDouble, MACROListFArrayDoubleHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListFArrayDouble, MACROListFArrayDoubleHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListFArrayDouble, MACROListFArrayDoubleHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListFArrayDouble, MACROListFArrayDoubleHandle);
ListFArrayDoubleHandle ListFArrayDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::FArray<double>>>());
    FALCON_C_API_END(nullptr)
}

ListFArrayDoubleHandle ListFArrayDouble_fill_value(size_t count, FArrayDoubleHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListFArrayDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::FArray<double>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::FArray<double>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListFArrayDoubleHandle ListFArrayDouble_create(FArrayDoubleHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListFArrayDouble_create");
}
    std::vector<falcon_core::generic::FArraySP<double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::FArray<double>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::FArray<double>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListFArrayDouble_size(ListFArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListFArrayDouble_empty(ListFArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListFArrayDouble_erase_at(ListFArrayDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListFArrayDouble_clear(ListFArrayDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListFArrayDouble_push_back(ListFArrayDoubleHandle handle, FArrayDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListFArrayDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::FArray<double>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListFArrayDouble_contains(ListFArrayDoubleHandle handle, FArrayDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListFArrayDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::FArray<double>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListFArrayDouble_index(ListFArrayDoubleHandle handle, FArrayDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListFArrayDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::FArray<double>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListFArrayDouble_items(ListFArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListFArrayDouble_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::FArray<double>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

FArrayDoubleHandle ListFArrayDouble_at(ListFArrayDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::FArray<double>>(obj);
    FALCON_C_API_END(nullptr)
}

ListFArrayDoubleHandle ListFArrayDouble_intersection(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListFArrayDouble_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::FArray<double>>(result);
    FALCON_C_API_END(nullptr)
}
}
