

# File AxesLabelledControlArray\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledControlArray\_c\_api.h**](AxesLabelledControlArray__c__api_8h.md)

[Go to the documentation of this file](AxesLabelledControlArray__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray_c_api.h"
#include "falcon_core/generic/ListLabelledControlArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledControlArrayHandle;
// Function declarations

// @category:allocation
AxesLabelledControlArrayHandle AxesLabelledControlArray_create_empty();
// @category:allocation
AxesLabelledControlArrayHandle AxesLabelledControlArray_copy(AxesLabelledControlArrayHandle handle);
// @category:allocation
AxesLabelledControlArrayHandle AxesLabelledControlArray_create(ListLabelledControlArrayHandle data);
// @category:deallocation
void AxesLabelledControlArray_destroy(AxesLabelledControlArrayHandle handle);
// @category:write
void AxesLabelledControlArray_push_back(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
size_t AxesLabelledControlArray_size(AxesLabelledControlArrayHandle handle);
// @category:read
bool AxesLabelledControlArray_empty(AxesLabelledControlArrayHandle handle);
// @category:write
void AxesLabelledControlArray_erase_at(AxesLabelledControlArrayHandle handle, size_t idx);
// @category:write
void AxesLabelledControlArray_clear(AxesLabelledControlArrayHandle handle);
// @category:read
LabelledControlArrayHandle AxesLabelledControlArray_at(AxesLabelledControlArrayHandle handle, size_t idx);
// @category:read
size_t AxesLabelledControlArray_items(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesLabelledControlArray_contains(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
size_t AxesLabelledControlArray_index(AxesLabelledControlArrayHandle handle, LabelledControlArrayHandle value);
// @category:read
AxesLabelledControlArrayHandle AxesLabelledControlArray_intersection(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);
// @category:read
bool AxesLabelledControlArray_equal(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);
// @category:read
bool AxesLabelledControlArray_not_equal(AxesLabelledControlArrayHandle handle, AxesLabelledControlArrayHandle other);

// @category:read
StringHandle      AxesLabelledControlArray_to_json_string(AxesLabelledControlArrayHandle handle);
// @category:allocation
AxesLabelledControlArrayHandle AxesLabelledControlArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


