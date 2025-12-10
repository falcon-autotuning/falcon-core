#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListWaveform_c_api.h"
#include "falcon_core/generic/MapInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
typedef void* MeasurementRequestHandle;

// @category:allocation
MeasurementRequestHandle MeasurementRequest_copy(
    MeasurementRequestHandle handle);
// @category:deallocation
void MeasurementRequest_destroy(MeasurementRequestHandle handle);
// @category:read
bool MeasurementRequest_equal(MeasurementRequestHandle handle,
                              MeasurementRequestHandle other);
// @category:read
bool MeasurementRequest_not_equal(MeasurementRequestHandle handle,
                                  MeasurementRequestHandle other);
// @category:read
StringHandle MeasurementRequest_to_json_string(MeasurementRequestHandle handle);
// @category:allocation
MeasurementRequestHandle MeasurementRequest_from_json_string(StringHandle json);
// @category:allocation
MeasurementRequestHandle MeasurementRequest_create(
    StringHandle                         message,
    StringHandle                         measurement_name,
    ListWaveformHandle                   waveforms,
    PortsHandle                          getters,
    MapInstrumentPortPortTransformHandle meter_transforms,
    LabelledDomainHandle                 time_domain);
// @category:read
StringHandle MeasurementRequest_measurement_name(
    MeasurementRequestHandle handle);
// @category:read
PortsHandle MeasurementRequest_getters(MeasurementRequestHandle handle);
// @category:read
ListWaveformHandle MeasurementRequest_waveforms(
    MeasurementRequestHandle handle);
// @category:read
MapInstrumentPortPortTransformHandle MeasurementRequest_meter_transforms(
    MeasurementRequestHandle handle);
// @category:read
LabelledDomainHandle MeasurementRequest_time_domain(
    MeasurementRequestHandle handle);
// @category:read
StringHandle MeasurementRequest_message(MeasurementRequestHandle handle);

#ifdef __cplusplus
}
#endif
