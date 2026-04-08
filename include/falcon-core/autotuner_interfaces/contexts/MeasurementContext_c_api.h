#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon-core/export_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
typedef void* MeasurementContextHandle;

// @category:allocation
FALCON_CORE_C_API MeasurementContextHandle
MeasurementContext_copy(MeasurementContextHandle handle);
// @category:deallocation
FALCON_CORE_C_API void MeasurementContext_destroy(
    MeasurementContextHandle handle);
// @category:read
FALCON_CORE_C_API bool MeasurementContext_equal(MeasurementContextHandle handle,
                                                MeasurementContextHandle other);
// @category:read
FALCON_CORE_C_API bool MeasurementContext_not_equal(
    MeasurementContextHandle handle, MeasurementContextHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementContext_to_json_string(MeasurementContextHandle handle);
// @category:allocation
FALCON_CORE_C_API MeasurementContextHandle
MeasurementContext_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API MeasurementContextHandle MeasurementContext_create(
    ConnectionHandle connection, StringHandle instrument_type);
// @category:allocation
FALCON_CORE_C_API MeasurementContextHandle
MeasurementContext_create_from_port(InstrumentPortHandle port);
// @category:read
FALCON_CORE_C_API ConnectionHandle
MeasurementContext_connection(MeasurementContextHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementContext_instrument_type(MeasurementContextHandle handle);

#ifdef __cplusplus
}
#endif
