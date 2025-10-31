#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>

LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_create(
    ListLabelledMeasuredArray1DHandle arrays) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>(list->items());
}

void LabelledArraysLabelledMeasuredArray1D_destroy(LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_destroy");
}
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
}

ListLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_arrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_arrays");
}
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->items());
}

ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray1D_labels(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_labels");
}
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->labels());
}

bool LabelledArraysLabelledMeasuredArray1D_isControlArrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_isControlArrays");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->isControlArrays();
}

bool LabelledArraysLabelledMeasuredArray1D_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArray1DHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_isMeasuredArrays");
    }
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->isMeasuredArrays();
}

LabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_at(LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_at");
}
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray1D(*obj);
}

LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_intersection(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_intersection");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray1D> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>(result->items());
}

size_t LabelledArraysLabelledMeasuredArray1D_size(LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_size");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->size();
}

bool LabelledArraysLabelledMeasuredArray1D_empty(LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_empty");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->empty();
}

void LabelledArraysLabelledMeasuredArray1D_erase_at(LabelledArraysLabelledMeasuredArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_erase_at");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->erase_at(idx);
}

void LabelledArraysLabelledMeasuredArray1D_clear(LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_clear");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->clear();
}

void LabelledArraysLabelledMeasuredArray1D_push_back(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_push_back");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray1D_push_back");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->push_back(stored_obj);
}

bool LabelledArraysLabelledMeasuredArray1D_contains(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_contains");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray1D_contains");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->contains(stored_obj);
}

size_t LabelledArraysLabelledMeasuredArray1D_index(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_index");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray1D_index");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->index(stored_obj);
}

bool LabelledArraysLabelledMeasuredArray1D_equal(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_equal");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    return *listA == *listB;
}

bool LabelledArraysLabelledMeasuredArray1D_not_equal(LabelledArraysLabelledMeasuredArray1DHandle handle, LabelledArraysLabelledMeasuredArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_not_equal");
}
    return !LabelledArraysLabelledMeasuredArray1D_equal(handle, other);
}

StringHandle      LabelledArraysLabelledMeasuredArray1D_to_json_string(LabelledArraysLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
LabelledArraysLabelledMeasuredArray1DHandle LabelledArraysLabelledMeasuredArray1D_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to LabelledArraysLabelledMeasuredArray1D_from_json_string");
}
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray1D>(*ptr);
}
