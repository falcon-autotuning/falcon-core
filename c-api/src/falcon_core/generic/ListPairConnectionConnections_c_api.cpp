#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionConnections_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connections.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
ListPairConnectionConnectionsHandle ListPairConnectionConnections_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>>());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_fill_value(size_t count, PairConnectionConnectionsHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>SP*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairConnectionConnectionsHandle ListPairConnectionConnections_create(PairConnectionConnectionsHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairConnectionConnections_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>SP*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>>(vec));
    FALCON_C_API_END(nullptr)
}

void ListPairConnectionConnections_destroy(ListPairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_destroy");
    }
    delete static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    FALCON_C_API_END()
}

size_t ListPairConnectionConnections_size(ListPairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairConnectionConnections_empty(ListPairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairConnectionConnections_erase_at(ListPairConnectionConnectionsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairConnectionConnections_clear(ListPairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairConnectionConnections_push_back(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>SP*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairConnectionConnections_contains(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>SP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairConnectionConnections_index(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionConnections_fill_value");
    }
    auto stored_obj = *static_cast<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>SP*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairConnectionConnections_items(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionConnections_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>SP(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairConnectionConnectionsHandle ListPairConnectionConnections_at(ListPairConnectionConnectionsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->at(idx);
    return new falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>(*obj);
    FALCON_C_API_END(nullptr)
}

bool ListPairConnectionConnections_equal(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool ListPairConnectionConnections_not_equal(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_not_equal");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_intersection(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      ListPairConnectionConnections_to_json_string(ListPairConnectionConnectionsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionConnections_to_json_string");
}
    std::string json = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionConnectionsHandle ListPairConnectionConnections_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to ListPairConnectionConnections_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>::from_json_string<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>>(json->raw);
  return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, falcon_core::physics::device_structures::Connections>>(ptr);
    FALCON_C_API_END(nullptr)
}
}
