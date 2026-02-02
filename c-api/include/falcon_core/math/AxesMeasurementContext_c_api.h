#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/contexts/MeasurementContext_c_api.h"
#include "falcon_core/generic/ListMeasurementContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesMeasurementContextHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesMeasurementContextHandle AxesMeasurementContext_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesMeasurementContextHandle AxesMeasurementContext_copy(AxesMeasurementContextHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesMeasurementContextHandle AxesMeasurementContext_create(ListMeasurementContextHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesMeasurementContext_destroy(AxesMeasurementContextHandle handle);
// @category:write
FALCON_CORE_C_API void AxesMeasurementContext_push_back(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesMeasurementContext_size(AxesMeasurementContextHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesMeasurementContext_empty(AxesMeasurementContextHandle handle);
// @category:write
FALCON_CORE_C_API void AxesMeasurementContext_erase_at(AxesMeasurementContextHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesMeasurementContext_clear(AxesMeasurementContextHandle handle);
// @category:read
FALCON_CORE_C_API MeasurementContextHandle AxesMeasurementContext_at(AxesMeasurementContextHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesMeasurementContext_items(AxesMeasurementContextHandle handle, MeasurementContextHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesMeasurementContext_contains(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesMeasurementContext_index(AxesMeasurementContextHandle handle, MeasurementContextHandle value);
// @category:read
FALCON_CORE_C_API AxesMeasurementContextHandle AxesMeasurementContext_intersection(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);
// @category:read
FALCON_CORE_C_API bool AxesMeasurementContext_equal(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);
// @category:read
FALCON_CORE_C_API bool AxesMeasurementContext_not_equal(AxesMeasurementContextHandle handle, AxesMeasurementContextHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesMeasurementContext_to_json_string(AxesMeasurementContextHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesMeasurementContextHandle AxesMeasurementContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif