

# File ListImpedance\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListImpedance\_c\_api.h**](ListImpedance__c__api_8h.md)

[Go to the documentation of this file](ListImpedance__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Impedance_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListImpedanceHandle;
// Function declarations

// @category:allocation
ListImpedanceHandle ListImpedance_create_empty();
// @category:allocation
ListImpedanceHandle ListImpedance_copy(ListImpedanceHandle handle);

// @category:allocation
ListImpedanceHandle ListImpedance_fill_value(size_t count, ImpedanceHandle value);
// @category:allocation
ListImpedanceHandle ListImpedance_create(ImpedanceHandle* data, size_t count);
// @category:deallocation
void ListImpedance_destroy(ListImpedanceHandle handle);
// @category:write
void ListImpedance_push_back(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
size_t ListImpedance_size(ListImpedanceHandle handle);
// @category:read
bool ListImpedance_empty(ListImpedanceHandle handle);
// @category:write
void ListImpedance_erase_at(ListImpedanceHandle handle, size_t idx);
// @category:write
void ListImpedance_clear(ListImpedanceHandle handle);
// @category:read
ImpedanceHandle ListImpedance_at(ListImpedanceHandle handle, size_t idx);
// @category:read
size_t ListImpedance_items(ListImpedanceHandle handle, ImpedanceHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListImpedance_contains(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
size_t ListImpedance_index(ListImpedanceHandle handle, ImpedanceHandle value);
// @category:read
ListImpedanceHandle ListImpedance_intersection(ListImpedanceHandle handle, ListImpedanceHandle other);
// @category:read
bool ListImpedance_equal(ListImpedanceHandle handle, ListImpedanceHandle other);
// @category:read
bool ListImpedance_not_equal(ListImpedanceHandle handle, ListImpedanceHandle other);

// @category:read
StringHandle      ListImpedance_to_json_string(ListImpedanceHandle handle);
// @category:allocation
ListImpedanceHandle ListImpedance_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


