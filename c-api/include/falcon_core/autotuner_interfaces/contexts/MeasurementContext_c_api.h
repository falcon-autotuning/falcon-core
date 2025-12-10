#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* MeasurementContextHandle;

// @category:allocation
MeasurementContextHandle MeasurementContext_copy(
    MeasurementContextHandle handle);
// @category:deallocation
void MeasurementContext_destroy(MeasurementContextHandle handle);
// @category:read
bool MeasurementContext_equal(MeasurementContextHandle handle,
                              MeasurementContextHandle other);
// @category:read
bool MeasurementContext_not_equal(MeasurementContextHandle handle,
                                  MeasurementContextHandle other);
// @category:read
StringHandle MeasurementContext_to_json_string(MeasurementContextHandle handle);
// @category:allocation
MeasurementContextHandle MeasurementContext_from_json_string(StringHandle json);
// @category:allocation
MeasurementContextHandle MeasurementContext_create(
    ConnectionHandle connection, StringHandle instrument_type);
// @category:allocation
MeasurementContextHandle MeasurementContext_create_from_port(
    InstrumentPortHandle port);
// @category:read
ConnectionHandle MeasurementContext_connection(MeasurementContextHandle handle);
// @category:read
StringHandle MeasurementContext_instrument_type(
    MeasurementContextHandle handle);

#ifdef __cplusplus
}
#endif
