#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledControlArray_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledControlArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesLabelledControlArrayHandle= falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>;
DEFINE_C_API_COPY_TEMPLATE(AxesLabelledControlArray, MACROAxesLabelledControlArrayHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesLabelledControlArray, MACROAxesLabelledControlArrayHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesLabelledControlArray, MACROAxesLabelledControlArrayHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesLabelledControlArray, MACROAxesLabelledControlArrayHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesLabelledControlArray, MACROAxesLabelledControlArrayHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesLabelledControlArray, MACROAxesLabelledControlArrayHandle);
AxesLabelledControlArrayHandle AxesLabelledControlArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>(
        std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>>());
    FALCON_C_API_END(nullptr)
}

AxesLabelledControlArrayHandle AxesLabelledControlArray_create(ListLabelledControlArrayHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledControlArray_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>(
            std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesLabelledControlArray_size(AxesLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesLabelledControlArray_empty(AxesLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesLabelledControlArray_erase_at(AxesLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesLabelledControlArray_clear(AxesLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesLabelledControlArray_push_back(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledControlArray_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesLabelledControlArray_contains(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledControlArray_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesLabelledControlArray_index(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledControlArray_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesLabelledControlArray_items(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesLabelledControlArray_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledControlArrayHandle AxesLabelledControlArray_at(AxesLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(obj);
    FALCON_C_API_END(nullptr)
}

AxesLabelledControlArrayHandle AxesLabelledControlArray_intersection(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledControlArray>(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>>(result));
    FALCON_C_API_END(nullptr)
}
}
