#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesDiscretizer_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/discrete_spaces/Discretizer.hpp>

AxesDiscretizerHandle AxesDiscretizer_create_empty() {
    return new falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>(
        falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>());
}

AxesDiscretizerHandle AxesDiscretizer_create_raw(const DiscretizerHandle* data, size_t count) {
    std::vector<falcon_core::math::discrete_spaces::DiscretizerSP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesDiscretizer_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(data[i]), [](falcon_core::math::discrete_spaces::Discretizer*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>(
        falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>(vec));
}

AxesDiscretizerHandle AxesDiscretizer_create(ListDiscretizerHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesDiscretizer_create");
}
    auto list = static_cast<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>*>(data);
    return new falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::math::discrete_spaces::Discretizer>>(list));
}

void AxesDiscretizer_destroy(AxesDiscretizerHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
}

size_t AxesDiscretizer_size(AxesDiscretizerHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->size();
}

bool AxesDiscretizer_empty(AxesDiscretizerHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->empty();
}

void AxesDiscretizer_erase_at(AxesDiscretizerHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->erase_at(idx);
}

void AxesDiscretizer_clear(AxesDiscretizerHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->clear();
}

void AxesDiscretizer_push_back(AxesDiscretizerHandle handle, DiscretizerHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesDiscretizer_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->push_back(stored_obj);
}

bool AxesDiscretizer_contains(AxesDiscretizerHandle handle, DiscretizerHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesDiscretizer_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->contains(stored_obj);
}

size_t AxesDiscretizer_index(AxesDiscretizerHandle handle, DiscretizerHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesDiscretizer_fill_value");
            }
            auto stored_obj = std::shared_ptr<falcon_core::math::discrete_spaces::Discretizer>(static_cast<falcon_core::math::discrete_spaces::Discretizer*>(value), [](falcon_core::math::discrete_spaces::Discretizer*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->index(stored_obj);
}

size_t AxesDiscretizer_items(AxesDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesDiscretizer_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::discrete_spaces::Discretizer(*list->items()[i]);
}
    return n;
}

DiscretizerHandle AxesDiscretizer_at(AxesDiscretizerHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->at(idx);
    return new falcon_core::math::discrete_spaces::Discretizer(*obj);
}

bool AxesDiscretizer_equal(AxesDiscretizerHandle a, AxesDiscretizerHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(b);
    return *listA == *listB;
}

bool AxesDiscretizer_not_equal(AxesDiscretizerHandle a, AxesDiscretizerHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_not_equal");
}
    return !AxesDiscretizer_equal(a, b);
}

AxesDiscretizerHandle AxesDiscretizer_intersection(AxesDiscretizerHandle handle, AxesDiscretizerHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>>(*listB));
    return new falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>(result);
}

StringHandle      AxesDiscretizer_to_json_string(AxesDiscretizerHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesDiscretizerHandle AxesDiscretizer_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesDiscretizer_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>::from_json_string<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>(*ptr);
}
