#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListInt_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesIntHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesIntHandle AxesInt_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesIntHandle AxesInt_copy(AxesIntHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesIntHandle AxesInt_create(ListIntHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesInt_destroy(AxesIntHandle handle);
// @category:write
FALCON_CORE_C_API void AxesInt_push_back(AxesIntHandle handle, int value);
// @category:read
FALCON_CORE_C_API size_t AxesInt_size(AxesIntHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesInt_empty(AxesIntHandle handle);
// @category:write
FALCON_CORE_C_API void AxesInt_erase_at(AxesIntHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesInt_clear(AxesIntHandle handle);
// @category:read
FALCON_CORE_C_API int AxesInt_at(AxesIntHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesInt_items(AxesIntHandle handle, int* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesInt_contains(AxesIntHandle handle, int value);
// @category:read
FALCON_CORE_C_API size_t AxesInt_index(AxesIntHandle handle, int value);
// @category:read
FALCON_CORE_C_API AxesIntHandle AxesInt_intersection(AxesIntHandle handle, AxesIntHandle other);
// @category:read
FALCON_CORE_C_API bool AxesInt_equal(AxesIntHandle handle, AxesIntHandle other);
// @category:read
FALCON_CORE_C_API bool AxesInt_not_equal(AxesIntHandle handle, AxesIntHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesInt_to_json_string(AxesIntHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesIntHandle AxesInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif