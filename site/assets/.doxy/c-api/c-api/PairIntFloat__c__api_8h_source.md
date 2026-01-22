

# File PairIntFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairIntFloat\_c\_api.h**](PairIntFloat__c__api_8h.md)

[Go to the documentation of this file](PairIntFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntFloatHandle;
// Function declarations

// @category:allocation
PairIntFloatHandle PairIntFloat_create(int first, float second);
// @category:allocation
PairIntFloatHandle PairIntFloat_copy(PairIntFloatHandle handle);
// @category:deallocation
void PairIntFloat_destroy(PairIntFloatHandle handle);
// @category:read
int PairIntFloat_first(PairIntFloatHandle handle);
// @category:read
float PairIntFloat_second(PairIntFloatHandle handle);
// @category:read
bool PairIntFloat_equal(PairIntFloatHandle handle, PairIntFloatHandle other);
// @category:read
bool PairIntFloat_not_equal(PairIntFloatHandle handle, PairIntFloatHandle other);
// @category:read
StringHandle      PairIntFloat_to_json_string(PairIntFloatHandle handle);
// @category:allocation
PairIntFloatHandle PairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


