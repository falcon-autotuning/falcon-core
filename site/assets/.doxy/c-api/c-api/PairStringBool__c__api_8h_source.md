

# File PairStringBool\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairStringBool\_c\_api.h**](PairStringBool__c__api_8h.md)

[Go to the documentation of this file](PairStringBool__c__api_8h.md)


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
typedef void* PairStringBoolHandle;
// Function declarations

// @category:allocation
PairStringBoolHandle PairStringBool_create(StringHandle first, bool second);
// @category:allocation
PairStringBoolHandle PairStringBool_copy(PairStringBoolHandle handle);
// @category:deallocation
void PairStringBool_destroy(PairStringBoolHandle handle);
// @category:read
StringHandle PairStringBool_first(PairStringBoolHandle handle);
// @category:read
bool PairStringBool_second(PairStringBoolHandle handle);
// @category:read
bool PairStringBool_equal(PairStringBoolHandle handle, PairStringBoolHandle other);
// @category:read
bool PairStringBool_not_equal(PairStringBoolHandle handle, PairStringBoolHandle other);
// @category:read
StringHandle      PairStringBool_to_json_string(PairStringBoolHandle handle);
// @category:allocation
PairStringBoolHandle PairStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


