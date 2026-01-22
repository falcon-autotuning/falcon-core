

# File PairMeasurementResponseMeasurementRequest\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**generic**](dir_496d41daa888fe924b07cec1e014cccd.md) **>** [**PairMeasurementResponseMeasurementRequest\_c\_api.h**](PairMeasurementResponseMeasurementRequest__c__api_8h.md)

[Go to the documentation of this file](PairMeasurementResponseMeasurementRequest__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/communications/messages/MeasurementResponse_c_api.h"
#include "falcon_core/communications/messages/MeasurementRequest_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairMeasurementResponseMeasurementRequestHandle;
// Function declarations

// @category:allocation
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create(MeasurementResponseHandle first, MeasurementRequestHandle second);
// @category:allocation
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_copy(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:deallocation
void PairMeasurementResponseMeasurementRequest_destroy(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
bool PairMeasurementResponseMeasurementRequest_equal(PairMeasurementResponseMeasurementRequestHandle handle, PairMeasurementResponseMeasurementRequestHandle other);
// @category:read
bool PairMeasurementResponseMeasurementRequest_not_equal(PairMeasurementResponseMeasurementRequestHandle handle, PairMeasurementResponseMeasurementRequestHandle other);
// @category:read
StringHandle      PairMeasurementResponseMeasurementRequest_to_json_string(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:allocation
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
```


