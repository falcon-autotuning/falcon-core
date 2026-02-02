#include <falcon_core\generic/List.hpp>
#include "falcon_core\generic\ListConnection_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListConnectionHandle= falcon_core::generic::List<falcon_core::physics::device_structures::Connection>;
DEFINE_C_API_COPY_TEMPLATE(ListConnection, MACROListConnectionHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListConnection, MACROListConnectionHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListConnection, MACROListConnectionHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListConnection, MACROListConnectionHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListConnection, MACROListConnectionHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListConnection, MACROListConnectionHandle);
ListConnectionHandle ListConnection_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>());
    FALCON_C_API_END(nullptr)
}

ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListConnectionHandle ListConnection_create(ConnectionHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListConnection_create");
}
    std::vector<falcon_core::physics::device_structures::ConnectionSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListConnection_size(ListConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListConnection_empty(ListConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListConnection_erase_at(ListConnectionHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListConnection_clear(ListConnectionHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connection>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListConnection_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::physics::device_structures::Connection>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::physics::device_structures::Connection>(obj);
    FALCON_C_API_END(nullptr)
}

ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListConnection_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connection>(result);
    FALCON_C_API_END(nullptr)
}
}
