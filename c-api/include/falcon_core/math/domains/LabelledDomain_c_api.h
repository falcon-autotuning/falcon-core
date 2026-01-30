#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>

#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
typedef void* LabelledDomainHandle;

// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_copy(LabelledDomainHandle handle);
// @category:deallocation
FALCON_CORE_C_API void LabelledDomain_destroy(LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_equal(LabelledDomainHandle handle,
                                            LabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_not_equal(LabelledDomainHandle handle,
                                                LabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
LabelledDomain_to_json_string(LabelledDomainHandle handle);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_create_primitive_knob(StringHandle     default_name,
                                     double           min_val,
                                     double           max_val,
                                     ConnectionHandle psuedo_name,
                                     StringHandle     instrument_type,
                                     bool             lesser_bound_contained,
                                     bool             greater_bound_contained,
                                     SymbolUnitHandle units,
                                     StringHandle     description);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_create_primitive_meter(StringHandle     default_name,
                                      double           min_val,
                                      double           max_val,
                                      ConnectionHandle psuedo_name,
                                      StringHandle     instrument_type,
                                      bool             lesser_bound_contained,
                                      bool             greater_bound_contained,
                                      SymbolUnitHandle units,
                                      StringHandle     description);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_create_primitive_port(StringHandle     default_name,
                                     double           min_val,
                                     double           max_val,
                                     ConnectionHandle psuedo_name,
                                     StringHandle     instrument_type,
                                     bool             lesser_bound_contained,
                                     bool             greater_bound_contained,
                                     SymbolUnitHandle units,
                                     StringHandle     description);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_create_from_port(double               min_val,
                                double               max_val,
                                InstrumentPortHandle port,
                                bool                 lesser_bound_contained,
                                bool                 greater_bound_contained);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_create_from_port_and_domain(InstrumentPortHandle port,
                                           DomainHandle         domain);
// @category:allocation
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_create_from_domain(DomainHandle     domain,
                                  StringHandle     default_name,
                                  ConnectionHandle psuedo_name,
                                  StringHandle     instrument_type,
                                  SymbolUnitHandle units,
                                  StringHandle     description);
// @category:read
/* AUTO-DOC from cpp: LabelledDomain_port |
 * falcon_core::math::domains::LabelledDomain::port */
/**
 * @brief Get the port.
 * @return Shared pointer to the port.
 */
FALCON_CORE_C_API InstrumentPortHandle
LabelledDomain_port(LabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledDomain_domain |
 * falcon_core::math::domains::LabelledDomain::domain */
/**
 * @brief Gets the domain associated with the port.
 */
FALCON_CORE_C_API DomainHandle
LabelledDomain_domain(LabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledDomain_matching_port |
 * falcon_core::math::domains::LabelledDomain::matching_port */
/**
 * @brief Checks if the port matches the given port.
 * @param port The port to compare with.
 * @return True if the ports match, false otherwise.
 */
FALCON_CORE_C_API bool LabelledDomain_matching_port(LabelledDomainHandle handle,
                                                    InstrumentPortHandle port);
// @category:read
FALCON_CORE_C_API double LabelledDomain_lesser_bound(
    LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledDomain_greater_bound(
    LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_lesser_bound_contained(
    LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_greater_bound_contained(
    LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_in(LabelledDomainHandle handle,
                                         double               value);
// @category:read
FALCON_CORE_C_API double LabelledDomain_range(LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API double LabelledDomain_center(LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle LabelledDomain_intersection(
    LabelledDomainHandle handle, LabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_union(LabelledDomainHandle handle, LabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_is_empty(LabelledDomainHandle handle);
// @category:read
FALCON_CORE_C_API bool LabelledDomain_contains_domain(
    LabelledDomainHandle handle, LabelledDomainHandle other);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_shift(LabelledDomainHandle handle, double offset);
// @category:read
FALCON_CORE_C_API LabelledDomainHandle
LabelledDomain_scale(LabelledDomainHandle handle, double scale);
// @category:read
FALCON_CORE_C_API double LabelledDomain_transform(LabelledDomainHandle handle,
                                                  LabelledDomainHandle other,
                                                  double               value);

#ifdef __cplusplus
}
#endif
