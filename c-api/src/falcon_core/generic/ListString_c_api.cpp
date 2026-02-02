#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListStringHandle= falcon_core::generic::List<std::string>;
DEFINE_C_API_COPY_TEMPLATE(ListString, MACROListStringHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListString, MACROListStringHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListString, MACROListStringHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListString, MACROListStringHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListString, MACROListStringHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListString, MACROListStringHandle);
ListStringHandle ListString_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<std::string>(std::make_shared<falcon_core::generic::List<std::string>>());
    FALCON_C_API_END(nullptr)
}

ListStringHandle ListString_fill_value(size_t count, StringHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    return new falcon_core::generic::ListSP<std::string>(
        std::make_shared<falcon_core::generic::List<std::string>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 ListStringHandle ListString_allocate(size_t count) {
    return new falcon_core::generic::ListSP<std::string>(std::make_shared<falcon_core::generic::List<std::string>>(count));
}


ListStringHandle ListString_create(StringHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListString_create");
}
    std::vector<std::string> vec;
    
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(data[i]->raw);
    }

    return new falcon_core::generic::ListSP<std::string>(
        std::make_shared<falcon_core::generic::List<std::string>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListString_size(ListStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_size");
}
    return (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListString_empty(ListStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListString_erase_at(ListStringHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListString_clear(ListStringHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_clear");
}
    (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListString_push_back(ListStringHandle handle, StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListString_contains(ListStringHandle handle, StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    return (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListString_index(ListStringHandle handle, StringHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null string handle passed to ListString_fill_value");
    }
    std::string stored_obj(value->raw, value->length);
    return (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListString_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<std::string>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
    for (size_t i = 0; i < n; ++i) {
        auto str      = list->items()[i];
        out_buffer[i] = String_create(str.data(), str.size());
    }

    return n;
    FALCON_C_API_END(0)
}

StringHandle ListString_at(ListStringHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListString_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<std::string>*>(handle))->at(idx);
    return String_create(obj.data(), obj.size());
    FALCON_C_API_END(nullptr)
}

ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListString_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<std::string>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<std::string>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<std::string>(result);
    FALCON_C_API_END(nullptr)
}
}
