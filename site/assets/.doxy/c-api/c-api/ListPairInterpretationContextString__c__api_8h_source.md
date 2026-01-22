

# File ListPairInterpretationContextString\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairInterpretationContextString\_c\_api.h**](ListPairInterpretationContextString__c__api_8h.md)

[Go to the documentation of this file](ListPairInterpretationContextString__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairInterpretationContextString_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairInterpretationContextStringHandle;
// Function declarations

// @category:allocation
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create_empty();
// @category:allocation
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_copy(ListPairInterpretationContextStringHandle handle);

// @category:allocation
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_fill_value(size_t count, PairInterpretationContextStringHandle value);
// @category:allocation
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_create(PairInterpretationContextStringHandle* data, size_t count);
// @category:deallocation
void ListPairInterpretationContextString_destroy(ListPairInterpretationContextStringHandle handle);
// @category:write
void ListPairInterpretationContextString_push_back(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
// @category:read
size_t ListPairInterpretationContextString_size(ListPairInterpretationContextStringHandle handle);
// @category:read
bool ListPairInterpretationContextString_empty(ListPairInterpretationContextStringHandle handle);
// @category:write
void ListPairInterpretationContextString_erase_at(ListPairInterpretationContextStringHandle handle, size_t idx);
// @category:write
void ListPairInterpretationContextString_clear(ListPairInterpretationContextStringHandle handle);
// @category:read
PairInterpretationContextStringHandle ListPairInterpretationContextString_at(ListPairInterpretationContextStringHandle handle, size_t idx);
// @category:read
size_t ListPairInterpretationContextString_items(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairInterpretationContextString_contains(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
// @category:read
size_t ListPairInterpretationContextString_index(ListPairInterpretationContextStringHandle handle, PairInterpretationContextStringHandle value);
// @category:read
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_intersection(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);
// @category:read
bool ListPairInterpretationContextString_equal(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);
// @category:read
bool ListPairInterpretationContextString_not_equal(ListPairInterpretationContextStringHandle handle, ListPairInterpretationContextStringHandle other);

// @category:read
StringHandle      ListPairInterpretationContextString_to_json_string(ListPairInterpretationContextStringHandle handle);
// @category:allocation
ListPairInterpretationContextStringHandle ListPairInterpretationContextString_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


