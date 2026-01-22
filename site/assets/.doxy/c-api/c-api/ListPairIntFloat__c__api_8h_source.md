

# File ListPairIntFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairIntFloat\_c\_api.h**](ListPairIntFloat__c__api_8h.md)

[Go to the documentation of this file](ListPairIntFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairIntFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairIntFloatHandle;
// Function declarations

// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_create_empty();
// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_copy(ListPairIntFloatHandle handle);

// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_fill_value(size_t count, PairIntFloatHandle value);
// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_create(PairIntFloatHandle* data, size_t count);
// @category:deallocation
void ListPairIntFloat_destroy(ListPairIntFloatHandle handle);
// @category:write
void ListPairIntFloat_push_back(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
size_t ListPairIntFloat_size(ListPairIntFloatHandle handle);
// @category:read
bool ListPairIntFloat_empty(ListPairIntFloatHandle handle);
// @category:write
void ListPairIntFloat_erase_at(ListPairIntFloatHandle handle, size_t idx);
// @category:write
void ListPairIntFloat_clear(ListPairIntFloatHandle handle);
// @category:read
PairIntFloatHandle ListPairIntFloat_at(ListPairIntFloatHandle handle, size_t idx);
// @category:read
size_t ListPairIntFloat_items(ListPairIntFloatHandle handle, PairIntFloatHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairIntFloat_contains(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
size_t ListPairIntFloat_index(ListPairIntFloatHandle handle, PairIntFloatHandle value);
// @category:read
ListPairIntFloatHandle ListPairIntFloat_intersection(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
// @category:read
bool ListPairIntFloat_equal(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);
// @category:read
bool ListPairIntFloat_not_equal(ListPairIntFloatHandle handle, ListPairIntFloatHandle other);

// @category:read
StringHandle      ListPairIntFloat_to_json_string(ListPairIntFloatHandle handle);
// @category:allocation
ListPairIntFloatHandle ListPairIntFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


