

# File DiscreteSpace\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**discrete\_spaces**](dir_4135ae89d8b25a1ab40962ee1784aac3.md) **>** [**DiscreteSpace\_c\_api.h**](DiscreteSpace__c__api_8h.md)

[Go to the documentation of this file](DiscreteSpace__c__api_8h.md)


```C++
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
DiscreteSpaceHandle DiscreteSpace_copy(DiscreteSpaceHandle handle);
// @category:deallocation
void DiscreteSpace_destroy(DiscreteSpaceHandle handle);
// @category:read
bool DiscreteSpace_equal(DiscreteSpaceHandle handle, DiscreteSpaceHandle other);
// @category:read
bool DiscreteSpace_not_equal(DiscreteSpaceHandle handle,
                             DiscreteSpaceHandle other);
// @category:read
StringHandle DiscreteSpace_to_json_string(DiscreteSpaceHandle handle);
// @category:allocation
DiscreteSpaceHandle DiscreteSpace_from_json_string(StringHandle json);
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

// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_space |
 * falcon_core::math::discrete_spaces::DiscreteSpace::space */
UnitSpaceHandle DiscreteSpace_space(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_axes |
 * falcon_core::math::discrete_spaces::DiscreteSpace::axes */
AxesCoupledLabelledDomainHandle DiscreteSpace_axes(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_increasing |
 * falcon_core::math::discrete_spaces::DiscreteSpace::increasing */
AxesMapStringBoolHandle DiscreteSpace_increasing(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_knobs |
 * falcon_core::math::discrete_spaces::DiscreteSpace::knobs */
PortsHandle DiscreteSpace_knobs(DiscreteSpaceHandle handle);
// @category:write
/* AUTO-DOC from cpp:
 * DiscreteSpace_validate_unit_space_dimensionality_matches_knobs |
 * falcon_core::math::discrete_spaces::DiscreteSpace::validate_unit_space_dimensionality_matches_knobs
 */
void DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(
    DiscreteSpaceHandle handle);
// @category:write
/* AUTO-DOC from cpp: DiscreteSpace_validate_knob_uniqueness |
 * falcon_core::math::discrete_spaces::DiscreteSpace::validate_knob_uniqueness
 */
void DiscreteSpace_validate_knob_uniqueness(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_get_axis |
 * falcon_core::math::discrete_spaces::DiscreteSpace::get_axis */
int DiscreteSpace_get_axis(DiscreteSpaceHandle  handle,
                           InstrumentPortHandle knob);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_get_domain |
 * falcon_core::math::discrete_spaces::DiscreteSpace::get_domain */
DomainHandle DiscreteSpace_get_domain(DiscreteSpaceHandle  handle,
                                      InstrumentPortHandle knob);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_get_projection |
 * falcon_core::math::discrete_spaces::DiscreteSpace::get_projection */
AxesLabelledControlArrayHandle DiscreteSpace_get_projection(
    DiscreteSpaceHandle handle, AxesInstrumentPortHandle projection);

#ifdef __cplusplus
}
#endif
```


