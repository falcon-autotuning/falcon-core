#include <falcon_core/math/Axes.hpp>
#include "falcon_core/math/AxesMeasurementContext_c_api.h"
#include "falcon_core/Precompiled_c_api.h"
#include "falcon_core/export_c_api.h"
#include <falcon_core/generic/List.hpp>
#include <falcon_core/autotuner_interfaces/contexts/MeasurementContext.hpp>
#include "falcon_core/generic/ErrorHandling_c_api.h"

extern "C" {
using MACROAxesMeasurementContextHandle= falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>;
DEFINE_C_API_COPY_TEMPLATE(AxesMeasurementContext, MACROAxesMeasurementContextHandle)
DEFINE_C_API_DESTROY_TEMPLATE(AxesMeasurementContext, MACROAxesMeasurementContextHandle);
DEFINE_C_API_EQUAL_TEMPLATE(AxesMeasurementContext, MACROAxesMeasurementContextHandle);
DEFINE_C_API_NOT_EQUAL_TEMPLATE(AxesMeasurementContext, MACROAxesMeasurementContextHandle);
DEFINE_C_API_TO_JSON_TEMPLATE(AxesMeasurementContext, MACROAxesMeasurementContextHandle);
DEFINE_C_API_FROM_JSON_TEMPLATE(AxesMeasurementContext, MACROAxesMeasurementContextHandle);
AxesMeasurementContextHandle AxesMeasurementContext_create_empty() {
    FALCON_C_API_BEGIN
    return new falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
        std::make_shared<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>());
    FALCON_C_API_END(nullptr)
}

AxesMeasurementContextHandle AxesMeasurementContext_create(ListMeasurementContextHandle data) {
    FALCON_C_API_BEGIN
if (!data) {
throw std::invalid_argument("Null data handle passed to AxesMeasurementContext_create");
}
    auto list = *static_cast<falcon_core::generic::ListSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(data);
    return new falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(
            std::make_shared<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(list));
    FALCON_C_API_END(nullptr)
}

size_t AxesMeasurementContext_size(AxesMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_size");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->size();
    FALCON_C_API_END(0)
}

bool AxesMeasurementContext_empty(AxesMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_empty");
}
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->empty();
    FALCON_C_API_END(false)
}

void AxesMeasurementContext_erase_at(AxesMeasurementContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_erase_at");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->erase_at(idx);
    FALCON_C_API_END()
}

void AxesMeasurementContext_clear(AxesMeasurementContextHandle handle) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_clear");
}
    (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->clear();
    FALCON_C_API_END()
}

void AxesMeasurementContext_push_back(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_push_back");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMeasurementContext_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->push_back(stored_obj);
    FALCON_C_API_END()
}

bool AxesMeasurementContext_contains(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_contains");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMeasurementContext_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->contains(stored_obj);
    FALCON_C_API_END(false)
}

size_t AxesMeasurementContext_index(AxesMeasurementContextHandle handle, MeasurementContextHandle value) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_index");
}
    
            if (!value) {
            throw std::invalid_argument("Null value passed to AxesMeasurementContext_fill_value");
            }
            auto stored_obj = *static_cast<std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(value);
    return (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->index(stored_obj);
    FALCON_C_API_END(0)
}

size_t AxesMeasurementContext_items(AxesMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_items");
}
if (!out_buffer) {
throw std::invalid_argument("Null output buffer passed to AxesMeasurementContext_items");
}
    auto list = *static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    size_t n = std::min(buffer_size, list->items().size());
    
for (size_t i = 0; i < n; ++i) {
    out_buffer[i] = new std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(list->items()[i]);
}
    return n;
    FALCON_C_API_END(0)
}

MeasurementContextHandle AxesMeasurementContext_at(AxesMeasurementContextHandle handle, size_t idx) {
    FALCON_C_API_BEGIN
if (!handle) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_at");
}
    auto obj = (*static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle))->at(idx);
    return new std::shared_ptr<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(obj);
    FALCON_C_API_END(nullptr)
}

AxesMeasurementContextHandle AxesMeasurementContext_intersection(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other) {
    FALCON_C_API_BEGIN
if (!handle || !other) {
throw std::invalid_argument("Null handle passed to AxesMeasurementContext_intersection");
}
    auto listA = *static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(handle);
    auto listB = *static_cast<falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>*>(other);
    auto result = listA->intersection(listB);
    return new falcon_core::math::AxesSP<falcon_core::autotuner_interfaces::contexts::MeasurementContext>(std::make_shared<falcon_core::math::Axes<falcon_core::autotuner_interfaces::contexts::MeasurementContext>>(result));
    FALCON_C_API_END(nullptr)
}
}
