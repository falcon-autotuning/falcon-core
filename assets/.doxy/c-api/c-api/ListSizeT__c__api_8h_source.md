

# File ListSizeT\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListSizeT\_c\_api.h**](ListSizeT__c__api_8h.md)

[Go to the documentation of this file](ListSizeT__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListSizeTHandle;
// Function declarations

// @category:allocation
ListSizeTHandle ListSizeT_create_empty();
// @category:allocation
ListSizeTHandle ListSizeT_copy(ListSizeTHandle handle);
// @category:allocation
ListSizeTHandle ListSizeT_allocate(size_t count);
// @category:allocation
ListSizeTHandle ListSizeT_fill_value(size_t count, size_t value);
// @category:allocation
ListSizeTHandle ListSizeT_create(size_t* data, size_t count);
// @category:deallocation
void ListSizeT_destroy(ListSizeTHandle handle);
// @category:write
void ListSizeT_push_back(ListSizeTHandle handle, size_t value);
// @category:read
size_t ListSizeT_size(ListSizeTHandle handle);
// @category:read
bool ListSizeT_empty(ListSizeTHandle handle);
// @category:write
void ListSizeT_erase_at(ListSizeTHandle handle, size_t idx);
// @category:write
void ListSizeT_clear(ListSizeTHandle handle);
// @category:read
size_t ListSizeT_at(ListSizeTHandle handle, size_t idx);
// @category:read
size_t ListSizeT_items(ListSizeTHandle handle, size_t* out_buffer, size_t buffer_size);
// @category:read
bool ListSizeT_contains(ListSizeTHandle handle, size_t value);
// @category:read
size_t ListSizeT_index(ListSizeTHandle handle, size_t value);
// @category:read
ListSizeTHandle ListSizeT_intersection(ListSizeTHandle handle, ListSizeTHandle other);
// @category:read
bool ListSizeT_equal(ListSizeTHandle handle, ListSizeTHandle other);
// @category:read
bool ListSizeT_not_equal(ListSizeTHandle handle, ListSizeTHandle other);

// @category:read
StringHandle      ListSizeT_to_json_string(ListSizeTHandle handle);
// @category:allocation
ListSizeTHandle ListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


