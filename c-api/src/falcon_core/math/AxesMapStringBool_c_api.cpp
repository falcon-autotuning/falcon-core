#include <falcon_core\math/Axes.hpp>
#include "falcon_core\math\AxesMapStringBool_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/generic/Map.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesMapStringBoolHandle= falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>;
DEFINE_C_API_COPY_TEMPLATE(AxesMapStringBool, MACROAxesMapStringBoolHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesMapStringBool, MACROAxesMapStringBoolHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesMapStringBool, MACROAxesMapStringBoolHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesMapStringBool, MACROAxesMapStringBoolHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesMapStringBool, MACROAxesMapStringBoolHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesMapStringBool, MACROAxesMapStringBoolHandle);
AxesMapStringBoolHandle AxesMapStringBool_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>(
        std::make_shared<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>>());
    FALCON_C_API_END(nullptr)
}

AxesMapStringBoolHandle AxesMapStringBool_create(ListMapStringBoolHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesMapStringBool_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::generic::Map<std::string, bool>>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>(
            std::make_shared<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesMapStringBool_size(AxesMapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesMapStringBool_empty(AxesMapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesMapStringBool_erase_at(AxesMapStringBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesMapStringBool_clear(AxesMapStringBoolHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesMapStringBool_push_back(AxesMapStringBoolHandle handle, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMapStringBool_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesMapStringBool_contains(AxesMapStringBoolHandle handle, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMapStringBool_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesMapStringBool_index(AxesMapStringBoolHandle handle, MapStringBoolHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMapStringBool_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::generic::Map<std::string, bool>>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesMapStringBool_items(AxesMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesMapStringBool_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

MapStringBoolHandle AxesMapStringBool_at(AxesMapStringBoolHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::generic::Map<std::string, bool>>(obj);
    FALCON_C_API_END(nullptr)
}

AxesMapStringBoolHandle AxesMapStringBool_intersection(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesMapStringBool_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::generic::Map<std::string, bool>>(std::make_shared<falcon_core::math::Axes<falcon_core::generic::Map<std::string, bool>>>(result));
    FALCON_C_API_END(nullptr)
}
}
