#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledMeasuredArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>());
    FALCON_C_API_END(nullptr)
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create(ListLabelledMeasuredArray1DHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray1D_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesLabelledMeasuredArray1D_destroy(AxesLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    FALCON_C_API_END()
}

size_t AxesLabelledMeasuredArray1D_size(AxesLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesLabelledMeasuredArray1D_empty(AxesLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesLabelledMeasuredArray1D_erase_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesLabelledMeasuredArray1D_clear(AxesLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->clear();
    FALCON_C_API_END()
}

void AxesLabelledMeasuredArray1D_push_back(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray1D_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray1D>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesLabelledMeasuredArray1D_contains(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray1D_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray1D>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesLabelledMeasuredArray1D_index(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray1D_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray1D>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesLabelledMeasuredArray1D_items(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesLabelledMeasuredArray1D_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledMeasuredArray1D(*list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray1D(*obj);
    FALCON_C_API_END(nullptr)
}

bool AxesLabelledMeasuredArray1D_equal(AxesLabelledMeasuredArray1DHandle a, AxesLabelledMeasuredArray1DHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesLabelledMeasuredArray1D_not_equal(AxesLabelledMeasuredArray1DHandle a, AxesLabelledMeasuredArray1DHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_not_equal");
}
    return !AxesLabelledMeasuredArray1D_equal(a, b);
    FALCON_C_API_END(false)
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_intersection(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesLabelledMeasuredArray1D_to_json_string(AxesLabelledMeasuredArray1DHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesLabelledMeasuredArray1D_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
