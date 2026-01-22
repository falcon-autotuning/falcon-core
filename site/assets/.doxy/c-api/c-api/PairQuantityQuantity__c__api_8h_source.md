

# File PairQuantityQuantity\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairQuantityQuantity\_c\_api.h**](PairQuantityQuantity__c__api_8h.md)

[Go to the documentation of this file](PairQuantityQuantity__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairQuantityQuantityHandle;
// Function declarations

// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_create(QuantityHandle first, QuantityHandle second);
// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_copy(PairQuantityQuantityHandle handle);
// @category:deallocation
void PairQuantityQuantity_destroy(PairQuantityQuantityHandle handle);
// @category:read
QuantityHandle PairQuantityQuantity_first(PairQuantityQuantityHandle handle);
// @category:read
QuantityHandle PairQuantityQuantity_second(PairQuantityQuantityHandle handle);
// @category:read
bool PairQuantityQuantity_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other);
// @category:read
bool PairQuantityQuantity_not_equal(PairQuantityQuantityHandle handle, PairQuantityQuantityHandle other);
// @category:read
StringHandle      PairQuantityQuantity_to_json_string(PairQuantityQuantityHandle handle);
// @category:allocation
PairQuantityQuantityHandle PairQuantityQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


