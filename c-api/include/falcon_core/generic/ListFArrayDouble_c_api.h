#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFArrayDoubleHandle;
// Function declarations

// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_create_empty();

// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_fill_value(size_t count, FArrayDoubleHandle value);
// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_create(FArrayDoubleHandle* data, size_t count);
// @category:deallocation
void ListFArrayDouble_destroy(ListFArrayDoubleHandle handle);
// @category:write
void ListFArrayDouble_push_back(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
size_t ListFArrayDouble_size(ListFArrayDoubleHandle handle);
// @category:read
bool ListFArrayDouble_empty(ListFArrayDoubleHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListFArrayDouble_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListFArrayDouble_erase_at(ListFArrayDoubleHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListFArrayDouble_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListFArrayDouble_clear(ListFArrayDoubleHandle handle);
// @category:read
FArrayDoubleHandle ListFArrayDouble_at(ListFArrayDoubleHandle handle, size_t idx);
// @category:read
size_t ListFArrayDouble_items(ListFArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListFArrayDouble_contains(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
size_t ListFArrayDouble_index(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
/* AUTO-DOC from cpp: ListFArrayDouble_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListFArrayDoubleHandle ListFArrayDouble_intersection(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);
// @category:read
bool ListFArrayDouble_equal(ListFArrayDoubleHandle a, ListFArrayDoubleHandle b);
// @category:read
bool ListFArrayDouble_not_equal(ListFArrayDoubleHandle a, ListFArrayDoubleHandle b);

// @category:read
StringHandle      ListFArrayDouble_to_json_string(ListFArrayDoubleHandle handle);
// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif