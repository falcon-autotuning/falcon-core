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
/**
 * @brief Return the stored UnitSpace.
 */
UnitSpaceHandle DiscreteSpace_space(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_axes |
 * falcon_core::math::discrete_spaces::DiscreteSpace::axes */
/**
 * @brief Return the stored axes.
 */
AxesCoupledLabelledDomainHandle DiscreteSpace_axes(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_increasing |
 * falcon_core::math::discrete_spaces::DiscreteSpace::increasing */
/**
 * @brief Return the increasing properties.
 */
AxesMapStringBoolHandle DiscreteSpace_increasing(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_knobs |
 * falcon_core::math::discrete_spaces::DiscreteSpace::knobs */
/**
 * @brief Return the knobs.
 */
PortsHandle DiscreteSpace_knobs(DiscreteSpaceHandle handle);
// @category:write
/* AUTO-DOC from cpp:
 * DiscreteSpace_validate_unit_space_dimensionality_matches_knobs |
 * falcon_core::math::discrete_spaces::DiscreteSpace::validate_unit_space_dimensionality_matches_knobs
 */
/**
 * @brief Validate that the unit space dimensionality matches the number of
 * knobs.
 */
void DiscreteSpace_validate_unit_space_dimensionality_matches_knobs(
    DiscreteSpaceHandle handle);
// @category:write
/* AUTO-DOC from cpp: DiscreteSpace_validate_knob_uniqueness |
 * falcon_core::math::discrete_spaces::DiscreteSpace::validate_knob_uniqueness
 */
/**
 * @brief Validate that the knobs are unique.
 */
void DiscreteSpace_validate_knob_uniqueness(DiscreteSpaceHandle handle);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_get_axis |
 * falcon_core::math::discrete_spaces::DiscreteSpace::get_axis */
/**
 * @brief Return the index of the axis containing the given knob.
 * @param knob The knob to search for.
 * @return The index of the axis containing the knob.
 * @throws std::runtime_error if the knob is not found.
 */
int DiscreteSpace_get_axis(DiscreteSpaceHandle  handle,
                           InstrumentPortHandle knob);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_get_domain |
 * falcon_core::math::discrete_spaces::DiscreteSpace::get_domain */
/**
 * @brief Return the domain of the given knob.
 * @param knob The knob to search for.
 * @return The domain of the knob.
 */
DomainHandle DiscreteSpace_get_domain(DiscreteSpaceHandle  handle,
                                      InstrumentPortHandle knob);
// @category:read
/* AUTO-DOC from cpp: DiscreteSpace_get_projection |
 * falcon_core::math::discrete_spaces::DiscreteSpace::get_projection */
/**
 * @brief Return the projection of the unit space onto the given axes.
 * @param projection The axes to project onto.
 * @return The projection of th espace onto the given axes.
 */
AxesLabelledControlArrayHandle DiscreteSpace_get_projection(
    DiscreteSpaceHandle handle, AxesInstrumentPortHandle projection);

#ifdef __cplusplus
}
#endif
