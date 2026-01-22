

# File DotGateWithNeighbors\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**DotGateWithNeighbors\_c\_api.h**](DotGateWithNeighbors__c__api_8h.md)

[Go to the documentation of this file](DotGateWithNeighbors__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* DotGateWithNeighborsHandle;

// @category:allocation
DotGateWithNeighborsHandle DotGateWithNeighbors_copy(
    DotGateWithNeighborsHandle handle);
// @category:deallocation
void DotGateWithNeighbors_destroy(DotGateWithNeighborsHandle handle);
// @category:read
bool DotGateWithNeighbors_equal(DotGateWithNeighborsHandle handle,
                                DotGateWithNeighborsHandle other);
// @category:read
bool DotGateWithNeighbors_not_equal(DotGateWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle other);
// @category:read
StringHandle DotGateWithNeighbors_to_json_string(
    DotGateWithNeighborsHandle handle);
// @category:allocation
DotGateWithNeighborsHandle DotGateWithNeighbors_from_json_string(
    StringHandle json);
// @category:allocation
DotGateWithNeighborsHandle
DotGateWithNeighbors_create_plunger_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
// @category:allocation
DotGateWithNeighborsHandle
DotGateWithNeighbors_create_barrier_gate_with_neighbors(
    StringHandle     name,
    ConnectionHandle left_neighbor,
    ConnectionHandle right_neighbor);
// @category:read
StringHandle DotGateWithNeighbors_name(DotGateWithNeighborsHandle handle);
// @category:read
StringHandle DotGateWithNeighbors_type(DotGateWithNeighborsHandle handle);
// @category:read
ConnectionHandle DotGateWithNeighbors_left_neighbor(
    DotGateWithNeighborsHandle handle);
// @category:read
ConnectionHandle DotGateWithNeighbors_right_neighbor(
    DotGateWithNeighborsHandle handle);
// @category:read
bool DotGateWithNeighbors_is_barrier_gate(DotGateWithNeighborsHandle handle);
// @category:read
bool DotGateWithNeighbors_is_plunger_gate(DotGateWithNeighborsHandle handle);

#ifdef __cplusplus
}
#endif
```


