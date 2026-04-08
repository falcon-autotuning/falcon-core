#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListIntHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListIntHandle ListInt_create_empty();
// @category:allocation
FALCON_CORE_C_API ListIntHandle ListInt_copy(ListIntHandle handle);
// @category:allocation
FALCON_CORE_C_API ListIntHandle ListInt_allocate(size_t count);
// @category:allocation
FALCON_CORE_C_API ListIntHandle ListInt_fill_value(size_t count, int value);
// @category:allocation
FALCON_CORE_C_API ListIntHandle ListInt_create(int* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListInt_destroy(ListIntHandle handle);
// @category:write
FALCON_CORE_C_API void ListInt_push_back(ListIntHandle handle, int value);
// @category:read
FALCON_CORE_C_API size_t ListInt_size(ListIntHandle handle);
// @category:read
FALCON_CORE_C_API bool ListInt_empty(ListIntHandle handle);
// @category:write
FALCON_CORE_C_API void ListInt_erase_at(ListIntHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListInt_clear(ListIntHandle handle);
// @category:read
FALCON_CORE_C_API int ListInt_at(ListIntHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListInt_contains(ListIntHandle handle, int value);
// @category:read
FALCON_CORE_C_API size_t ListInt_index(ListIntHandle handle, int value);
// @category:read
FALCON_CORE_C_API ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other);
// @category:read
FALCON_CORE_C_API bool ListInt_equal(ListIntHandle handle, ListIntHandle other);
// @category:read
FALCON_CORE_C_API bool ListInt_not_equal(ListIntHandle handle, ListIntHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListInt_to_json_string(ListIntHandle handle);
// @category:allocation
FALCON_CORE_C_API ListIntHandle ListInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif