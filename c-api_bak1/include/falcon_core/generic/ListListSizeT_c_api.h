#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListListSizeTHandle;
// Function declarations

ListListSizeTHandle ListListSizeT_create_empty();

ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value);
ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count);
void ListListSizeT_destroy(ListListSizeTHandle handle);
void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value);
size_t ListListSizeT_size(ListListSizeTHandle handle);
bool ListListSizeT_empty(ListListSizeTHandle handle);
/* AUTO-DOC from cpp: ListListSizeT_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListListSizeT_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListListSizeT_clear(ListListSizeTHandle handle);
ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx);
size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size);
bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value);
size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value);
/* AUTO-DOC from cpp: ListListSizeT_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other);
bool ListListSizeT_equal(ListListSizeTHandle a, ListListSizeTHandle b);
bool ListListSizeT_not_equal(ListListSizeTHandle a, ListListSizeTHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListListSizeT_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle);
/* AUTO-DOC from cpp: ListListSizeT_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif