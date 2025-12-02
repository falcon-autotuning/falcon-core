#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledControlArray1DHandle;
// Function declarations

// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create_empty();

// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_fill_value(size_t count, LabelledControlArray1DHandle value);
// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create(LabelledControlArray1DHandle* data, size_t count);
// @category:deallocation
void ListLabelledControlArray1D_destroy(ListLabelledControlArray1DHandle handle);
// @category:write
void ListLabelledControlArray1D_push_back(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
size_t ListLabelledControlArray1D_size(ListLabelledControlArray1DHandle handle);
// @category:read
bool ListLabelledControlArray1D_empty(ListLabelledControlArray1DHandle handle);
// @category:write
/* AUTO-DOC from cpp: ListLabelledControlArray1D_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListLabelledControlArray1D_erase_at(ListLabelledControlArray1DHandle handle, size_t idx);
// @category:write
/* AUTO-DOC from cpp: ListLabelledControlArray1D_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListLabelledControlArray1D_clear(ListLabelledControlArray1DHandle handle);
// @category:read
LabelledControlArray1DHandle ListLabelledControlArray1D_at(ListLabelledControlArray1DHandle handle, size_t idx);
// @category:read
size_t ListLabelledControlArray1D_items(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListLabelledControlArray1D_contains(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
size_t ListLabelledControlArray1D_index(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
/* AUTO-DOC from cpp: ListLabelledControlArray1D_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListLabelledControlArray1DHandle ListLabelledControlArray1D_intersection(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other);
// @category:read
bool ListLabelledControlArray1D_equal(ListLabelledControlArray1DHandle a, ListLabelledControlArray1DHandle b);
// @category:read
bool ListLabelledControlArray1D_not_equal(ListLabelledControlArray1DHandle a, ListLabelledControlArray1DHandle b);

// @category:read
StringHandle      ListLabelledControlArray1D_to_json_string(ListLabelledControlArray1DHandle handle);
// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif