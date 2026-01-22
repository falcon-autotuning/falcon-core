

# File ListMapStringBool\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListMapStringBool\_c\_api.h**](ListMapStringBool__c__api_8h.md)

[Go to the documentation of this file](ListMapStringBool__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/MapStringBool_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListMapStringBoolHandle;
// Function declarations

// @category:allocation
ListMapStringBoolHandle ListMapStringBool_create_empty();
// @category:allocation
ListMapStringBoolHandle ListMapStringBool_copy(ListMapStringBoolHandle handle);

// @category:allocation
ListMapStringBoolHandle ListMapStringBool_fill_value(size_t count, MapStringBoolHandle value);
// @category:allocation
ListMapStringBoolHandle ListMapStringBool_create(MapStringBoolHandle* data, size_t count);
// @category:deallocation
void ListMapStringBool_destroy(ListMapStringBoolHandle handle);
// @category:write
void ListMapStringBool_push_back(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
size_t ListMapStringBool_size(ListMapStringBoolHandle handle);
// @category:read
bool ListMapStringBool_empty(ListMapStringBoolHandle handle);
// @category:write
void ListMapStringBool_erase_at(ListMapStringBoolHandle handle, size_t idx);
// @category:write
void ListMapStringBool_clear(ListMapStringBoolHandle handle);
// @category:read
MapStringBoolHandle ListMapStringBool_at(ListMapStringBoolHandle handle, size_t idx);
// @category:read
size_t ListMapStringBool_items(ListMapStringBoolHandle handle, MapStringBoolHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListMapStringBool_contains(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
size_t ListMapStringBool_index(ListMapStringBoolHandle handle, MapStringBoolHandle value);
// @category:read
ListMapStringBoolHandle ListMapStringBool_intersection(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);
// @category:read
bool ListMapStringBool_equal(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);
// @category:read
bool ListMapStringBool_not_equal(ListMapStringBoolHandle handle, ListMapStringBoolHandle other);

// @category:read
StringHandle      ListMapStringBool_to_json_string(ListMapStringBoolHandle handle);
// @category:allocation
ListMapStringBoolHandle ListMapStringBool_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


