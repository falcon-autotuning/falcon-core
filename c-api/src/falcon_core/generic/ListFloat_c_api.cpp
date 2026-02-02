#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListFloat_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListfloat= falcon_core::generic::List<float>;
DEFINE_C_API_COPY_TEMPLATE(ListFloat, MACROListfloat)
DEFINE_C_API_DESTROY_TEMPLATE(ListFloat, MACROListfloat);
DEFINE_C_API_EQUAL_TEMPLATE(ListFloat, MACROListfloat);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListFloat, MACROListfloat);
DEFINE_C_API_TO_JSON_TEMPLATE(ListFloat, MACROListfloat);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListFloat, MACROListfloat);
ListFloatHandle ListFloat_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<float>(std::make_shared<falcon_core::generic::List<float>>());
    FALCON_C_API_END(nullptr)
}

ListFloatHandle ListFloat_fill_value(size_t count, float value) {
    FALCON_C_API_BEGIN
    auto stored_obj = value;
    return new falcon_core::generic::ListSP<float>(
        std::make_shared<falcon_core::generic::List<float>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 ListFloatHandle ListFloat_allocate(size_t count) {
    return new falcon_core::generic::ListSP<float>(std::make_shared<falcon_core::generic::List<float>>(count));
}


ListFloatHandle ListFloat_create(float* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListFloat_create");
}
    std::vector<float> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::ListSP<float>(
        std::make_shared<falcon_core::generic::List<float>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListFloat_size(ListFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_size");
}
    return (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListFloat_empty(ListFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListFloat_erase_at(ListFloatHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListFloat_clear(ListFloatHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_clear");
}
    (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListFloat_push_back(ListFloatHandle handle, float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_push_back");
}
    auto stored_obj = value;
    (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListFloat_contains(ListFloatHandle handle, float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_contains");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListFloat_index(ListFloatHandle handle, float value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_index");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListFloat_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<float>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
    FALCON_C_API_END(0)
}

float ListFloat_at(ListFloatHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListFloat_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<float>*>(handle))->at(idx);
    return obj;
    FALCON_C_API_END(0.0)
}

ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListFloat_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<float>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<float>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<float>(result);
    FALCON_C_API_END(nullptr)
}
}
