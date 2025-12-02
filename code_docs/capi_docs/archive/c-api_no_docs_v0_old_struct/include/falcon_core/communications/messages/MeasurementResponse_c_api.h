#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
typedef void* MeasurementResponseHandle;

// Constructors
MeasurementResponseHandle MeasurementResponse_create(
    LabelledArraysLabelledMeasuredArrayHandle arrays);

// Destructor
void MeasurementResponse_destroy(MeasurementResponseHandle handle);

// Methods
LabelledArraysLabelledMeasuredArrayHandle MeasurementResponse_arrays(
    MeasurementResponseHandle handle);
StringHandle MeasurementResponse_message(MeasurementResponseHandle handle);
bool         MeasurementResponse_equal(MeasurementResponseHandle handle,
                                       MeasurementResponseHandle other);
bool         MeasurementResponse_not_equal(MeasurementResponseHandle handle,
                                           MeasurementResponseHandle other);

// Serialization (from Song)
StringHandle MeasurementResponse_to_json_string(
    MeasurementResponseHandle handle);
MeasurementResponseHandle MeasurementResponse_from_json_string(
    StringHandle json);

#ifdef __cplusplus
}
#endif
