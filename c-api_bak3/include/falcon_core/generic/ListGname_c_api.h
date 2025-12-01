#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGnameHandle;
// Function declarations

ListGnameHandle ListGname_create_empty();

ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value);
ListGnameHandle ListGname_create(GnameHandle* data, size_t count);
void ListGname_destroy(ListGnameHandle handle);
void ListGname_push_back(ListGnameHandle handle, GnameHandle value);
size_t ListGname_size(ListGnameHandle handle);
bool ListGname_empty(ListGnameHandle handle);
/* AUTO-DOC from cpp: ListGname_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListGname_erase_at(ListGnameHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListGname_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListGname_clear(ListGnameHandle handle);
GnameHandle ListGname_at(ListGnameHandle handle, size_t idx);
size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size);
bool ListGname_contains(ListGnameHandle handle, GnameHandle value);
size_t ListGname_index(ListGnameHandle handle, GnameHandle value);
/* AUTO-DOC from cpp: ListGname_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other);
bool ListGname_equal(ListGnameHandle a, ListGnameHandle b);
bool ListGname_not_equal(ListGnameHandle a, ListGnameHandle b);

// Serialization (from Song)
StringHandle      ListGname_to_json_string(ListGnameHandle handle);
ListGnameHandle ListGname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif