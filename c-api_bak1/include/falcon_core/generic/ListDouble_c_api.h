#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDoubleHandle;
// Function declarations

ListDoubleHandle ListDouble_create_empty();
ListDoubleHandle ListDouble_allocate(size_t count);
ListDoubleHandle ListDouble_fill_value(size_t count, double value);
ListDoubleHandle ListDouble_create(double* data, size_t count);
void ListDouble_destroy(ListDoubleHandle handle);
void ListDouble_push_back(ListDoubleHandle handle, double value);
size_t ListDouble_size(ListDoubleHandle handle);
bool ListDouble_empty(ListDoubleHandle handle);
/* AUTO-DOC from cpp: ListDouble_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListDouble_erase_at(ListDoubleHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListDouble_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListDouble_clear(ListDoubleHandle handle);
double ListDouble_at(ListDoubleHandle handle, size_t idx);
size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size);
bool ListDouble_contains(ListDoubleHandle handle, double value);
size_t ListDouble_index(ListDoubleHandle handle, double value);
/* AUTO-DOC from cpp: ListDouble_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other);
bool ListDouble_equal(ListDoubleHandle a, ListDoubleHandle b);
bool ListDouble_not_equal(ListDoubleHandle a, ListDoubleHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListDouble_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListDouble_to_json_string(ListDoubleHandle handle);
/* AUTO-DOC from cpp: ListDouble_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListDoubleHandle ListDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif