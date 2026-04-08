#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/generic/MapStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMapStringBoolHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListMapStringBoolHandle ListMapStringBool_create_empty();
// @category:allocation
FALCON_CORE_C_API ListMapStringBoolHandle ListMapStringBool_copy(ListMapStringBoolHandle handle);

// @category:allocation
FALCON_CORE_C_API ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value);
// @category:allocation
FALCON_CORE_C_API ListMapStringBoolHandle ListMapStringBool_create(MapStringBoolHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListMapStringBool_destroy(ListMapStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
FALCON_CORE_C_API size_t ListMapStringBool_size(ListMapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API bool ListMapStringBool_empty(ListMapStringBoolHandle handle);
// @category:write
FALCON_CORE_C_API void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListMapStringBool_clear(ListMapStringBoolHandle handle);
// @category:read
FALCON_CORE_C_API MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
FALCON_CORE_C_API size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
FALCON_CORE_C_API ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool ListMapStringBool_equal(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);
// @category:read
FALCON_CORE_C_API bool ListMapStringBool_not_equal(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListMapStringBool_to_json_string(ListMapStringBoolHandle handle);
// @category:allocation
FALCON_CORE_C_API ListMapStringBoolHandle ListMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif