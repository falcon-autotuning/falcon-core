

# File VoltageConstraints\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**VoltageConstraints\_c\_api.h**](VoltageConstraints__c__api_8h.md)

[Go to the documentation of this file](VoltageConstraints__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/FArrayDouble_c_api.h"
#include "falcon_core/generic/PairDoubleDouble_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Adjacency_c_api.h"
typedef void* VoltageConstraintsHandle;

// @category:allocation
VoltageConstraintsHandle VoltageConstraints_copy(
    VoltageConstraintsHandle handle);
// @category:deallocation
void VoltageConstraints_destroy(VoltageConstraintsHandle handle);
// @category:read
bool VoltageConstraints_equal(VoltageConstraintsHandle handle,
                              VoltageConstraintsHandle other);
// @category:read
bool VoltageConstraints_not_equal(VoltageConstraintsHandle handle,
                                  VoltageConstraintsHandle other);
// @category:read
StringHandle VoltageConstraints_to_json_string(VoltageConstraintsHandle handle);
// @category:allocation
VoltageConstraintsHandle VoltageConstraints_from_json_string(StringHandle json);
// @category:allocation
VoltageConstraintsHandle VoltageConstraints_create(
    AdjacencyHandle        adjacency,
    double                 max_safe_diff,
    PairDoubleDoubleHandle bounds);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_matrix |
 * falcon_core::physics::config::core::VoltageConstraints::matrix */
FArrayDoubleHandle VoltageConstraints_matrix(VoltageConstraintsHandle handle);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_adjacency |
 * falcon_core::physics::config::core::VoltageConstraints::adjacency */
AdjacencyHandle VoltageConstraints_adjacency(VoltageConstraintsHandle handle);
// @category:read
/* AUTO-DOC from cpp: VoltageConstraints_limits |
 * falcon_core::physics::config::core::VoltageConstraints::limits */
FArrayDoubleHandle VoltageConstraints_limits(VoltageConstraintsHandle handle);

#ifdef __cplusplus
}
#endif
```


