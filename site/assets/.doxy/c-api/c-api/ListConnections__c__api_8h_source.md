

# File ListConnections\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListConnections\_c\_api.h**](ListConnections__c__api_8h.md)

[Go to the documentation of this file](ListConnections__c__api_8h.md)


```C++
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

// @category:allocation
ListConnectionsHandle ListConnections_create_empty();
// @category:allocation
ListConnectionsHandle ListConnections_copy(ListConnectionsHandle handle);

// @category:allocation
ListConnectionsHandle ListConnections_fill_value(size_t count, ConnectionsHandle value);
// @category:allocation
ListConnectionsHandle ListConnections_create(ConnectionsHandle* data, size_t count);
// @category:deallocation
void ListConnections_destroy(ListConnectionsHandle handle);
// @category:write
void ListConnections_push_back(ListConnectionsHandle handle, ConnectionsHandle value);
// @category:read
size_t ListConnections_size(ListConnectionsHandle handle);
// @category:read
bool ListConnections_empty(ListConnectionsHandle handle);
// @category:write
void ListConnections_erase_at(ListConnectionsHandle handle, size_t idx);
// @category:write
void ListConnections_clear(ListConnectionsHandle handle);
// @category:read
ConnectionsHandle ListConnections_at(ListConnectionsHandle handle, size_t idx);
// @category:read
size_t ListConnections_items(ListConnectionsHandle handle, ConnectionsHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListConnections_contains(ListConnectionsHandle handle, ConnectionsHandle value);
// @category:read
size_t ListConnections_index(ListConnectionsHandle handle, ConnectionsHandle value);
// @category:read
ListConnectionsHandle ListConnections_intersection(ListConnectionsHandle handle, ListConnectionsHandle other);
// @category:read
bool ListConnections_equal(ListConnectionsHandle handle, ListConnectionsHandle other);
// @category:read
bool ListConnections_not_equal(ListConnectionsHandle handle, ListConnectionsHandle other);

// @category:read
StringHandle      ListConnections_to_json_string(ListConnectionsHandle handle);
// @category:allocation
ListConnectionsHandle ListConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


