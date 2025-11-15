#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"

typedef void* PortTransformsHandle;

// Constructors
PortTransformsHandle PortTransforms_create_empty();
PortTransformsHandle PortTransforms_create_raw(PortTransformHandle* data,
                                               size_t               count);
PortTransformHandle  PortTransforms_create(ListPortTransformHandle handle);

// Destructor
void PortTransforms_destroy(PortTransformsHandle handle);

// Methods
ListPortTransformHandle PortTransforms_transforms(PortTransformHandle handle);
void                    PortTransforms_push_back(PortTransformsHandle handle,
                                                 PortTransformHandle  value);
size_t                  PortTransforms_size(PortTransformsHandle handle);
bool                    PortTransforms_empty(PortTransformsHandle handle);
void PortTransforms_erase_at(PortTransformsHandle handle, size_t idx);
void PortTransforms_clear(PortTransformsHandle handle);
PortTransformHandle PortTransforms_at(PortTransformsHandle handle, size_t idx);
ListPortTransformHandle PortTransforms_items(PortTransformsHandle handle);
bool                    PortTransforms_contains(PortTransformsHandle handle,
                                                PortTransformHandle  value);
size_t                  PortTransforms_index(PortTransformsHandle handle,
                                             PortTransformHandle  value);
PortTransformsHandle    PortTransforms_intersection(PortTransformsHandle handle,
                                                    PortTransformsHandle other);
bool PortTransforms_equal(PortTransformsHandle a, PortTransformsHandle b);
bool PortTransforms_not_equal(PortTransformsHandle a, PortTransformsHandle b);

// Serialization (from Song)
StringHandle         PortTransforms_to_json_string(PortTransformsHandle handle);
PortTransformsHandle PortTransforms_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
