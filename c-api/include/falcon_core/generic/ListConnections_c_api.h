#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListConnectionsHandle;
// Function declarations

ListConnectionsHandle ListConnections_create_empty();
ListConnectionsHandle ListConnections_allocate(size_t count);
ListConnectionsHandle ListConnections_fill_value(size_t count, ConnectionsHandle value);
ListConnectionsHandle ListConnections_create(const ConnectionsHandle* data, size_t count);
void ListConnections_destroy(ListConnectionsHandle handle);
void ListConnections_push_back(ListConnectionsHandle handle, ConnectionsHandle value);
size_t ListConnections_size(ListConnectionsHandle handle);
bool ListConnections_empty(ListConnectionsHandle handle);
void ListConnections_erase_at(ListConnectionsHandle handle, size_t idx);
void ListConnections_clear(ListConnectionsHandle handle);
ConnectionsHandle ListConnections_at(ListConnectionsHandle handle, size_t idx);
size_t ListConnections_items(ListConnectionsHandle handle, ConnectionsHandle* out_buffer, size_t buffer_size);
bool ListConnections_contains(ListConnectionsHandle handle, ConnectionsHandle value);
size_t ListConnections_index(ListConnectionsHandle handle, ConnectionsHandle value);
ListConnectionsHandle ListConnections_intersection(ListConnectionsHandle handle, ListConnectionsHandle other);
bool ListConnections_equal(ListConnectionsHandle a, ListConnectionsHandle b);
bool ListConnections_not_equal(ListConnectionsHandle a, ListConnectionsHandle b);

// Serialization (from Song)
const char*      ListConnections_to_json_string(ListConnectionsHandle handle);
ListConnectionsHandle ListConnections_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif