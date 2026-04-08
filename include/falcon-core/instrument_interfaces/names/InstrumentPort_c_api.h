#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

#include "falcon-core/generic/String_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentTypes_c_api.h"
#include "falcon-core/physics/device_structures/Connection_c_api.h"
#include "falcon-core/physics/units/SymbolUnit_c_api.h"

typedef void* InstrumentPortHandle;

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
FALCON_CORE_C_API InstrumentPortHandle
InstrumentPort_create_port(StringHandle     default_name,
                           ConnectionHandle psuedo_name,
                           StringHandle     instrument_type,
                           SymbolUnitHandle units,
                           StringHandle     description);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle
InstrumentPort_create_knob(StringHandle     default_name,
                           ConnectionHandle psuedo_name,
                           StringHandle     instrument_type,
                           SymbolUnitHandle units,
                           StringHandle     description);
// @category:allocation
FALCON_CORE_C_API InstrumentPortHandle
InstrumentPort_create_meter(StringHandle     default_name,
                            ConnectionHandle psuedo_name,
                            StringHandle     instrument_type,
                            SymbolUnitHandle units,
                            StringHandle     description);
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
FALCON_CORE_C_API ConnectionHandle
InstrumentPort_psuedo_name(InstrumentPortHandle handle);
// @category:read
/* AUTO-DOC from cpp: InstrumentPort_instrument_type |
 * falcon_core::instrument_interfaces::names::InstrumentPort::instrument_type */
/**
 * @brief Returns the type of the instrument that the port is connected to.
 */
FALCON_CORE_C_API StringHandle
InstrumentPort_instrument_type(InstrumentPortHandle handle);
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
 * @brief Returns the psuedo name if it exists, otherwise the instrument type
 * as a string.
 */
FALCON_CORE_C_API StringHandle
InstrumentPort_instrument_facing_name(InstrumentPortHandle handle);
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
/* AUTO-DOC from cpp: InstrumentPort_is_port |
 * falcon_core::instrument_interfaces::names::InstrumentPort::is_port */
/**
 * @brief Checks if this port is a port.
 */
FALCON_CORE_C_API bool InstrumentPort_is_port(InstrumentPortHandle handle);

#ifdef __cplusplus
}
#endif
