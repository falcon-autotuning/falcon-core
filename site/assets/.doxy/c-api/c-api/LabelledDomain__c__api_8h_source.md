

# File LabelledDomain\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**math**](dir_5926e65cd25d57bf5041735c2c12a8f7.md) **>** [**domains**](dir_f5c6b653fd63ad902756e04c4af35f80.md) **>** [**LabelledDomain\_c\_api.h**](LabelledDomain__c__api_8h.md)

[Go to the documentation of this file](LabelledDomain__c__api_8h.md)


```C++
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
LabelledDomainHandle LabelledDomain_copy(LabelledDomainHandle handle);
// @category:deallocation
void LabelledDomain_destroy(LabelledDomainHandle handle);
// @category:read
bool LabelledDomain_equal(LabelledDomainHandle handle,
                          LabelledDomainHandle other);
// @category:read
bool LabelledDomain_not_equal(LabelledDomainHandle handle,
                              LabelledDomainHandle other);
// @category:read
StringHandle LabelledDomain_to_json_string(LabelledDomainHandle handle);
// @category:allocation
LabelledDomainHandle LabelledDomain_from_json_string(StringHandle json);
// @category:allocation
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
// @category:allocation
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
// @category:allocation
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
// @category:allocation
LabelledDomainHandle LabelledDomain_create_from_port(
    double               min_val,
    double               max_val,
    InstrumentPortHandle port,
    bool                 lesser_bound_contained,
    bool                 greater_bound_contained);
// @category:allocation
LabelledDomainHandle LabelledDomain_create_from_port_and_domain(
    InstrumentPortHandle port, DomainHandle domain);
// @category:allocation
LabelledDomainHandle LabelledDomain_create_from_domain(
    DomainHandle     domain,
    StringHandle     default_name,
    ConnectionHandle psuedo_name,
    StringHandle     instrument_type,
    SymbolUnitHandle units,
    StringHandle     description);
// @category:read
/* AUTO-DOC from cpp: LabelledDomain_port |
 * falcon_core::math::domains::LabelledDomain::port */
InstrumentPortHandle LabelledDomain_port(LabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledDomain_domain |
 * falcon_core::math::domains::LabelledDomain::domain */
DomainHandle LabelledDomain_domain(LabelledDomainHandle handle);
// @category:read
/* AUTO-DOC from cpp: LabelledDomain_matching_port |
 * falcon_core::math::domains::LabelledDomain::matching_port */
bool LabelledDomain_matching_port(LabelledDomainHandle handle,
                                  InstrumentPortHandle port);
// @category:read
double LabelledDomain_lesser_bound(LabelledDomainHandle handle);
// @category:read
double LabelledDomain_greater_bound(LabelledDomainHandle handle);
// @category:read
bool LabelledDomain_lesser_bound_contained(LabelledDomainHandle handle);
// @category:read
bool LabelledDomain_greater_bound_contained(LabelledDomainHandle handle);
// @category:read
bool LabelledDomain_in(LabelledDomainHandle handle, double value);
// @category:read
double LabelledDomain_range(LabelledDomainHandle handle);
// @category:read
double LabelledDomain_center(LabelledDomainHandle handle);
// @category:read
LabelledDomainHandle LabelledDomain_intersection(LabelledDomainHandle handle,
                                                 LabelledDomainHandle other);
// @category:read
LabelledDomainHandle LabelledDomain_union(LabelledDomainHandle handle,
                                          LabelledDomainHandle other);
// @category:read
bool LabelledDomain_is_empty(LabelledDomainHandle handle);
// @category:read
bool LabelledDomain_contains_domain(LabelledDomainHandle handle,
                                    LabelledDomainHandle other);
// @category:read
LabelledDomainHandle LabelledDomain_shift(LabelledDomainHandle handle,
                                          double               offset);
// @category:read
LabelledDomainHandle LabelledDomain_scale(LabelledDomainHandle handle,
                                          double               scale);
// @category:read
double LabelledDomain_transform(LabelledDomainHandle handle,
                                LabelledDomainHandle other,
                                double               value);

#ifdef __cplusplus
}
#endif
```


