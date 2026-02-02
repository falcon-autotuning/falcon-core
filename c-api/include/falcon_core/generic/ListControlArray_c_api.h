#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListControlArrayHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListControlArrayHandle ListControlArray_create_empty();
// @category:allocation
FALCON_CORE_C_API ListControlArrayHandle ListControlArray_copy(ListControlArrayHandle handle);

// @category:allocation
FALCON_CORE_C_API ListControlArrayHandle ListControlArray_fill_value(size_t count, ControlArrayHandle value);
// @category:allocation
FALCON_CORE_C_API ListControlArrayHandle ListControlArray_create(ControlArrayHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListControlArray_destroy(ListControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ListControlArray_push_back(ListControlArrayHandle handle, ControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t ListControlArray_size(ListControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API bool ListControlArray_empty(ListControlArrayHandle handle);
// @category:write
FALCON_CORE_C_API void ListControlArray_erase_at(ListControlArrayHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListControlArray_clear(ListControlArrayHandle handle);
// @category:read
FALCON_CORE_C_API ControlArrayHandle ListControlArray_at(ListControlArrayHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListControlArray_items(ListControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListControlArray_contains(ListControlArrayHandle handle, ControlArrayHandle value);
// @category:read
FALCON_CORE_C_API size_t ListControlArray_index(ListControlArrayHandle handle, ControlArrayHandle value);
// @category:read
FALCON_CORE_C_API ListControlArrayHandle ListControlArray_intersection(ListControlArrayHandle handle, ListControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ListControlArray_equal(ListControlArrayHandle handle, ListControlArrayHandle other);
// @category:read
FALCON_CORE_C_API bool ListControlArray_not_equal(ListControlArrayHandle handle, ListControlArrayHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListControlArray_to_json_string(ListControlArrayHandle handle);
// @category:allocation
FALCON_CORE_C_API ListControlArrayHandle ListControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif