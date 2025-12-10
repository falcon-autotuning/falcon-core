#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/physics/config/geometries/DotGateWithNeighbors.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListDotGateWithNeighborsHandle= falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>;
DEFINE_C_API_COPY_TEMPLATE(ListDotGateWithNeighbors, MACROListDotGateWithNeighborsHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListDotGateWithNeighbors, MACROListDotGateWithNeighborsHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListDotGateWithNeighbors, MACROListDotGateWithNeighborsHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListDotGateWithNeighbors, MACROListDotGateWithNeighborsHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListDotGateWithNeighbors, MACROListDotGateWithNeighborsHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListDotGateWithNeighbors, MACROListDotGateWithNeighborsHandle);
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>(std::make_shared<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>>());
    FALCON_C_API_END(nullptr)
}

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_fill_value(size_t count, DotGateWithNeighborsHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create(DotGateWithNeighborsHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListDotGateWithNeighbors_create");
}
    std::vector<falcon_core::physics::config::geometries::DotGateWithNeighborsSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::config::geometries::DotGateWithNeighbors>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListDotGateWithNeighbors_size(ListDotGateWithNeighborsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListDotGateWithNeighbors_empty(ListDotGateWithNeighborsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListDotGateWithNeighbors_erase_at(ListDotGateWithNeighborsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListDotGateWithNeighbors_clear(ListDotGateWithNeighborsHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListDotGateWithNeighbors_push_back(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListDotGateWithNeighbors_contains(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListDotGateWithNeighbors_index(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDotGateWithNeighbors_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListDotGateWithNeighbors_items(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListDotGateWithNeighbors_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

DotGateWithNeighborsHandle ListDotGateWithNeighbors_at(ListDotGateWithNeighborsHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::physics::config::geometries::DotGateWithNeighbors>(obj);
    FALCON_C_API_END(nullptr)
}

ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_intersection(ListDotGateWithNeighborsHandle handle, ListDotGateWithNeighborsHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListDotGateWithNeighbors_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::physics::config::geometries::DotGateWithNeighbors>(result);
    FALCON_C_API_END(nullptr)
}
}
