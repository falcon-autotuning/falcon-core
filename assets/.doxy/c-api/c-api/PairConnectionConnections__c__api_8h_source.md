

# File PairConnectionConnections\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionConnections\_c\_api.h**](PairConnectionConnections__c__api_8h.md)

[Go to the documentation of this file](PairConnectionConnections__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionsHandle;
// Function declarations

// @category:allocation
PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second);
// @category:allocation
PairConnectionConnectionsHandle PairConnectionConnections_copy(PairConnectionConnectionsHandle handle);
// @category:deallocation
void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle);
// @category:read
ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle);
// @category:read
ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle);
// @category:read
bool PairConnectionConnections_equal(PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other);
// @category:read
bool PairConnectionConnections_not_equal(PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other);
// @category:read
StringHandle      PairConnectionConnections_to_json_string(PairConnectionConnectionsHandle handle);
// @category:allocation
PairConnectionConnectionsHandle PairConnectionConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


