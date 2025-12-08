#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesDiscretizer_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/math/discrete_spaces/Discretizer.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
AxesDiscretizerHandle AxesDiscretizer_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>(
        std::make_shared<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>>());
    FALCON_C_API_END(nullptr)
}

AxesDiscretizerHandle AxesDiscretizer_create(ListDiscretizerHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesDiscretizer_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::math::discrete_spaces::Discretizer>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>(
            std::make_shared<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>>(list));
    FALCON_C_API_END(nullptr)
}

void AxesDiscretizer_destroy(AxesDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_destroy");
}
    delete static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    FALCON_C_API_END()
}

size_t AxesDiscretizer_size(AxesDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesDiscretizer_empty(AxesDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesDiscretizer_erase_at(AxesDiscretizerHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesDiscretizer_clear(AxesDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesDiscretizer_push_back(AxesDiscretizerHandle handle, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesDiscretizer_fill_value");
            }
            auto stored_obj = *static_cast<falcon_core::math::discrete_spaces::DiscretizerSP*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesDiscretizer_contains(AxesDiscretizerHandle handle, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesDiscretizer_fill_value");
            }
            auto stored_obj = *static_cast<falcon_core::math::discrete_spaces::DiscretizerSP*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesDiscretizer_index(AxesDiscretizerHandle handle, DiscretizerHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesDiscretizer_fill_value");
            }
            auto stored_obj = *static_cast<falcon_core::math::discrete_spaces::DiscretizerSP*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesDiscretizer_items(AxesDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesDiscretizer_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::math::discrete_spaces::DiscretizerSP(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

DiscretizerHandle AxesDiscretizer_at(AxesDiscretizerHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->at(idx);
    return new falcon_core::math::discrete_spaces::DiscretizerSP(obj);
    FALCON_C_API_END(nullptr)
}

bool AxesDiscretizer_equal(AxesDiscretizerHandle handle, AxesDiscretizerHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_equal");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(other);
    return *listA == *listB;
    FALCON_C_API_END(false)
}

bool AxesDiscretizer_not_equal(AxesDiscretizerHandle handle, AxesDiscretizerHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_not_equal");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(other);
    return *listA != *listB;
    FALCON_C_API_END(false)
}

AxesDiscretizerHandle AxesDiscretizer_intersection(AxesDiscretizerHandle handle, AxesDiscretizerHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>(std::make_shared<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>>(result));
    FALCON_C_API_END(nullptr)
}

StringHandle      AxesDiscretizer_to_json_string(AxesDiscretizerHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesDiscretizer_to_json_string");
}
    std::string json = (*static_cast<falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>*>(handle))->to_json_string();
    return String_create(json.c_str(), json.size());
    FALCON_C_API_END(nullptr)
}

AxesDiscretizerHandle AxesDiscretizer_from_json_string(StringHandle json) {
    FALCON_C_API_BEGIN
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesDiscretizer_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>::from_json_string<falcon_core::math::Axes<falcon_core::math::discrete_spaces::Discretizer>>(json->raw);
  return new falcon_core::math::AxesSP<falcon_core::math::discrete_spaces::Discretizer>(ptr);
    FALCON_C_API_END(nullptr)
}
}
