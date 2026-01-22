

# File AxesDouble\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesDouble\_c\_api.h**](AxesDouble__c__api_8h.md)

[Go to the documentation of this file](AxesDouble__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListDouble_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesDoubleHandle;
// Function declarations

// @category:allocation
AxesDoubleHandle AxesDouble_create_empty();
// @category:allocation
AxesDoubleHandle AxesDouble_copy(AxesDoubleHandle handle);
// @category:allocation
AxesDoubleHandle AxesDouble_create(ListDoubleHandle data);
// @category:deallocation
void AxesDouble_destroy(AxesDoubleHandle handle);
// @category:write
void AxesDouble_push_back(AxesDoubleHandle handle, double value);
// @category:read
size_t AxesDouble_size(AxesDoubleHandle handle);
// @category:read
bool AxesDouble_empty(AxesDoubleHandle handle);
// @category:write
void AxesDouble_erase_at(AxesDoubleHandle handle, size_t idx);
// @category:write
void AxesDouble_clear(AxesDoubleHandle handle);
// @category:read
double AxesDouble_at(AxesDoubleHandle handle, size_t idx);
// @category:read
size_t AxesDouble_items(AxesDoubleHandle handle, double* out_buffer, size_t buffer_size);
// @category:read
bool AxesDouble_contains(AxesDoubleHandle handle, double value);
// @category:read
size_t AxesDouble_index(AxesDoubleHandle handle, double value);
// @category:read
AxesDoubleHandle AxesDouble_intersection(AxesDoubleHandle handle, AxesDoubleHandle other);
// @category:read
bool AxesDouble_equal(AxesDoubleHandle handle, AxesDoubleHandle other);
// @category:read
bool AxesDouble_not_equal(AxesDoubleHandle handle, AxesDoubleHandle other);

// @category:read
StringHandle      AxesDouble_to_json_string(AxesDoubleHandle handle);
// @category:allocation
AxesDoubleHandle AxesDouble_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


