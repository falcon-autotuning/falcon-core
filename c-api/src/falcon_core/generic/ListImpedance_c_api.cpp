#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListImpedance_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/physics/device_structures/Impedance.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListImpedanceHandle= falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>;
DEFINE_C_API_COPY_TEMPLATE(ListImpedance, MACROListImpedanceHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListImpedance, MACROListImpedanceHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListImpedance, MACROListImpedanceHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListImpedance, MACROListImpedanceHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListImpedance, MACROListImpedanceHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListImpedance, MACROListImpedanceHandle);
ListImpedanceHandle ListImpedance_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>(std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>());
    FALCON_C_API_END(nullptr)
}

ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Impedance>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListImpedanceHandle ListImpedance_create(ImpedanceHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListImpedance_create");
}
    std::vector<falcon_core::physics::device_structures::ImpedanceSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::physics::device_structures::Impedance>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>(
        std::make_shared<falcon_core::generic::List<falcon_core::physics::device_structures::Impedance>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListImpedance_size(ListImpedanceHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListImpedance_empty(ListImpedanceHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListImpedance_clear(ListImpedanceHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Impedance>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Impedance>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListImpedance_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::physics::device_structures::Impedance>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListImpedance_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::physics::device_structures::Impedance>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListImpedance_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::physics::device_structures::Impedance>(obj);
    FALCON_C_API_END(nullptr)
}

ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListImpedance_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::physics::device_structures::Impedance>(result);
    FALCON_C_API_END(nullptr)
}
}
