

# File Connection\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Connection\_c\_api.h**](Connection__c__api_8h.md)

[Go to the documentation of this file](Connection__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
typedef void* ConnectionHandle;

// @category:allocation
ConnectionHandle Connection_copy(ConnectionHandle handle);
// @category:deallocation
void Connection_destroy(ConnectionHandle handle);
// @category:read
bool Connection_equal(ConnectionHandle handle, ConnectionHandle other);
// @category:read
bool Connection_not_equal(ConnectionHandle handle, ConnectionHandle other);
// @category:read
StringHandle Connection_to_json_string(ConnectionHandle handle);
// @category:allocation
ConnectionHandle Connection_from_json_string(StringHandle json);
// @category:allocation
ConnectionHandle Connection_create_barrier_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_plunger_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_reservoir_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_screening_gate(StringHandle name);
// @category:allocation
ConnectionHandle Connection_create_ohmic(StringHandle name);
// @category:read
/* AUTO-DOC from cpp: Connection_name |
 * falcon_core::physics::device_structures::Connection::name */
StringHandle Connection_name(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_type |
 * falcon_core::physics::device_structures::Connection::type */
StringHandle Connection_type(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_dot_gate |
 * falcon_core::physics::device_structures::Connection::is_dot_gate */
bool Connection_is_dot_gate(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_barrier_gate |
 * falcon_core::physics::device_structures::Connection::is_barrier_gate */
bool Connection_is_barrier_gate(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_plunger_gate |
 * falcon_core::physics::device_structures::Connection::is_plunger_gate */
bool Connection_is_plunger_gate(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_reservoir_gate |
 * falcon_core::physics::device_structures::Connection::is_reservoir_gate */
bool Connection_is_reservoir_gate(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_screening_gate |
 * falcon_core::physics::device_structures::Connection::is_screening_gate */
bool Connection_is_screening_gate(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_ohmic |
 * falcon_core::physics::device_structures::Connection::is_ohmic */
bool Connection_is_ohmic(ConnectionHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connection_is_gate |
 * falcon_core::physics::device_structures::Connection::is_gate */
bool Connection_is_gate(ConnectionHandle handle);

#ifdef __cplusplus
}
#endif
```


