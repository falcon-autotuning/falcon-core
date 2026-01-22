

# File ListInterpretationContext\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListInterpretationContext\_c\_api.h**](ListInterpretationContext__c__api_8h.md)

[Go to the documentation of this file](ListInterpretationContext__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/interpretations/InterpretationContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListInterpretationContextHandle;
// Function declarations

// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_create_empty();
// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_copy(ListInterpretationContextHandle handle);

// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_fill_value(size_t count, InterpretationContextHandle value);
// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_create(InterpretationContextHandle* data, size_t count);
// @category:deallocation
void ListInterpretationContext_destroy(ListInterpretationContextHandle handle);
// @category:write
void ListInterpretationContext_push_back(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
size_t ListInterpretationContext_size(ListInterpretationContextHandle handle);
// @category:read
bool ListInterpretationContext_empty(ListInterpretationContextHandle handle);
// @category:write
void ListInterpretationContext_erase_at(ListInterpretationContextHandle handle, size_t idx);
// @category:write
void ListInterpretationContext_clear(ListInterpretationContextHandle handle);
// @category:read
InterpretationContextHandle ListInterpretationContext_at(ListInterpretationContextHandle handle, size_t idx);
// @category:read
size_t ListInterpretationContext_items(ListInterpretationContextHandle handle, InterpretationContextHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListInterpretationContext_contains(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
size_t ListInterpretationContext_index(ListInterpretationContextHandle handle, InterpretationContextHandle value);
// @category:read
ListInterpretationContextHandle ListInterpretationContext_intersection(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);
// @category:read
bool ListInterpretationContext_equal(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);
// @category:read
bool ListInterpretationContext_not_equal(ListInterpretationContextHandle handle, ListInterpretationContextHandle other);

// @category:read
StringHandle      ListInterpretationContext_to_json_string(ListInterpretationContextHandle handle);
// @category:allocation
ListInterpretationContextHandle ListInterpretationContext_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


