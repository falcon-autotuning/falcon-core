#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionConnections_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>

ListPairConnectionConnectionsHandle ListPairConnectionConnections_create_empty() {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>());
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_fill_value(size_t count, PairConnectionConnectionsHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*) {} );
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(count, stored_obj));
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_allocate(size_t count) {
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(count));
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_create(PairConnectionConnectionsHandle* data, size_t count) {
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>> vec;
        vec.reserve(count);
    if (!data) {
    throw std::invalid_argument("Null data handle passed to ListPairConnectionConnections_create_allocation");
    }
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(data[i]), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(
        falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(vec));
}

void ListPairConnectionConnections_destroy(ListPairConnectionConnectionsHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
}

size_t ListPairConnectionConnections_size(ListPairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->size();
}

bool ListPairConnectionConnections_empty(ListPairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->empty();
}

void ListPairConnectionConnections_erase_at(ListPairConnectionConnectionsHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->erase_at(idx);
}

void ListPairConnectionConnections_clear(ListPairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->clear();
}

void ListPairConnectionConnections_push_back(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*) {} );
    static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->push_back(stored_obj);
}

bool ListPairConnectionConnections_contains(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->contains(stored_obj);
}

size_t ListPairConnectionConnections_index(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*>(value), [](falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->index(stored_obj);
}

size_t ListPairConnectionConnections_items(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionConnections_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(*list->items()[i]);
}
    return n;
}

PairConnectionConnectionsHandle ListPairConnectionConnections_at(ListPairConnectionConnectionsHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(*obj);
}

bool ListPairConnectionConnections_equal(ListPairConnectionConnectionsHandle a, ListPairConnectionConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(b);
    return *listA == *listB;
}

bool ListPairConnectionConnections_not_equal(ListPairConnectionConnectionsHandle a, ListPairConnectionConnectionsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_not_equal");
}
    return !ListPairConnectionConnections_equal(a, b);
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_intersection(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>>(*listB));
    return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(*result);
}

StringHandle      ListPairConnectionConnections_to_json_string(ListPairConnectionConnectionsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListPairConnectionConnectionsHandle ListPairConnectionConnections_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairConnectionConnections_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>>(json->raw);
  return new falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(*ptr);
}
