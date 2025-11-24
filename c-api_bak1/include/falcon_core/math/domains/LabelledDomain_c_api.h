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

// Constructors
LabelledDomainHandle LabelledDomain_create_primitive_knob(
    StringHandle     default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle     description);
LabelledDomainHandle LabelledDomain_create_primitive_meter(
    StringHandle     default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle     description);
LabelledDomainHandle LabelledDomain_create_primitive_port(
    StringHandle     default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    StringHandle     description);
LabelledDomainHandle LabelledDomain_create_from_port(
    double               min_val,
    double               max_val,
    StringHandle         instrument_type,
    InstrumentPortHandle port,
    bool                 lesser_bound_contained,
    bool                 greater_bound_contained);
LabelledDomainHandle LabelledDomain_create_from_port_and_domain(
    InstrumentPortHandle port, DomainHandle domain);
LabelledDomainHandle LabelledDomain_create_from_domain(
    DomainHandle     domain,
    StringHandle     default_name,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    SymbolUnitHandle units,
    StringHandle     description);

// Destructor
void LabelledDomain_destroy(LabelledDomainHandle handle);

// Methods
/* AUTO-DOC from cpp: LabelledDomain_port | falcon_core::math::domains::LabelledDomain::port */
/**
 * @brief (from C++: falcon_core::math::domains::LabelledDomain::port)
 * @brief Get the port.
 * @return Shared pointer to the port.
 */
InstrumentPortHandle LabelledDomain_port(LabelledDomainHandle handle);
/* AUTO-DOC from cpp: LabelledDomain_domain | falcon_core::math::domains::LabelledDomain::domain */
/**
 * @brief (from C++: falcon_core::math::domains::LabelledDomain::domain)
 * @brief Gets the domain associated with the port.
 */
DomainHandle         LabelledDomain_domain(LabelledDomainHandle handle);
/* AUTO-DOC from cpp: LabelledDomain_matching_port | falcon_core::math::domains::LabelledDomain::matching_port */
/**
 * @brief (from C++: falcon_core::math::domains::LabelledDomain::matching_port)
 * @brief Checks if the port matches the given port.
 * @param port The port to compare with.
 * @return True if the ports match, false otherwise.
 */
bool                 LabelledDomain_matching_port(LabelledDomainHandle handle,
                                                  InstrumentPortHandle port);
double               LabelledDomain_lesser_bound(LabelledDomainHandle handle);
double               LabelledDomain_greater_bound(LabelledDomainHandle handle);
bool   LabelledDomain_lesser_bound_contained(LabelledDomainHandle handle);
bool   LabelledDomain_greater_bound_contained(LabelledDomainHandle handle);
bool   LabelledDomain_in(LabelledDomainHandle handle, double value);
double LabelledDomain_range(LabelledDomainHandle handle);
double LabelledDomain_center(LabelledDomainHandle handle);
LabelledDomainHandle LabelledDomain_intersection(LabelledDomainHandle handle,
                                                 LabelledDomainHandle other);
LabelledDomainHandle LabelledDomain_union(LabelledDomainHandle handle,
                                          LabelledDomainHandle other);
bool                 LabelledDomain_is_empty(LabelledDomainHandle handle);
bool                 LabelledDomain_contains_domain(LabelledDomainHandle handle,
                                                    LabelledDomainHandle other);
LabelledDomainHandle LabelledDomain_shift(LabelledDomainHandle handle,
                                          double               offset);
LabelledDomainHandle LabelledDomain_scale(LabelledDomainHandle handle,
                                          double               scale);
double               LabelledDomain_transform(LabelledDomainHandle handle,
                                              LabelledDomainHandle other,
                                              double               value);
bool                 LabelledDomain_equal(LabelledDomainHandle handle,
                                          LabelledDomainHandle other);
bool                 LabelledDomain_not_equal(LabelledDomainHandle handle,
                                              LabelledDomainHandle other);

// Serialization (from Song)
StringHandle         LabelledDomain_to_json_string(LabelledDomainHandle handle);
LabelledDomainHandle LabelledDomain_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
