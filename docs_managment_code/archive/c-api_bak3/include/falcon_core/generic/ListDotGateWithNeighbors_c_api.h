#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/config/geometries/DotGateWithNeighbors_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDotGateWithNeighborsHandle;
// Function declarations

// @category:allocation
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create_empty();

// @category:allocation
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_fill_value(size_t count, DotGateWithNeighborsHandle value);
// @category:allocation
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_create(DotGateWithNeighborsHandle* data, size_t count);
// @category:deallocation
void ListDotGateWithNeighbors_destroy(ListDotGateWithNeighborsHandle handle);
// @category:write
void ListDotGateWithNeighbors_push_back(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value);
// @category:read
size_t ListDotGateWithNeighbors_size(ListDotGateWithNeighborsHandle handle);
// @category:read
bool ListDotGateWithNeighbors_empty(ListDotGateWithNeighborsHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListDotGateWithNeighbors_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListDotGateWithNeighbors_erase_at(ListDotGateWithNeighborsHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListDotGateWithNeighbors_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListDotGateWithNeighbors_clear(ListDotGateWithNeighborsHandle handle);
// @category:read
DotGateWithNeighborsHandle ListDotGateWithNeighbors_at(ListDotGateWithNeighborsHandle handle, size_t idx);
// @category:read
size_t ListDotGateWithNeighbors_items(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListDotGateWithNeighbors_contains(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value);
// @category:read
size_t ListDotGateWithNeighbors_index(ListDotGateWithNeighborsHandle handle, DotGateWithNeighborsHandle value);
// @category:read
/* AUTO-DOC from cpp: ListDotGateWithNeighbors_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_intersection(ListDotGateWithNeighborsHandle handle, ListDotGateWithNeighborsHandle other);
// @category:read
bool ListDotGateWithNeighbors_equal(ListDotGateWithNeighborsHandle a, ListDotGateWithNeighborsHandle b);
// @category:read
bool ListDotGateWithNeighbors_not_equal(ListDotGateWithNeighborsHandle a, ListDotGateWithNeighborsHandle b);

// @category:read
StringHandle      ListDotGateWithNeighbors_to_json_string(ListDotGateWithNeighborsHandle handle);
// @category:allocation
ListDotGateWithNeighborsHandle ListDotGateWithNeighbors_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif