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
FALCON_CORE_C_API PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create(MeasurementResponseHandle first, MeasurementRequestHandle second);
// @category:allocation
FALCON_CORE_C_API PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_copy(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairMeasurementResponseMeasurementRequest_destroy(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API bool PairMeasurementResponseMeasurementRequest_equal(PairMeasurementResponseMeasurementRequestHandle handle, PairMeasurementResponseMeasurementRequestHandle other);
// @category:read
FALCON_CORE_C_API bool PairMeasurementResponseMeasurementRequest_not_equal(PairMeasurementResponseMeasurementRequestHandle handle, PairMeasurementResponseMeasurementRequestHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairMeasurementResponseMeasurementRequest_to_json_string(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:allocation
FALCON_CORE_C_API PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif