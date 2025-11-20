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

// Constructors
DiscreteSpaceHandle DiscreteSpace_create(UnitSpaceHandle                 space,
                                         AxesCoupledLabelledDomainHandle axes,
                                         AxesMapStringBoolHandle increasing);
DiscreteSpaceHandle DiscreteSpace_create_cartesiandiscretespace(
    AxesIntHandle                   divisions,
    AxesCoupledLabelledDomainHandle axes,
    AxesMapStringBoolHandle         increasing,
    DomainHandle                    domain);
DiscreteSpaceHandle DiscreteSpace_create_cartesiandiscretespace1D(
    int                         division,
    CoupledLabelledDomainHandle shared_domain,
    MapStringBoolHandle         increasing,
    DomainHandle                domain);

// Destructor
void DiscreteSpace_destroy(DiscreteSpaceHandle handle);

// Methods
UnitSpaceHandle                 DiscreteSpace_space(DiscreteSpaceHandle handle);
AxesCoupledLabelledDomainHandle DiscreteSpace_axes(DiscreteSpaceHandle handle);
AxesMapStringBoolHandle DiscreteSpace_increasing(DiscreteSpaceHandle handle);
PortsHandle             DiscreteSpace_knobs(DiscreteSpaceHandle handle);
void DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(
    DiscreteSpaceHandle handle);
void         DiscreteSpace_validate_knob_uniqueness(DiscreteSpaceHandle handle);
int          DiscreteSpace_get_axis(DiscreteSpaceHandle  handle,
                                    InstrumentPortHandle knob);
DomainHandle DiscreteSpace_get_domain(DiscreteSpaceHandle  handle,
                                      InstrumentPortHandle knob);
AxesLabelledControlArrayHandle DiscreteSpace_get_projection(
    DiscreteSpaceHandle handle, AxesInstrumentPortHandle projection);
bool DiscreteSpace_equal(DiscreteSpaceHandle handle, DiscreteSpaceHandle other);
bool DiscreteSpace_not_equal(DiscreteSpaceHandle handle,
                             DiscreteSpaceHandle other);

// Serialization (from Song)
StringHandle        DiscreteSpace_to_json_string(DiscreteSpaceHandle handle);
DiscreteSpaceHandle DiscreteSpace_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
