

# File PairFloatFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairFloatFloat\_c\_api.h**](PairFloatFloat__c__api_8h.md)

[Go to the documentation of this file](PairFloatFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairFloatFloatHandle;
// Function declarations

// @category:allocation
PairFloatFloatHandle PairFloatFloat_create(float first, float second);
// @category:allocation
PairFloatFloatHandle PairFloatFloat_copy(PairFloatFloatHandle handle);
// @category:deallocation
void PairFloatFloat_destroy(PairFloatFloatHandle handle);
// @category:read
float PairFloatFloat_first(PairFloatFloatHandle handle);
// @category:read
float PairFloatFloat_second(PairFloatFloatHandle handle);
// @category:read
bool PairFloatFloat_equal(PairFloatFloatHandle handle, PairFloatFloatHandle other);
// @category:read
bool PairFloatFloat_not_equal(PairFloatFloatHandle handle, PairFloatFloatHandle other);
// @category:read
StringHandle      PairFloatFloat_to_json_string(PairFloatFloatHandle handle);
// @category:allocation
PairFloatFloatHandle PairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


