

# File InstrumentPort\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**names**](dir_fb9004cf3d6d1aecbf7000576bf4839c.md) **>** [**InstrumentPort\_c\_api.h**](InstrumentPort__c__api_8h.md)

[Go to the documentation of this file](InstrumentPort__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"

typedef void* InstrumentPortHandle;

// @category:allocation
InstrumentPortHandle InstrumentPort_copy(InstrumentPortHandle handle);
// @category:deallocation
void InstrumentPort_destroy(InstrumentPortHandle handle);
// @category:read
bool InstrumentPort_equal(InstrumentPortHandle handle,
                          InstrumentPortHandle other);
// @category:read
bool InstrumentPort_not_equal(InstrumentPortHandle handle,
                              InstrumentPortHandle other);
// @category:read
StringHandle InstrumentPort_to_json_string(InstrumentPortHandle handle);
// @category:allocation
InstrumentPortHandle InstrumentPort_from_json_string(StringHandle json);
// @category:allocation
InstrumentPortHandle InstrumentPort_create_port(StringHandle     default_name,
                                                ConnectionHandle psuedo_name,
                                                StringHandle instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle     description);
// @category:allocation
InstrumentPortHandle InstrumentPort_create_knob(StringHandle     default_name,
                                                ConnectionHandle psuedo_name,
                                                StringHandle instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle     description);
// @category:allocation
InstrumentPortHandle InstrumentPort_create_meter(StringHandle     default_name,
                                                 ConnectionHandle psuedo_name,
                                                 StringHandle instrument_type,
                                                 SymbolUnitHandle units,
                                                 StringHandle     description);
// @category:allocation
InstrumentPortHandle InstrumentPort_create_timer();
// @category:allocation
InstrumentPortHandle InstrumentPort_create_execution_clock();

// @category:read
/* AUTO-DOC from cpp: InstrumentPort_default_name |
 * falcon_core::instrument_interfaces::names::InstrumentPort::default_name */
StringHandle InstrumentPort_default_name(InstrumentPortHandle handle);
// @category:read
ConnectionHandle InstrumentPort_psuedo_name(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_instrument_type |
 * falcon_core::instrument_interfaces::names::InstrumentPort::instrument_type */
StringHandle InstrumentPort_instrument_type(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_units |
 * falcon_core::instrument_interfaces::names::InstrumentPort::units */
SymbolUnitHandle InstrumentPort_units(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_description |
 * falcon_core::instrument_interfaces::names::InstrumentPort::description */
StringHandle InstrumentPort_description(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_instrument_facing_name |
 * falcon_core::instrument_interfaces::names::InstrumentPort::instrument_facing_name
 */
StringHandle InstrumentPort_instrument_facing_name(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_is_knob |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_knob */
bool InstrumentPort_is_knob(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_is_meter |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_meter */
bool InstrumentPort_is_meter(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_is_port |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_port */
bool InstrumentPort_is_port(InstrumentPortHandle handle);

#ifdef __cplusplus
}
#endif
```


