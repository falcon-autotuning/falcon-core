

# File PairStringString\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairStringString\_c\_api.h**](PairStringString__c__api_8h.md)

[Go to the documentation of this file](PairStringString__c__api_8h.md)


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
typedef void* PairStringStringHandle;
// Function declarations

// @category:allocation
PairStringStringHandle PairStringString_create(StringHandle first, StringHandle second);
// @category:allocation
PairStringStringHandle PairStringString_copy(PairStringStringHandle handle);
// @category:deallocation
void PairStringString_destroy(PairStringStringHandle handle);
// @category:read
StringHandle PairStringString_first(PairStringStringHandle handle);
// @category:read
StringHandle PairStringString_second(PairStringStringHandle handle);
// @category:read
bool PairStringString_equal(PairStringStringHandle handle, PairStringStringHandle other);
// @category:read
bool PairStringString_not_equal(PairStringStringHandle handle, PairStringStringHandle other);
// @category:read
StringHandle      PairStringString_to_json_string(PairStringStringHandle handle);
// @category:allocation
PairStringStringHandle PairStringString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


