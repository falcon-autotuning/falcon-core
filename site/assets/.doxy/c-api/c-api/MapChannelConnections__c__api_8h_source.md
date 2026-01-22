

# File MapChannelConnections\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**MapChannelConnections\_c\_api.h**](MapChannelConnections__c__api_8h.md)

[Go to the documentation of this file](MapChannelConnections__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairChannelConnections_c_api.h"
#include "falcon_core/generic/ListChannel_c_api.h"
#include "falcon_core/generic/ListConnections_c_api.h"
#include "falcon_core/generic/ListPairChannelConnections_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* MapChannelConnectionsHandle;
// Function declarations

// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_create_empty();
// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_copy(MapChannelConnectionsHandle handle);
// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_create(PairChannelConnectionsHandle* data, size_t count);
// @category:deallocation
void MapChannelConnections_destroy(MapChannelConnectionsHandle handle);
// @category:write
void MapChannelConnections_insert_or_assign(MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value);
// @category:write
void MapChannelConnections_insert(MapChannelConnectionsHandle handle, ChannelHandle key, ConnectionsHandle value);
// @category:read
ConnectionsHandle MapChannelConnections_at(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:write
void MapChannelConnections_erase(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:read
size_t MapChannelConnections_size(MapChannelConnectionsHandle handle);
// @category:read
bool MapChannelConnections_empty(MapChannelConnectionsHandle handle);
// @category:write
void MapChannelConnections_clear(MapChannelConnectionsHandle handle);
// @category:read
bool MapChannelConnections_contains(MapChannelConnectionsHandle handle, ChannelHandle key);
// @category:read
ListChannelHandle MapChannelConnections_keys(MapChannelConnectionsHandle handle);
// @category:read
ListConnectionsHandle MapChannelConnections_values(MapChannelConnectionsHandle handle);
// @category:read
ListPairChannelConnectionsHandle MapChannelConnections_items(MapChannelConnectionsHandle handle);
// @category:read
bool MapChannelConnections_equal(MapChannelConnectionsHandle handle, MapChannelConnectionsHandle other);
// @category:read
bool MapChannelConnections_not_equal(MapChannelConnectionsHandle handle, MapChannelConnectionsHandle other);
// @category:read
StringHandle      MapChannelConnections_to_json_string(MapChannelConnectionsHandle handle);
// @category:allocation
MapChannelConnectionsHandle MapChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


