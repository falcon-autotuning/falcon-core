

# File Connections\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Connections\_c\_api.h**](Connections__c__api_8h.md)

[Go to the documentation of this file](Connections__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ConnectionsHandle;

// @category:allocation
ConnectionsHandle Connections_copy(ConnectionsHandle handle);
// @category:deallocation
void Connections_destroy(ConnectionsHandle handle);
// @category:read
bool Connections_equal(ConnectionsHandle handle, ConnectionsHandle other);
// @category:read
bool Connections_not_equal(ConnectionsHandle handle, ConnectionsHandle other);
// @category:read
StringHandle Connections_to_json_string(ConnectionsHandle handle);
// @category:allocation
ConnectionsHandle Connections_from_json_string(StringHandle json);
// @category:allocation
ConnectionsHandle Connections_create_empty();
// @category:allocation
ConnectionsHandle Connections_create(ListConnectionHandle items);
// @category:read
/* AUTO-DOC from cpp: Connections_is_gates |
 * falcon_core::physics::device_structures::Connections::is_gates */
bool Connections_is_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_ohmics |
 * falcon_core::physics::device_structures::Connections::is_ohmics */
bool Connections_is_ohmics(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_dot_gates |
 * falcon_core::physics::device_structures::Connections::is_dot_gates */
bool Connections_is_dot_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_plunger_gates |
 * falcon_core::physics::device_structures::Connections::is_plunger_gates */
bool Connections_is_plunger_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_barrier_gates |
 * falcon_core::physics::device_structures::Connections::is_barrier_gates */
bool Connections_is_barrier_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_reservoir_gates |
 * falcon_core::physics::device_structures::Connections::is_reservoir_gates */
bool Connections_is_reservoir_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_screening_gates |
 * falcon_core::physics::device_structures::Connections::is_screening_gates */
bool Connections_is_screening_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_intersection |
 * falcon_core::physics::device_structures::Connections::intersection */
ConnectionsHandle Connections_intersection(ConnectionsHandle handle,
                                           ConnectionsHandle other);
// @category:write
void Connections_push_back(ConnectionsHandle handle, ConnectionHandle value);
// @category:read
size_t Connections_size(ConnectionsHandle handle);
// @category:read
bool Connections_empty(ConnectionsHandle handle);
// @category:write
void Connections_erase_at(ConnectionsHandle handle, size_t idx);
// @category:write
void Connections_clear(ConnectionsHandle handle);
// @category:read
ConnectionHandle Connections_at(ConnectionsHandle handle, size_t idx);
// @category:read
ListConnectionHandle Connections_items(ConnectionsHandle handle);
// @category:read
bool Connections_contains(ConnectionsHandle handle, ConnectionHandle value);
// @category:read
size_t Connections_index(ConnectionsHandle handle, ConnectionHandle value);

#ifdef __cplusplus
}
#endif
```


