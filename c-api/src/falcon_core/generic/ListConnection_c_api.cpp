#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListConnection_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

ListConnectionHandle ListConnection_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>());
}

ListConnectionHandle ListConnection_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(count));
}

void ListConnection_destroy(ListConnectionHandle handle) {
    delete static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle);
}

size_t ListConnection_size(ListConnectionHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->size();
}

bool ListConnection_empty(ListConnectionHandle handle) {
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->empty();
}

void ListConnection_erase_at(ListConnectionHandle handle, size_t idx) {
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->erase_at(idx);
}

void ListConnection_clear(ListConnectionHandle handle) {
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->clear();
}

bool ListConnection_equal(ListConnectionHandle a, ListConnectionHandle b) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(b);
    return *listA == *listB;
}

bool ListConnection_not_equal(ListConnectionHandle a, ListConnectionHandle b) {
    return !ListConnection_equal(a, b);
}

ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other) {
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*result);
}

ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(count, stored_obj));
}

ListConnectionHandle ListConnection_create(const ConnectionHandle* data, size_t count) {
    std::vector<falcon_core::physics::device_structures::ConnectionSP> vec;
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(data[i]), [](falcon_core::physics::device_structures::Connection*) {} ));
    }
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(vec));
}

void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->push_back(stored_obj);
}

ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->at(idx);
    return new falcon_core::physics::device_structures::Connection(*obj);
}

size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    for (size_t i = 0; i < n; ++i) {
        out_buffer[i] = new falcon_core::physics::device_structures::Connection(*list->items()[i]);
    }
    return n;
}

bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->contains(stored_obj);
}

size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->index(stored_obj);
}

const char*      ListConnection_to_json_string(ListConnectionHandle handle) {
  static thread_local std::string json;
  json = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->to_json_string();
  return json.c_str();
}
ListConnectionHandle ListConnection_from_json_string(const char* json) {
  auto ptr = falcon_core::generic::List<falcon_core::physics::device_structures::Connection>::from_json_string<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(std::string(json));
  return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*ptr);
}
