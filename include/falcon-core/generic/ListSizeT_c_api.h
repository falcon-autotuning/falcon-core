#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListSizeTHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListSizeTHandle ListSizeT_create_empty();
// @category:allocation
FALCON_CORE_C_API ListSizeTHandle ListSizeT_copy(ListSizeTHandle handle);
// @category:allocation
FALCON_CORE_C_API ListSizeTHandle ListSizeT_allocate(size_t count);
// @category:allocation
FALCON_CORE_C_API ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value);
// @category:allocation
FALCON_CORE_C_API ListSizeTHandle ListSizeT_create(size_t* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListSizeT_destroy(ListSizeTHandle handle);
// @category:write
FALCON_CORE_C_API void ListSizeT_push_back(ListSizeTHandle handle, size_t value);
// @category:read
FALCON_CORE_C_API size_t ListSizeT_size(ListSizeTHandle handle);
// @category:read
FALCON_CORE_C_API bool ListSizeT_empty(ListSizeTHandle handle);
// @category:write
FALCON_CORE_C_API void ListSizeT_erase_at(ListSizeTHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListSizeT_clear(ListSizeTHandle handle);
// @category:read
FALCON_CORE_C_API size_t ListSizeT_at(ListSizeTHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListSizeT_contains(ListSizeTHandle handle, size_t value);
// @category:read
FALCON_CORE_C_API size_t ListSizeT_index(ListSizeTHandle handle, size_t value);
// @category:read
FALCON_CORE_C_API ListSizeTHandle ListSizeT_intersection(ListSizeTHandle handle, ListSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool ListSizeT_equal(ListSizeTHandle handle, ListSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool ListSizeT_not_equal(ListSizeTHandle handle, ListSizeTHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListSizeT_to_json_string(ListSizeTHandle handle);
// @category:allocation
FALCON_CORE_C_API ListSizeTHandle ListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif