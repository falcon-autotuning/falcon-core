

# File AxesDiscretizer\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesDiscretizer\_c\_api.h**](AxesDiscretizer__c__api_8h.md)

[Go to the documentation of this file](AxesDiscretizer__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/discrete_spaces/Discretizer_c_api.h"
#include "falcon_core/generic/ListDiscretizer_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesDiscretizerHandle;
// Function declarations

// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_create_empty();
// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_copy(AxesDiscretizerHandle handle);
// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_create(ListDiscretizerHandle data);
// @category:deallocation
void AxesDiscretizer_destroy(AxesDiscretizerHandle handle);
// @category:write
void AxesDiscretizer_push_back(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
size_t AxesDiscretizer_size(AxesDiscretizerHandle handle);
// @category:read
bool AxesDiscretizer_empty(AxesDiscretizerHandle handle);
// @category:write
void AxesDiscretizer_erase_at(AxesDiscretizerHandle handle, size_t idx);
// @category:write
void AxesDiscretizer_clear(AxesDiscretizerHandle handle);
// @category:read
DiscretizerHandle AxesDiscretizer_at(AxesDiscretizerHandle handle, size_t idx);
// @category:read
size_t AxesDiscretizer_items(AxesDiscretizerHandle handle, DiscretizerHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesDiscretizer_contains(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
size_t AxesDiscretizer_index(AxesDiscretizerHandle handle, DiscretizerHandle value);
// @category:read
AxesDiscretizerHandle AxesDiscretizer_intersection(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);
// @category:read
bool AxesDiscretizer_equal(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);
// @category:read
bool AxesDiscretizer_not_equal(AxesDiscretizerHandle handle, AxesDiscretizerHandle other);

// @category:read
StringHandle      AxesDiscretizer_to_json_string(AxesDiscretizerHandle handle);
// @category:allocation
AxesDiscretizerHandle AxesDiscretizer_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


