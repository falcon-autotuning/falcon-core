

# File MeasurementRequest\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**communications**](dir_333323e88b5d6263154607a1eb6b024f.md) **>** [**messages**](dir_b9b9af6e426ae6e63b9b7113e9a16e28.md) **>** [**MeasurementRequest\_c\_api.h**](MeasurementRequest__c__api_8h.md)

[Go to the documentation of this file](MeasurementRequest__c__api_8h.md)


```C++
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
```


