#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/generic/ListPortTransform_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform_c_api.h"

typedef void* PortTransformsHandle;

// @category:allocation
FALCON_CORE_C_API PortTransformsHandle
PortTransforms_copy(PortTransformsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PortTransforms_destroy(PortTransformsHandle handle);
// @category:read
FALCON_CORE_C_API bool PortTransforms_equal(PortTransformsHandle handle,
                                            PortTransformsHandle other);
// @category:read
FALCON_CORE_C_API bool PortTransforms_not_equal(PortTransformsHandle handle,
                                                PortTransformsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
PortTransforms_to_json_string(PortTransformsHandle handle);
// @category:allocation
FALCON_CORE_C_API PortTransformsHandle
PortTransforms_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API PortTransformsHandle PortTransforms_create_empty();
// @category:allocation
FALCON_CORE_C_API PortTransformHandle
PortTransforms_create(ListPortTransformHandle handle);
// @category:read
FALCON_CORE_C_API ListPortTransformHandle
PortTransforms_transforms(PortTransformsHandle handle);
// @category:write
FALCON_CORE_C_API void PortTransforms_push_back(PortTransformsHandle handle,
                                                PortTransformHandle  value);
// @category:read
FALCON_CORE_C_API size_t PortTransforms_size(PortTransformsHandle handle);
// @category:read
FALCON_CORE_C_API bool PortTransforms_empty(PortTransformsHandle handle);
// @category:write
FALCON_CORE_C_API void PortTransforms_erase_at(PortTransformsHandle handle,
                                               size_t               idx);
// @category:write
FALCON_CORE_C_API void PortTransforms_clear(PortTransformsHandle handle);
// @category:read
FALCON_CORE_C_API PortTransformHandle
PortTransforms_at(PortTransformsHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API ListPortTransformHandle
PortTransforms_items(PortTransformsHandle handle);
// @category:read
FALCON_CORE_C_API bool PortTransforms_contains(PortTransformsHandle handle,
                                               PortTransformHandle  value);
// @category:read
FALCON_CORE_C_API size_t PortTransforms_index(PortTransformsHandle handle,
                                              PortTransformHandle  value);
// @category:read
FALCON_CORE_C_API PortTransformsHandle PortTransforms_intersection(
    PortTransformsHandle handle, PortTransformsHandle other);

#ifdef __cplusplus
}
#endif
