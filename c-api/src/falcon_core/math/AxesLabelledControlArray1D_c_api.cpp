#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesLabelledControlArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/LabelledControlArray1D.hpp>

AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>());
}

AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create_raw(const LabelledControlArray1DHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::LabelledControlArray1DSP> vec;
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(data[i]), [](falcon_core::math::arrays::LabelledControlArray1D*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>(vec));
}

AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create(ListLabelledControlArray1DHandle data) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::math::arrays::LabelledControlArray1D>>(list));
}

void AxesLabelledControlArray1D_destroy(AxesLabelledControlArray1DHandle handle) {
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
}

size_t AxesLabelledControlArray1D_size(AxesLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->size();
}

bool AxesLabelledControlArray1D_empty(AxesLabelledControlArray1DHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->empty();
}

void AxesLabelledControlArray1D_erase_at(AxesLabelledControlArray1DHandle handle, size_t idx) {
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->erase_at(idx);
}

void AxesLabelledControlArray1D_clear(AxesLabelledControlArray1DHandle handle) {
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->clear();
}

void AxesLabelledControlArray1D_push_back(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->push_back(stored_obj);
}

bool AxesLabelledControlArray1D_contains(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->contains(stored_obj);
}

size_t AxesLabelledControlArray1D_index(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::math::arrays::LabelledControlArray1D>(static_cast<falcon_core::math::arrays::LabelledControlArray1D*>(value), [](falcon_core::math::arrays::LabelledControlArray1D*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->index(stored_obj);
}

size_t AxesLabelledControlArray1D_items(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::LabelledControlArray1D(*list->items()[i]);
}
    return n;
}

LabelledControlArray1DHandle AxesLabelledControlArray1D_at(AxesLabelledControlArray1DHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::LabelledControlArray1D(*obj);
}

bool AxesLabelledControlArray1D_equal(AxesLabelledControlArray1DHandle a, AxesLabelledControlArray1DHandle b) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(b);
    return *listA == *listB;
}

bool AxesLabelledControlArray1D_not_equal(AxesLabelledControlArray1DHandle a, AxesLabelledControlArray1DHandle b) {
    return !AxesLabelledControlArray1D_equal(a, b);
}

AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_intersection(AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>(result);
}

StringHandle      AxesLabelledControlArray1D_to_json_string(AxesLabelledControlArray1DHandle handle) {
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::LabelledControlArray1D>(*ptr);
}
