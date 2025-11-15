#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/generic/ListMeasurementContext_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesMeasurementContextHandle;
// Function declarations

AxesMeasurementContextHandle AxesMeasurementContext_create_empty();
AxesMeasurementContextHandle AxesMeasurementContext_create_raw(const MeasurementContextHandle* data, size_t count);
AxesMeasurementContextHandle AxesMeasurementContext_create(ListMeasurementContextHandle data);
void AxesMeasurementContext_destroy(AxesMeasurementContextHandle handle);
void AxesMeasurementContext_push_back(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
size_t AxesMeasurementContext_size(AxesMeasurementContextHandle handle);
bool AxesMeasurementContext_empty(AxesMeasurementContextHandle handle);
void AxesMeasurementContext_erase_at(AxesMeasurementContextHandle handle, size_t idx);
void AxesMeasurementContext_clear(AxesMeasurementContextHandle handle);
MeasurementContextHandle AxesMeasurementContext_at(AxesMeasurementContextHandle handle, size_t idx);
size_t AxesMeasurementContext_items(AxesMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size);
bool AxesMeasurementContext_contains(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
size_t AxesMeasurementContext_index(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
AxesMeasurementContextHandle AxesMeasurementContext_intersection(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);
bool AxesMeasurementContext_equal(AxesMeasurementContextHandle a, AxesMeasurementContextHandle b);
bool AxesMeasurementContext_not_equal(AxesMeasurementContextHandle a, AxesMeasurementContextHandle b);

// Serialization (from Song)
StringHandle      AxesMeasurementContext_to_json_string(AxesMeasurementContextHandle handle);
AxesMeasurementContextHandle AxesMeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif