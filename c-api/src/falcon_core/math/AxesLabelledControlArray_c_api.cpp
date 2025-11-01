#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledControlArray_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledControlArray.hpp>

AxesLabelledControlArrayHandle AxesLabelledControlArray_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>());
}

AxesLabelledControlArrayHandle AxesLabelledControlArray_create_raw(const LabelledControlArrayHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::LabelledControlArraySP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesLabelledControlArray_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(data[i]), [](falcon_core::math::arrays::LabelledControlArray*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>(vec));
}

AxesLabelledControlArrayHandle AxesLabelledControlArray_create(ListLabelledControlArrayHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledControlArray_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray>>(list));
}

void AxesLabelledControlArray_destroy(AxesLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle);
}

size_t AxesLabelledControlArray_size(AxesLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->size();
}

bool AxesLabelledControlArray_empty(AxesLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->empty();
}

void AxesLabelledControlArray_erase_at(AxesLabelledControlArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->erase_at(idx);
}

void AxesLabelledControlArray_clear(AxesLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->clear();
}

void AxesLabelledControlArray_push_back(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledControlArray_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->push_back(stored_obj);
}

bool AxesLabelledControlArray_contains(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledControlArray_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->contains(stored_obj);
}

size_t AxesLabelledControlArray_index(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledControlArray_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray>(static_cast<falcon_core::math::arrays::LabelledControlArray*>(value), [](falcon_core::math::arrays::LabelledControlArray*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->index(stored_obj);
}

size_t AxesLabelledControlArray_items(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesLabelledControlArray_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledControlArray(*list->items()[i]);
}
    return n;
}

LabelledControlArrayHandle AxesLabelledControlArray_at(AxesLabelledControlArrayHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray(*obj);
}

bool AxesLabelledControlArray_equal(AxesLabelledControlArrayHandle a, AxesLabelledControlArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(b);
    return *listA == *listB;
}

bool AxesLabelledControlArray_not_equal(AxesLabelledControlArrayHandle a, AxesLabelledControlArrayHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_not_equal");
}
    return !AxesLabelledControlArray_equal(a, b);
}

AxesLabelledControlArrayHandle AxesLabelledControlArray_intersection(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>(result);
}

StringHandle      AxesLabelledControlArray_to_json_string(AxesLabelledControlArrayHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledControlArray_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesLabelledControlArrayHandle AxesLabelledControlArray_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesLabelledControlArray_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray>(*ptr);
}
