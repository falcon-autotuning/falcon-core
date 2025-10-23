#pragma once
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#include "falcon_core/math/domains/Domain_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
typedef void* LabelledDomainHandle;

// Constructors
LabelledDomainHandle LabelledDomain_create_primitive_knob(
    const char*      default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    const char*      instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    const char*      description = "");
LabelledDomainHandle LabelledDomain_create_primitive_meter(
    const char*      default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    const char*      instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    const char*      description = "");
LabelledDomainHandle LabelledDomain_create_primitive_port(
    const char*      default_name,
    double           min_val,
    double           max_val,
    ConnectionHandle psuedo_name,
    const char*      instrument_type,
    bool             lesser_bound_contained,
    bool             greater_bound_contained,
    SymbolUnitHandle units,
    const char*      description = "");
LabelledDomainHandle LabelledDomain_create_from_port(
    double               min_val,
    double               max_val,
    const char*          instrument_type,
    InstrumentPortHandle port,
    bool                 lesser_bound_contained  = true,
    bool                 greater_bound_contained = true);
LabelledDomainHandle LabelledDomain_create_from_port_and_domain(
    const char* instrument_type, DomainHandle domain);
LabelledDomainHandle LabelledDomain_create_from_domain(
    DomainHandle     domain,
    const char*      default_name,
    ConnectionHandle psuedo_name,
    const char*      instrument_type,
    SymbolUnitHandle units       = SymbolUnit_create_volt(),
    const char*      description = "");

// Destructor
void LabelledDomain_destroy(LabelledDomainHandle handle);

// Methods
InstrumentPortHandle LabelledDomain_port(LabelledDomainHandle handle);
DomainHandle         LabelledDomain_domain(LabelledDomainHandle handle);
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
const char*          LabelledDomain_to_json_string(LabelledDomainHandle handle);
LabelledDomainHandle LabelledDomain_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
