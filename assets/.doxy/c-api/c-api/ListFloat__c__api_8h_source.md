

# File ListFloat\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListFloat\_c\_api.h**](ListFloat__c__api_8h.md)

[Go to the documentation of this file](ListFloat__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFloatHandle;
// Function declarations

// @category:allocation
ListFloatHandle ListFloat_create_empty();
// @category:allocation
ListFloatHandle ListFloat_copy(ListFloatHandle handle);
// @category:allocation
ListFloatHandle ListFloat_allocate(size_t count);
// @category:allocation
ListFloatHandle ListFloat_fill_value(size_t count, float value);
// @category:allocation
ListFloatHandle ListFloat_create(float* data, size_t count);
// @category:deallocation
void ListFloat_destroy(ListFloatHandle handle);
// @category:write
void ListFloat_push_back(ListFloatHandle handle, float value);
// @category:read
size_t ListFloat_size(ListFloatHandle handle);
// @category:read
bool ListFloat_empty(ListFloatHandle handle);
// @category:write
void ListFloat_erase_at(ListFloatHandle handle, size_t idx);
// @category:write
void ListFloat_clear(ListFloatHandle handle);
// @category:read
float ListFloat_at(ListFloatHandle handle, size_t idx);
// @category:read
size_t ListFloat_items(ListFloatHandle handle, float* out_buffer, size_t buffer_size);
// @category:read
bool ListFloat_contains(ListFloatHandle handle, float value);
// @category:read
size_t ListFloat_index(ListFloatHandle handle, float value);
// @category:read
ListFloatHandle ListFloat_intersection(ListFloatHandle handle, ListFloatHandle other);
// @category:read
bool ListFloat_equal(ListFloatHandle handle, ListFloatHandle other);
// @category:read
bool ListFloat_not_equal(ListFloatHandle handle, ListFloatHandle other);

// @category:read
StringHandle      ListFloat_to_json_string(ListFloatHandle handle);
// @category:allocation
ListFloatHandle ListFloat_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


