

# File ListBool\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListBool\_c\_api.h**](ListBool__c__api_8h.md)

[Go to the documentation of this file](ListBool__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListBoolHandle;
// Function declarations

// @category:allocation
ListBoolHandle ListBool_create_empty();
// @category:allocation
ListBoolHandle ListBool_copy(ListBoolHandle handle);
// @category:allocation
ListBoolHandle ListBool_allocate(size_t count);
// @category:allocation
ListBoolHandle ListBool_fill_value(size_t count, bool value);
// @category:allocation
ListBoolHandle ListBool_create(bool* data, size_t count);
// @category:deallocation
void ListBool_destroy(ListBoolHandle handle);
// @category:write
void ListBool_push_back(ListBoolHandle handle, bool value);
// @category:read
size_t ListBool_size(ListBoolHandle handle);
// @category:read
bool ListBool_empty(ListBoolHandle handle);
// @category:write
void ListBool_erase_at(ListBoolHandle handle, size_t idx);
// @category:write
void ListBool_clear(ListBoolHandle handle);
// @category:read
bool ListBool_at(ListBoolHandle handle, size_t idx);
// @category:read
size_t ListBool_items(ListBoolHandle handle, bool* out_buffer, size_t buffer_size);
// @category:read
bool ListBool_contains(ListBoolHandle handle, bool value);
// @category:read
size_t ListBool_index(ListBoolHandle handle, bool value);
// @category:read
ListBoolHandle ListBool_intersection(ListBoolHandle handle, ListBoolHandle other);
// @category:read
bool ListBool_equal(ListBoolHandle handle, ListBoolHandle other);
// @category:read
bool ListBool_not_equal(ListBoolHandle handle, ListBoolHandle other);

// @category:read
StringHandle      ListBool_to_json_string(ListBoolHandle handle);
// @category:allocation
ListBoolHandle ListBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


