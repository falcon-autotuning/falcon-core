

# File ListDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDouble\_c\_api.h**](ListDouble__c__api_8h.md)

[Go to the documentation of this file](ListDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDoubleHandle;
// Function declarations

// @category:allocation
ListDoubleHandle ListDouble_create_empty();
// @category:allocation
ListDoubleHandle ListDouble_copy(ListDoubleHandle handle);
// @category:allocation
ListDoubleHandle ListDouble_allocate(size_t count);
// @category:allocation
ListDoubleHandle ListDouble_fill_value(size_t count, double value);
// @category:allocation
ListDoubleHandle ListDouble_create(double* data, size_t count);
// @category:deallocation
void ListDouble_destroy(ListDoubleHandle handle);
// @category:write
void ListDouble_push_back(ListDoubleHandle handle, double value);
// @category:read
size_t ListDouble_size(ListDoubleHandle handle);
// @category:read
bool ListDouble_empty(ListDoubleHandle handle);
// @category:write
void ListDouble_erase_at(ListDoubleHandle handle, size_t idx);
// @category:write
void ListDouble_clear(ListDoubleHandle handle);
// @category:read
double ListDouble_at(ListDoubleHandle handle, size_t idx);
// @category:read
size_t ListDouble_items(ListDoubleHandle handle, double* out_buffer, size_t buffer_size);
// @category:read
bool ListDouble_contains(ListDoubleHandle handle, double value);
// @category:read
size_t ListDouble_index(ListDoubleHandle handle, double value);
// @category:read
ListDoubleHandle ListDouble_intersection(ListDoubleHandle handle, ListDoubleHandle other);
// @category:read
bool ListDouble_equal(ListDoubleHandle handle, ListDoubleHandle other);
// @category:read
bool ListDouble_not_equal(ListDoubleHandle handle, ListDoubleHandle other);

// @category:read
StringHandle      ListDouble_to_json_string(ListDoubleHandle handle);
// @category:allocation
ListDoubleHandle ListDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


