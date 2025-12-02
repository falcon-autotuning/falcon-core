#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListStringHandle;
// Function declarations

// @category:allocation
ListStringHandle ListString_create_empty();
// @category:allocation
ListStringHandle ListString_allocate(size_t count);
// @category:allocation
ListStringHandle ListString_fill_value(size_t count, StringHandle value);
// @category:allocation
ListStringHandle ListString_create(StringHandle* data, size_t count);
// @category:deallocation
void ListString_destroy(ListStringHandle handle);
// @category:write
void ListString_push_back(ListStringHandle handle, StringHandle value);
// @category:read
size_t ListString_size(ListStringHandle handle);
// @category:read
bool ListString_empty(ListStringHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListString_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListString_erase_at(ListStringHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListString_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListString_clear(ListStringHandle handle);
// @category:read
StringHandle ListString_at(ListStringHandle handle, size_t idx);
// @category:read
size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListString_contains(ListStringHandle handle, StringHandle value);
// @category:read
size_t ListString_index(ListStringHandle handle, StringHandle value);
// @category:read
/* AUTO-DOC from cpp: ListString_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other);
// @category:read
bool ListString_equal(ListStringHandle a, ListStringHandle b);
// @category:read
bool ListString_not_equal(ListStringHandle a, ListStringHandle b);

// @category:read
StringHandle      ListString_to_json_string(ListStringHandle handle);
// @category:allocation
ListStringHandle ListString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif