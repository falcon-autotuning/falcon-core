

# File ListPortTransform\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListPortTransform\_c\_api.h**](ListPortTransform__c__api_8h.md)

[Go to the documentation of this file](ListPortTransform__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListPortTransformHandle;
// Function declarations

// @category:allocation
ListPortTransformHandle ListPortTransform_create_empty();
// @category:allocation
ListPortTransformHandle ListPortTransform_copy(ListPortTransformHandle handle);

// @category:allocation
ListPortTransformHandle ListPortTransform_fill_value(size_t count, PortTransformHandle value);
// @category:allocation
ListPortTransformHandle ListPortTransform_create(PortTransformHandle* data, size_t count);
// @category:deallocation
void ListPortTransform_destroy(ListPortTransformHandle handle);
// @category:write
void ListPortTransform_push_back(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
size_t ListPortTransform_size(ListPortTransformHandle handle);
// @category:read
bool ListPortTransform_empty(ListPortTransformHandle handle);
// @category:write
void ListPortTransform_erase_at(ListPortTransformHandle handle, size_t idx);
// @category:write
void ListPortTransform_clear(ListPortTransformHandle handle);
// @category:read
PortTransformHandle ListPortTransform_at(ListPortTransformHandle handle, size_t idx);
// @category:read
size_t ListPortTransform_items(ListPortTransformHandle handle, PortTransformHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListPortTransform_contains(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
size_t ListPortTransform_index(ListPortTransformHandle handle, PortTransformHandle value);
// @category:read
ListPortTransformHandle ListPortTransform_intersection(ListPortTransformHandle handle, ListPortTransformHandle other);
// @category:read
bool ListPortTransform_equal(ListPortTransformHandle handle, ListPortTransformHandle other);
// @category:read
bool ListPortTransform_not_equal(ListPortTransformHandle handle, ListPortTransformHandle other);

// @category:read
StringHandle      ListPortTransform_to_json_string(ListPortTransformHandle handle);
// @category:allocation
ListPortTransformHandle ListPortTransform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


