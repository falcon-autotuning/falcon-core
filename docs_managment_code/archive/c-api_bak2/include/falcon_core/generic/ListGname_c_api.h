#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGnameHandle;
// Function declarations

// @category:allocation
ListGnameHandle ListGname_create_empty();

// @category:allocation
ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value);
// @category:allocation
ListGnameHandle ListGname_create(GnameHandle* data, size_t count);
// @category:deallocation
void ListGname_destroy(ListGnameHandle handle);
// @category:write
void ListGname_push_back(ListGnameHandle handle, GnameHandle value);
// @category:read
size_t ListGname_size(ListGnameHandle handle);
// @category:read
bool ListGname_empty(ListGnameHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListGname_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListGname_erase_at(ListGnameHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListGname_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListGname_clear(ListGnameHandle handle);
// @category:read
GnameHandle ListGname_at(ListGnameHandle handle, size_t idx);
// @category:read
size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListGname_contains(ListGnameHandle handle, GnameHandle value);
// @category:read
size_t ListGname_index(ListGnameHandle handle, GnameHandle value);
// @category:read
/* AUTO-DOC from cpp: ListGname_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other);
// @category:read
bool ListGname_equal(ListGnameHandle a, ListGnameHandle b);
// @category:read
bool ListGname_not_equal(ListGnameHandle a, ListGnameHandle b);

// @category:read
StringHandle      ListGname_to_json_string(ListGnameHandle handle);
// @category:allocation
ListGnameHandle ListGname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif