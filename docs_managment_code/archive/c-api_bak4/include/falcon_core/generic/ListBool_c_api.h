#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListBoolHandle;
// Function declarations

// @category:allocation
ListBoolHandle ListBool_create_empty();
// @category:allocation
ListBoolHandle ListBool_allocate(size_t count);
// @category:allocation
ListBoolHandle ListBool_fill_value(size_t count, bool value);
// @category:allocation
ListBoolHandle ListBool_create(bool* data, size_t count);
// @category:deallocation
void ListBool_destroy(ListBoolHandle handle);
// @category:write
void ListBool_push_back(ListBoolHandle handle, bool value);
// @category:read
size_t ListBool_size(ListBoolHandle handle);
// @category:read
bool ListBool_empty(ListBoolHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListBool_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListBool_erase_at(ListBoolHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListBool_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListBool_clear(ListBoolHandle handle);
// @category:read
bool ListBool_at(ListBoolHandle handle, size_t idx);
// @category:read
size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size);
// @category:read
bool ListBool_contains(ListBoolHandle handle, bool value);
// @category:read
size_t ListBool_index(ListBoolHandle handle, bool value);
// @category:read
/* AUTO-DOC from cpp: ListBool_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other);
// @category:read
bool ListBool_equal(ListBoolHandle a, ListBoolHandle b);
// @category:read
bool ListBool_not_equal(ListBoolHandle a, ListBoolHandle b);

// @category:read
StringHandle      ListBool_to_json_string(ListBoolHandle handle);
// @category:allocation
ListBoolHandle ListBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif