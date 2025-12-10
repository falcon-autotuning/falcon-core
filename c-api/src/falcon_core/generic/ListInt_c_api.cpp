#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListInt_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListint= falcon_core::generic::List<int>;
DEFINE_C_API_COPY_TEMPLATE(ListInt, MACROListint)
DEFINE_C_API_DESTROY_TEMPLATE(ListInt, MACROListint);
DEFINE_C_API_EQUAL_TEMPLATE(ListInt, MACROListint);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListInt, MACROListint);
DEFINE_C_API_TO_JSON_TEMPLATE(ListInt, MACROListint);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListInt, MACROListint);
ListIntHandle ListInt_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<int>(std::make_shared<falcon_core::generic::List<int>>());
    FALCON_C_API_END(nullptr)
}

ListIntHandle ListInt_fill_value(size_t count, int value) {
    FALCON_C_API_BEGIN
    auto stored_obj = value;
    return new falcon_core::generic::ListSP<int>(
        std::make_shared<falcon_core::generic::List<int>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 ListIntHandle ListInt_allocate(size_t count) {
    return new falcon_core::generic::ListSP<int>(std::make_shared<falcon_core::generic::List<int>>(count));
}


ListIntHandle ListInt_create(int* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListInt_create");
}
    std::vector<int> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::ListSP<int>(
        std::make_shared<falcon_core::generic::List<int>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListInt_size(ListIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_size");
}
    return (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListInt_empty(ListIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListInt_erase_at(ListIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListInt_clear(ListIntHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_clear");
}
    (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListInt_push_back(ListIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_push_back");
}
    auto stored_obj = value;
    (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListInt_contains(ListIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_contains");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListInt_index(ListIntHandle handle, int value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_index");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListInt_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<int>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
    FALCON_C_API_END(0)
}

int ListInt_at(ListIntHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListInt_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<int>*>(handle))->at(idx);
    return obj;
    FALCON_C_API_END(0)
}

ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListInt_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<int>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<int>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<int>(result);
    FALCON_C_API_END(nullptr)
}
}
