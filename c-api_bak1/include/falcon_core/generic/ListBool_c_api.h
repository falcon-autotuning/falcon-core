#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListBoolHandle;
// Function declarations

ListBoolHandle ListBool_create_empty();
ListBoolHandle ListBool_allocate(size_t count);
ListBoolHandle ListBool_fill_value(size_t count, bool value);
ListBoolHandle ListBool_create(bool* data, size_t count);
void ListBool_destroy(ListBoolHandle handle);
void ListBool_push_back(ListBoolHandle handle, bool value);
size_t ListBool_size(ListBoolHandle handle);
bool ListBool_empty(ListBoolHandle handle);
/* AUTO-DOC from cpp: ListBool_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListBool_erase_at(ListBoolHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListBool_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListBool_clear(ListBoolHandle handle);
bool ListBool_at(ListBoolHandle handle, size_t idx);
size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size);
bool ListBool_contains(ListBoolHandle handle, bool value);
size_t ListBool_index(ListBoolHandle handle, bool value);
/* AUTO-DOC from cpp: ListBool_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other);
bool ListBool_equal(ListBoolHandle a, ListBoolHandle b);
bool ListBool_not_equal(ListBoolHandle a, ListBoolHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListBool_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListBool_to_json_string(ListBoolHandle handle);
/* AUTO-DOC from cpp: ListBool_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListBoolHandle ListBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif