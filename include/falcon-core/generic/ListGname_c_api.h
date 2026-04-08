#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/autotuner_interfaces/names/Gname_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGnameHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListGnameHandle ListGname_create_empty();
// @category:allocation
FALCON_CORE_C_API ListGnameHandle ListGname_copy(ListGnameHandle handle);

// @category:allocation
FALCON_CORE_C_API ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value);
// @category:allocation
FALCON_CORE_C_API ListGnameHandle ListGname_create(GnameHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListGname_destroy(ListGnameHandle handle);
// @category:write
FALCON_CORE_C_API void ListGname_push_back(ListGnameHandle handle, GnameHandle value);
// @category:read
FALCON_CORE_C_API size_t ListGname_size(ListGnameHandle handle);
// @category:read
FALCON_CORE_C_API bool ListGname_empty(ListGnameHandle handle);
// @category:write
FALCON_CORE_C_API void ListGname_erase_at(ListGnameHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListGname_clear(ListGnameHandle handle);
// @category:read
FALCON_CORE_C_API GnameHandle ListGname_at(ListGnameHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListGname_contains(ListGnameHandle handle, GnameHandle value);
// @category:read
FALCON_CORE_C_API size_t ListGname_index(ListGnameHandle handle, GnameHandle value);
// @category:read
FALCON_CORE_C_API ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other);
// @category:read
FALCON_CORE_C_API bool ListGname_equal(ListGnameHandle handle, ListGnameHandle other);
// @category:read
FALCON_CORE_C_API bool ListGname_not_equal(ListGnameHandle handle, ListGnameHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListGname_to_json_string(ListGnameHandle handle);
// @category:allocation
FALCON_CORE_C_API ListGnameHandle ListGname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif