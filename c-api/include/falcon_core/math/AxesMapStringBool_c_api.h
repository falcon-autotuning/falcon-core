#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListMapStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesMapStringBoolHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API AxesMapStringBoolHandle AxesMapStringBool_create_empty();
// @category:allocation
FALCON_CORE_C_API AxesMapStringBoolHandle AxesMapStringBool_copy(AxesMapStringBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesMapStringBoolHandle AxesMapStringBool_create(ListMapStringBoolHandle data);
// @category:deallocation
FALCON_CORE_C_API void AxesMapStringBool_destroy(AxesMapStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void AxesMapStringBool_push_back(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesMapStringBool_size(AxesMapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool AxesMapStringBool_empty(AxesMapStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void AxesMapStringBool_erase_at(AxesMapStringBoolHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void AxesMapStringBool_clear(AxesMapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API MapStringBoolHandle AxesMapStringBool_at(AxesMapStringBoolHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t AxesMapStringBool_items(AxesMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool AxesMapStringBool_contains(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
FALCON_CORE_C_API size_t AxesMapStringBool_index(AxesMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
FALCON_CORE_C_API AxesMapStringBoolHandle AxesMapStringBool_intersection(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool AxesMapStringBool_equal(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool AxesMapStringBool_not_equal(AxesMapStringBoolHandle handle, AxesMapStringBoolHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      AxesMapStringBool_to_json_string(AxesMapStringBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API AxesMapStringBoolHandle AxesMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif