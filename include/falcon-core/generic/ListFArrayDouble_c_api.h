#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/FArrayDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFArrayDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListFArrayDoubleHandle ListFArrayDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API ListFArrayDoubleHandle ListFArrayDouble_copy(ListFArrayDoubleHandle handle);

// @category:allocation
FALCON_CORE_C_API ListFArrayDoubleHandle ListFArrayDouble_fill_value(size_t count, FArrayDoubleHandle value);
// @category:allocation
FALCON_CORE_C_API ListFArrayDoubleHandle ListFArrayDouble_create(FArrayDoubleHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListFArrayDouble_destroy(ListFArrayDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void ListFArrayDouble_push_back(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
FALCON_CORE_C_API size_t ListFArrayDouble_size(ListFArrayDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool ListFArrayDouble_empty(ListFArrayDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void ListFArrayDouble_erase_at(ListFArrayDoubleHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListFArrayDouble_clear(ListFArrayDoubleHandle handle);
// @category:read
FALCON_CORE_C_API FArrayDoubleHandle ListFArrayDouble_at(ListFArrayDoubleHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListFArrayDouble_items(ListFArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListFArrayDouble_contains(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
FALCON_CORE_C_API size_t ListFArrayDouble_index(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
FALCON_CORE_C_API ListFArrayDoubleHandle ListFArrayDouble_intersection(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool ListFArrayDouble_equal(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool ListFArrayDouble_not_equal(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListFArrayDouble_to_json_string(ListFArrayDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API ListFArrayDoubleHandle ListFArrayDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif