#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledMeasuredArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledMeasuredArray1D.hpp>

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>());
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create_raw(const LabelledMeasuredArray1DHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::LabelledMeasuredArray1DSP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray1D_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(data[i]), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(vec));
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_create(ListLabelledMeasuredArray1DHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesLabelledMeasuredArray1D_create");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::math::arrays::LabelledMeasuredArray1D>>(list));
}

void AxesLabelledMeasuredArray1D_destroy(AxesLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
}

size_t AxesLabelledMeasuredArray1D_size(AxesLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->size();
}

bool AxesLabelledMeasuredArray1D_empty(AxesLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->empty();
}

void AxesLabelledMeasuredArray1D_erase_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->erase_at(idx);
}

void AxesLabelledMeasuredArray1D_clear(AxesLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->clear();
}

void AxesLabelledMeasuredArray1D_push_back(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray1D_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->push_back(stored_obj);
}

bool AxesLabelledMeasuredArray1D_contains(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray1D_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->contains(stored_obj);
}

size_t AxesLabelledMeasuredArray1D_index(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesLabelledMeasuredArray1D_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledMeasuredArray1D>(static_cast<falcon_core::math::arrays::LabelledMeasuredArray1D*>(value), [](falcon_core::math::arrays::LabelledMeasuredArray1D*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->index(stored_obj);
}

size_t AxesLabelledMeasuredArray1D_items(AxesLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size) {
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
}

LabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_at(AxesLabelledMeasuredArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledMeasuredArray1D(*obj);
}

bool AxesLabelledMeasuredArray1D_equal(AxesLabelledMeasuredArray1DHandle a, AxesLabelledMeasuredArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(b);
    return *listA == *listB;
}

bool AxesLabelledMeasuredArray1D_not_equal(AxesLabelledMeasuredArray1DHandle a, AxesLabelledMeasuredArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_not_equal");
}
    return !AxesLabelledMeasuredArray1D_equal(a, b);
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_intersection(AxesLabelledMeasuredArray1DHandle handle, AxesLabelledMeasuredArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(result);
}

StringHandle      AxesLabelledMeasuredArray1D_to_json_string(AxesLabelledMeasuredArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesLabelledMeasuredArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesLabelledMeasuredArray1DHandle AxesLabelledMeasuredArray1D_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesLabelledMeasuredArray1D_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledMeasuredArray1D>(*ptr);
}
