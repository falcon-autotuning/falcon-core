#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListControlArrayHandle;
// Function declarations

ListControlArrayHandle ListControlArray_create_empty();

ListControlArrayHandle ListControlArray_fill_value(size_t count, ControlArrayHandle value);
ListControlArrayHandle ListControlArray_create(ControlArrayHandle* data, size_t count);
void ListControlArray_destroy(ListControlArrayHandle handle);
void ListControlArray_push_back(ListControlArrayHandle handle, ControlArrayHandle value);
size_t ListControlArray_size(ListControlArrayHandle handle);
bool ListControlArray_empty(ListControlArrayHandle handle);
/* AUTO-DOC from cpp: ListControlArray_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListControlArray_erase_at(ListControlArrayHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListControlArray_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListControlArray_clear(ListControlArrayHandle handle);
ControlArrayHandle ListControlArray_at(ListControlArrayHandle handle, size_t idx);
size_t ListControlArray_items(ListControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
bool ListControlArray_contains(ListControlArrayHandle handle, ControlArrayHandle value);
size_t ListControlArray_index(ListControlArrayHandle handle, ControlArrayHandle value);
/* AUTO-DOC from cpp: ListControlArray_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListControlArrayHandle ListControlArray_intersection(ListControlArrayHandle handle, ListControlArrayHandle other);
bool ListControlArray_equal(ListControlArrayHandle a, ListControlArrayHandle b);
bool ListControlArray_not_equal(ListControlArrayHandle a, ListControlArrayHandle b);

// Serialization (from Song)
StringHandle      ListControlArray_to_json_string(ListControlArrayHandle handle);
ListControlArrayHandle ListControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif