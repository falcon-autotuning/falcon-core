#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListGname_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/autotuner_interfaces/names/Gname.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListGnameHandle= falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>;
DEFINE_C_API_COPY_TEMPLATE(ListGname, MACROListGnameHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListGname, MACROListGnameHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListGname, MACROListGnameHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListGname, MACROListGnameHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListGname, MACROListGnameHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListGname, MACROListGnameHandle);
ListGnameHandle ListGname_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>(std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>>());
    FALCON_C_API_END(nullptr)
}

ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGname_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListGnameHandle ListGname_create(GnameHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListGname_create");
}
    std::vector<falcon_core::autotuner_interfaces::names::GnameSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>(
        std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::names::Gname>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListGname_size(ListGnameHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListGname_empty(ListGnameHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListGname_erase_at(ListGnameHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListGname_clear(ListGnameHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListGname_push_back(ListGnameHandle handle, GnameHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGname_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListGname_contains(ListGnameHandle handle, GnameHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGname_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListGname_index(ListGnameHandle handle, GnameHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListGname_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListGname_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

GnameHandle ListGname_at(ListGnameHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListGname_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::names::Gname>(obj);
    FALCON_C_API_END(nullptr)
}

ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListGname_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::names::Gname>(result);
    FALCON_C_API_END(nullptr)
}
}
