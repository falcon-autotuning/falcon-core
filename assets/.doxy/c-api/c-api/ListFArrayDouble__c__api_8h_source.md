

# File ListFArrayDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListFArrayDouble\_c\_api.h**](ListFArrayDouble__c__api_8h.md)

[Go to the documentation of this file](ListFArrayDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/FArrayDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListFArrayDoubleHandle;
// Function declarations

// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_create_empty();
// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_copy(ListFArrayDoubleHandle handle);

// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_fill_value(size_t count, FArrayDoubleHandle value);
// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_create(FArrayDoubleHandle* data, size_t count);
// @category:deallocation
void ListFArrayDouble_destroy(ListFArrayDoubleHandle handle);
// @category:write
void ListFArrayDouble_push_back(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
size_t ListFArrayDouble_size(ListFArrayDoubleHandle handle);
// @category:read
bool ListFArrayDouble_empty(ListFArrayDoubleHandle handle);
// @category:write
void ListFArrayDouble_erase_at(ListFArrayDoubleHandle handle, size_t idx);
// @category:write
void ListFArrayDouble_clear(ListFArrayDoubleHandle handle);
// @category:read
FArrayDoubleHandle ListFArrayDouble_at(ListFArrayDoubleHandle handle, size_t idx);
// @category:read
size_t ListFArrayDouble_items(ListFArrayDoubleHandle handle, FArrayDoubleHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListFArrayDouble_contains(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
size_t ListFArrayDouble_index(ListFArrayDoubleHandle handle, FArrayDoubleHandle value);
// @category:read
ListFArrayDoubleHandle ListFArrayDouble_intersection(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);
// @category:read
bool ListFArrayDouble_equal(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);
// @category:read
bool ListFArrayDouble_not_equal(ListFArrayDoubleHandle handle, ListFArrayDoubleHandle other);

// @category:read
StringHandle      ListFArrayDouble_to_json_string(ListFArrayDoubleHandle handle);
// @category:allocation
ListFArrayDoubleHandle ListFArrayDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


