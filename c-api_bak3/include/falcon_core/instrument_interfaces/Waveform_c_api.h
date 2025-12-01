
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

// Constructors
WaveformHandle Waveform_create(DiscreteSpaceHandle     space,
                               ListPortTransformHandle transforms);
/* AUTO-DOC from cpp: Waveform_create_cartesianwaveform | falcon_core::instrument_interfaces::Waveform::CartesianWaveform */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::CartesianWaveform)
 * @brief Create a ND CartesianWaveform from raw deltas.
 * @param divisions The number of divisions along each axis.
 * @param axes The axes defining the cartesian space.
 * @param domain The base domain of the cartesian space.
 * @param transforms the transforms to apply to the waveform.
 * @param increasing if the array should increase following the domain or not.
 */
WaveformHandle Waveform_create_cartesianwaveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain);
/* AUTO-DOC from cpp: Waveform_create_cartesianidentitywaveform | falcon_core::instrument_interfaces::Waveform::CartesianIdentityWaveform */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::CartesianIdentityWaveform)
 * @brief Create a ND CartesianWaveform with identity transforms.
 * @param divisions The number of divisions along each axis.
 * @param axes The axes defining the cartesian space.
 * @param domain The base domain of the cartesian space.
 * @param increasing if the array should increase following the domain or not.
 */
WaveformHandle Waveform_create_cartesianidentitywaveform(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
/* AUTO-DOC from cpp: Waveform_create_cartesianwaveform2D | falcon_core::instrument_interfaces::Waveform::CartesianWaveform2D */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::CartesianWaveform2D)
 * @brief Create a 2D CartesianWaveform from raw deltas.
 * @param divisions The number of divisions along each axis.
 * @param axes The axes defining the cartesian space.
 * @param domain The base domain of the cartesian space.
 * @param transforms the transforms to apply to the waveform.
 * @param increasing if the array should increase following the domain or not.
 */
WaveformHandle Waveform_create_cartesianwaveform2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    ListPortTransformHandle         transforms,
    DomainHandle                    domain);
/* AUTO-DOC from cpp: Waveform_create_cartesianidentitywaveform2D | falcon_core::instrument_interfaces::Waveform::CartesianIdentityWaveform2D */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::CartesianIdentityWaveform2D)
 * @brief Create a 2D CartesianWaveform with identity transforms.
 * @param divisions The number of divisions along each axis.
 * @param axes The axes defining the cartesian space.
 * @param domain The base domain of the cartesian space.
 * @param increasing if the array should increase following the domain or not.
 */
WaveformHandle Waveform_create_cartesianidentitywaveform2D(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
/* AUTO-DOC from cpp: Waveform_create_cartesianwaveform1D | falcon_core::instrument_interfaces::Waveform::CartesianWaveform1D */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::CartesianWaveform1D)
 * @brief Create a 1D CartesianWaveform from raw deltas.
 * @param divisions The number of divisions along each axis.
 * @param axes The axes defining the cartesian space.
 * @param domain The base domain of the cartesian space.
 * @param transforms the transforms to apply to the waveform.
 * @param increasing if the array should increase following the domain or not.
 */
WaveformHandle Waveform_create_cartesianwaveform1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    ListPortTransformHandle     transforms,
    DomainHandle                domain);
/* AUTO-DOC from cpp: Waveform_create_cartesianidentitywaveform1D | falcon_core::instrument_interfaces::Waveform::CartesianIdentityWaveform1D */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::CartesianIdentityWaveform1D)
 * @brief Create a 1D CartesianWaveform with identity transforms.
 * @param divisions The number of divisions along each axis.
 * @param axes The axes defining the cartesian space.
 * @param domain The base domain of the cartesian space.
 * @param increasing if the array should increase following the domain or not.
 */
WaveformHandle Waveform_create_cartesianidentitywaveform1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain);

// Destructor
void Waveform_destroy(WaveformHandle handle);

// Methods
/* AUTO-DOC from cpp: Waveform_space | falcon_core::instrument_interfaces::Waveform::space */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::Waveform::space)
 * @brief Get the measurement space.
 */
DiscreteSpaceHandle     Waveform_space(WaveformHandle handle);
ListPortTransformHandle Waveform_transforms(WaveformHandle handle);
void   Waveform_push_back(WaveformHandle handle, PortTransformHandle value);
size_t Waveform_size(WaveformHandle handle);
bool   Waveform_empty(WaveformHandle handle);
void   Waveform_erase_at(WaveformHandle handle, size_t idx);
void   Waveform_clear(WaveformHandle handle);
PortTransformHandle     Waveform_at(WaveformHandle handle, size_t idx);
ListPortTransformHandle Waveform_items(WaveformHandle handle);
bool   Waveform_contains(WaveformHandle handle, PortTransformHandle value);
size_t Waveform_index(WaveformHandle handle, PortTransformHandle value);
WaveformHandle Waveform_intersection(WaveformHandle handle,
                                     WaveformHandle other);
bool           Waveform_equal(WaveformHandle handle, WaveformHandle other);
bool           Waveform_not_equal(WaveformHandle handle, WaveformHandle other);

// Serialization (from Song)
StringHandle   Waveform_to_json_string(WaveformHandle handle);
WaveformHandle Waveform_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
