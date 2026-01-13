

# File PairConnectionFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairConnectionFloat\_c\_api.h**](PairConnectionFloat__c__api_8h.md)

[Go to the documentation of this file](PairConnectionFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionFloatHandle;
// Function declarations

// @category:allocation
PairConnectionFloatHandle PairConnectionFloat_create(ConnectionHandle first, float second);
// @category:allocation
PairConnectionFloatHandle PairConnectionFloat_copy(PairConnectionFloatHandle handle);
// @category:deallocation
void PairConnectionFloat_destroy(PairConnectionFloatHandle handle);
// @category:read
ConnectionHandle PairConnectionFloat_first(PairConnectionFloatHandle handle);
// @category:read
float PairConnectionFloat_second(PairConnectionFloatHandle handle);
// @category:read
bool PairConnectionFloat_equal(PairConnectionFloatHandle handle, PairConnectionFloatHandle other);
// @category:read
bool PairConnectionFloat_not_equal(PairConnectionFloatHandle handle, PairConnectionFloatHandle other);
// @category:read
StringHandle      PairConnectionFloat_to_json_string(PairConnectionFloatHandle handle);
// @category:allocation
PairConnectionFloatHandle PairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


