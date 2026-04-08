#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/ListDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesDoubleHandle AxesDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesDoubleHandle AxesDouble_copy(AxesDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesDoubleHandle AxesDouble_create(ListDoubleHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesDouble_destroy(AxesDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void AxesDouble_push_back(AxesDoubleHandle handle, double value);
// @category:read
FALCON_CORE_C_API size_t AxesDouble_size(AxesDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesDouble_empty(AxesDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void AxesDouble_erase_at(AxesDoubleHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesDouble_clear(AxesDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double AxesDouble_at(AxesDoubleHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesDouble_items(AxesDoubleHandle handle, double* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesDouble_contains(AxesDoubleHandle handle, double value);
// @category:read
FALCON_CORE_C_API size_t AxesDouble_index(AxesDoubleHandle handle, double value);
// @category:read
FALCON_CORE_C_API AxesDoubleHandle AxesDouble_intersection(AxesDoubleHandle handle, AxesDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool AxesDouble_equal(AxesDoubleHandle handle, AxesDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool AxesDouble_not_equal(AxesDoubleHandle handle, AxesDoubleHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesDouble_to_json_string(AxesDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesDoubleHandle AxesDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif