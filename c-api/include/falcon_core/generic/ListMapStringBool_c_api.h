#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/MapStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMapStringBoolHandle;
// Function declarations

// @category:allocation
ListMapStringBoolHandle ListMapStringBool_create_empty();

// @category:allocation
ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value);
// @category:allocation
ListMapStringBoolHandle ListMapStringBool_create(MapStringBoolHandle* data, size_t count);
// @category:deallocation
void ListMapStringBool_destroy(ListMapStringBoolHandle handle);
// @category:write
void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
size_t ListMapStringBool_size(ListMapStringBoolHandle handle);
// @category:read
bool ListMapStringBool_empty(ListMapStringBoolHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListMapStringBool_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListMapStringBool_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListMapStringBool_clear(ListMapStringBoolHandle handle);
// @category:read
MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx);
// @category:read
size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
/* AUTO-DOC from cpp: ListMapStringBool_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);
// @category:read
bool ListMapStringBool_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b);
// @category:read
bool ListMapStringBool_not_equal(ListMapStringBoolHandle a, ListMapStringBoolHandle b);

// @category:read
StringHandle      ListMapStringBool_to_json_string(ListMapStringBoolHandle handle);
// @category:allocation
ListMapStringBoolHandle ListMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif