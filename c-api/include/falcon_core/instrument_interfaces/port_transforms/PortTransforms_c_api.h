#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"

typedef void* PortTransformsHandle;

// @category:allocation
PortTransformsHandle PortTransforms_copy(PortTransformsHandle handle);
// @category:deallocation
void PortTransforms_destroy(PortTransformsHandle handle);
// @category:read
bool PortTransforms_equal(PortTransformsHandle handle,
                          PortTransformsHandle other);
// @category:read
bool PortTransforms_not_equal(PortTransformsHandle handle,
                              PortTransformsHandle other);
// @category:read
StringHandle PortTransforms_to_json_string(PortTransformsHandle handle);
// @category:allocation
PortTransformsHandle PortTransforms_from_json_string(StringHandle json);
// @category:allocation
PortTransformsHandle PortTransforms_create_empty();
// @category:allocation
PortTransformHandle PortTransforms_create(ListPortTransformHandle handle);
// @category:read
ListPortTransformHandle PortTransforms_transforms(PortTransformsHandle handle);
// @category:write
void PortTransforms_push_back(PortTransformsHandle handle,
                              PortTransformHandle  value);
// @category:read
size_t PortTransforms_size(PortTransformsHandle handle);
// @category:read
bool PortTransforms_empty(PortTransformsHandle handle);
// @category:write
void PortTransforms_erase_at(PortTransformsHandle handle, size_t idx);
// @category:write
void PortTransforms_clear(PortTransformsHandle handle);
// @category:read
PortTransformHandle PortTransforms_at(PortTransformsHandle handle, size_t idx);
// @category:read
ListPortTransformHandle PortTransforms_items(PortTransformsHandle handle);
// @category:read
bool PortTransforms_contains(PortTransformsHandle handle,
                             PortTransformHandle  value);
// @category:read
size_t PortTransforms_index(PortTransformsHandle handle,
                            PortTransformHandle  value);
// @category:read
PortTransformsHandle PortTransforms_intersection(PortTransformsHandle handle,
                                                 PortTransformsHandle other);

#ifdef __cplusplus
}
#endif
