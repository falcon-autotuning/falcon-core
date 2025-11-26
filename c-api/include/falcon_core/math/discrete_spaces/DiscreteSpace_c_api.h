#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/AxesCoupledLabelledDomain_c_api.h"
#include "falcon_core/math/AxesInstrumentPort_c_api.h"
#include "falcon_core/math/AxesLabelledControlArray_c_api.h"
#include "falcon_core/math/AxesMapStringBool_c_api.h"
#include "falcon_core/math/UnitSpace_c_api.h"
#include "falcon_core/math/domains/CoupledLabelledDomain_c_api.h"
typedef void* DiscreteSpaceHandle;

// @category:allocation
DiscreteSpaceHandle DiscreteSpace_create(UnitSpaceHandle                 space,
                                         AxesCoupledLabelledDomainHandle axes,
                                         AxesMapStringBoolHandle increasing);
// @category:allocation
DiscreteSpaceHandle DiscreteSpace_create_cartesian_discrete_space(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
// @category:allocation
DiscreteSpaceHandle DiscreteSpace_create_cartesian_discrete_space_1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain);
// @category:deallocation
void DiscreteSpace_destroy(DiscreteSpaceHandle handle);

// @category:read
UnitSpaceHandle DiscreteSpace_space(DiscreteSpaceHandle handle);
// @category:read
AxesCoupledLabelledDomainHandle DiscreteSpace_axes(DiscreteSpaceHandle handle);
// @category:read
AxesMapStringBoolHandle DiscreteSpace_increasing(DiscreteSpaceHandle handle);
// @category:read
PortsHandle DiscreteSpace_knobs(DiscreteSpaceHandle handle);
// @category:write
void DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(
    DiscreteSpaceHandle handle);
// @category:write
void DiscreteSpace_validate_knob_uniqueness(DiscreteSpaceHandle handle);
// @category:read
int DiscreteSpace_get_axis(DiscreteSpaceHandle  handle,
                           InstrumentPortHandle knob);
// @category:read
DomainHandle DiscreteSpace_get_domain(DiscreteSpaceHandle  handle,
                                      InstrumentPortHandle knob);
// @category:read
AxesLabelledControlArrayHandle DiscreteSpace_get_projection(
    DiscreteSpaceHandle handle, AxesInstrumentPortHandle projection);
// @category:read
bool DiscreteSpace_equal(DiscreteSpaceHandle handle, DiscreteSpaceHandle other);
// @category:read
bool DiscreteSpace_not_equal(DiscreteSpaceHandle handle,
                             DiscreteSpaceHandle other);
// @category:read
StringHandle DiscreteSpace_to_json_string(DiscreteSpaceHandle handle);
// @category:allocation
DiscreteSpaceHandle DiscreteSpace_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
