#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>

LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_create(
    ListLabelledMeasuredArrayHandle arrays) {
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledMeasuredArray_create");
    }
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>(list->items());
}

void LabelledArraysLabelledMeasuredArray_destroy(LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_destroy");
}
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
}

ListLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_arrays");
}
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->items());
}

ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray_labels(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_labels");
}
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->labels());
}

bool LabelledArraysLabelledMeasuredArray_isControlArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_isControlArrays");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->isControlArrays();
}

bool LabelledArraysLabelledMeasuredArray_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_isMeasuredArrays");
    }
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->isMeasuredArrays();
}

LabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_at(LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_at");
}
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
}

LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_intersection(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_intersection");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>(result->items());
}

size_t LabelledArraysLabelledMeasuredArray_size(LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_size");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
}

bool LabelledArraysLabelledMeasuredArray_empty(LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_empty");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
}

void LabelledArraysLabelledMeasuredArray_erase_at(LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_erase_at");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
}

void LabelledArraysLabelledMeasuredArray_clear(LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_clear");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
}

void LabelledArraysLabelledMeasuredArray_push_back(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_push_back");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray_push_back");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
}

bool LabelledArraysLabelledMeasuredArray_contains(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_contains");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray_contains");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
}

size_t LabelledArraysLabelledMeasuredArray_index(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_index");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray_index");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
}

bool LabelledArraysLabelledMeasuredArray_equal(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_equal");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    return *listA == *listB;
}

bool LabelledArraysLabelledMeasuredArray_not_equal(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_not_equal");
}
    return !LabelledArraysLabelledMeasuredArray_equal(handle, other);
}

StringHandle      LabelledArraysLabelledMeasuredArray_to_json_string(LabelledArraysLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to LabelledArraysLabelledMeasuredArray_from_json_string");
}
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
}
