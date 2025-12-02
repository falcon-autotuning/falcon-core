#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_create(
    ListLabelledMeasuredArrayHandle arrays) {
    FALCON_C_API_BEGIN
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledMeasuredArray_create");
    }
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>(list->items());
    FALCON_C_API_END(nullptr)
}

void LabelledArraysLabelledMeasuredArray_destroy(LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_destroy");
}
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    FALCON_C_API_END()
}

ListLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_arrays(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_arrays");
}
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->items());
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle LabelledArraysLabelledMeasuredArray_labels(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_labels");
}
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->labels());
    FALCON_C_API_END(nullptr)
}

bool LabelledArraysLabelledMeasuredArray_isControlArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_isControlArrays");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->isControlArrays();
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledMeasuredArray_isMeasuredArrays(
    LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_isMeasuredArrays");
    }
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->isMeasuredArrays();
    FALCON_C_API_END(false)
}

LabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_at(LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_at");
}
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_intersection(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_intersection");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledMeasuredArray> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>(result->items());
    FALCON_C_API_END(nullptr)
}

size_t LabelledArraysLabelledMeasuredArray_size(LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_size");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledMeasuredArray_empty(LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_empty");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void LabelledArraysLabelledMeasuredArray_erase_at(LabelledArraysLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_erase_at");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void LabelledArraysLabelledMeasuredArray_clear(LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_clear");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
    FALCON_C_API_END()
}

void LabelledArraysLabelledMeasuredArray_push_back(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_push_back");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray_push_back");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool LabelledArraysLabelledMeasuredArray_contains(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_contains");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray_contains");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t LabelledArraysLabelledMeasuredArray_index(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_index");
}
if (!value) {
throw std::invalid_argument("Null value passed to LabelledArraysLabelledMeasuredArray_index");
}
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledMeasuredArray_equal(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_equal");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledMeasuredArray_not_equal(LabelledArraysLabelledMeasuredArrayHandle handle, LabelledArraysLabelledMeasuredArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_not_equal");
}
    return !LabelledArraysLabelledMeasuredArray_equal(handle, other);
    FALCON_C_API_END(false)
}

StringHandle      LabelledArraysLabelledMeasuredArray_to_json_string(LabelledArraysLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledMeasuredArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledMeasuredArrayHandle LabelledArraysLabelledMeasuredArray_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to LabelledArraysLabelledMeasuredArray_from_json_string");
}
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
