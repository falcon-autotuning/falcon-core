#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionDoubleHandle;
// Function declarations

ListPairConnectionDoubleHandle ListPairConnectionDouble_create_empty();

ListPairConnectionDoubleHandle ListPairConnectionDouble_fill_value(size_t count, PairConnectionDoubleHandle value);
ListPairConnectionDoubleHandle ListPairConnectionDouble_create(PairConnectionDoubleHandle* data, size_t count);
void ListPairConnectionDouble_destroy(ListPairConnectionDoubleHandle handle);
void ListPairConnectionDouble_push_back(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
size_t ListPairConnectionDouble_size(ListPairConnectionDoubleHandle handle);
bool ListPairConnectionDouble_empty(ListPairConnectionDoubleHandle handle);
/* AUTO-DOC from cpp: ListPairConnectionDouble_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairConnectionDouble_erase_at(ListPairConnectionDoubleHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairConnectionDouble_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairConnectionDouble_clear(ListPairConnectionDoubleHandle handle);
PairConnectionDoubleHandle ListPairConnectionDouble_at(ListPairConnectionDoubleHandle handle, size_t idx);
size_t ListPairConnectionDouble_items(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle* out_buffer, size_t buffer_size);
bool ListPairConnectionDouble_contains(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
size_t ListPairConnectionDouble_index(ListPairConnectionDoubleHandle handle, PairConnectionDoubleHandle value);
/* AUTO-DOC from cpp: ListPairConnectionDouble_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairConnectionDoubleHandle ListPairConnectionDouble_intersection(ListPairConnectionDoubleHandle handle, ListPairConnectionDoubleHandle other);
bool ListPairConnectionDouble_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b);
bool ListPairConnectionDouble_not_equal(ListPairConnectionDoubleHandle a, ListPairConnectionDoubleHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListPairConnectionDouble_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListPairConnectionDouble_to_json_string(ListPairConnectionDoubleHandle handle);
/* AUTO-DOC from cpp: ListPairConnectionDouble_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListPairConnectionDoubleHandle ListPairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif