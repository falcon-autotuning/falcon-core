#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
#include <falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp>

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create_empty() {
    return new falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>(
        falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>());
}

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_fill_value(size_t count, DotGateWithNeighborsHandle value) {
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(static_cast<falcon_core::physics::config::geometries::DotGateWithNeighbors*>(value), [](falcon_core::physics::config::geometries::DotGateWithNeighbors*) {} );
    return new falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>(
        count, stored_obj);
}
 

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create(DotGateWithNeighborsHandle* data, size_t count) {
if (!data) {
throw std::invalid_argument("Null data handle passed to ListDotGateWithNeighbors_create");
}
    std::vector<falcon_core::physics::config::geometries::DotGateWithNeighborsSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(static_cast<falcon_core::physics::config::geometries::DotGateWithNeighbors*>(data[i]), [](falcon_core::physics::config::geometries::DotGateWithNeighbors*) {} ));
    }

    return new falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>(
        falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>(vec));
}

void ListDotGateWithNeighbors_destroy(ListDotGateWithNeighborsHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_destroy");
    }
    delete static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle);
}

size_t ListDotGateWithNeighbors_size(ListDotGateWithNeighborsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_size");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->size();
}

bool ListDotGateWithNeighbors_empty(ListDotGateWithNeighborsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_empty");
}
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->empty();
}

void ListDotGateWithNeighbors_erase_at(ListDotGateWithNeighborsHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_erase_at");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->erase_at(idx);
}

void ListDotGateWithNeighbors_clear(ListDotGateWithNeighborsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_clear");
}
    static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->clear();
}

void ListDotGateWithNeighbors_push_back(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(static_cast<falcon_core::physics::config::geometries::DotGateWithNeighbors*>(value), [](falcon_core::physics::config::geometries::DotGateWithNeighbors*) {} );
    static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->push_back(stored_obj);
}

bool ListDotGateWithNeighbors_contains(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(static_cast<falcon_core::physics::config::geometries::DotGateWithNeighbors*>(value), [](falcon_core::physics::config::geometries::DotGateWithNeighbors*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->contains(stored_obj);
}

size_t ListDotGateWithNeighbors_index(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(static_cast<falcon_core::physics::config::geometries::DotGateWithNeighbors*>(value), [](falcon_core::physics::config::geometries::DotGateWithNeighbors*) {} );
    return static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->index(stored_obj);
}

size_t ListDotGateWithNeighbors_items(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListDotGateWithNeighbors_items");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::physics::config::geometries::DotGateWithNeighbors(*list->items()[i]);
}
    return n;
}

DotGateWithNeighborsHandle ListDotGateWithNeighbors_at(ListDotGateWithNeighborsHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_at");
}
    auto obj = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->at(idx);
    return new falcon_core::physics::config::geometries::DotGateWithNeighbors(*obj);
}

bool ListDotGateWithNeighbors_equal(ListDotGateWithNeighborsHandle a, ListDotGateWithNeighborsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_equal");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(a);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(b);
    return *listA == *listB;
}

bool ListDotGateWithNeighbors_not_equal(ListDotGateWithNeighborsHandle a, ListDotGateWithNeighborsHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_not_equal");
}
    return !ListDotGateWithNeighbors_equal(a, b);
}

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_intersection(ListDotGateWithNeighborsHandle handle, ListDotGateWithNeighborsHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_intersection");
}
    auto listA = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle);
    auto listB = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>>(*listB));
    return new falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>(*result);
}

StringHandle      ListDotGateWithNeighbors_to_json_string(ListDotGateWithNeighborsHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_to_json_string");
}
    std::string json = static_cast<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to ListDotGateWithNeighbors_from_json_string");
}
  auto ptr = falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>::from_json_string<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>>(json->raw);
  return new falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>(*ptr);
}
