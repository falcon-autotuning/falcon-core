

# File DotGatesWithNeighbors\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**geometries**](dir_1d88f50ca6512fed7187c162c771cfa6.md) **>** [**DotGatesWithNeighbors\_c\_api.h**](DotGatesWithNeighbors__c__api_8h.md)

[Go to the documentation of this file](DotGatesWithNeighbors__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListDotGateWithNeighbors_c_api.h"
typedef void* DotGatesWithNeighborsHandle;

// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_copy(
    DotGatesWithNeighborsHandle handle);
// @category:deallocation
void DotGatesWithNeighbors_destroy(DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_equal(DotGatesWithNeighborsHandle handle,
                                 DotGatesWithNeighborsHandle other);
// @category:read
bool DotGatesWithNeighbors_not_equal(DotGatesWithNeighborsHandle handle,
                                     DotGatesWithNeighborsHandle other);
// @category:read
StringHandle DotGatesWithNeighbors_to_json_string(
    DotGatesWithNeighborsHandle handle);
// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_from_json_string(
    StringHandle json);
// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create_empty();
// @category:allocation
DotGatesWithNeighborsHandle DotGatesWithNeighbors_create(
    ListDotGateWithNeighborsHandle items);
// @category:read
/* AUTO-DOC from cpp: DotGatesWithNeighbors_is_plunger_gates |
 * falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_plunger_gates
 */
bool DotGatesWithNeighbors_is_plunger_gates(DotGatesWithNeighborsHandle handle);
// @category:read
/* AUTO-DOC from cpp: DotGatesWithNeighbors_is_barrier_gates |
 * falcon_core::physics::config::geometries::DotGatesWithNeighbors::is_barrier_gates
 */
bool DotGatesWithNeighbors_is_barrier_gates(DotGatesWithNeighborsHandle handle);
// @category:read
DotGatesWithNeighborsHandle DotGatesWithNeighbors_intersection(
    DotGatesWithNeighborsHandle handle, DotGatesWithNeighborsHandle other);
// @category:write
void DotGatesWithNeighbors_push_back(DotGatesWithNeighborsHandle handle,
                                     DotGateWithNeighborsHandle  value);
// @category:read
size_t DotGatesWithNeighbors_size(DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_empty(DotGatesWithNeighborsHandle handle);
// @category:write
void DotGatesWithNeighbors_erase_at(DotGatesWithNeighborsHandle handle,
                                    size_t                      idx);
// @category:write
void DotGatesWithNeighbors_clear(DotGatesWithNeighborsHandle handle);
// @category:read
DotGateWithNeighborsHandle DotGatesWithNeighbors_at(
    DotGatesWithNeighborsHandle handle, size_t idx);
// @category:read
ListDotGateWithNeighborsHandle DotGatesWithNeighbors_items(
    DotGatesWithNeighborsHandle handle);
// @category:read
bool DotGatesWithNeighbors_contains(DotGatesWithNeighborsHandle handle,
                                    DotGateWithNeighborsHandle  value);
// @category:read
size_t DotGatesWithNeighbors_index(DotGatesWithNeighborsHandle handle,
                                   DotGateWithNeighborsHandle  value);

#ifdef __cplusplus
}
#endif
```


