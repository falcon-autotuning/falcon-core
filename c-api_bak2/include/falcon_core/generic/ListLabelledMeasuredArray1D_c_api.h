#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledMeasuredArray1DHandle;
// Function declarations

ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create_empty();

ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_fill_value(size_t count, LabelledMeasuredArray1DHandle value);
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_create(LabelledMeasuredArray1DHandle* data, size_t count);
void ListLabelledMeasuredArray1D_destroy(ListLabelledMeasuredArray1DHandle handle);
void ListLabelledMeasuredArray1D_push_back(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
size_t ListLabelledMeasuredArray1D_size(ListLabelledMeasuredArray1DHandle handle);
bool ListLabelledMeasuredArray1D_empty(ListLabelledMeasuredArray1DHandle handle);
/* AUTO-DOC from cpp: ListLabelledMeasuredArray1D_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListLabelledMeasuredArray1D_erase_at(ListLabelledMeasuredArray1DHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListLabelledMeasuredArray1D_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListLabelledMeasuredArray1D_clear(ListLabelledMeasuredArray1DHandle handle);
LabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_at(ListLabelledMeasuredArray1DHandle handle, size_t idx);
size_t ListLabelledMeasuredArray1D_items(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle* out_buffer, size_t buffer_size);
bool ListLabelledMeasuredArray1D_contains(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
size_t ListLabelledMeasuredArray1D_index(ListLabelledMeasuredArray1DHandle handle, LabelledMeasuredArray1DHandle value);
/* AUTO-DOC from cpp: ListLabelledMeasuredArray1D_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_intersection(ListLabelledMeasuredArray1DHandle handle, ListLabelledMeasuredArray1DHandle other);
bool ListLabelledMeasuredArray1D_equal(ListLabelledMeasuredArray1DHandle a, ListLabelledMeasuredArray1DHandle b);
bool ListLabelledMeasuredArray1D_not_equal(ListLabelledMeasuredArray1DHandle a, ListLabelledMeasuredArray1DHandle b);

// Serialization (from Song)
StringHandle      ListLabelledMeasuredArray1D_to_json_string(ListLabelledMeasuredArray1DHandle handle);
ListLabelledMeasuredArray1DHandle ListLabelledMeasuredArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif