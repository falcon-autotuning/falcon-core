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

/* AUTO-DOC from cpp: PairMeasurementResponseMeasurementRequest_create | falcon_core::generic::Pair::create */
/**
 * @brief (from C++: falcon_core::generic::Pair::create)
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_create(MeasurementResponseHandle first, MeasurementRequestHandle second);
void PairMeasurementResponseMeasurementRequest_destroy(PairMeasurementResponseMeasurementRequestHandle handle);
/* AUTO-DOC from cpp: PairMeasurementResponseMeasurementRequest_first | falcon_core::generic::Pair::first */
/**
 * @brief (from C++: falcon_core::generic::Pair::first)
 * @brief Get the stored first value.
 */
MeasurementResponseHandle PairMeasurementResponseMeasurementRequest_first(PairMeasurementResponseMeasurementRequestHandle handle);
/* AUTO-DOC from cpp: PairMeasurementResponseMeasurementRequest_second | falcon_core::generic::Pair::second */
/**
 * @brief (from C++: falcon_core::generic::Pair::second)
 * @brief Get the stored second value.
 */
MeasurementRequestHandle PairMeasurementResponseMeasurementRequest_second(PairMeasurementResponseMeasurementRequestHandle handle);
bool PairMeasurementResponseMeasurementRequest_equal(PairMeasurementResponseMeasurementRequestHandle a, PairMeasurementResponseMeasurementRequestHandle b);
bool PairMeasurementResponseMeasurementRequest_not_equal(PairMeasurementResponseMeasurementRequestHandle a, PairMeasurementResponseMeasurementRequestHandle b);
// Serialization (from Song)
StringHandle      PairMeasurementResponseMeasurementRequest_to_json_string(PairMeasurementResponseMeasurementRequestHandle handle);
PairMeasurementResponseMeasurementRequestHandle PairMeasurementResponseMeasurementRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif