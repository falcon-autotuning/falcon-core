#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPortTransformHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API ListPortTransformHandle ListPortTransform_create_empty();
// @category:allocation
FALCON_CORE_C_API ListPortTransformHandle ListPortTransform_copy(ListPortTransformHandle handle);

// @category:allocation
FALCON_CORE_C_API ListPortTransformHandle ListPortTransform_fill_value(size_t count, PortTransformHandle value);
// @category:allocation
FALCON_CORE_C_API ListPortTransformHandle ListPortTransform_create(PortTransformHandle* data, size_t count);
// @category:deallocation
FALCON_CORE_C_API void ListPortTransform_destroy(ListPortTransformHandle handle);
// @category:write
FALCON_CORE_C_API void ListPortTransform_push_back(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPortTransform_size(ListPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API bool ListPortTransform_empty(ListPortTransformHandle handle);
// @category:write
FALCON_CORE_C_API void ListPortTransform_erase_at(ListPortTransformHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void ListPortTransform_clear(ListPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API PortTransformHandle ListPortTransform_at(ListPortTransformHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API size_t ListPortTransform_items(ListPortTransformHandle handle, PortTransformHandle* out_buffer, size_t buffer_size);
// @category:read
FALCON_CORE_C_API bool ListPortTransform_contains(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
FALCON_CORE_C_API size_t ListPortTransform_index(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
FALCON_CORE_C_API ListPortTransformHandle ListPortTransform_intersection(ListPortTransformHandle handle, ListPortTransformHandle other);
// @category:read
FALCON_CORE_C_API bool ListPortTransform_equal(ListPortTransformHandle handle, ListPortTransformHandle other);
// @category:read
FALCON_CORE_C_API bool ListPortTransform_not_equal(ListPortTransformHandle handle, ListPortTransformHandle other);

// @category:read
FALCON_CORE_C_API StringHandle      ListPortTransform_to_json_string(ListPortTransformHandle handle);
// @category:allocation
FALCON_CORE_C_API ListPortTransformHandle ListPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif