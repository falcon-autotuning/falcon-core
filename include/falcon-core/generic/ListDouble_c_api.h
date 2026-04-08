#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDoubleHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListDoubleHandle ListDouble_create_empty();
// @category:allocation
FALCON_CORE_C_API ListDoubleHandle ListDouble_copy(ListDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API ListDoubleHandle ListDouble_allocate(size_t count);
// @category:allocation
FALCON_CORE_C_API ListDoubleHandle ListDouble_fill_value(size_t count, double value);
// @category:allocation
FALCON_CORE_C_API ListDoubleHandle ListDouble_create(double* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListDouble_destroy(ListDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void ListDouble_push_back(ListDoubleHandle handle, double value);
// @category:read
FALCON_CORE_C_API size_t ListDouble_size(ListDoubleHandle handle);
// @category:read
FALCON_CORE_C_API bool ListDouble_empty(ListDoubleHandle handle);
// @category:write
FALCON_CORE_C_API void ListDouble_erase_at(ListDoubleHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListDouble_clear(ListDoubleHandle handle);
// @category:read
FALCON_CORE_C_API double ListDouble_at(ListDoubleHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListDouble_contains(ListDoubleHandle handle, double value);
// @category:read
FALCON_CORE_C_API size_t ListDouble_index(ListDoubleHandle handle, double value);
// @category:read
FALCON_CORE_C_API ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool ListDouble_equal(ListDoubleHandle handle, ListDoubleHandle other);
// @category:read
FALCON_CORE_C_API bool ListDouble_not_equal(ListDoubleHandle handle, ListDoubleHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListDouble_to_json_string(ListDoubleHandle handle);
// @category:allocation
FALCON_CORE_C_API ListDoubleHandle ListDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif