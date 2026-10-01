#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

typedef void *InstrumentPortHandle;

typedef enum { PORT_TYPE_KNOB, PORT_TYPE_METER, PORT_TYPE_SETTING } PortType;
typedef enum { SCOPE_LOCAL, SCOPE_GLOBAL } Scope;
typedef enum { ACCESS_READ, ACCESS_WRITE, ACCESS_READWRITE } Access;
typedef enum {
  INSTRUMENT_DC_VOLTAGE_SOURCE,
  INSTRUMENT_AMNMETER,
  INSTRUMENT_MAGNET,
  INSTRUMENT_LOCKIN,
  INSTRUMENT_VOLTAGE_SOURCE,
  INSTRUMENT_CURRENT_SOURCE,
  INSTRUMENT_HF_VOLTAGE_SOURCE,
  INSTRUMENT_DC_CURRENT_SOURCE,
  INSTRUMENT_HF_CURRENT_SOURCE,
  INSTRUMENT_THERMOMETER,
  INSTRUMENT_VOLTMETER,
  INSTRUMENT_FPGA,
  INSTRUMENT_CLOCK,
  INSTRUMENT_DISCRETE
} Instrument;
typedef enum {
  INSTRUMENT_CHARACTERISTIC_NONE,
  INSTRUMENT_CHARACTERISTIC_SAMPLE_RATE,
  INSTRUMENT_CHARACTERISTIC_MAX_SAMPLE_RATE,
  INSTRUMENT_CHARACTERISTIC_MIN_SAMPLE_RATE,
  INSTRUMENT_CHARACTERISTIC_APPLIED_VOLTAGE,
  INSTRUMENT_CHARACTERISTIC_MAX_SOURCE_VOLTAGE,
  INSTRUMENT_CHARACTERISTIC_MIN_SOURCE_VOLTAGE,
  INSTRUMENT_CHARACTERISTIC_NUMBER_OF_SAMPLES,
  INSTRUMENT_CHARACTERISTIC_MAX_NUMBER_OF_SAMPLES,
  INSTRUMENT_CHARACTERISTIC_MIN_NUMBER_OF_SAMPLES,
  INSTRUMENT_CHARACTERISTIC_VOLTAGE_RAMP_SLOPE,
  INSTRUMENT_CHARACTERISTIC_MAX_VOLTAGE_RAMP_SLOPE,
  INSTRUMENT_CHARACTERISTIC_MIN_VOLTAGE_RAMP_SLOPE,
  INSTRUMENT_CHARACTERISTIC_TEMPERATURE,
  INSTRUMENT_CHARACTERISTIC_MAGNET_STRENGTH
} InstrumentCharacteristic;

// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle
InstrumentPort_copy(InstrumentPortHandle handle);
// @category:deallocation
FALCON_CORE_C_API void InstrumentPort_destroy(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API bool InstrumentPort_equal(InstrumentPortHandle handle,
                                            InstrumentPortHandle other);
// @category:read
FALCON_CORE_C_API bool InstrumentPort_not_equal(InstrumentPortHandle handle,
                                                InstrumentPortHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
InstrumentPort_to_json_string(InstrumentPortHandle handle);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle
InstrumentPort_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle InstrumentPort_create_port(
    StringHandle default_name, StringHandle instrument_name, Scope scope,
    Access access, InstrumentCharacteristic characteristic, PortType type,
    ConnectionHandle pseudo_name, Instrument instrument_type,
    SymbolUnitHandle units, StringHandle description);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle InstrumentPort_create_setting(
    StringHandle default_name, StringHandle instrument_name, Scope scope,
    Access access, InstrumentCharacteristic characteristic,
    ConnectionHandle pseudo_name, Instrument instrument_type,
    SymbolUnitHandle units, StringHandle description);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle InstrumentPort_create_knob(
    StringHandle default_name, StringHandle instrument_name,
    ConnectionHandle pseudo_name, Instrument instrument_type,
    SymbolUnitHandle units, StringHandle description);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle InstrumentPort_create_meter(
    StringHandle default_name, StringHandle instrument_name,
    ConnectionHandle pseudo_name, Instrument instrument_type,
    SymbolUnitHandle units, StringHandle description);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle InstrumentPort_create_timer();
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle InstrumentPort_create_execution_clock();

// @category:read
/* AUTO-DOC from cpp: InstrumentPort_default_name |
 * falcon_core::instrument_interfaces::names::InstrumentPort::default_name */
/**
 * @brief Rreturn the default name of the port.
 */
FALCON_CORE_C_API StringHandle
InstrumentPort_default_name(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API StringHandle
InstrumentPort_instrument_name(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle
InstrumentPort_pseudo_name(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_instrument_type |
 * falcon_core::instrument_interfaces::names::InstrumentPort::instrument_type */
/**
 * @brief Returns the type of the instrument that the port is connected to.
 */
FALCON_CORE_C_API Instrument
InstrumentPort_instrument_type(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API Scope InstrumentPort_scope(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API Access InstrumentPort_access(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API InstrumentCharacteristic
InstrumentPort_characteristic(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_units |
 * falcon_core::instrument_interfaces::names::InstrumentPort::units */
/**
 * @brief Returns the untis of the port.
 */
FALCON_CORE_C_API SymbolUnitHandle
InstrumentPort_units(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_description |
 * falcon_core::instrument_interfaces::names::InstrumentPort::description */
/**
 * @brief Returns the description of the port.
 */
FALCON_CORE_C_API StringHandle
InstrumentPort_description(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_instrument_facing_name |
 * falcon_core::instrument_interfaces::names::InstrumentPort::instrument_facing_name
 */
/**
 * @brief Returns the pseudo name if it exists, otherwise the instrument type
 * as a string.
 */
FALCON_CORE_C_API StringHandle
InstrumentPort_instrument_facing_name(InstrumentPortHandle handle);
// @category:read
FALCON_CORE_C_API PortType InstrumentPort_type(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_is_knob |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_knob */
/**
 * @brief Checks if this port is a knob.
 */
FALCON_CORE_C_API bool InstrumentPort_is_knob(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_is_meter |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_meter */
/**
 * @brief Checks if this port is a meter.
 */
FALCON_CORE_C_API bool InstrumentPort_is_meter(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_is_setting |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_setting */
/**
 * @brief Checks if this port is a setting.
 */
FALCON_CORE_C_API bool InstrumentPort_is_setting(InstrumentPortHandle handle);

#ifdef __cplusplus
}
#endif
