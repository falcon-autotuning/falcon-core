#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionConnections_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionConnectionsHandle;
// Function declarations

ListPairConnectionConnectionsHandle ListPairConnectionConnections_create_empty();

ListPairConnectionConnectionsHandle ListPairConnectionConnections_fill_value(size_t count, PairConnectionConnectionsHandle value);
ListPairConnectionConnectionsHandle ListPairConnectionConnections_create(PairConnectionConnectionsHandle* data, size_t count);
void ListPairConnectionConnections_destroy(ListPairConnectionConnectionsHandle handle);
void ListPairConnectionConnections_push_back(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
size_t ListPairConnectionConnections_size(ListPairConnectionConnectionsHandle handle);
bool ListPairConnectionConnections_empty(ListPairConnectionConnectionsHandle handle);
/* AUTO-DOC from cpp: ListPairConnectionConnections_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief (from C++: falcon_core::generic::List::erase_at)
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListPairConnectionConnections_erase_at(ListPairConnectionConnectionsHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListPairConnectionConnections_clear | falcon_core::generic::List::clear */
/**
 * @brief (from C++: falcon_core::generic::List::clear)
 * @brief clears to contents of the list.
 */
void ListPairConnectionConnections_clear(ListPairConnectionConnectionsHandle handle);
PairConnectionConnectionsHandle ListPairConnectionConnections_at(ListPairConnectionConnectionsHandle handle, size_t idx);
size_t ListPairConnectionConnections_items(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle* out_buffer, size_t buffer_size);
bool ListPairConnectionConnections_contains(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
size_t ListPairConnectionConnections_index(ListPairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle value);
/* AUTO-DOC from cpp: ListPairConnectionConnections_intersection | falcon_core::generic::List::intersection */
/**
 * @brief (from C++: falcon_core::generic::List::intersection)
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListPairConnectionConnectionsHandle ListPairConnectionConnections_intersection(ListPairConnectionConnectionsHandle handle, ListPairConnectionConnectionsHandle other);
bool ListPairConnectionConnections_equal(ListPairConnectionConnectionsHandle a, ListPairConnectionConnectionsHandle b);
bool ListPairConnectionConnections_not_equal(ListPairConnectionConnectionsHandle a, ListPairConnectionConnectionsHandle b);

// Serialization (from Song)
/* AUTO-DOC from cpp: ListPairConnectionConnections_to_json_string | falcon_core::generic::Song::to_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::to_json_string)
 * @brief Serialize this object to a JSON string.
 */
StringHandle      ListPairConnectionConnections_to_json_string(ListPairConnectionConnectionsHandle handle);
/* AUTO-DOC from cpp: ListPairConnectionConnections_from_json_string | falcon_core::generic::Song::from_json_string */
/**
 * @brief (from C++: falcon_core::generic::Song::from_json_string)
 * @brief Deserialize an object from a JSON string.
 * @return std::shared_ptr<Song> (actually the derived type)
 */
ListPairConnectionConnectionsHandle ListPairConnectionConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif