#include <falcon_core\math\arrays/LabelledArrays.hpp>
#include "falcon_core\math\arrays\LabelledArraysLabelledControlArray_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledControlArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROLabelledArraysLabelledControlArrayHandle= falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>;
DEFINE_C_API_COPY_TEMPLATE(LabelledArraysLabelledControlArray, MACROLabelledArraysLabelledControlArrayHandle)
DEFINE_C_API_DESTROY_TEMPLATE(LabelledArraysLabelledControlArray, MACROLabelledArraysLabelledControlArrayHandle);
DEFINE_C_API_EQUAL_TEMPLATE(LabelledArraysLabelledControlArray, MACROLabelledArraysLabelledControlArrayHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(LabelledArraysLabelledControlArray, MACROLabelledArraysLabelledControlArrayHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(LabelledArraysLabelledControlArray, MACROLabelledArraysLabelledControlArrayHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(LabelledArraysLabelledControlArray, MACROLabelledArraysLabelledControlArrayHandle);

LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_create(
    ListLabelledControlArrayHandle arrays) {
    FALCON_C_API_BEGIN
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledControlArray_create");
    }
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>*>(arrays);
    return new falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>(
        std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>>(list->items()));
    FALCON_C_API_END(nullptr)
}

ListLabelledControlArrayHandle LabelledArraysLabelledControlArray_arrays(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_arrays");
}
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(
            (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(
                handle))->items()));
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle LabelledArraysLabelledControlArray_labels(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_labels");
}
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>((*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->labels());
    FALCON_C_API_END(nullptr)
}

bool LabelledArraysLabelledControlArray_is_control_arrays(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_is_control_arrays");
}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->is_control_arrays();
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledControlArray_is_measured_arrays(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_is_measured_arrays");
    }
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->is_measured_arrays();
    FALCON_C_API_END(false)
}

LabelledControlArrayHandle LabelledArraysLabelledControlArray_at(LabelledArraysLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_at");
}
    auto obj = (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(obj);
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_intersection(LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_intersection");
}
    auto listA = *static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = *static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray> result = listA->intersection(listB);
    return new falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>(
        std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>>(
            result->items()));
    FALCON_C_API_END(nullptr)
}

size_t LabelledArraysLabelledControlArray_size(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_size");
}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledControlArray_empty(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_empty");
}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void LabelledArraysLabelledControlArray_erase_at(LabelledArraysLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_erase_at");
}
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void LabelledArraysLabelledControlArray_clear(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_clear");
}
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->clear();
    FALCON_C_API_END()
}

void LabelledArraysLabelledControlArray_push_back(LabelledArraysLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_push_back");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledControlArray_push_back");
}
    auto stored_obj = falcon_core::math::arrays::LabelledControlArraySP(*static_cast<falcon_core::math::arrays::LabelledControlArraySP*>(value));
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool LabelledArraysLabelledControlArray_contains(LabelledArraysLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_contains");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledControlArray_contains");
}
    auto stored_obj = falcon_core::math::arrays::LabelledControlArraySP(*static_cast<falcon_core::math::arrays::LabelledControlArraySP*>(value));
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t LabelledArraysLabelledControlArray_index(LabelledArraysLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_index");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledControlArray_index");
}
    auto stored_obj = falcon_core::math::arrays::LabelledControlArraySP(*static_cast<falcon_core::math::arrays::LabelledControlArraySP*>(value));
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}
}
