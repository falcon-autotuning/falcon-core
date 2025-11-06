#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesMeasurementContext_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>

AxesMeasurementContextHandle AxesMeasurementContext_create_empty() {
    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>());
}

AxesMeasurementContextHandle AxesMeasurementContext_create_raw(const MeasurementContextHandle* data, size_t count) {
    std::vector<falcon_core::autotuner_interfaces::contexts::MeasurementContextSP> vec;
        
    if (!data) {
    throw std::invalid_argument("Null data handle passed to AxesMeasurementContext_create_allocation");
                }
    vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(data[i])));
    }

    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(vec));
}

AxesMeasurementContextHandle AxesMeasurementContext_create(ListMeasurementContextHandle data) {
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesMeasurementContext_create");
}
    auto list = *static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(data);
    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
            std::make_shared<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(list));
}

void AxesMeasurementContext_destroy(AxesMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_destroy");
}
    delete static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
}

size_t AxesMeasurementContext_size(AxesMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_size");
}
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->size();
}

bool AxesMeasurementContext_empty(AxesMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_empty");
}
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->empty();
}

void AxesMeasurementContext_erase_at(AxesMeasurementContextHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_erase_at");
}
    static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->erase_at(idx);
}

void AxesMeasurementContext_clear(AxesMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_clear");
}
    static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->clear();
}

void AxesMeasurementContext_push_back(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMeasurementContext_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value));
    static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->push_back(stored_obj);
}

bool AxesMeasurementContext_contains(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMeasurementContext_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->contains(stored_obj);
}

size_t AxesMeasurementContext_index(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMeasurementContext_fill_value");
            }
            auto stored_obj = std::make_shared<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value));
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->index(stored_obj);
}

size_t AxesMeasurementContext_items(AxesMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesMeasurementContext_items");
}
    auto list = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::contexts::MeasurementContext(*list->items()[i]);
}
    return n;
}

MeasurementContextHandle AxesMeasurementContext_at(AxesMeasurementContextHandle handle, size_t idx) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_at");
}
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::contexts::MeasurementContext(*obj);
}

bool AxesMeasurementContext_equal(AxesMeasurementContextHandle a, AxesMeasurementContextHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_equal");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(b);
    return *listA == *listB;
}

bool AxesMeasurementContext_not_equal(AxesMeasurementContextHandle a, AxesMeasurementContextHandle b) {
if (!a || !b) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_not_equal");
}
    return !AxesMeasurementContext_equal(a, b);
}

AxesMeasurementContextHandle AxesMeasurementContext_intersection(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other) {
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_intersection");
}
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(*listB));
    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(result);
}

StringHandle      AxesMeasurementContext_to_json_string(AxesMeasurementContextHandle handle) {
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_to_json_string");
}
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}

AxesMeasurementContextHandle AxesMeasurementContext_from_json_string(StringHandle json) {
if (!json) {
throw std::invalid_argument("Null string handle passed to AxesMeasurementContext_from_json_string");
}
  auto ptr = falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>::from_json_string<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*ptr);
}
