#include <falcon-core/generic/List.hpp>
#include "falcon-core/generic/ListDiscretizer_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/math/discrete_spaces/Discretizer.hpp>
#include <falcon-core/math/UnitSpace.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROListDiscretizerHandle= falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>;
DEFINE_C_API_COPY_TEMPLATE(ListDiscretizer, MACROListDiscretizerHandle)
DEFINE_C_API_DESTROY_TEMPLATE(ListDiscretizer, MACROListDiscretizerHandle);
DEFINE_C_API_EQUAL_TEMPLATE(ListDiscretizer, MACROListDiscretizerHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(ListDiscretizer, MACROListDiscretizerHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(ListDiscretizer, MACROListDiscretizerHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(ListDiscretizer, MACROListDiscretizerHandle);
ListDiscretizerHandle ListDiscretizer_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>(std::make_shared<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>>());
    FALCON_C_API_END(nullptr)
}

ListDiscretizerHandle ListDiscretizer_fill_value(size_t count, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDiscretizer_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>*>(value);
    
    return new falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>>(
            count, stored_obj));
    FALCON_C_API_END(nullptr)
}
 

ListDiscretizerHandle ListDiscretizer_create(DiscretizerHandle* data, size_t count) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to ListDiscretizer_create");
}
    std::vector<falcon_core::math::discrete_spaces::DiscretizerSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(*static_cast<std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>*>(data[i])); 
    }

    return new falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>>(vec));
    FALCON_C_API_END(nullptr)
}

size_t ListDiscretizer_size(ListDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_size");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool ListDiscretizer_empty(ListDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_empty");
}
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void ListDiscretizer_erase_at(ListDiscretizerHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_erase_at");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void ListDiscretizer_clear(ListDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_clear");
}
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->clear();
    FALCON_C_API_END()
}

void ListDiscretizer_push_back(ListDiscretizerHandle handle, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_push_back");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDiscretizer_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>*>(value);
    
    (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool ListDiscretizer_contains(ListDiscretizerHandle handle, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_contains");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDiscretizer_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t ListDiscretizer_index(ListDiscretizerHandle handle, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_index");
}
    
    if (!value) {
    throw std::invalid_argument("Null value passed to ListDiscretizer_fill_value");
    }
    auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>*>(value);
    
    return (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t ListDiscretizer_items(ListDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to ListDiscretizer_items");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

DiscretizerHandle ListDiscretizer_at(ListDiscretizerHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_at");
}
    auto obj = (*static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(obj);
    FALCON_C_API_END(nullptr)
}

ListDiscretizerHandle ListDiscretizer_intersection(ListDiscretizerHandle handle, ListDiscretizerHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to ListDiscretizer_intersection");
}
    auto listA = *static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    auto listB = *static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>(result);
    FALCON_C_API_END(nullptr)
}
}
