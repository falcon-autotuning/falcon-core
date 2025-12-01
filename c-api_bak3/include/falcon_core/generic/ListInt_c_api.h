#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListIntHandle;
// Function declarations

ListIntHandle ListInt_create_empty();
ListIntHandle ListInt_allocate(size_t count);
ListIntHandle ListInt_fill_value(size_t count, int value);
ListIntHandle ListInt_create(int* data, size_t count);
void ListInt_destroy(ListIntHandle handle);
void ListInt_push_back(ListIntHandle handle, int value);
size_t ListInt_size(ListIntHandle handle);
bool ListInt_empty(ListIntHandle handle);
/* AUTO-DOC from cpp: ListInt_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListInt_erase_at(ListIntHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListInt_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListInt_clear(ListIntHandle handle);
int ListInt_at(ListIntHandle handle, size_t idx);
size_t ListInt_items(ListIntHandle handle, int* out_buffer, size_t buffer_size);
bool ListInt_contains(ListIntHandle handle, int value);
size_t ListInt_index(ListIntHandle handle, int value);
/* AUTO-DOC from cpp: ListInt_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListIntHandle ListInt_intersection(ListIntHandle handle, ListIntHandle other);
bool ListInt_equal(ListIntHandle a, ListIntHandle b);
bool ListInt_not_equal(ListIntHandle a, ListIntHandle b);

// Serialization (from Song)
StringHandle      ListInt_to_json_string(ListIntHandle handle);
ListIntHandle ListInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif