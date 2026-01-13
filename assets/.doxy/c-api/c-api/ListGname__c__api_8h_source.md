

# File ListGname\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListGname\_c\_api.h**](ListGname__c__api_8h.md)

[Go to the documentation of this file](ListGname__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListGnameHandle;
// Function declarations

// @category:allocation
ListGnameHandle ListGname_create_empty();
// @category:allocation
ListGnameHandle ListGname_copy(ListGnameHandle handle);

// @category:allocation
ListGnameHandle ListGname_fill_value(size_t count, GnameHandle value);
// @category:allocation
ListGnameHandle ListGname_create(GnameHandle* data, size_t count);
// @category:deallocation
void ListGname_destroy(ListGnameHandle handle);
// @category:write
void ListGname_push_back(ListGnameHandle handle, GnameHandle value);
// @category:read
size_t ListGname_size(ListGnameHandle handle);
// @category:read
bool ListGname_empty(ListGnameHandle handle);
// @category:write
void ListGname_erase_at(ListGnameHandle handle, size_t idx);
// @category:write
void ListGname_clear(ListGnameHandle handle);
// @category:read
GnameHandle ListGname_at(ListGnameHandle handle, size_t idx);
// @category:read
size_t ListGname_items(ListGnameHandle handle, GnameHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListGname_contains(ListGnameHandle handle, GnameHandle value);
// @category:read
size_t ListGname_index(ListGnameHandle handle, GnameHandle value);
// @category:read
ListGnameHandle ListGname_intersection(ListGnameHandle handle, ListGnameHandle other);
// @category:read
bool ListGname_equal(ListGnameHandle handle, ListGnameHandle other);
// @category:read
bool ListGname_not_equal(ListGnameHandle handle, ListGnameHandle other);

// @category:read
StringHandle      ListGname_to_json_string(ListGnameHandle handle);
// @category:allocation
ListGnameHandle ListGname_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


