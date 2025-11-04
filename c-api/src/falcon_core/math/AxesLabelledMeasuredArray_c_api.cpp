#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledMeasuredArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray.hpp>

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>());
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_raw(const LabelledMeasuredArrayHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::LabelledMeasuredArraySP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(data[i]), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(vec));
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(list));
}

void AxesLabelledMeasuredArray_destroy(AxesLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
}

size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
}

bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
}

void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
}

void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
}

void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
}

bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
}

size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::math::arrays::LabelledMeasuredArray>(*static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
}

size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
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
}

LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
}

bool AxesLabelledMeasuredArray_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(b);
    return *listA == *listB;
}

bool AxesLabelledMeasuredArray_not_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_not_equal");
}
    return !AxesLabelledMeasuredArray_equal(a, b);
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(result);
}

StringHandle      AxesLabelledMeasuredArray_to_json_string(AxesLabelledMeasuredArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesLabelledMeasuredArray_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
}
