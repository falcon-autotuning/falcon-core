#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListConnections_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListConnectionsHandle ListConnections_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>>());
    FALCON_C_API_END(nullptr)
}

ListConnectionsHandle ListConnections_fill_value(size_t count, ConnectionsHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListConnectionsHandle ListConnections_create(ConnectionsHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListConnections_create");
}
    std::vector<falcon_core::physics::device_structures::ConnectionsSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListConnections_destroy(ListConnectionsHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListConnections_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle);
    FALCON_C_API_END()
}

size_t ListConnections_size(ListConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListConnections_empty(ListConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListConnections_erase_at(ListConnectionsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListConnections_clear(ListConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListConnections_push_back(ListConnectionsHandle handle, ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListConnections_contains(ListConnectionsHandle handle, ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListConnections_index(ListConnectionsHandle handle, ConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnections_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Connections>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListConnections_items(ListConnectionsHandle handle, ConnectionsHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListConnections_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::physics::device_structures::Connections>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ConnectionsHandle ListConnections_at(ListConnectionsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->at(idx);
    return new falcon_core::physics::device_structures::Connections(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListConnections_equal(ListConnectionsHandle handle, ListConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListConnections_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListConnections_not_equal(ListConnectionsHandle handle, ListConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListConnections_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListConnectionsHandle ListConnections_intersection(ListConnectionsHandle handle, ListConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListConnections_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListConnections_to_json_string(ListConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnections_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListConnectionsHandle ListConnections_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListConnections_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::physics::device_structures::Connections>::from_json_string<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Connections>(ptr);
    FALCON_C_API_END(nullptr)
}
}
