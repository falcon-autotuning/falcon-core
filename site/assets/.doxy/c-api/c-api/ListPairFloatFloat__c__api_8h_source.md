

# File ListPairFloatFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairFloatFloat\_c\_api.h**](ListPairFloatFloat__c__api_8h.md)

[Go to the documentation of this file](ListPairFloatFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairFloatFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairFloatFloatHandle;
// Function declarations

// @category:allocation
ListPairFloatFloatHandle ListPairFloatFloat_create_empty();
// @category:allocation
ListPairFloatFloatHandle ListPairFloatFloat_copy(ListPairFloatFloatHandle handle);

// @category:allocation
ListPairFloatFloatHandle ListPairFloatFloat_fill_value(size_t count, PairFloatFloatHandle value);
// @category:allocation
ListPairFloatFloatHandle ListPairFloatFloat_create(PairFloatFloatHandle* data, size_t count);
// @category:deallocation
void ListPairFloatFloat_destroy(ListPairFloatFloatHandle handle);
// @category:write
void ListPairFloatFloat_push_back(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
// @category:read
size_t ListPairFloatFloat_size(ListPairFloatFloatHandle handle);
// @category:read
bool ListPairFloatFloat_empty(ListPairFloatFloatHandle handle);
// @category:write
void ListPairFloatFloat_erase_at(ListPairFloatFloatHandle handle, size_t idx);
// @category:write
void ListPairFloatFloat_clear(ListPairFloatFloatHandle handle);
// @category:read
PairFloatFloatHandle ListPairFloatFloat_at(ListPairFloatFloatHandle handle, size_t idx);
// @category:read
size_t ListPairFloatFloat_items(ListPairFloatFloatHandle handle, PairFloatFloatHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairFloatFloat_contains(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
// @category:read
size_t ListPairFloatFloat_index(ListPairFloatFloatHandle handle, PairFloatFloatHandle value);
// @category:read
ListPairFloatFloatHandle ListPairFloatFloat_intersection(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);
// @category:read
bool ListPairFloatFloat_equal(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);
// @category:read
bool ListPairFloatFloat_not_equal(ListPairFloatFloatHandle handle, ListPairFloatFloatHandle other);

// @category:read
StringHandle      ListPairFloatFloat_to_json_string(ListPairFloatFloatHandle handle);
// @category:allocation
ListPairFloatFloatHandle ListPairFloatFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


