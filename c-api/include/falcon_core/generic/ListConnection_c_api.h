#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListConnectionHandle;
// Function declarations

// @category:allocation
ListConnectionHandle ListConnection_create_empty();
// @category:allocation
ListConnectionHandle ListConnection_copy(ListConnectionHandle handle);

// @category:allocation
ListConnectionHandle ListConnection_fill_value(size_t count, ConnectionHandle value);
// @category:allocation
ListConnectionHandle ListConnection_create(ConnectionHandle* data, size_t count);
// @category:deallocation
void ListConnection_destroy(ListConnectionHandle handle);
// @category:write
void ListConnection_push_back(ListConnectionHandle handle, ConnectionHandle value);
// @category:read
size_t ListConnection_size(ListConnectionHandle handle);
// @category:read
bool ListConnection_empty(ListConnectionHandle handle);
// @category:write
void ListConnection_erase_at(ListConnectionHandle handle, size_t idx);
// @category:write
void ListConnection_clear(ListConnectionHandle handle);
// @category:read
ConnectionHandle ListConnection_at(ListConnectionHandle handle, size_t idx);
// @category:read
size_t ListConnection_items(ListConnectionHandle handle, ConnectionHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListConnection_contains(ListConnectionHandle handle, ConnectionHandle value);
// @category:read
size_t ListConnection_index(ListConnectionHandle handle, ConnectionHandle value);
// @category:read
ListConnectionHandle ListConnection_intersection(ListConnectionHandle handle, ListConnectionHandle other);
// @category:read
bool ListConnection_equal(ListConnectionHandle handle, ListConnectionHandle other);
// @category:read
bool ListConnection_not_equal(ListConnectionHandle handle, ListConnectionHandle other);

// @category:read
StringHandle      ListConnection_to_json_string(ListConnectionHandle handle);
// @category:allocation
ListConnectionHandle ListConnection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif