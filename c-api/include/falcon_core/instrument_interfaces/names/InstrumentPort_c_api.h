#pragma once
#include <cstddef>

#include "falcon_core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/physics/units/SymbolUnit_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef void* InstrumentPortHandle;

// Constructors
InstrumentPortHandle InstrumentPort_create_port(
    const char*      default_name,
    ConnectionHandle psuedo_name     = NULL,
    const char*      instrument_type = InstrumentTypes_dc_voltage_source(),
    SymbolUnitHandle units           = SymbolUnit_create_volt(),
    const char*      description     = "");
InstrumentPortHandle InstrumentPort_create_knob(
    const char*      default_name,
    ConnectionHandle psuedo_name     = NULL,
    const char*      instrument_type = InstrumentTypes_dc_voltage_source(),
    SymbolUnitHandle units           = SymbolUnit_create_millivolt(),
    const char*      description     = "A default voltage source");
InstrumentPortHandle InstrumentPort_create_meter(
    const char*      default_name,
    ConnectionHandle psuedo_name     = NULL,
    const char*      instrument_type = InstrumentTypes_amnmeter(),
    SymbolUnitHandle units           = SymbolUnit_create_nanoampere(),
    const char*      description = "A default current instrument interface");
InstrumentPortHandle InstrumentPort_create_timer();
InstrumentPortHandle InstrumentPort_create_execution_clock();

// Destructor
void InstrumentPort_destroy(InstrumentPortHandle handle);

// Methods
const char*      InstrumentPort_default_name(InstrumentPortHandle handle);
ConnectionHandle InstrumentPort_psuedo_name(InstrumentPortHandle handle);
const char*      InstrumentPort_instrument_type(InstrumentPortHandle handle);
SymbolUnitHandle InstrumentPort_units(InstrumentPortHandle handle);
const char*      InstrumentPort_description(InstrumentPortHandle handle);
const char* InstrumentPort_instrument_facing_name(InstrumentPortHandle handle);
bool        InstrumentPort_is_knob(InstrumentPortHandle handle);
bool        InstrumentPort_is_meter(InstrumentPortHandle handle);
bool        InstrumentPort_is_port(InstrumentPortHandle handle);
bool        InstrumentPort_equal(InstrumentPortHandle handle,
                                 InstrumentPortHandle other);
bool        InstrumentPort_not_equal(InstrumentPortHandle handle,
                                     InstrumentPortHandle other);

// Serialization (from Song)
const char*          InstrumentPort_to_json_string(InstrumentPortHandle handle);
InstrumentPortHandle InstrumentPort_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif
