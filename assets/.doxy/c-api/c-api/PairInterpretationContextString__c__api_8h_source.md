

# File PairInterpretationContextString\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairInterpretationContextString\_c\_api.h**](PairInterpretationContextString__c__api_8h.md)

[Go to the documentation of this file](PairInterpretationContextString__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairInterpretationContextStringHandle;
// Function declarations

// @category:allocation
PairInterpretationContextStringHandle PairInterpretationContextString_create(InterpretationContextHandle first, StringHandle second);
// @category:allocation
PairInterpretationContextStringHandle PairInterpretationContextString_copy(PairInterpretationContextStringHandle handle);
// @category:deallocation
void PairInterpretationContextString_destroy(PairInterpretationContextStringHandle handle);
// @category:read
InterpretationContextHandle PairInterpretationContextString_first(PairInterpretationContextStringHandle handle);
// @category:read
StringHandle PairInterpretationContextString_second(PairInterpretationContextStringHandle handle);
// @category:read
bool PairInterpretationContextString_equal(PairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle other);
// @category:read
bool PairInterpretationContextString_not_equal(PairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle other);
// @category:read
StringHandle      PairInterpretationContextString_to_json_string(PairInterpretationContextStringHandle handle);
// @category:allocation
PairInterpretationContextStringHandle PairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


