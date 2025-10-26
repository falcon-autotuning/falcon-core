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
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(data[i]), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(vec));
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray>>(list));
}

void AxesLabelledMeasuredArray_destroy(AxesLabelledMeasuredArrayHandle handle) {
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
}

size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->size();
}

bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->empty();
}

void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->erase_at(idx);
}

void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle) {
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->clear();
}

void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->push_back(stored_obj);
}

bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->contains(stored_obj);
}

size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->index(stored_obj);
}

size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledMeasuredArray(*list->items()[i]);
}
    return n;
}

LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray(*obj);
}

bool AxesLabelledMeasuredArray_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(b);
    return *listA == *listB;
}

bool AxesLabelledMeasuredArray_not_equal(AxesLabelledMeasuredArrayHandle a, AxesLabelledMeasuredArrayHandle b) {
    return !AxesLabelledMeasuredArray_equal(a, b);
}

AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(result);
}

StringHandle      AxesLabelledMeasuredArray_to_json_string(AxesLabelledMeasuredArrayHandle handle) {
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray>(*ptr);
}
