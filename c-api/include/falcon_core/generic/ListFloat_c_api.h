#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFloatHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListFloatHandle ListFloat_create_empty();
// @category:allocation
FALCON_CORE_C_API ListFloatHandle ListFloat_copy(ListFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API ListFloatHandle ListFloat_allocate(size_t count);
// @category:allocation
FALCON_CORE_C_API ListFloatHandle ListFloat_fill_value(size_t count, float value);
// @category:allocation
FALCON_CORE_C_API ListFloatHandle ListFloat_create(float* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListFloat_destroy(ListFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListFloat_push_back(ListFloatHandle handle, float value);
// @category:read
FALCON_CORE_C_API size_t ListFloat_size(ListFloatHandle handle);
// @category:read
FALCON_CORE_C_API bool ListFloat_empty(ListFloatHandle handle);
// @category:write
FALCON_CORE_C_API void ListFloat_erase_at(ListFloatHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListFloat_clear(ListFloatHandle handle);
// @category:read
FALCON_CORE_C_API float ListFloat_at(ListFloatHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListFloat_contains(ListFloatHandle handle, float value);
// @category:read
FALCON_CORE_C_API size_t ListFloat_index(ListFloatHandle handle, float value);
// @category:read
FALCON_CORE_C_API ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListFloat_equal(ListFloatHandle handle, ListFloatHandle other);
// @category:read
FALCON_CORE_C_API bool ListFloat_not_equal(ListFloatHandle handle, ListFloatHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListFloat_to_json_string(ListFloatHandle handle);
// @category:allocation
FALCON_CORE_C_API ListFloatHandle ListFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif