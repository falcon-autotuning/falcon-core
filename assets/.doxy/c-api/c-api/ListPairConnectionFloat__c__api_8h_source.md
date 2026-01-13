

# File ListPairConnectionFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPairConnectionFloat\_c\_api.h**](ListPairConnectionFloat__c__api_8h.md)

[Go to the documentation of this file](ListPairConnectionFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/PairConnectionFloat_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPairConnectionFloatHandle;
// Function declarations

// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_create_empty();
// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_copy(ListPairConnectionFloatHandle handle);

// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_fill_value(size_t count, PairConnectionFloatHandle value);
// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_create(PairConnectionFloatHandle* data, size_t count);
// @category:deallocation
void ListPairConnectionFloat_destroy(ListPairConnectionFloatHandle handle);
// @category:write
void ListPairConnectionFloat_push_back(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
size_t ListPairConnectionFloat_size(ListPairConnectionFloatHandle handle);
// @category:read
bool ListPairConnectionFloat_empty(ListPairConnectionFloatHandle handle);
// @category:write
void ListPairConnectionFloat_erase_at(ListPairConnectionFloatHandle handle, size_t idx);
// @category:write
void ListPairConnectionFloat_clear(ListPairConnectionFloatHandle handle);
// @category:read
PairConnectionFloatHandle ListPairConnectionFloat_at(ListPairConnectionFloatHandle handle, size_t idx);
// @category:read
size_t ListPairConnectionFloat_items(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPairConnectionFloat_contains(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
size_t ListPairConnectionFloat_index(ListPairConnectionFloatHandle handle, PairConnectionFloatHandle value);
// @category:read
ListPairConnectionFloatHandle ListPairConnectionFloat_intersection(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
// @category:read
bool ListPairConnectionFloat_equal(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);
// @category:read
bool ListPairConnectionFloat_not_equal(ListPairConnectionFloatHandle handle, ListPairConnectionFloatHandle other);

// @category:read
StringHandle      ListPairConnectionFloat_to_json_string(ListPairConnectionFloatHandle handle);
// @category:allocation
ListPairConnectionFloatHandle ListPairConnectionFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


