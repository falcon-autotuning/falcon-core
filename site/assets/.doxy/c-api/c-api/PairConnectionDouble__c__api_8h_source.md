

# File PairConnectionDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionDouble\_c\_api.h**](PairConnectionDouble__c__api_8h.md)

[Go to the documentation of this file](PairConnectionDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionDoubleHandle;
// Function declarations

// @category:allocation
PairConnectionDoubleHandle PairConnectionDouble_create(ConnectionHandle first, double second);
// @category:allocation
PairConnectionDoubleHandle PairConnectionDouble_copy(PairConnectionDoubleHandle handle);
// @category:deallocation
void PairConnectionDouble_destroy(PairConnectionDoubleHandle handle);
// @category:read
ConnectionHandle PairConnectionDouble_first(PairConnectionDoubleHandle handle);
// @category:read
double PairConnectionDouble_second(PairConnectionDoubleHandle handle);
// @category:read
bool PairConnectionDouble_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other);
// @category:read
bool PairConnectionDouble_not_equal(PairConnectionDoubleHandle handle, PairConnectionDoubleHandle other);
// @category:read
StringHandle      PairConnectionDouble_to_json_string(PairConnectionDoubleHandle handle);
// @category:allocation
PairConnectionDoubleHandle PairConnectionDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


