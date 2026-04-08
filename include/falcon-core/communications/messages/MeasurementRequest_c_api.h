#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon-core/generic/ListWaveform_c_api.h"
#include "falcon-core/generic/MapInstrumentPortPortTransform_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon-core/math/domains/LabelledDomain_c_api.h"
typedef void* MeasurementRequestHandle;

// @category:allocation
FALCON_CORE_C_API MeasurementRequestHandle
MeasurementRequest_copy(MeasurementRequestHandle handle);
// @category:deallocation
FALCON_CORE_C_API void MeasurementRequest_destroy(
    MeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API bool MeasurementRequest_equal(MeasurementRequestHandle handle,
                                                MeasurementRequestHandle other);
// @category:read
FALCON_CORE_C_API bool MeasurementRequest_not_equal(
    MeasurementRequestHandle handle, MeasurementRequestHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementRequest_to_json_string(MeasurementRequestHandle handle);
// @category:allocation
FALCON_CORE_C_API MeasurementRequestHandle
MeasurementRequest_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API MeasurementRequestHandle
MeasurementRequest_create(StringHandle                         message,
                          StringHandle                         measurement_name,
                          ListWaveformHandle                   waveforms,
                          PortsHandle                          getters,
                          MapInstrumentPortPortTransformHandle meter_transforms,
                          LabelledDomainHandle                 time_domain);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementRequest_measurement_name(MeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API PortsHandle
MeasurementRequest_getters(MeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API ListWaveformHandle
MeasurementRequest_waveforms(MeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API MapInstrumentPortPortTransformHandle
MeasurementRequest_meter_transforms(MeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle
MeasurementRequest_time_domain(MeasurementRequestHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
MeasurementRequest_message(MeasurementRequestHandle handle);

#ifdef __cplusplus
}
#endif
