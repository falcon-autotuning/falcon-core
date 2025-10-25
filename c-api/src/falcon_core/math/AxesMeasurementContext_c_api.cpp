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
        vec.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        vec.push_back(std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(data[i]), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} ));
    }

    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(vec));
}

AxesMeasurementContextHandle AxesMeasurementContext_create(ListMeasurementContextHandle data) {
    auto list = static_cast<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(data);
    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
            std::shared_ptr<falcon_core::generic::List<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(list));
}

void AxesMeasurementContext_destroy(AxesMeasurementContextHandle handle) {
    delete static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
}

size_t AxesMeasurementContext_size(AxesMeasurementContextHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->size();
}

bool AxesMeasurementContext_empty(AxesMeasurementContextHandle handle) {
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->empty();
}

void AxesMeasurementContext_erase_at(AxesMeasurementContextHandle handle, size_t idx) {
    static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->erase_at(idx);
}

void AxesMeasurementContext_clear(AxesMeasurementContextHandle handle) {
    static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->clear();
}

void AxesMeasurementContext_push_back(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->push_back(stored_obj);
}

bool AxesMeasurementContext_contains(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->contains(stored_obj);
}

size_t AxesMeasurementContext_index(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
    auto stored_obj = std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(static_cast<falcon_core::autotuner_interfaces::contexts::MeasurementContext*>(value), [](falcon_core::autotuner_interfaces::contexts::MeasurementContext*) {} );
    return static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->index(stored_obj);
}

size_t AxesMeasurementContext_items(AxesMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size) {
    auto list = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new falcon_core::autotuner_interfaces::contexts::MeasurementContext(*list->items()[i]);
}
    return n;
}

MeasurementContextHandle AxesMeasurementContext_at(AxesMeasurementContextHandle handle, size_t idx) {
    auto obj = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->at(idx);
    return new falcon_core::autotuner_interfaces::contexts::MeasurementContext(*obj);
}

bool AxesMeasurementContext_equal(AxesMeasurementContextHandle a, AxesMeasurementContextHandle b) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(a);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(b);
    return *listA == *listB;
}

bool AxesMeasurementContext_not_equal(AxesMeasurementContextHandle a, AxesMeasurementContextHandle b) {
    return !AxesMeasurementContext_equal(a, b);
}

AxesMeasurementContextHandle AxesMeasurementContext_intersection(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other) {
    auto listA = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    auto result = listA->intersection(std::make_shared<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(*listB));
    return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(result);
}

StringHandle      AxesMeasurementContext_to_json_string(AxesMeasurementContextHandle handle) {
    std::string json = static_cast<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle)->to_json_string();
    return String_create(json.c_str(), json.size());
}
AxesMeasurementContextHandle AxesMeasurementContext_from_json_string(StringHandle json) {
  auto ptr = falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>::from_json_string<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(json->raw);
  return new falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(*ptr);
}
