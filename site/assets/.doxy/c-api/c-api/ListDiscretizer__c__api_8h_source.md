

# File ListDiscretizer\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListDiscretizer\_c\_api.h**](ListDiscretizer__c__api_8h.md)

[Go to the documentation of this file](ListDiscretizer__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListDiscretizerHandle;
// Function declarations

// @category:allocation
ListDiscretizerHandle ListDiscretizer_create_empty();
// @category:allocation
ListDiscretizerHandle ListDiscretizer_copy(ListDiscretizerHandle handle);

// @category:allocation
ListDiscretizerHandle ListDiscretizer_fill_value(size_t count, DiscretizerHandle value);
// @category:allocation
ListDiscretizerHandle ListDiscretizer_create(DiscretizerHandle* data, size_t count);
// @category:deallocation
void ListDiscretizer_destroy(ListDiscretizerHandle handle);
// @category:write
void ListDiscretizer_push_back(ListDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
size_t ListDiscretizer_size(ListDiscretizerHandle handle);
// @category:read
bool ListDiscretizer_empty(ListDiscretizerHandle handle);
// @category:write
void ListDiscretizer_erase_at(ListDiscretizerHandle handle, size_t idx);
// @category:write
void ListDiscretizer_clear(ListDiscretizerHandle handle);
// @category:read
DiscretizerHandle ListDiscretizer_at(ListDiscretizerHandle handle, size_t idx);
// @category:read
size_t ListDiscretizer_items(ListDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListDiscretizer_contains(ListDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
size_t ListDiscretizer_index(ListDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
ListDiscretizerHandle ListDiscretizer_intersection(ListDiscretizerHandle handle, ListDiscretizerHandle other);
// @category:read
bool ListDiscretizer_equal(ListDiscretizerHandle handle, ListDiscretizerHandle other);
// @category:read
bool ListDiscretizer_not_equal(ListDiscretizerHandle handle, ListDiscretizerHandle other);

// @category:read
StringHandle      ListDiscretizer_to_json_string(ListDiscretizerHandle handle);
// @category:allocation
ListDiscretizerHandle ListDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


