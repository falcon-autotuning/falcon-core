

# File PairStringDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairStringDouble\_c\_api.h**](PairStringDouble__c__api_8h.md)

[Go to the documentation of this file](PairStringDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairStringDoubleHandle;
// Function declarations

// @category:allocation
PairStringDoubleHandle PairStringDouble_create(StringHandle first, double second);
// @category:allocation
PairStringDoubleHandle PairStringDouble_copy(PairStringDoubleHandle handle);
// @category:deallocation
void PairStringDouble_destroy(PairStringDoubleHandle handle);
// @category:read
StringHandle PairStringDouble_first(PairStringDoubleHandle handle);
// @category:read
double PairStringDouble_second(PairStringDoubleHandle handle);
// @category:read
bool PairStringDouble_equal(PairStringDoubleHandle handle, PairStringDoubleHandle other);
// @category:read
bool PairStringDouble_not_equal(PairStringDoubleHandle handle, PairStringDoubleHandle other);
// @category:read
StringHandle      PairStringDouble_to_json_string(PairStringDoubleHandle handle);
// @category:allocation
PairStringDoubleHandle PairStringDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


