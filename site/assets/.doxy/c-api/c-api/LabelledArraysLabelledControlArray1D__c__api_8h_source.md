

# File LabelledArraysLabelledControlArray1D\_c\_api.h

[**File List**](files.md) **>** [**arrays**](dir_bfe73c8db2db54615e75c4ba09b4f73a.md) **>** [**LabelledArraysLabelledControlArray1D\_c\_api.h**](LabelledArraysLabelledControlArray1D__c__api_8h.md)

[Go to the documentation of this file](LabelledArraysLabelledControlArray1D__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/generic/ListLabelledControlArray1D_c_api.h"
#include "falcon_core/generic/ListAcquisitionContext_c_api.h"
#include <stddef.h>
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* LabelledArraysLabelledControlArray1DHandle;
// Function declarations

// @category:allocation
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_create(
    ListLabelledControlArray1DHandle arrays);
// @category:allocation
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_copy(LabelledArraysLabelledControlArray1DHandle handle);
// @category:deallocation
void LabelledArraysLabelledControlArray1D_destroy(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
ListLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
ListAcquisitionContextHandle LabelledArraysLabelledControlArray1D_labels(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray1D_is_control_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray1D_is_measured_arrays(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:write
void LabelledArraysLabelledControlArray1D_push_back(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
size_t LabelledArraysLabelledControlArray1D_size(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
bool LabelledArraysLabelledControlArray1D_empty(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:write
void LabelledArraysLabelledControlArray1D_erase_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
// @category:write
void LabelledArraysLabelledControlArray1D_clear(
    LabelledArraysLabelledControlArray1DHandle handle);
// @category:read
LabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_at(
    LabelledArraysLabelledControlArray1DHandle handle, size_t idx);
// @category:read
bool LabelledArraysLabelledControlArray1D_contains(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
size_t LabelledArraysLabelledControlArray1D_index(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledControlArray1DHandle value);
// @category:read
LabelledArraysLabelledControlArray1DHandle
LabelledArraysLabelledControlArray1D_intersection(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
// @category:read
bool LabelledArraysLabelledControlArray1D_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);
// @category:read
bool LabelledArraysLabelledControlArray1D_not_equal(
    LabelledArraysLabelledControlArray1DHandle handle,
    LabelledArraysLabelledControlArray1DHandle other);

// @category:read
StringHandle      LabelledArraysLabelledControlArray1D_to_json_string(LabelledArraysLabelledControlArray1DHandle handle);
// @category:allocation
LabelledArraysLabelledControlArray1DHandle LabelledArraysLabelledControlArray1D_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


