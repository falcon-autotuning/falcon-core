#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListListSizeTHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListListSizeTHandle ListListSizeT_create_empty();
// @category:allocation
FALCON_CORE_C_API ListListSizeTHandle ListListSizeT_copy(ListListSizeTHandle handle);

// @category:allocation
FALCON_CORE_C_API ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value);
// @category:allocation
FALCON_CORE_C_API ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListListSizeT_destroy(ListListSizeTHandle handle);
// @category:write
FALCON_CORE_C_API void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
FALCON_CORE_C_API size_t ListListSizeT_size(ListListSizeTHandle handle);
// @category:read
FALCON_CORE_C_API bool ListListSizeT_empty(ListListSizeTHandle handle);
// @category:write
FALCON_CORE_C_API void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListListSizeT_clear(ListListSizeTHandle handle);
// @category:read
FALCON_CORE_C_API ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
FALCON_CORE_C_API size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
FALCON_CORE_C_API ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool ListListSizeT_equal(ListListSizeTHandle handle, ListListSizeTHandle other);
// @category:read
FALCON_CORE_C_API bool ListListSizeT_not_equal(ListListSizeTHandle handle, ListListSizeTHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle);
// @category:allocation
FALCON_CORE_C_API ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif