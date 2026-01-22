

# File PairInterpretationContextQuantity\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInterpretationContextQuantity\_c\_api.h**](PairInterpretationContextQuantity__c__api_8h.md)

[Go to the documentation of this file](PairInterpretationContextQuantity__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include "falcon_core/math/Quantity_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextQuantityHandle;
// Function declarations

// @category:allocation
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_create(InterpretationContextHandle first, QuantityHandle second);
// @category:allocation
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_copy(PairInterpretationContextQuantityHandle handle);
// @category:deallocation
void PairInterpretationContextQuantity_destroy(PairInterpretationContextQuantityHandle handle);
// @category:read
InterpretationContextHandle PairInterpretationContextQuantity_first(PairInterpretationContextQuantityHandle handle);
// @category:read
QuantityHandle PairInterpretationContextQuantity_second(PairInterpretationContextQuantityHandle handle);
// @category:read
bool PairInterpretationContextQuantity_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other);
// @category:read
bool PairInterpretationContextQuantity_not_equal(PairInterpretationContextQuantityHandle handle, PairInterpretationContextQuantityHandle other);
// @category:read
StringHandle      PairInterpretationContextQuantity_to_json_string(PairInterpretationContextQuantityHandle handle);
// @category:allocation
PairInterpretationContextQuantityHandle PairInterpretationContextQuantity_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


