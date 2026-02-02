#include <falcon_core/generic/List.hpp>
#include "falcon_core/generic/ListQuantity_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/math/Quantity.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListQuantityHandle= falcon_core::generic::List<falcon_core::math::Quantity>;
DEFINE_C_API_COPY_TEMPLATE(ListQuantity, MACROListQuantityHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListQuantity, MACROListQuantityHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListQuantity, MACROListQuantityHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListQuantity, MACROListQuantityHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListQuantity, MACROListQuantityHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListQuantity, MACROListQuantityHandle);
ListQuantityHandle ListQuantity_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(std::make_shared<falcon_core::generic::List<falcon_core::math::Quantity>>());
    FALCON_C_API_END(nullptr)
}

ListQuantityHandle ListQuantity_fill_value(size_t count, QuantityHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::Quantity>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListQuantityHandle ListQuantity_create(QuantityHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListQuantity_create");
}
    std::vector<falcon_core::math::QuantitySP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::Quantity>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListQuantity_size(ListQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListQuantity_empty(ListQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListQuantity_erase_at(ListQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListQuantity_clear(ListQuantityHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListQuantity_push_back(ListQuantityHandle handle, QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListQuantity_contains(ListQuantityHandle handle, QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListQuantity_index(ListQuantityHandle handle, QuantityHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListQuantity_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::Quantity>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListQuantity_items(ListQuantityHandle handle, QuantityHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListQuantity_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::Quantity>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

QuantityHandle ListQuantity_at(ListQuantityHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListQuantity_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::Quantity>(obj);
    FALCON_C_API_END(nullptr)
}

ListQuantityHandle ListQuantity_intersection(ListQuantityHandle handle, ListQuantityHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListQuantity_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::Quantity>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::Quantity>(result);
    FALCON_C_API_END(nullptr)
}
}
