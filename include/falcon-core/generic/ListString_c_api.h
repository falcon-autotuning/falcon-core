#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListStringHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListStringHandle ListString_create_empty();
// @category:allocation
FALCON_CORE_C_API ListStringHandle ListString_copy(ListStringHandle handle);
// @category:allocation
FALCON_CORE_C_API ListStringHandle ListString_allocate(size_t count);
// @category:allocation
FALCON_CORE_C_API ListStringHandle ListString_fill_value(size_t count, StringHandle value);
// @category:allocation
FALCON_CORE_C_API ListStringHandle ListString_create(StringHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListString_destroy(ListStringHandle handle);
// @category:write
FALCON_CORE_C_API void ListString_push_back(ListStringHandle handle, StringHandle value);
// @category:read
FALCON_CORE_C_API size_t ListString_size(ListStringHandle handle);
// @category:read
FALCON_CORE_C_API bool ListString_empty(ListStringHandle handle);
// @category:write
FALCON_CORE_C_API void ListString_erase_at(ListStringHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListString_clear(ListStringHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle ListString_at(ListStringHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListString_contains(ListStringHandle handle, StringHandle value);
// @category:read
FALCON_CORE_C_API size_t ListString_index(ListStringHandle handle, StringHandle value);
// @category:read
FALCON_CORE_C_API ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other);
// @category:read
FALCON_CORE_C_API bool ListString_equal(ListStringHandle handle, ListStringHandle other);
// @category:read
FALCON_CORE_C_API bool ListString_not_equal(ListStringHandle handle, ListStringHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListString_to_json_string(ListStringHandle handle);
// @category:allocation
FALCON_CORE_C_API ListStringHandle ListString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif