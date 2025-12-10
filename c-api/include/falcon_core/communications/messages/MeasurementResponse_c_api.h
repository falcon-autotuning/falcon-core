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
