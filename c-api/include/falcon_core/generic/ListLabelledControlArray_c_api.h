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

ListLabelledControlArrayHandle ListLabelledControlArray_create_empty();

ListLabelledControlArrayHandle ListLabelledControlArray_fill_value(size_t count, LabelledControlArrayHandle value);
ListLabelledControlArrayHandle ListLabelledControlArray_create(LabelledControlArrayHandle* data, size_t count);
void ListLabelledControlArray_destroy(ListLabelledControlArrayHandle handle);
void ListLabelledControlArray_push_back(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
size_t ListLabelledControlArray_size(ListLabelledControlArrayHandle handle);
bool ListLabelledControlArray_empty(ListLabelledControlArrayHandle handle);
/* AUTO-DOC from cpp: ListLabelledControlArray_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListLabelledControlArray_erase_at(ListLabelledControlArrayHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListLabelledControlArray_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListLabelledControlArray_clear(ListLabelledControlArrayHandle handle);
LabelledControlArrayHandle ListLabelledControlArray_at(ListLabelledControlArrayHandle handle, size_t idx);
size_t ListLabelledControlArray_items(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size);
bool ListLabelledControlArray_contains(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
size_t ListLabelledControlArray_index(ListLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
/* AUTO-DOC from cpp: ListLabelledControlArray_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListLabelledControlArrayHandle ListLabelledControlArray_intersection(ListLabelledControlArrayHandle handle, ListLabelledControlArrayHandle other);
bool ListLabelledControlArray_equal(ListLabelledControlArrayHandle a, ListLabelledControlArrayHandle b);
bool ListLabelledControlArray_not_equal(ListLabelledControlArrayHandle a, ListLabelledControlArrayHandle b);

// Serialization (from Song)
StringHandle      ListLabelledControlArray_to_json_string(ListLabelledControlArrayHandle handle);
ListLabelledControlArrayHandle ListLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif