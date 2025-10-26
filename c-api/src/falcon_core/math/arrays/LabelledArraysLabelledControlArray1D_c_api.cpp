#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledControlArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>

LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>(list->items());
}

void LabelledArraysLabelledControlArray1D_destroy(LabelledArraysLabelledControlArray1DHandle handle) {
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
}

ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->items());
}

ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle) {
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->labels());
}

bool LabelledArraysLabelledControlArray1D_isControlArrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->isControlArrays();
}

bool LabelledArraysLabelledControlArray1D_isMeasuredArrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->isMeasuredArrays();
}

LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(LabelledArraysLabelledControlArray1DHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray1D(*obj);
}

LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_intersection(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>(result->items());
}

size_t LabelledArraysLabelledControlArray1D_size(LabelledArraysLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->size();
}

bool LabelledArraysLabelledControlArray1D_empty(LabelledArraysLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->empty();
}

void LabelledArraysLabelledControlArray1D_erase_at(LabelledArraysLabelledControlArray1DHandle handle, size_t idx) {
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->erase_at(idx);
}

void LabelledArraysLabelledControlArray1D_clear(LabelledArraysLabelledControlArray1DHandle handle) {
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->clear();
}

void LabelledArraysLabelledControlArray1D_push_back(LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->push_back(stored_obj);
}

bool LabelledArraysLabelledControlArray1D_contains(LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->contains(stored_obj);
}

size_t LabelledArraysLabelledControlArray1D_index(LabelledArraysLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->index(stored_obj);
}

bool LabelledArraysLabelledControlArray1D_equal(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    return *listA == *listB;
}

bool LabelledArraysLabelledControlArray1D_not_equal(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    return !LabelledArraysLabelledControlArray1D_equal(handle, other);
}

StringHandle      LabelledArraysLabelledControlArray1D_to_json_string(LabelledArraysLabelledControlArray1DHandle handle) {
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>(*ptr);
}
