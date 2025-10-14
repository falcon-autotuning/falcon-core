#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <cstddef>

// Forward declarations for opaque handles
typedef void* ListConnectionHandle;
// Function declarations

ListConnectionHandle ListConnection_create_empty();
ListConnectionHandle ListConnection_allocate(size_t count);
ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value);
ListConnectionHandle ListConnection_create(const ConnectionHandle* data, size_t count);
void ListConnection_destroy(ListConnectionHandle handle);
void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value);
size_t ListConnection_size(ListConnectionHandle handle);
bool ListConnection_empty(ListConnectionHandle handle);
void ListConnection_erase_at(ListConnectionHandle handle, size_t idx);
void ListConnection_clear(ListConnectionHandle handle);
ConnectionHandle ListConnection_const_at(ListConnectionHandle handle, size_t idx);
ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx);
size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size);
bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value);
size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value);
ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other);
bool ListConnection_equal(ListConnectionHandle a, ListConnectionHandle b);
bool ListConnection_not_equal(ListConnectionHandle a, ListConnectionHandle b);
#ifdef __cplusplus
}
#endif