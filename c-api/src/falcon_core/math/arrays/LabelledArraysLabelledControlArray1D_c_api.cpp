#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledControlArray1D_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROLabelledArraysLabelledControlArray1DHandle= falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>;
DEFINE_C_API_COPY_TEMPLATE(LabelledArraysLabelledControlArray1D, MACROLabelledArraysLabelledControlArray1DHandle)
DEFINE_C_API_DESTROY_TEMPLATE(LabelledArraysLabelledControlArray1D, MACROLabelledArraysLabelledControlArray1DHandle);
DEFINE_C_API_EQUAL_TEMPLATE(LabelledArraysLabelledControlArray1D, MACROLabelledArraysLabelledControlArray1DHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(LabelledArraysLabelledControlArray1D, MACROLabelledArraysLabelledControlArray1DHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(LabelledArraysLabelledControlArray1D, MACROLabelledArraysLabelledControlArray1DHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(LabelledArraysLabelledControlArray1D, MACROLabelledArraysLabelledControlArray1DHandle);

LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays) {
    FALCON_C_API_BEGIN
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledControlArray1D_create");
    }
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>*>(arrays);
    return new falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>(
        std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>>(list->items()));
    FALCON_C_API_END(nullptr)
}

ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_arrays");
}
    return new falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D>(
        std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>(
            (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(
                handle))->items()));
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_labels");
}
    return new falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>((*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->labels());
    FALCON_C_API_END(nullptr)
}

bool LabelledArraysLabelledControlArray1D_is_control_arrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_is_control_arrays");
}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->is_control_arrays();
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledControlArray1D_is_measured_arrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_is_measured_arrays");
    }
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->is_measured_arrays();
    FALCON_C_API_END(false)
}

LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(LabelledArraysLabelledControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_at");
}
    auto obj = (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(obj);
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_intersection(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_intersection");
}
    auto listA = *static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = *static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D> result = listA->intersection(listB);
    return new falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>(
        std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>>(
            result->items()));
    FALCON_C_API_END(nullptr)
}

size_t LabelledArraysLabelledControlArray1D_size(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_size");
}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledControlArray1D_empty(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_empty");
}
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void LabelledArraysLabelledControlArray1D_erase_at(LabelledArraysLabelledControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_erase_at");
}
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void LabelledArraysLabelledControlArray1D_clear(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_clear");
}
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->clear();
    FALCON_C_API_END()
}

void LabelledArraysLabelledControlArray1D_push_back(LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_push_back");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledControlArray1D_push_back");
}
    auto stored_obj = falcon_core::math::arrays::LabelledControlArray1DSP(*static_cast<falcon_core::math::arrays::LabelledControlArray1DSP*>(value));
    (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool LabelledArraysLabelledControlArray1D_contains(LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_contains");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledControlArray1D_contains");
}
    auto stored_obj = falcon_core::math::arrays::LabelledControlArray1DSP(*static_cast<falcon_core::math::arrays::LabelledControlArray1DSP*>(value));
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t LabelledArraysLabelledControlArray1D_index(LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_index");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledControlArray1D_index");
}
    auto stored_obj = falcon_core::math::arrays::LabelledControlArray1DSP(*static_cast<falcon_core::math::arrays::LabelledControlArray1DSP*>(value));
    return (*static_cast<falcon_core::math::arrays::LabelledArraysSP<falcon_core::math::arrays::LabelledControlArray1D>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}
}
