

# File AxesLabelledControlArray1D\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledControlArray1D\_c\_api.h**](AxesLabelledControlArray1D__c__api_8h.md)

[Go to the documentation of this file](AxesLabelledControlArray1D__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"
#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledControlArray1DHandle;
// Function declarations

// @category:allocation
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create_empty();
// @category:allocation
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_copy(AxesLabelledControlArray1DHandle handle);
// @category:allocation
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_create(ListLabelledControlArray1DHandle data);
// @category:deallocation
void AxesLabelledControlArray1D_destroy(AxesLabelledControlArray1DHandle handle);
// @category:write
void AxesLabelledControlArray1D_push_back(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
size_t AxesLabelledControlArray1D_size(AxesLabelledControlArray1DHandle handle);
// @category:read
bool AxesLabelledControlArray1D_empty(AxesLabelledControlArray1DHandle handle);
// @category:write
void AxesLabelledControlArray1D_erase_at(AxesLabelledControlArray1DHandle handle, size_t idx);
// @category:write
void AxesLabelledControlArray1D_clear(AxesLabelledControlArray1DHandle handle);
// @category:read
LabelledControlArray1DHandle AxesLabelledControlArray1D_at(AxesLabelledControlArray1DHandle handle, size_t idx);
// @category:read
size_t AxesLabelledControlArray1D_items(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesLabelledControlArray1D_contains(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
size_t AxesLabelledControlArray1D_index(AxesLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_intersection(AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other);
// @category:read
bool AxesLabelledControlArray1D_equal(AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other);
// @category:read
bool AxesLabelledControlArray1D_not_equal(AxesLabelledControlArray1DHandle handle, AxesLabelledControlArray1DHandle other);

// @category:read
StringHandle      AxesLabelledControlArray1D_to_json_string(AxesLabelledControlArray1DHandle handle);
// @category:allocation
AxesLabelledControlArray1DHandle AxesLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


