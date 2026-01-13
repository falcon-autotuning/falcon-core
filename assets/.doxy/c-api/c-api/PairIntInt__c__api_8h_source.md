

# File PairIntInt\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairIntInt\_c\_api.h**](PairIntInt__c__api_8h.md)

[Go to the documentation of this file](PairIntInt__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairIntIntHandle;
// Function declarations

// @category:allocation
PairIntIntHandle PairIntInt_create(int first, int second);
// @category:allocation
PairIntIntHandle PairIntInt_copy(PairIntIntHandle handle);
// @category:deallocation
void PairIntInt_destroy(PairIntIntHandle handle);
// @category:read
int PairIntInt_first(PairIntIntHandle handle);
// @category:read
int PairIntInt_second(PairIntIntHandle handle);
// @category:read
bool PairIntInt_equal(PairIntIntHandle handle, PairIntIntHandle other);
// @category:read
bool PairIntInt_not_equal(PairIntIntHandle handle, PairIntIntHandle other);
// @category:read
StringHandle      PairIntInt_to_json_string(PairIntIntHandle handle);
// @category:allocation
PairIntIntHandle PairIntInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


