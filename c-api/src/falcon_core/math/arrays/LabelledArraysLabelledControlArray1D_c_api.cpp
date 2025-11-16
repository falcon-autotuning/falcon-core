#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include "falcon_core/math/arrays/LabelledArraysLabelledControlArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledArrays.hpp>
#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays) {
    FALCON_C_API_BEGIN
    if (!arrays) {
    throw std::invalid_argument("Null arrays handle passed to LabelledArraysLabelledControlArray1D_create");
    }
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(arrays);
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>(list->items());
    FALCON_C_API_END(nullptr)
}

void LabelledArraysLabelledControlArray1D_destroy(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_destroy");
}
    delete static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    FALCON_C_API_END()
}

ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_arrays");
}
    return new falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->items());
    FALCON_C_API_END(nullptr)
}

ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_labels");
}
    return new falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::AcquisitionContext>(*static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->labels());
    FALCON_C_API_END(nullptr)
}

bool LabelledArraysLabelledControlArray1D_isControlArrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_isControlArrays");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->isControlArrays();
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledControlArray1D_isMeasuredArrays(
    LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
    if (!handle) {
    throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_isMeasuredArrays");
    }
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->isMeasuredArrays();
    FALCON_C_API_END(false)
}

LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(LabelledArraysLabelledControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_at");
}
    auto obj = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray1D(*obj);
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_intersection(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_intersection");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    falcon_core::generic::ListSP<falcon_core::math::arrays::LabelledControlArray1D> result = listA->intersection(std::make_shared<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>>(*listB));
    return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>(result->items());
    FALCON_C_API_END(nullptr)
}

size_t LabelledArraysLabelledControlArray1D_size(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_size");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledControlArray1D_empty(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_empty");
}
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void LabelledArraysLabelledControlArray1D_erase_at(LabelledArraysLabelledControlArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_erase_at");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void LabelledArraysLabelledControlArray1D_clear(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_clear");
}
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->clear();
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
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->push_back(stored_obj);
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
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->contains(stored_obj);
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
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

bool LabelledArraysLabelledControlArray1D_equal(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_equal");
}
    auto listA = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool LabelledArraysLabelledControlArray1D_not_equal(LabelledArraysLabelledControlArray1DHandle handle, LabelledArraysLabelledControlArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_not_equal");
}
    return !LabelledArraysLabelledControlArray1D_equal(handle, other);
    FALCON_C_API_END(false)
}

StringHandle      LabelledArraysLabelledControlArray1D_to_json_string(LabelledArraysLabelledControlArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to LabelledArraysLabelledControlArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to LabelledArraysLabelledControlArray1D_from_json_string");
}
  auto ptr = falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>::from_json_string<falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>>(json->raw);
  return new falcon_core::math::arrays::LabelledArrays<falcon_core::math::arrays::LabelledControlArray1D>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
