

# File AxesInt\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesInt\_c\_api.h**](AxesInt__c__api_8h.md)

[Go to the documentation of this file](AxesInt__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListInt_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesIntHandle;
// Function declarations

// @category:allocation
AxesIntHandle AxesInt_create_empty();
// @category:allocation
AxesIntHandle AxesInt_copy(AxesIntHandle handle);
// @category:allocation
AxesIntHandle AxesInt_create(ListIntHandle data);
// @category:deallocation
void AxesInt_destroy(AxesIntHandle handle);
// @category:write
void AxesInt_push_back(AxesIntHandle handle, int value);
// @category:read
size_t AxesInt_size(AxesIntHandle handle);
// @category:read
bool AxesInt_empty(AxesIntHandle handle);
// @category:write
void AxesInt_erase_at(AxesIntHandle handle, size_t idx);
// @category:write
void AxesInt_clear(AxesIntHandle handle);
// @category:read
int AxesInt_at(AxesIntHandle handle, size_t idx);
// @category:read
size_t AxesInt_items(AxesIntHandle handle, int* out_buffer, size_t buffer_size);
// @category:read
bool AxesInt_contains(AxesIntHandle handle, int value);
// @category:read
size_t AxesInt_index(AxesIntHandle handle, int value);
// @category:read
AxesIntHandle AxesInt_intersection(AxesIntHandle handle, AxesIntHandle other);
// @category:read
bool AxesInt_equal(AxesIntHandle handle, AxesIntHandle other);
// @category:read
bool AxesInt_not_equal(AxesIntHandle handle, AxesIntHandle other);

// @category:read
StringHandle      AxesInt_to_json_string(AxesIntHandle handle);
// @category:allocation
AxesIntHandle AxesInt_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


