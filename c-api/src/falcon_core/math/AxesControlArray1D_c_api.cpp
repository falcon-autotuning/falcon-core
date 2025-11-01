#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesControlArray1D_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/arrays/ControlArray1D.hpp>

AxesControlArray1DHandle AxesControlArray1D_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>());
}

AxesControlArray1DHandle AxesControlArray1D_create_raw(const ControlArray1DHandle* data, size_t count) {
    std::vector<falcon_core::math::arrays::ControlArray1DSP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesControlArray1D_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(data[i]), [](falcon_core::math::arrays::ControlArray1D*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>(
        falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>(vec));
}

AxesControlArray1DHandle AxesControlArray1D_create(ListControlArray1DHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesControlArray1D_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>(
            std::make_shared<falcon_core::generic::List<falcon_core::math::arrays::ControlArray1D>>(list));
}

void AxesControlArray1D_destroy(AxesControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle);
}

size_t AxesControlArray1D_size(AxesControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->size();
}

bool AxesControlArray1D_empty(AxesControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->empty();
}

void AxesControlArray1D_erase_at(AxesControlArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->erase_at(idx);
}

void AxesControlArray1D_clear(AxesControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->clear();
}

void AxesControlArray1D_push_back(AxesControlArray1DHandle handle, ControlArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray1D_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->push_back(stored_obj);
}

bool AxesControlArray1D_contains(AxesControlArray1DHandle handle, ControlArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray1D_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->contains(stored_obj);
}

size_t AxesControlArray1D_index(AxesControlArray1DHandle handle, ControlArray1DHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesControlArray1D_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::arrays::ControlArray1D>(static_cast<falcon_core::math::arrays::ControlArray1D*>(value), [](falcon_core::math::arrays::ControlArray1D*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->index(stored_obj);
}

size_t AxesControlArray1D_items(AxesControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesControlArray1D_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::arrays::ControlArray1D(*list->items()[i]);
}
    return n;
}

ControlArray1DHandle AxesControlArray1D_at(AxesControlArray1DHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->at(idx);
    return new falcon_core::math::arrays::ControlArray1D(*obj);
}

bool AxesControlArray1D_equal(AxesControlArray1DHandle a, AxesControlArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(b);
    return *listA == *listB;
}

bool AxesControlArray1D_not_equal(AxesControlArray1DHandle a, AxesControlArray1DHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_not_equal");
}
    return !AxesControlArray1D_equal(a, b);
}

AxesControlArray1DHandle AxesControlArray1D_intersection(AxesControlArray1DHandle handle, AxesControlArray1DHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>(result);
}

StringHandle      AxesControlArray1D_to_json_string(AxesControlArray1DHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesControlArray1D_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesControlArray1DHandle AxesControlArray1D_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesControlArray1D_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>::from_json_string<falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::arrays::ControlArray1D>(*ptr);
}
