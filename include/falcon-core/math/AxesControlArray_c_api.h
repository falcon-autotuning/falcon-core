#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/math/arrays/ControlArray_c_api.h"
#include "falcon-core/generic/ListControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesControlArrayHandle AxesControlArray_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesControlArrayHandle AxesControlArray_copy(AxesControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesControlArrayHandle AxesControlArray_create(ListControlArrayHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesControlArray_destroy(AxesControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void AxesControlArray_push_back(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesControlArray_size(AxesControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesControlArray_empty(AxesControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void AxesControlArray_erase_at(AxesControlArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesControlArray_clear(AxesControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API ControlArrayHandle AxesControlArray_at(AxesControlArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesControlArray_items(AxesControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesControlArray_contains(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesControlArray_index(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
FALCON_CORE_C_API AxesControlArrayHandle AxesControlArray_intersection(AxesControlArrayHandle handle, AxesControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool AxesControlArray_equal(AxesControlArrayHandle handle, AxesControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool AxesControlArray_not_equal(AxesControlArrayHandle handle, AxesControlArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesControlArray_to_json_string(AxesControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesControlArrayHandle AxesControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif