#include <falcon-core/math/Axes.hpp>
#include "falcon-core/math/AxesLabelledMeasuredArray_c_api.h"
#include "falcon-core/Precompiled_c_api.h"
#include "falcon-core/export_c_api.h"
#include <falcon-core/generic/List.hpp>
#include <falcon-core/math/arrays/LabelledMeasuredArray.hpp>
#include "falcon-core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesLabelledMeasuredArrayHandle= falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>;
DEFINE_C_API_COPY_TEMPLATE(AxesLabelledMeasuredArray, MACROAxesLabelledMeasuredArrayHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesLabelledMeasuredArray, MACROAxesLabelledMeasuredArrayHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesLabelledMeasuredArray, MACROAxesLabelledMeasuredArrayHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesLabelledMeasuredArray, MACROAxesLabelledMeasuredArrayHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesLabelledMeasuredArray, MACROAxesLabelledMeasuredArrayHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesLabelledMeasuredArray, MACROAxesLabelledMeasuredArrayHandle);
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>(
        std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>());
    FALCON_C_API_END(nullptr)
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>(
            std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesLabelledMeasuredArray_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(obj);
    FALCON_C_API_END(nullptr)
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::math::arrays::LabelledMeasuredArray>(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(result));
    FALCON_C_API_END(nullptr)
}
}
