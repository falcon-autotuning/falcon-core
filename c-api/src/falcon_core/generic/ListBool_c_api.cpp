#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListBool_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListbool= falcon_core::generic::List<bool>;
DEFINE_C_API_COPY_TEMPLATE(ListBool, MACROListbool)
DEFINE_C_API_DESTROY_TEMPLATE(ListBool, MACROListbool);
DEFINE_C_API_EQUAL_TEMPLATE(ListBool, MACROListbool);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListBool, MACROListbool);
DEFINE_C_API_TO_JSON_TEMPLATE(ListBool, MACROListbool);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListBool, MACROListbool);
ListBoolHandle ListBool_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<bool>(std::make_shared<falcon_core::generic::List<bool>>());
    FALCON_C_API_END(nullptr)
}

ListBoolHandle ListBool_fill_value(size_t count, bool value) {
    FALCON_C_API_BEGIN
    auto stored_obj = value;
    return new falcon_core::generic::ListSP<bool>(
        std::make_shared<falcon_core::generic::List<bool>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 ListBoolHandle ListBool_allocate(size_t count) {
    return new falcon_core::generic::ListSP<bool>(std::make_shared<falcon_core::generic::List<bool>>(count));
}


ListBoolHandle ListBool_create(bool* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListBool_create");
}
    std::vector<bool> vec;
    vec.insert(vec.end(), data, data + count);
    return new falcon_core::generic::ListSP<bool>(
        std::make_shared<falcon_core::generic::List<bool>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListBool_size(ListBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_size");
}
    return (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListBool_empty(ListBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListBool_erase_at(ListBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListBool_clear(ListBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_clear");
}
    (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListBool_push_back(ListBoolHandle handle, bool value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_push_back");
}
    auto stored_obj = value;
    (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListBool_contains(ListBoolHandle handle, bool value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_contains");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListBool_index(ListBoolHandle handle, bool value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_index");
}
    auto stored_obj = value;
    return (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListBool_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<bool>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    std::copy_n(list->items().begin(), n, out_buffer);
    return n;
    FALCON_C_API_END(0)
}

bool ListBool_at(ListBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListBool_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<bool>*>(handle))->at(idx);
    return obj;
    FALCON_C_API_END(false)
}

ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListBool_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<bool>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<bool>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<bool>(result);
    FALCON_C_API_END(nullptr)
}
}
