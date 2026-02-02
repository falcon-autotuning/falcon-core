#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListBoolHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListBoolHandle ListBool_create_empty();
// @category:allocation
FALCON_CORE_C_API ListBoolHandle ListBool_copy(ListBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API ListBoolHandle ListBool_allocate(size_t count);
// @category:allocation
FALCON_CORE_C_API ListBoolHandle ListBool_fill_value(size_t count, bool value);
// @category:allocation
FALCON_CORE_C_API ListBoolHandle ListBool_create(bool* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListBool_destroy(ListBoolHandle handle);
// @category:write
FALCON_CORE_C_API void ListBool_push_back(ListBoolHandle handle, bool value);
// @category:read
FALCON_CORE_C_API size_t ListBool_size(ListBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool ListBool_empty(ListBoolHandle handle);
// @category:write
FALCON_CORE_C_API void ListBool_erase_at(ListBoolHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListBool_clear(ListBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool ListBool_at(ListBoolHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListBool_contains(ListBoolHandle handle, bool value);
// @category:read
FALCON_CORE_C_API size_t ListBool_index(ListBoolHandle handle, bool value);
// @category:read
FALCON_CORE_C_API ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other);
// @category:read
FALCON_CORE_C_API bool ListBool_equal(ListBoolHandle handle, ListBoolHandle other);
// @category:read
FALCON_CORE_C_API bool ListBool_not_equal(ListBoolHandle handle, ListBoolHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListBool_to_json_string(ListBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API ListBoolHandle ListBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif