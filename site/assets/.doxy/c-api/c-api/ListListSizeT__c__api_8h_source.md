

# File ListListSizeT\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListListSizeT\_c\_api.h**](ListListSizeT__c__api_8h.md)

[Go to the documentation of this file](ListListSizeT__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListSizeT_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListListSizeTHandle;
// Function declarations

// @category:allocation
ListListSizeTHandle ListListSizeT_create_empty();
// @category:allocation
ListListSizeTHandle ListListSizeT_copy(ListListSizeTHandle handle);

// @category:allocation
ListListSizeTHandle ListListSizeT_fill_value(size_t count, ListSizeTHandle value);
// @category:allocation
ListListSizeTHandle ListListSizeT_create(ListSizeTHandle* data, size_t count);
// @category:deallocation
void ListListSizeT_destroy(ListListSizeTHandle handle);
// @category:write
void ListListSizeT_push_back(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
size_t ListListSizeT_size(ListListSizeTHandle handle);
// @category:read
bool ListListSizeT_empty(ListListSizeTHandle handle);
// @category:write
void ListListSizeT_erase_at(ListListSizeTHandle handle, size_t idx);
// @category:write
void ListListSizeT_clear(ListListSizeTHandle handle);
// @category:read
ListSizeTHandle ListListSizeT_at(ListListSizeTHandle handle, size_t idx);
// @category:read
size_t ListListSizeT_items(ListListSizeTHandle handle, ListSizeTHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListListSizeT_contains(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
size_t ListListSizeT_index(ListListSizeTHandle handle, ListSizeTHandle value);
// @category:read
ListListSizeTHandle ListListSizeT_intersection(ListListSizeTHandle handle, ListListSizeTHandle other);
// @category:read
bool ListListSizeT_equal(ListListSizeTHandle handle, ListListSizeTHandle other);
// @category:read
bool ListListSizeT_not_equal(ListListSizeTHandle handle, ListListSizeTHandle other);

// @category:read
StringHandle      ListListSizeT_to_json_string(ListListSizeTHandle handle);
// @category:allocation
ListListSizeTHandle ListListSizeT_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


