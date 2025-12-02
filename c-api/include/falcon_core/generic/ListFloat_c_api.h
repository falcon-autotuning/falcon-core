#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFloatHandle;
// Function declarations

ListFloatHandle ListFloat_create_empty();
ListFloatHandle ListFloat_allocate(size_t count);
ListFloatHandle ListFloat_fill_value(size_t count, float value);
ListFloatHandle ListFloat_create(float* data, size_t count);
void ListFloat_destroy(ListFloatHandle handle);
void ListFloat_push_back(ListFloatHandle handle, float value);
size_t ListFloat_size(ListFloatHandle handle);
bool ListFloat_empty(ListFloatHandle handle);
/* AUTO-DOC from cpp: ListFloat_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListFloat_erase_at(ListFloatHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListFloat_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListFloat_clear(ListFloatHandle handle);
float ListFloat_at(ListFloatHandle handle, size_t idx);
size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size);
bool ListFloat_contains(ListFloatHandle handle, float value);
size_t ListFloat_index(ListFloatHandle handle, float value);
/* AUTO-DOC from cpp: ListFloat_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other);
bool ListFloat_equal(ListFloatHandle a, ListFloatHandle b);
bool ListFloat_not_equal(ListFloatHandle a, ListFloatHandle b);

// Serialization (from Song)
StringHandle      ListFloat_to_json_string(ListFloatHandle handle);
ListFloatHandle ListFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif