#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListConnection_c_api.h"
#include <falcon_core/physics/device_structures/Connection.hpp>

ListConnectionHandle ListConnection_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>());
}

ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        count, stored_obj);
}

ListConnectionHandle ListConnection_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(count));
}

ListConnectionHandle ListConnection_create(ConnectionHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListConnection_create");
}
    std::vector<falcon_core::physics::device_structures::ConnectionSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(data[i]), [](falcon_core::physics::device_structures::Connection*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(
        falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(vec));
}

void ListConnection_destroy(ListConnectionHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListConnection_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle);
}

size_t ListConnection_size(ListConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->size();
}

bool ListConnection_empty(ListConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->empty();
}

void ListConnection_erase_at(ListConnectionHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->erase_at(idx);
}

void ListConnection_clear(ListConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->clear();
}

void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->push_back(stored_obj);
}

bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->contains(stored_obj);
}

size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListConnection_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::device_structures::Connection>(static_cast<falcon_core::physics::device_structures::Connection*>(value), [](falcon_core::physics::device_structures::Connection*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->index(stored_obj);
}

size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListConnection_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::device_structures::Connection(*list->items()[i]);
}
    return n;
}

ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->at(idx);
    return new falcon_core::physics::device_structures::Connection(*obj);
}

bool ListConnection_equal(ListConnectionHandle a, ListConnectionHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListConnection_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(b);
    return *listA == *listB;
}

bool ListConnection_not_equal(ListConnectionHandle a, ListConnectionHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListConnection_not_equal");
}
    return !ListConnection_equal(a, b);
}

ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListConnection_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*result);
}

StringHandle      ListConnection_to_json_string(ListConnectionHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListConnection_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListConnectionHandle ListConnection_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListConnection_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::physics::device_structures::Connection>::from_json_string<falcon_core::generic::List<falcon_core::physics::device_structures::Connection>>(json->raw);
  return new falcon_core::generic::List<falcon_core::physics::device_structures::Connection>(*ptr);
}
