
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/generic/ListPortTransform_c_api.h"
#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/port_transforms/PortTransform_c_api.h"
#include "falcon-core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon-core/math/AxesInt_c_api.h"
#include "falcon-core/math/AxesMapStringBool_c_api.h"
#include "falcon-core/math/discrete_spaces/DiscreteSpace_c_api.h"

typedef void* WaveformHandle;

// @category:allocation
FALCON_CORE_C_API WaveformHandle Waveform_copy(WaveformHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Waveform_destroy(WaveformHandle handle);
// @category:read
FALCON_CORE_C_API bool Waveform_equal(WaveformHandle handle,
                                      WaveformHandle other);
// @category:read
FALCON_CORE_C_API bool Waveform_not_equal(WaveformHandle handle,
                                          WaveformHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Waveform_to_json_string(WaveformHandle handle);
// @category:allocation
FALCON_CORE_C_API WaveformHandle Waveform_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API WaveformHandle
Waveform_create(DiscreteSpaceHandle space, ListPortTransformHandle transforms);
// @category:allocation
FALCON_CORE_C_API WaveformHandle
Waveform_create_cartesian_waveform(AxesIntHandle                   divisions,
                                   AxesCoupledLabelledDomainHandle axes,
                                   AxesMapStringBoolHandle         increasing,
                                   ListPortTransformHandle         transforms,
                                   DomainHandle                    domain);
// @category:allocation
FALCON_CORE_C_API WaveformHandle Waveform_create_cartesian_identity_waveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
// @category:allocation
FALCON_CORE_C_API WaveformHandle
Waveform_create_cartesian_waveform_2D(AxesIntHandle                   divisions,
                                      AxesCoupledLabelledDomainHandle axes,
                                      AxesMapStringBoolHandle increasing,
                                      ListPortTransformHandle transforms,
                                      DomainHandle            domain);
// @category:allocation
FALCON_CORE_C_API WaveformHandle Waveform_create_cartesian_identity_waveform_2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
// @category:allocation
FALCON_CORE_C_API WaveformHandle
Waveform_create_cartesian_waveform_1D(int                         division,
                                      CoupledLabelledDomainHandle shared_domain,
                                      MapStringBoolHandle         increasing,
                                      ListPortTransformHandle     transforms,
                                      DomainHandle                domain);
// @category:allocation
FALCON_CORE_C_API WaveformHandle Waveform_create_cartesian_identity_waveform_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain);
// @category:read
/* AUTO-DOC from cpp: Waveform_space |
 * falcon_core::instrument_interfaces::Waveform::space */
/**
 * @brief Get the measurement space.
 */
FALCON_CORE_C_API DiscreteSpaceHandle Waveform_space(WaveformHandle handle);
// @category:read
FALCON_CORE_C_API ListPortTransformHandle
Waveform_transforms(WaveformHandle handle);
// @category:write
FALCON_CORE_C_API void Waveform_push_back(WaveformHandle      handle,
                                          PortTransformHandle value);
// @category:read
FALCON_CORE_C_API size_t Waveform_size(WaveformHandle handle);
// @category:read
FALCON_CORE_C_API bool Waveform_empty(WaveformHandle handle);
// @category:write
FALCON_CORE_C_API void Waveform_erase_at(WaveformHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void Waveform_clear(WaveformHandle handle);
// @category:read
FALCON_CORE_C_API PortTransformHandle Waveform_at(WaveformHandle handle,
                                                  size_t         idx);
// @category:read
FALCON_CORE_C_API ListPortTransformHandle Waveform_items(WaveformHandle handle);
// @category:read
FALCON_CORE_C_API bool Waveform_contains(WaveformHandle      handle,
                                         PortTransformHandle value);
// @category:read
FALCON_CORE_C_API size_t Waveform_index(WaveformHandle      handle,
                                        PortTransformHandle value);
// @category:read
FALCON_CORE_C_API WaveformHandle Waveform_intersection(WaveformHandle handle,
                                                       WaveformHandle other);

#ifdef __cplusplus
}
#endif
