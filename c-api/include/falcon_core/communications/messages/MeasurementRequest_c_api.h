#pragma once
#include "falcon_core/instrument_interfaces/names/Ports_c_api.h"
#include "falcon_core/math/domains/LabelledDomain_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListWaveform_c_api.h"
#include "falcon_core/generic/MapInstrumentPortPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
typedef void* MeasurementRequestHandle;

// Constructors
MeasurementRequestHandle MeasurementRequest_create(
    StringHandle                         message,
    StringHandle                         measurement_name,
    ListWaveformHandle                   waveforms,
    PortsHandle                          getters,
    MapInstrumentPortPortTransformHandle meter_transforms,
    LabelledDomainHandle                 time_domain);

// Destructor
void MeasurementRequest_destroy(MeasurementRequestHandle handle);

// Methods
StringHandle MeasurementRequest_measurement_name(
    MeasurementRequestHandle handle);
PortsHandle        MeasurementRequest_getters(MeasurementRequestHandle handle);
ListWaveformHandle MeasurementRequest_waveforms(
    MeasurementRequestHandle handle);
MapInstrumentPortPortTransformHandle MeasurementRequest_meter_transforms(
    MeasurementRequestHandle handle);
LabelledDomainHandle MeasurementRequest_time_domain(
    MeasurementRequestHandle handle);
StringHandle MeasurementRequest_message(MeasurementRequestHandle handle);
bool         MeasurementRequest_equal(MeasurementRequestHandle handle,
                                      MeasurementRequestHandle other);
bool         MeasurementRequest_not_equal(MeasurementRequestHandle handle,
                                          MeasurementRequestHandle other);

// Serialization (from Song)
StringHandle MeasurementRequest_to_json_string(MeasurementRequestHandle handle);
MeasurementRequestHandle MeasurementRequest_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
