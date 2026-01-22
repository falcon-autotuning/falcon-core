

# File Impedance\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**device\_structures**](dir_8f58be43a4a4299c8fba030674c04b93.md) **>** [**Impedance\_c\_api.h**](Impedance__c__api_8h.md)

[Go to the documentation of this file](Impedance__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ImpedanceHandle;

// @category:allocation
ImpedanceHandle Impedance_copy(ImpedanceHandle handle);
// @category:deallocation
void Impedance_destroy(ImpedanceHandle handle);
// @category:read
bool Impedance_equal(ImpedanceHandle handle, ImpedanceHandle other);
// @category:read
bool Impedance_not_equal(ImpedanceHandle handle, ImpedanceHandle other);
// @category:read
StringHandle Impedance_to_json_string(ImpedanceHandle handle);
// @category:allocation
ImpedanceHandle Impedance_from_json_string(StringHandle json);
// @category:allocation
ImpedanceHandle Impedance_create(ConnectionHandle connection,
                                 double           resistance,
                                 double           capacitance);
// @category:read
/* AUTO-DOC from cpp: Impedance_connection |
 * falcon_core::physics::device_structures::Impedance::connection */
ConnectionHandle Impedance_connection(ImpedanceHandle handle);
// @category:read
/* AUTO-DOC from cpp: Impedance_resistance |
 * falcon_core::physics::device_structures::Impedance::resistance */
double Impedance_resistance(ImpedanceHandle handle);
// @category:read
/* AUTO-DOC from cpp: Impedance_capacitance |
 * falcon_core::physics::device_structures::Impedance::capacitance */
double Impedance_capacitance(ImpedanceHandle handle);

#ifdef __cplusplus
}
#endif
```


