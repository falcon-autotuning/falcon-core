#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include <stddef.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMeasurementContextHandle;
// Function declarations

ListMeasurementContextHandle ListMeasurementContext_create_empty();

ListMeasurementContextHandle ListMeasurementContext_fill_value(size_t count, MeasurementContextHandle value);
ListMeasurementContextHandle ListMeasurementContext_create(MeasurementContextHandle* data, size_t count);
void ListMeasurementContext_destroy(ListMeasurementContextHandle handle);
void ListMeasurementContext_push_back(ListMeasurementContextHandle handle, MeasurementContextHandle value);
size_t ListMeasurementContext_size(ListMeasurementContextHandle handle);
bool ListMeasurementContext_empty(ListMeasurementContextHandle handle);
void ListMeasurementContext_erase_at(ListMeasurementContextHandle handle, size_t idx);
void ListMeasurementContext_clear(ListMeasurementContextHandle handle);
MeasurementContextHandle ListMeasurementContext_at(ListMeasurementContextHandle handle, size_t idx);
size_t ListMeasurementContext_items(ListMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size);
bool ListMeasurementContext_contains(ListMeasurementContextHandle handle, MeasurementContextHandle value);
size_t ListMeasurementContext_index(ListMeasurementContextHandle handle, MeasurementContextHandle value);
ListMeasurementContextHandle ListMeasurementContext_intersection(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);
bool ListMeasurementContext_equal(ListMeasurementContextHandle a, ListMeasurementContextHandle b);
bool ListMeasurementContext_not_equal(ListMeasurementContextHandle a, ListMeasurementContextHandle b);

// Serialization (from Song)
StringHandle      ListMeasurementContext_to_json_string(ListMeasurementContextHandle handle);
ListMeasurementContextHandle ListMeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif