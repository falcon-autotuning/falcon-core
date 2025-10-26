#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include <cstddef>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPortTransformHandle;
// Function declarations

ListPortTransformHandle ListPortTransform_create_empty();
ListPortTransformHandle ListPortTransform_allocate(size_t count);
ListPortTransformHandle ListPortTransform_fill_value(size_t count, PortTransformHandle value);
ListPortTransformHandle ListPortTransform_create(PortTransformHandle* data, size_t count);
void ListPortTransform_destroy(ListPortTransformHandle handle);
void ListPortTransform_push_back(ListPortTransformHandle handle, PortTransformHandle value);
size_t ListPortTransform_size(ListPortTransformHandle handle);
bool ListPortTransform_empty(ListPortTransformHandle handle);
void ListPortTransform_erase_at(ListPortTransformHandle handle, size_t idx);
void ListPortTransform_clear(ListPortTransformHandle handle);
PortTransformHandle ListPortTransform_at(ListPortTransformHandle handle, size_t idx);
size_t ListPortTransform_items(ListPortTransformHandle handle, PortTransformHandle* out_buffer, size_t buffer_size);
bool ListPortTransform_contains(ListPortTransformHandle handle, PortTransformHandle value);
size_t ListPortTransform_index(ListPortTransformHandle handle, PortTransformHandle value);
ListPortTransformHandle ListPortTransform_intersection(ListPortTransformHandle handle, ListPortTransformHandle other);
bool ListPortTransform_equal(ListPortTransformHandle a, ListPortTransformHandle b);
bool ListPortTransform_not_equal(ListPortTransformHandle a, ListPortTransformHandle b);

// Serialization (from Song)
StringHandle      ListPortTransform_to_json_string(ListPortTransformHandle handle);
ListPortTransformHandle ListPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif