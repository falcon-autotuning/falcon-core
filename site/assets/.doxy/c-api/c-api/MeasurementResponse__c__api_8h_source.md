

# File MeasurementResponse\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**MeasurementResponse\_c\_api.h**](MeasurementResponse__c__api_8h.md)

[Go to the documentation of this file](MeasurementResponse__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
typedef void* MeasurementResponseHandle;

// @category:allocation
MeasurementResponseHandle MeasurementResponse_copy(
    MeasurementResponseHandle handle);
// @category:deallocation
void MeasurementResponse_destroy(MeasurementResponseHandle handle);
// @category:read
bool MeasurementResponse_equal(MeasurementResponseHandle handle,
                               MeasurementResponseHandle other);
// @category:read
bool MeasurementResponse_not_equal(MeasurementResponseHandle handle,
                                   MeasurementResponseHandle other);
// @category:read
StringHandle MeasurementResponse_to_json_string(
    MeasurementResponseHandle handle);
// @category:allocation
MeasurementResponseHandle MeasurementResponse_from_json_string(
    StringHandle json);
// @category:allocation
MeasurementResponseHandle MeasurementResponse_create(
    LabelledArraysLabelledMeasuredArrayHandle arrays);
// @category:read
LabelledArraysLabelledMeasuredArrayHandle MeasurementResponse_arrays(
    MeasurementResponseHandle handle);
// @category:read
StringHandle MeasurementResponse_message(MeasurementResponseHandle handle);

#ifdef __cplusplus
}
#endif
```


