#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledControlArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledControlArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_create(
    ListLabelledControlArrayHandle arrays) {
    FALCON_C_API_BEGIN
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledControlArray_create");
    }
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>(list->items());
    FALCON_C_API_END(nullptr)
}

void LabelledArraysLabelledControlArray_destroy(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_destroy");
}
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    FALCON_C_API_END()
}

ListLabelledControlArrayHandle LabelledArraysLabelledControlArray_arrays(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_arrays");
}
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->items());
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle LabelledArraysLabelledControlArray_labels(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_labels");
}
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->labels());
    FALCON_C_API_END(nullptr)
}

bool LabelledArraysLabelledControlArray_isControlArrays(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_isControlArrays");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->isControlArrays();
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledControlArray_isMeasuredArrays(
    LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_isMeasuredArrays");
    }
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->isMeasuredArrays();
    FALCON_C_API_END(false)
}

LabelledControlArrayHandle LabelledArraysLabelledControlArray_at(LabelledArraysLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_at");
}
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray(*obj);
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_intersection(LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_intersection");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>(result->items());
    FALCON_C_API_END(nullptr)
}

size_t LabelledArraysLabelledControlArray_size(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_size");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledControlArray_empty(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_empty");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void LabelledArraysLabelledControlArray_erase_at(LabelledArraysLabelledControlArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_erase_at");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void LabelledArraysLabelledControlArray_clear(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_clear");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->clear();
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
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->push_back(stored_obj);
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
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->contains(stored_obj);
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
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledControlArray_equal(LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_equal");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledControlArray_not_equal(LabelledArraysLabelledControlArrayHandle handle, LabelledArraysLabelledControlArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_not_equal");
}
    return !LabelledArraysLabelledControlArray_equal(handle, other);
    FALCON_C_API_END(false)
}

StringHandle      LabelledArraysLabelledControlArray_to_json_string(LabelledArraysLabelledControlArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledControlArrayHandle LabelledArraysLabelledControlArray_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to LabelledArraysLabelledControlArray_from_json_string");
}
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
