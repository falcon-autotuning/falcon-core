#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledMeasuredArrayHandle;
// Function declarations

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create_empty();

ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_fill_value(size_t count, LabelledMeasuredArrayHandle value);
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_create(LabelledMeasuredArrayHandle* data, size_t count);
void ListLabelledMeasuredArray_destroy(ListLabelledMeasuredArrayHandle handle);
void ListLabelledMeasuredArray_push_back(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
size_t ListLabelledMeasuredArray_size(ListLabelledMeasuredArrayHandle handle);
bool ListLabelledMeasuredArray_empty(ListLabelledMeasuredArrayHandle handle);
/* AUTO-DOC from cpp: ListLabelledMeasuredArray_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListLabelledMeasuredArray_erase_at(ListLabelledMeasuredArrayHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListLabelledMeasuredArray_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListLabelledMeasuredArray_clear(ListLabelledMeasuredArrayHandle handle);
LabelledMeasuredArrayHandle ListLabelledMeasuredArray_at(ListLabelledMeasuredArrayHandle handle, size_t idx);
size_t ListLabelledMeasuredArray_items(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size);
bool ListLabelledMeasuredArray_contains(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
size_t ListLabelledMeasuredArray_index(ListLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
/* AUTO-DOC from cpp: ListLabelledMeasuredArray_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_intersection(ListLabelledMeasuredArrayHandle handle, ListLabelledMeasuredArrayHandle other);
bool ListLabelledMeasuredArray_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b);
bool ListLabelledMeasuredArray_not_equal(ListLabelledMeasuredArrayHandle a, ListLabelledMeasuredArrayHandle b);

// Serialization (from Song)
StringHandle      ListLabelledMeasuredArray_to_json_string(ListLabelledMeasuredArrayHandle handle);
ListLabelledMeasuredArrayHandle ListLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif