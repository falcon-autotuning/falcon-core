#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledControlArrayHandle;
// Function declarations

// @category:allocation
ListLabelledControlArrayHandle ListLabelledControlArray_create_empty();

// @category:allocation
ListLabelledControlArrayHandle ListLabelledControlArray_fill_value(size_t count, LabelledControlArrayHandle value);
// @category:allocation
ListLabelledControlArrayHandle ListLabelledControlArray_create(LabelledControlArrayHandle* data, size_t count);
// @category:deallocation
void ListLabelledControlArray_destroy(ListLabelledControlArrayHandle handle);
// @category:write
void ListLabelledControlArray_push_back(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
size_t ListLabelledControlArray_size(ListLabelledControlArrayHandle handle);
// @category:read
bool ListLabelledControlArray_empty(ListLabelledControlArrayHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListLabelledControlArray_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListLabelledControlArray_erase_at(ListLabelledControlArrayHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListLabelledControlArray_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListLabelledControlArray_clear(ListLabelledControlArrayHandle handle);
// @category:read
LabelledControlArrayHandle ListLabelledControlArray_at(ListLabelledControlArrayHandle handle, size_t idx);
// @category:read
size_t ListLabelledControlArray_items(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListLabelledControlArray_contains(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
size_t ListLabelledControlArray_index(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
/* AUTO-DOC from cpp: ListLabelledControlArray_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListLabelledControlArrayHandle ListLabelledControlArray_intersection(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other);
// @category:read
bool ListLabelledControlArray_equal(ListLabelledControlArrayHandle a, ListLabelledControlArrayHandle b);
// @category:read
bool ListLabelledControlArray_not_equal(ListLabelledControlArrayHandle a, ListLabelledControlArrayHandle b);

// @category:read
StringHandle      ListLabelledControlArray_to_json_string(ListLabelledControlArrayHandle handle);
// @category:allocation
ListLabelledControlArrayHandle ListLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif