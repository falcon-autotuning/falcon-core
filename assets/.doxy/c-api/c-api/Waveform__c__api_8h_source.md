

# File Waveform\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**Waveform\_c\_api.h**](Waveform__c__api_8h.md)

[Go to the documentation of this file](Waveform__c__api_8h.md)


```C++

#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/ListPortTransform_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/AxesInt_c_api.h"
#include "falcon_core/math/AxesMapStringBool_c_api.h"
#include "falcon_core/math/discrete_spaces/DiscreteSpace_c_api.h"

typedef void* WaveformHandle;

// @category:allocation
WaveformHandle Waveform_copy(WaveformHandle handle);
// @category:deallocation
void Waveform_destroy(WaveformHandle handle);
// @category:read
bool Waveform_equal(WaveformHandle handle, WaveformHandle other);
// @category:read
bool Waveform_not_equal(WaveformHandle handle, WaveformHandle other);
// @category:read
StringHandle Waveform_to_json_string(WaveformHandle handle);
// @category:allocation
WaveformHandle Waveform_from_json_string(StringHandle json);
// @category:allocation
WaveformHandle Waveform_create(DiscreteSpaceHandle     space,
                               ListPortTransformHandle transforms);
// @category:allocation
WaveformHandle Waveform_create_cartesian_waveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain);
// @category:allocation
WaveformHandle Waveform_create_cartesian_identity_waveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
// @category:allocation
WaveformHandle Waveform_create_cartesian_waveform_2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain);
// @category:allocation
WaveformHandle Waveform_create_cartesian_identity_waveform_2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
// @category:allocation
WaveformHandle Waveform_create_cartesian_waveform_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    ListPortTransformHandle     transforms,
    DomainHandle                domain);
// @category:allocation
WaveformHandle Waveform_create_cartesian_identity_waveform_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain);
// @category:read
/* AUTO-DOC from cpp: Waveform_space |
 * falcon_core::instrument_interfaces::Waveform::space */
DiscreteSpaceHandle Waveform_space(WaveformHandle handle);
// @category:read
ListPortTransformHandle Waveform_transforms(WaveformHandle handle);
// @category:write
void Waveform_push_back(WaveformHandle handle, PortTransformHandle value);
// @category:read
size_t Waveform_size(WaveformHandle handle);
// @category:read
bool Waveform_empty(WaveformHandle handle);
// @category:write
void Waveform_erase_at(WaveformHandle handle, size_t idx);
// @category:write
void Waveform_clear(WaveformHandle handle);
// @category:read
PortTransformHandle Waveform_at(WaveformHandle handle, size_t idx);
// @category:read
ListPortTransformHandle Waveform_items(WaveformHandle handle);
// @category:read
bool Waveform_contains(WaveformHandle handle, PortTransformHandle value);
// @category:read
size_t Waveform_index(WaveformHandle handle, PortTransformHandle value);
// @category:read
WaveformHandle Waveform_intersection(WaveformHandle handle,
                                     WaveformHandle other);

#ifdef __cplusplus
}
#endif
```


