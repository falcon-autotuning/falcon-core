#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMeasurementContextHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListMeasurementContextHandle ListMeasurementContext_create_empty();
// @category:allocation
FALCON_CORE_C_API ListMeasurementContextHandle ListMeasurementContext_copy(ListMeasurementContextHandle handle);

// @category:allocation
FALCON_CORE_C_API ListMeasurementContextHandle ListMeasurementContext_fill_value(size_t count, MeasurementContextHandle value);
// @category:allocation
FALCON_CORE_C_API ListMeasurementContextHandle ListMeasurementContext_create(MeasurementContextHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListMeasurementContext_destroy(ListMeasurementContextHandle handle);
// @category:write
FALCON_CORE_C_API void ListMeasurementContext_push_back(ListMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
FALCON_CORE_C_API size_t ListMeasurementContext_size(ListMeasurementContextHandle handle);
// @category:read
FALCON_CORE_C_API bool ListMeasurementContext_empty(ListMeasurementContextHandle handle);
// @category:write
FALCON_CORE_C_API void ListMeasurementContext_erase_at(ListMeasurementContextHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListMeasurementContext_clear(ListMeasurementContextHandle handle);
// @category:read
FALCON_CORE_C_API MeasurementContextHandle ListMeasurementContext_at(ListMeasurementContextHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListMeasurementContext_items(ListMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListMeasurementContext_contains(ListMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
FALCON_CORE_C_API size_t ListMeasurementContext_index(ListMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
FALCON_CORE_C_API ListMeasurementContextHandle ListMeasurementContext_intersection(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);
// @category:read
FALCON_CORE_C_API bool ListMeasurementContext_equal(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);
// @category:read
FALCON_CORE_C_API bool ListMeasurementContext_not_equal(ListMeasurementContextHandle handle, ListMeasurementContextHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListMeasurementContext_to_json_string(ListMeasurementContextHandle handle);
// @category:allocation
FALCON_CORE_C_API ListMeasurementContextHandle ListMeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif