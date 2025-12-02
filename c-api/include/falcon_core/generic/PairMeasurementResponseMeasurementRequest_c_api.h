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
/* AUTO-DOC from cpp: PairMeasurementResponseMeasurementRequest_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create(MeasurementResponseHandle first, MeasurementRequestHandle second);
// @category:deallocation
void PairMeasurementResponseMeasurementRequest_destroy(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairMeasurementResponseMeasurementRequest_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairMeasurementResponseMeasurementRequest_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:read
bool PairMeasurementResponseMeasurementRequest_equal(PairMeasurementResponseMeasurementRequestHandle a, PairMeasurementResponseMeasurementRequestHandle b);
// @category:read
bool PairMeasurementResponseMeasurementRequest_not_equal(PairMeasurementResponseMeasurementRequestHandle a, PairMeasurementResponseMeasurementRequestHandle b);
// @category:read
StringHandle      PairMeasurementResponseMeasurementRequest_to_json_string(PairMeasurementResponseMeasurementRequestHandle handle);
// @category:allocation
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif