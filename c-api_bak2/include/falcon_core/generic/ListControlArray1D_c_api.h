#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListControlArray1DHandle;
// Function declarations

ListControlArray1DHandle ListControlArray1D_create_empty();

ListControlArray1DHandle ListControlArray1D_fill_value(size_t count, ControlArray1DHandle value);
ListControlArray1DHandle ListControlArray1D_create(ControlArray1DHandle* data, size_t count);
void ListControlArray1D_destroy(ListControlArray1DHandle handle);
void ListControlArray1D_push_back(ListControlArray1DHandle handle, ControlArray1DHandle value);
size_t ListControlArray1D_size(ListControlArray1DHandle handle);
bool ListControlArray1D_empty(ListControlArray1DHandle handle);
/* AUTO-DOC from cpp: ListControlArray1D_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListControlArray1D_erase_at(ListControlArray1DHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListControlArray1D_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListControlArray1D_clear(ListControlArray1DHandle handle);
ControlArray1DHandle ListControlArray1D_at(ListControlArray1DHandle handle, size_t idx);
size_t ListControlArray1D_items(ListControlArray1DHandle handle, ControlArray1DHandle* out_buffer, size_t buffer_size);
bool ListControlArray1D_contains(ListControlArray1DHandle handle, ControlArray1DHandle value);
size_t ListControlArray1D_index(ListControlArray1DHandle handle, ControlArray1DHandle value);
/* AUTO-DOC from cpp: ListControlArray1D_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListControlArray1DHandle ListControlArray1D_intersection(ListControlArray1DHandle handle, ListControlArray1DHandle other);
bool ListControlArray1D_equal(ListControlArray1DHandle a, ListControlArray1DHandle b);
bool ListControlArray1D_not_equal(ListControlArray1DHandle a, ListControlArray1DHandle b);

// Serialization (from Song)
StringHandle      ListControlArray1D_to_json_string(ListControlArray1DHandle handle);
ListControlArray1DHandle ListControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif