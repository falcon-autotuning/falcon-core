#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesControlArray1D_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/ControlArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesControlArray1DHandle= falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>;
DEFINE_C_API_COPY_TEMPLATE(AxesControlArray1D, MACROAxesControlArray1DHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesControlArray1D, MACROAxesControlArray1DHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesControlArray1D, MACROAxesControlArray1DHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesControlArray1D, MACROAxesControlArray1DHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesControlArray1D, MACROAxesControlArray1DHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesControlArray1D, MACROAxesControlArray1DHandle);
AxesControlArray1DHandle AxesControlArray1D_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>(
        std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>>());
    FALCON_C_API_END(nullptr)
}

AxesControlArray1DHandle AxesControlArray1D_create(ListControlArray1DHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesControlArray1D_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::ControlArray1D>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>(
            std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesControlArray1D_size(AxesControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesControlArray1D_empty(AxesControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesControlArray1D_erase_at(AxesControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesControlArray1D_clear(AxesControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesControlArray1D_push_back(AxesControlArray1DHandle handle, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray1D_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesControlArray1D_contains(AxesControlArray1DHandle handle, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray1D_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesControlArray1D_index(AxesControlArray1DHandle handle, ControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray1D_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::ControlArray1D>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesControlArray1D_items(AxesControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesControlArray1D_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

ControlArray1DHandle AxesControlArray1D_at(AxesControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(obj);
    FALCON_C_API_END(nullptr)
}

AxesControlArray1DHandle AxesControlArray1D_intersection(AxesControlArray1DHandle handle, AxesControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::ControlArray1D>(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>>(result));
    FALCON_C_API_END(nullptr)
}
}
