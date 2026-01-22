

# File AxesControlArray\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesControlArray\_c\_api.h**](AxesControlArray__c__api_8h.md)

[Go to the documentation of this file](AxesControlArray__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/ControlArray_c_api.h"
#include "falcon_core/generic/ListControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesControlArrayHandle;
// Function declarations

// @category:allocation
AxesControlArrayHandle AxesControlArray_create_empty();
// @category:allocation
AxesControlArrayHandle AxesControlArray_copy(AxesControlArrayHandle handle);
// @category:allocation
AxesControlArrayHandle AxesControlArray_create(ListControlArrayHandle data);
// @category:deallocation
void AxesControlArray_destroy(AxesControlArrayHandle handle);
// @category:write
void AxesControlArray_push_back(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
size_t AxesControlArray_size(AxesControlArrayHandle handle);
// @category:read
bool AxesControlArray_empty(AxesControlArrayHandle handle);
// @category:write
void AxesControlArray_erase_at(AxesControlArrayHandle handle, size_t idx);
// @category:write
void AxesControlArray_clear(AxesControlArrayHandle handle);
// @category:read
ControlArrayHandle AxesControlArray_at(AxesControlArrayHandle handle, size_t idx);
// @category:read
size_t AxesControlArray_items(AxesControlArrayHandle handle, ControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesControlArray_contains(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
size_t AxesControlArray_index(AxesControlArrayHandle handle, ControlArrayHandle value);
// @category:read
AxesControlArrayHandle AxesControlArray_intersection(AxesControlArrayHandle handle, AxesControlArrayHandle other);
// @category:read
bool AxesControlArray_equal(AxesControlArrayHandle handle, AxesControlArrayHandle other);
// @category:read
bool AxesControlArray_not_equal(AxesControlArrayHandle handle, AxesControlArrayHandle other);

// @category:read
StringHandle      AxesControlArray_to_json_string(AxesControlArrayHandle handle);
// @category:allocation
AxesControlArrayHandle AxesControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


