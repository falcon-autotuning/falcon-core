

# File PairChannelConnections\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairChannelConnections\_c\_api.h**](PairChannelConnections__c__api_8h.md)

[Go to the documentation of this file](PairChannelConnections__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairChannelConnectionsHandle;
// Function declarations

// @category:allocation
PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second);
// @category:allocation
PairChannelConnectionsHandle PairChannelConnections_copy(PairChannelConnectionsHandle handle);
// @category:deallocation
void PairChannelConnections_destroy(PairChannelConnectionsHandle handle);
// @category:read
ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle);
// @category:read
ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle);
// @category:read
bool PairChannelConnections_equal(PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other);
// @category:read
bool PairChannelConnections_not_equal(PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other);
// @category:read
StringHandle      PairChannelConnections_to_json_string(PairChannelConnectionsHandle handle);
// @category:allocation
PairChannelConnectionsHandle PairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


