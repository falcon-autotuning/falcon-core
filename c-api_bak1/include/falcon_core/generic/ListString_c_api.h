#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListStringHandle;
// Function declarations

ListStringHandle ListString_create_empty();
ListStringHandle ListString_allocate(size_t count);
ListStringHandle ListString_fill_value(size_t count, StringHandle value);
ListStringHandle ListString_create(StringHandle* data, size_t count);
void ListString_destroy(ListStringHandle handle);
void ListString_push_back(ListStringHandle handle, StringHandle value);
size_t ListString_size(ListStringHandle handle);
bool ListString_empty(ListStringHandle handle);
/* AUTO-DOC from cpp: ListString_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListString_erase_at(ListStringHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListString_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListString_clear(ListStringHandle handle);
StringHandle ListString_at(ListStringHandle handle, size_t idx);
size_t ListString_items(ListStringHandle handle, StringHandle* out_buffer, size_t buffer_size);
bool ListString_contains(ListStringHandle handle, StringHandle value);
size_t ListString_index(ListStringHandle handle, StringHandle value);
/* AUTO-DOC from cpp: ListString_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListStringHandle ListString_intersection(ListStringHandle handle, ListStringHandle other);
bool ListString_equal(ListStringHandle a, ListStringHandle b);
bool ListString_not_equal(ListStringHandle a, ListStringHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListString_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListString_to_json_string(ListStringHandle handle);
/* AUTO-DOC from cpp: ListString_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListStringHandle ListString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif