#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListPairConnectionDouble_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/generic/Pair.hpp>
#include <falcon_core/physics/device_structures/Connection.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListPairConnectionDoubleHandle= falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>;
DEFINE_C_API_COPY_TEMPLATE(ListPairConnectionDouble, MACROListPairConnectionDoubleHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListPairConnectionDouble, MACROListPairConnectionDoubleHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListPairConnectionDouble, MACROListPairConnectionDoubleHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListPairConnectionDouble, MACROListPairConnectionDoubleHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListPairConnectionDouble, MACROListPairConnectionDoubleHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListPairConnectionDouble, MACROListPairConnectionDoubleHandle);
ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>());
    FALCON_C_API_END(nullptr)
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListPairConnectionDoubleHandle ListPairConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListPairConnectionDouble_create");
}
    std::vector<falcon_core::generic::PairSP<falcon_core::physics::device_structures::Connection, double>> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(
        std::make_shared<falcon_core::generic::List<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListPairConnectionDouble_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListPairConnectionDouble_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(obj);
    FALCON_C_API_END(nullptr)
}

ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListPairConnectionDouble_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::generic::Pair<falcon_core::physics::device_structures::Connection, double>>(result);
    FALCON_C_API_END(nullptr)
}
}
