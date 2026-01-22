

# File Ports\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**instrument\_interfaces**](dir_9a3e3629c63b09e0e53088699a1e2284.md) **>** [**names**](dir_fb9004cf3d6d1aecbf7000576bf4839c.md) **>** [**Ports\_c\_api.h**](Ports__c__api_8h.md)

[Go to the documentation of this file](Ports__c__api_8h.md)


```C++
#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"

typedef void* PortsHandle;

// @category:allocation
PortsHandle Ports_copy(PortsHandle handle);
// @category:deallocation
void Ports_destroy(PortsHandle handle);
// @category:read
bool Ports_equal(PortsHandle handle, PortsHandle other);
// @category:read
bool Ports_not_equal(PortsHandle handle, PortsHandle other);
// @category:read
StringHandle Ports_to_json_string(PortsHandle handle);
// @category:allocation
PortsHandle Ports_from_json_string(StringHandle json);
// @category:allocation
PortsHandle Ports_create_empty();
// @category:allocation
PortsHandle Ports_create(ListInstrumentPortHandle items);
// @category:read
/* AUTO-DOC from cpp: Ports_ports |
 * falcon_core::instrument_interfaces::names::Ports::ports */
ListInstrumentPortHandle Ports_ports(PortsHandle handle);
// @category:read
ListStringHandle Ports_default_names(PortsHandle handle);
// @category:read
ListConnectionHandle Ports_get_psuedo_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_raw_names |
 * falcon_core::instrument_interfaces::names::Ports::_get_raw_names */
ListStringHandle Ports__get_raw_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_instrument_facing_names |
 * falcon_core::instrument_interfaces::names::Ports::_get_instrument_facing_names
 */
ListStringHandle Ports__get_instrument_facing_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_psuedoname_matching_port |
 * falcon_core::instrument_interfaces::names::Ports::_get_psuedoname_matching_port
 */
InstrumentPortHandle Ports__get_psuedoname_matching_port(PortsHandle handle,
                                                         ConnectionHandle name);
// @category:read
/* AUTO-DOC from cpp: Ports__get_instrument_type_matching_port |
 * falcon_core::instrument_interfaces::names::Ports::_get_instrument_type_matching_port
 */
InstrumentPortHandle Ports__get_instrument_type_matching_port(
    PortsHandle handle, StringHandle insttype);
// @category:read
/* AUTO-DOC from cpp: Ports_is_knobs |
 * falcon_core::instrument_interfaces::names::Ports::is_knobs */
bool Ports_is_knobs(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports_is_meters |
 * falcon_core::instrument_interfaces::names::Ports::is_meters */
bool Ports_is_meters(PortsHandle handle);
// @category:read
PortsHandle Ports_intersection(PortsHandle handle, PortsHandle other);
// @category:write
void Ports_push_back(PortsHandle handle, InstrumentPortHandle value);
// @category:read
size_t Ports_size(PortsHandle handle);
// @category:read
bool Ports_empty(PortsHandle handle);
// @category:write
void Ports_erase_at(PortsHandle handle, size_t idx);
// @category:write
void Ports_clear(PortsHandle handle);
// @category:read
InstrumentPortHandle Ports_at(PortsHandle handle, size_t idx);
// @category:read
ListStringHandle Ports_items(PortsHandle handle);
// @category:read
bool Ports_contains(PortsHandle handle, InstrumentPortHandle value);
// @category:read
size_t Ports_index(PortsHandle handle, InstrumentPortHandle value);

#ifdef __cplusplus
}
#endif
```


