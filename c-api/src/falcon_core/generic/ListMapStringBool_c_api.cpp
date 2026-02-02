#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListMapStringBool_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListMapStringBoolHandle= falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>;
DEFINE_C_API_COPY_TEMPLATE(ListMapStringBool, MACROListMapStringBoolHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListMapStringBool, MACROListMapStringBoolHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListMapStringBool, MACROListMapStringBoolHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListMapStringBool, MACROListMapStringBoolHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListMapStringBool, MACROListMapStringBoolHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListMapStringBool, MACROListMapStringBoolHandle);
ListMapStringBoolHandle ListMapStringBool_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>());
    FALCON_C_API_END(nullptr)
}

ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListMapStringBoolHandle ListMapStringBool_create(MapStringBoolHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListMapStringBool_create");
}
    std::vector<falcon_core::generic::MapSP<std::string, bool>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Map<std::string, bool>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListMapStringBool_size(ListMapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListMapStringBool_empty(ListMapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListMapStringBool_clear(ListMapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListMapStringBool_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListMapStringBool_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(obj);
    FALCON_C_API_END(nullptr)
}

ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListMapStringBool_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>(result);
    FALCON_C_API_END(nullptr)
}
}
