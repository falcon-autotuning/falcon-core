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
// @category:deallocation
void InstrumentPort_destroy(InstrumentPortHandle handle);

// @category:read
StringHandle InstrumentPort_default_name(InstrumentPortHandle handle);
// @category:read
ConnectionHandle InstrumentPort_psuedo_name(InstrumentPortHandle handle);
// @category:read
StringHandle InstrumentPort_instrument_type(InstrumentPortHandle handle);
// @category:read
SymbolUnitHandle InstrumentPort_units(InstrumentPortHandle handle);
// @category:read
StringHandle InstrumentPort_description(InstrumentPortHandle handle);
// @category:read
StringHandle InstrumentPort_instrument_facing_name(InstrumentPortHandle handle);
// @category:read
bool InstrumentPort_is_knob(InstrumentPortHandle handle);
// @category:read
bool InstrumentPort_is_meter(InstrumentPortHandle handle);
// @category:read
bool InstrumentPort_is_port(InstrumentPortHandle handle);
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

#ifdef __cplusplus
}
#endif
