

# File PairInterpretationContextDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInterpretationContextDouble\_c\_api.h**](PairInterpretationContextDouble__c__api_8h.md)

[Go to the documentation of this file](PairInterpretationContextDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextDoubleHandle;
// Function declarations

// @category:allocation
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_create(InterpretationContextHandle first, double second);
// @category:allocation
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_copy(PairInterpretationContextDoubleHandle handle);
// @category:deallocation
void PairInterpretationContextDouble_destroy(PairInterpretationContextDoubleHandle handle);
// @category:read
InterpretationContextHandle PairInterpretationContextDouble_first(PairInterpretationContextDoubleHandle handle);
// @category:read
double PairInterpretationContextDouble_second(PairInterpretationContextDoubleHandle handle);
// @category:read
bool PairInterpretationContextDouble_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other);
// @category:read
bool PairInterpretationContextDouble_not_equal(PairInterpretationContextDoubleHandle handle, PairInterpretationContextDoubleHandle other);
// @category:read
StringHandle      PairInterpretationContextDouble_to_json_string(PairInterpretationContextDoubleHandle handle);
// @category:allocation
PairInterpretationContextDoubleHandle PairInterpretationContextDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


