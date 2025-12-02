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
ListPortTransformHandle ListPortTransform_create_empty();

// @category:allocation
ListPortTransformHandle ListPortTransform_fill_value(size_t count, PortTransformHandle value);
// @category:allocation
ListPortTransformHandle ListPortTransform_create(PortTransformHandle* data, size_t count);
// @category:deallocation
void ListPortTransform_destroy(ListPortTransformHandle handle);
// @category:write
void ListPortTransform_push_back(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
size_t ListPortTransform_size(ListPortTransformHandle handle);
// @category:read
bool ListPortTransform_empty(ListPortTransformHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListPortTransform_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPortTransform_erase_at(ListPortTransformHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListPortTransform_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListPortTransform_clear(ListPortTransformHandle handle);
// @category:read
PortTransformHandle ListPortTransform_at(ListPortTransformHandle handle, size_t idx);
// @category:read
size_t ListPortTransform_items(ListPortTransformHandle handle, PortTransformHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPortTransform_contains(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
size_t ListPortTransform_index(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
/* AUTO-DOC from cpp: ListPortTransform_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPortTransformHandle ListPortTransform_intersection(ListPortTransformHandle handle, ListPortTransformHandle other);
// @category:read
bool ListPortTransform_equal(ListPortTransformHandle a, ListPortTransformHandle b);
// @category:read
bool ListPortTransform_not_equal(ListPortTransformHandle a, ListPortTransformHandle b);

// @category:read
StringHandle      ListPortTransform_to_json_string(ListPortTransformHandle handle);
// @category:allocation
ListPortTransformHandle ListPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif