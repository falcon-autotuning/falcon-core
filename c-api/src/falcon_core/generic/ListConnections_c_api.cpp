#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListConnections_c_api.h"
#include <falcon_core/physics/device_structures/Connections.hpp>

ListConnectionsHandle ListConnections_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connections>());
}

ListConnectionsHandle ListConnections_fill_value(size_t count, ConnectionsHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(value), [](falcon_core::physics::device_structures::Connections*) {} );
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(count, stored_obj));
}

ListConnectionsHandle ListConnections_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(count));
}

ListConnectionsHandle ListConnections_create(ConnectionsHandle* data, size_t count) {
    std::vector<falcon_core::physics::device_structures::ConnectionsSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(data[i]), [](falcon_core::physics::device_structures::Connections*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(vec));
}

void ListConnections_destroy(ListConnectionsHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle);
}

size_t ListConnections_size(ListConnectionsHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->size();
}

bool ListConnections_empty(ListConnectionsHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->empty();
}

void ListConnections_erase_at(ListConnectionsHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->erase_at(idx);
}

void ListConnections_clear(ListConnectionsHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->clear();
}

void ListConnections_push_back(ListConnectionsHandle handle, ConnectionsHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(value), [](falcon_core::physics::device_structures::Connections*) {} );
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->push_back(stored_obj);
}

bool ListConnections_contains(ListConnectionsHandle handle, ConnectionsHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(value), [](falcon_core::physics::device_structures::Connections*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->contains(stored_obj);
}

size_t ListConnections_index(ListConnectionsHandle handle, ConnectionsHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connections>(static_cast<falcon_core::physics::device_structures::Connections*>(value), [](falcon_core::physics::device_structures::Connections*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->index(stored_obj);
}

size_t ListConnections_items(ListConnectionsHandle handle, ConnectionsHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::device_structures::Connections(*list->items()[i]);
}
    return n;
}

ConnectionsHandle ListConnections_at(ListConnectionsHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->at(idx);
    return new falcon_core::physics::device_structures::Connections(*obj);
}

bool ListConnections_equal(ListConnectionsHandle a, ListConnectionsHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(b);
    return *listA == *listB;
}

bool ListConnections_not_equal(ListConnectionsHandle a, ListConnectionsHandle b) {
    return !ListConnections_equal(a, b);
}

ListConnectionsHandle ListConnections_intersection(ListConnectionsHandle handle, ListConnectionsHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(*result);
}

StringHandle      ListConnections_to_json_string(ListConnectionsHandle handle) {
    std::string json = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListConnectionsHandle ListConnections_from_json_string(StringHandle json) {
  auto ptr = falcon_core::generic::List<falcon_core::physics::device_structures::Connections>::from_json_string<falcon_core::generic::List<falcon_core::physics::device_structures::Connections>>(json->raw);
  return new falcon_core::generic::List<falcon_core::physics::device_structures::Connections>(*ptr);
}
