#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledMeasuredArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>());
    FALCON_C_API_END(nullptr)
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesLabelledMeasuredArray_destroy(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    FALCON_C_API_END()
}

size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
    FALCON_C_API_END(0)
}

bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
    FALCON_C_API_END(false)
}

void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
    FALCON_C_API_END()
}

void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
    FALCON_C_API_END()
}

void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesLabelledMeasuredArray_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledMeasuredArray(*list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
    FALCON_C_API_END(nullptr)
}

bool AxesLabelledMeasuredArray_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(b);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesLabelledMeasuredArray_not_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b) {
    FALCON_C_API_BEGIN
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_not_equal");
}
    return !AxesLabelledMeasuredArray_equal(a, b);
    FALCON_C_API_END(false)
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(result);
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesLabelledMeasuredArray_to_json_string(AxesLabelledMeasuredArrayHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesLabelledMeasuredArray_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
    FALCON_C_API_END(nullptr)
}
}
