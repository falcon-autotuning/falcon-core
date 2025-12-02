#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_create(
    ListLabelledMeasuredArray1DHandle arrays) {
    FALCON_C_API_BEGIN
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledMeasuredArray1D_create");
    }
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>(list->items());
    FALCON_C_API_END(nullptr)
}

void LabelledArraysLabelledMeasuredArray1D_destroy(LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_destroy");
}
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    FALCON_C_API_END()
}

ListLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_arrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_arrays");
}
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->items());
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray1D_labels(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_labels");
}
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->labels());
    FALCON_C_API_END(nullptr)
}

bool LabelledArraysLabelledMeasuredArray1D_isControlArrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_isControlArrays");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->isControlArrays();
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledMeasuredArray1D_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_isMeasuredArrays");
    }
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->isMeasuredArrays();
    FALCON_C_API_END(false)
}

LabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_at(LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_at");
}
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray1D(*obj);
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_intersection(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_intersection");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray1D> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>(result->items());
    FALCON_C_API_END(nullptr)
}

size_t LabelledArraysLabelledMeasuredArray1D_size(LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_size");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledMeasuredArray1D_empty(LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_empty");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void LabelledArraysLabelledMeasuredArray1D_erase_at(LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_erase_at");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void LabelledArraysLabelledMeasuredArray1D_clear(LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_clear");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->clear();
    FALCON_C_API_END()
}

void LabelledArraysLabelledMeasuredArray1D_push_back(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_push_back");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray1D_push_back");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool LabelledArraysLabelledMeasuredArray1D_contains(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_contains");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray1D_contains");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t LabelledArraysLabelledMeasuredArray1D_index(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_index");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray1D_index");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledMeasuredArray1D_equal(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_equal");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledMeasuredArray1D_not_equal(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_not_equal");
}
    return !LabelledArraysLabelledMeasuredArray1D_equal(handle, other);
    FALCON_C_API_END(false)
}

StringHandle      LabelledArraysLabelledMeasuredArray1D_to_json_string(LabelledArraysLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to LabelledArraysLabelledMeasuredArray1D_from_json_string");
}
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
