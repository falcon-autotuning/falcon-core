#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListConnectionsHandle;
// Function declarations

ListConnectionsHandle ListConnections_create_empty();

ListConnectionsHandle ListConnections_fill_value(size_t count, ConnectionsHandle value);
ListConnectionsHandle ListConnections_create(ConnectionsHandle* data, size_t count);
void ListConnections_destroy(ListConnectionsHandle handle);
void ListConnections_push_back(ListConnectionsHandle handle, ConnectionsHandle value);
size_t ListConnections_size(ListConnectionsHandle handle);
bool ListConnections_empty(ListConnectionsHandle handle);
/* AUTO-DOC from cpp: ListConnections_erase_at | falcon_core::generic::List::erase_at */
/**
 * @brief Allows for targetted eraseall of elements at an index.
 * @param idx The index to erase at.
 */
void ListConnections_erase_at(ListConnectionsHandle handle, size_t idx);
/* AUTO-DOC from cpp: ListConnections_clear | falcon_core::generic::List::clear */
/**
 * @brief clears to contents of the list.
 */
void ListConnections_clear(ListConnectionsHandle handle);
ConnectionsHandle ListConnections_at(ListConnectionsHandle handle, size_t idx);
size_t ListConnections_items(ListConnectionsHandle handle, ConnectionsHandle* out_buffer, size_t buffer_size);
bool ListConnections_contains(ListConnectionsHandle handle, ConnectionsHandle value);
size_t ListConnections_index(ListConnectionsHandle handle, ConnectionsHandle value);
/* AUTO-DOC from cpp: ListConnections_intersection | falcon_core::generic::List::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ListConnectionsHandle ListConnections_intersection(ListConnectionsHandle handle, ListConnectionsHandle other);
bool ListConnections_equal(ListConnectionsHandle a, ListConnectionsHandle b);
bool ListConnections_not_equal(ListConnectionsHandle a, ListConnectionsHandle b);

// Serialization (from Song)
StringHandle      ListConnections_to_json_string(ListConnectionsHandle handle);
ListConnectionsHandle ListConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif