

# File ListControlArray\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListControlArray\_c\_api.h**](ListControlArray__c__api_8h.md)

[Go to the documentation of this file](ListControlArray__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListControlArrayHandle;
// Function declarations

// @category:allocation
ListControlArrayHandle ListControlArray_create_empty();
// @category:allocation
ListControlArrayHandle ListControlArray_copy(ListControlArrayHandle handle);

// @category:allocation
ListControlArrayHandle ListControlArray_fill_value(size_t count, ControlArrayHandle value);
// @category:allocation
ListControlArrayHandle ListControlArray_create(ControlArrayHandle* data, size_t count);
// @category:deallocation
void ListControlArray_destroy(ListControlArrayHandle handle);
// @category:write
void ListControlArray_push_back(ListControlArrayHandle handle, ControlArrayHandle value);
// @category:read
size_t ListControlArray_size(ListControlArrayHandle handle);
// @category:read
bool ListControlArray_empty(ListControlArrayHandle handle);
// @category:write
void ListControlArray_erase_at(ListControlArrayHandle handle, size_t idx);
// @category:write
void ListControlArray_clear(ListControlArrayHandle handle);
// @category:read
ControlArrayHandle ListControlArray_at(ListControlArrayHandle handle, size_t idx);
// @category:read
size_t ListControlArray_items(ListControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListControlArray_contains(ListControlArrayHandle handle, ControlArrayHandle value);
// @category:read
size_t ListControlArray_index(ListControlArrayHandle handle, ControlArrayHandle value);
// @category:read
ListControlArrayHandle ListControlArray_intersection(ListControlArrayHandle handle, ListControlArrayHandle other);
// @category:read
bool ListControlArray_equal(ListControlArrayHandle handle, ListControlArrayHandle other);
// @category:read
bool ListControlArray_not_equal(ListControlArrayHandle handle, ListControlArrayHandle other);

// @category:read
StringHandle      ListControlArray_to_json_string(ListControlArrayHandle handle);
// @category:allocation
ListControlArrayHandle ListControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


