

# File ListLabelledControlArray1D\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**ListLabelledControlArray1D\_c\_api.h**](ListLabelledControlArray1D__c__api_8h.md)

[Go to the documentation of this file](ListLabelledControlArray1D__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/math/arrays/LabelledControlArray1D_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* ListLabelledControlArray1DHandle;
// Function declarations

// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create_empty();
// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_copy(ListLabelledControlArray1DHandle handle);

// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_fill_value(size_t count, LabelledControlArray1DHandle value);
// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_create(LabelledControlArray1DHandle* data, size_t count);
// @category:deallocation
void ListLabelledControlArray1D_destroy(ListLabelledControlArray1DHandle handle);
// @category:write
void ListLabelledControlArray1D_push_back(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
size_t ListLabelledControlArray1D_size(ListLabelledControlArray1DHandle handle);
// @category:read
bool ListLabelledControlArray1D_empty(ListLabelledControlArray1DHandle handle);
// @category:write
void ListLabelledControlArray1D_erase_at(ListLabelledControlArray1DHandle handle, size_t idx);
// @category:write
void ListLabelledControlArray1D_clear(ListLabelledControlArray1DHandle handle);
// @category:read
LabelledControlArray1DHandle ListLabelledControlArray1D_at(ListLabelledControlArray1DHandle handle, size_t idx);
// @category:read
size_t ListLabelledControlArray1D_items(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle* out_buffer, size_t buffer_size);
// @category:read
bool ListLabelledControlArray1D_contains(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
size_t ListLabelledControlArray1D_index(ListLabelledControlArray1DHandle handle, LabelledControlArray1DHandle value);
// @category:read
ListLabelledControlArray1DHandle ListLabelledControlArray1D_intersection(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other);
// @category:read
bool ListLabelledControlArray1D_equal(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other);
// @category:read
bool ListLabelledControlArray1D_not_equal(ListLabelledControlArray1DHandle handle, ListLabelledControlArray1DHandle other);

// @category:read
StringHandle      ListLabelledControlArray1D_to_json_string(ListLabelledControlArray1DHandle handle);
// @category:allocation
ListLabelledControlArray1DHandle ListLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


