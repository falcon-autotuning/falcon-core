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

// Constructors
InstrumentPortHandle InstrumentPort_create_port(StringHandle     default_name,
                                                ConnectionHandle psuedo_name,
                                                StringHandle instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle     description);
InstrumentPortHandle InstrumentPort_create_knob(StringHandle     default_name,
                                                ConnectionHandle psuedo_name,
                                                StringHandle instrument_type,
                                                SymbolUnitHandle units,
                                                StringHandle     description);
InstrumentPortHandle InstrumentPort_create_meter(StringHandle     default_name,
                                                 ConnectionHandle psuedo_name,
                                                 StringHandle instrument_type,
                                                 SymbolUnitHandle units,
                                                 StringHandle     description);
InstrumentPortHandle InstrumentPort_create_timer();
InstrumentPortHandle InstrumentPort_create_execution_clock();

// Destructor
void InstrumentPort_destroy(InstrumentPortHandle handle);

// Methods
StringHandle     InstrumentPort_default_name(InstrumentPortHandle handle);
ConnectionHandle InstrumentPort_psuedo_name(InstrumentPortHandle handle);
StringHandle     InstrumentPort_instrument_type(InstrumentPortHandle handle);
SymbolUnitHandle InstrumentPort_units(InstrumentPortHandle handle);
StringHandle     InstrumentPort_description(InstrumentPortHandle handle);
StringHandle InstrumentPort_instrument_facing_name(InstrumentPortHandle handle);
bool         InstrumentPort_is_knob(InstrumentPortHandle handle);
bool         InstrumentPort_is_meter(InstrumentPortHandle handle);
bool         InstrumentPort_is_port(InstrumentPortHandle handle);
bool         InstrumentPort_equal(InstrumentPortHandle handle,
                                  InstrumentPortHandle other);
bool         InstrumentPort_not_equal(InstrumentPortHandle handle,
                                      InstrumentPortHandle other);

// Serialization (from Song)
StringHandle         InstrumentPort_to_json_string(InstrumentPortHandle handle);
InstrumentPortHandle InstrumentPort_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
