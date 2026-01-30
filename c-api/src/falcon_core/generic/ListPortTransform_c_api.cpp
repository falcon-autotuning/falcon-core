#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/instrument_interfaces/port_transforms/PortTransform.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPortTransformHandle= falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>;
DEFINE_C_API_COPY_TEMPLATE(ListPortTransform, MACROListPortTransformHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPortTransform, MACROListPortTransformHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPortTransform, MACROListPortTransformHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPortTransform, MACROListPortTransformHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPortTransform, MACROListPortTransformHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPortTransform, MACROListPortTransformHandle);
ListPortTransformHandle ListPortTransform_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>(std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>>());
    FALCON_C_API_END(nullptr)
}

ListPortTransformHandle ListPortTransform_fill_value(size_t count, PortTransformHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPortTransformHandle ListPortTransform_create(PortTransformHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPortTransform_create");
}
    std::vector<falcon_core::instrument_interfaces::port_transforms::PortTransformSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>(
        std::make_shared<falcon_core::generic::List<falcon_core::instrument_interfaces::port_transforms::PortTransform>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPortTransform_size(ListPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPortTransform_empty(ListPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPortTransform_erase_at(ListPortTransformHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPortTransform_clear(ListPortTransformHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPortTransform_push_back(ListPortTransformHandle handle, PortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPortTransform_contains(ListPortTransformHandle handle, PortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPortTransform_index(ListPortTransformHandle handle, PortTransformHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPortTransform_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPortTransform_items(ListPortTransformHandle handle, PortTransformHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPortTransform_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PortTransformHandle ListPortTransform_at(ListPortTransformHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPortTransform_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::instrument_interfaces::port_transforms::PortTransform>(obj);
    FALCON_C_API_END(nullptr)
}

ListPortTransformHandle ListPortTransform_intersection(ListPortTransformHandle handle, ListPortTransformHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPortTransform_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::instrument_interfaces::port_transforms::PortTransform>(result);
    FALCON_C_API_END(nullptr)
}
}
