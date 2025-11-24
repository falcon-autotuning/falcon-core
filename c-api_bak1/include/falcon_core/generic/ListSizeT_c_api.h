#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListSizeTHandle;
// Function declarations

ListSizeTHandle ListSizeT_create_empty();
ListSizeTHandle ListSizeT_allocate(size_t count);
ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value);
ListSizeTHandle ListSizeT_create(size_t* data, size_t count);
void ListSizeT_destroy(ListSizeTHandle handle);
void ListSizeT_push_back(ListSizeTHandle handle, size_t value);
size_t ListSizeT_size(ListSizeTHandle handle);
bool ListSizeT_empty(ListSizeTHandle handle);
/* AUTO-DOC from cpp: ListSizeT_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListSizeT_erase_at(ListSizeTHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListSizeT_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListSizeT_clear(ListSizeTHandle handle);
size_t ListSizeT_at(ListSizeTHandle handle, size_t idx);
size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size);
bool ListSizeT_contains(ListSizeTHandle handle, size_t value);
size_t ListSizeT_index(ListSizeTHandle handle, size_t value);
/* AUTO-DOC from cpp: ListSizeT_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListSizeTHandle ListSizeT_intersection(ListSizeTHandle handle, ListSizeTHandle other);
bool ListSizeT_equal(ListSizeTHandle a, ListSizeTHandle b);
bool ListSizeT_not_equal(ListSizeTHandle a, ListSizeTHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListSizeT_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListSizeT_to_json_string(ListSizeTHandle handle);
/* AUTO-DOC from cpp: ListSizeT_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListSizeTHandle ListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif