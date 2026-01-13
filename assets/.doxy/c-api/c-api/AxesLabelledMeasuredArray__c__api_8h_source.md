

# File AxesLabelledMeasuredArray\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**AxesLabelledMeasuredArray\_c\_api.h**](AxesLabelledMeasuredArray__c__api_8h.md)

[Go to the documentation of this file](AxesLabelledMeasuredArray__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledMeasuredArray_c_api.h"
#include "falcon_core/generic/ListLabelledMeasuredArray_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* AxesLabelledMeasuredArrayHandle;
// Function declarations

// @category:allocation
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create_empty();
// @category:allocation
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_copy(AxesLabelledMeasuredArrayHandle handle);
// @category:allocation
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_create(ListLabelledMeasuredArrayHandle data);
// @category:deallocation
void AxesLabelledMeasuredArray_destroy(AxesLabelledMeasuredArrayHandle handle);
// @category:write
void AxesLabelledMeasuredArray_push_back(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
size_t AxesLabelledMeasuredArray_size(AxesLabelledMeasuredArrayHandle handle);
// @category:read
bool AxesLabelledMeasuredArray_empty(AxesLabelledMeasuredArrayHandle handle);
// @category:write
void AxesLabelledMeasuredArray_erase_at(AxesLabelledMeasuredArrayHandle handle, size_t idx);
// @category:write
void AxesLabelledMeasuredArray_clear(AxesLabelledMeasuredArrayHandle handle);
// @category:read
LabelledMeasuredArrayHandle AxesLabelledMeasuredArray_at(AxesLabelledMeasuredArrayHandle handle, size_t idx);
// @category:read
size_t AxesLabelledMeasuredArray_items(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle* out_buffer, size_t buffer_size);
// @category:read
bool AxesLabelledMeasuredArray_contains(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
size_t AxesLabelledMeasuredArray_index(AxesLabelledMeasuredArrayHandle handle, LabelledMeasuredArrayHandle value);
// @category:read
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_intersection(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);
// @category:read
bool AxesLabelledMeasuredArray_equal(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);
// @category:read
bool AxesLabelledMeasuredArray_not_equal(AxesLabelledMeasuredArrayHandle handle, AxesLabelledMeasuredArrayHandle other);

// @category:read
StringHandle      AxesLabelledMeasuredArray_to_json_string(AxesLabelledMeasuredArrayHandle handle);
// @category:allocation
AxesLabelledMeasuredArrayHandle AxesLabelledMeasuredArray_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


