#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/math/arrays/LabelledArraysLabelledMeasuredArray_c_api.h"
typedef void* MeasurementResponseHandle;

// @category:allocation
FALCON_CORE_C_API MeasurementResponseHandle
MeasurementResponse_copy(MeasurementResponseHandle handle);
// @category:deallocation
FALCON_CORE_C_API void MeasurementResponse_destroy(
    MeasurementResponseHandle handle);
// @category:read
FALCON_CORE_C_API bool MeasurementResponse_equal(
    MeasurementResponseHandle handle, MeasurementResponseHandle other);
// @category:read
FALCON_CORE_C_API bool MeasurementResponse_not_equal(
    MeasurementResponseHandle handle, MeasurementResponseHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementResponse_to_json_string(MeasurementResponseHandle handle);
// @category:allocation
FALCON_CORE_C_API MeasurementResponseHandle
MeasurementResponse_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API MeasurementResponseHandle
MeasurementResponse_create(LabelledArraysLabelledMeasuredArrayHandle arrays);
// @category:read
FALCON_CORE_C_API LabelledArraysLabelledMeasuredArrayHandle
MeasurementResponse_arrays(MeasurementResponseHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementResponse_message(MeasurementResponseHandle handle);

#ifdef __cplusplus
}
#endif
