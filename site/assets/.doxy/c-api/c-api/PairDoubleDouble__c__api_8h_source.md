

# File PairDoubleDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairDoubleDouble\_c\_api.h**](PairDoubleDouble__c__api_8h.md)

[Go to the documentation of this file](PairDoubleDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairDoubleDoubleHandle;
// Function declarations

// @category:allocation
PairDoubleDoubleHandle PairDoubleDouble_create(double first, double second);
// @category:allocation
PairDoubleDoubleHandle PairDoubleDouble_copy(PairDoubleDoubleHandle handle);
// @category:deallocation
void PairDoubleDouble_destroy(PairDoubleDoubleHandle handle);
// @category:read
double PairDoubleDouble_first(PairDoubleDoubleHandle handle);
// @category:read
double PairDoubleDouble_second(PairDoubleDoubleHandle handle);
// @category:read
bool PairDoubleDouble_equal(PairDoubleDoubleHandle handle, PairDoubleDoubleHandle other);
// @category:read
bool PairDoubleDouble_not_equal(PairDoubleDoubleHandle handle, PairDoubleDoubleHandle other);
// @category:read
StringHandle      PairDoubleDouble_to_json_string(PairDoubleDoubleHandle handle);
// @category:allocation
PairDoubleDoubleHandle PairDoubleDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


