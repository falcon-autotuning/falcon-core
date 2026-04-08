#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>

#include "falcon-core/generic/ListConnection_c_api.h"
#include "falcon-core/generic/ListInstrumentPort_c_api.h"
#include "falcon-core/generic/ListString_c_api.h"
#include "falcon-core/instrument_interfaces/names/InstrumentPort_c_api.h"

typedef void* PortsHandle;

// @category:allocation
FALCON_CORE_C_API PortsHandle Ports_copy(PortsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Ports_destroy(PortsHandle handle);
// @category:read
FALCON_CORE_C_API bool Ports_equal(PortsHandle handle, PortsHandle other);
// @category:read
FALCON_CORE_C_API bool Ports_not_equal(PortsHandle handle, PortsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle Ports_to_json_string(PortsHandle handle);
// @category:allocation
FALCON_CORE_C_API PortsHandle Ports_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API PortsHandle Ports_create_empty();
// @category:allocation
FALCON_CORE_C_API PortsHandle Ports_create(ListInstrumentPortHandle items);
// @category:read
/* AUTO-DOC from cpp: Ports_ports |
 * falcon_core::instrument_interfaces::names::Ports::ports */
/**
 * @brief return the collection of ports.
 */
FALCON_CORE_C_API ListInstrumentPortHandle Ports_ports(PortsHandle handle);
// @category:read
FALCON_CORE_C_API ListStringHandle Ports_default_names(PortsHandle handle);
// @category:read
FALCON_CORE_C_API ListConnectionHandle
Ports_get_psuedo_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_raw_names |
 * falcon_core::instrument_interfaces::names::Ports::_get_raw_names */
/**
 * @brief Return the raw string names of the ports.
 */
FALCON_CORE_C_API ListStringHandle Ports__get_raw_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_instrument_facing_names |
 * falcon_core::instrument_interfaces::names::Ports::_get_instrument_facing_names
 */
/**
 * @brief Gets a llist of names to satisfy an instrument interface.
 */
FALCON_CORE_C_API ListStringHandle
Ports__get_instrument_facing_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_psuedoname_matching_port |
 * falcon_core::instrument_interfaces::names::Ports::_get_psuedoname_matching_port
 */
/**
 * @brief Check if any port has the given pseudo name.
 * @param name The pseudo name to check for.
 * @return The port with the given name
 * @throws std::runtime_error if no port has the given name.
 */
FALCON_CORE_C_API InstrumentPortHandle
Ports__get_psuedoname_matching_port(PortsHandle handle, ConnectionHandle name);
// @category:read
/* AUTO-DOC from cpp: Ports__get_instrument_type_matching_port |
 * falcon_core::instrument_interfaces::names::Ports::_get_instrument_type_matching_port
 */
/**
 * @brief Check if any port has the given instrument type.
 * @param type The instrument type to check for.
 * @return The port with the given instrument type.
 * @throws std::runtime_error if no port has the given type.
 */
FALCON_CORE_C_API InstrumentPortHandle Ports__get_instrument_type_matching_port(
    PortsHandle handle, StringHandle insttype);
// @category:read
/* AUTO-DOC from cpp: Ports_is_knobs |
 * falcon_core::instrument_interfaces::names::Ports::is_knobs */
/**
 * @brief Check if the ports contains only knobs.
 * @return True if the ports only contain knobs.
 */
FALCON_CORE_C_API bool Ports_is_knobs(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports_is_meters |
 * falcon_core::instrument_interfaces::names::Ports::is_meters */
/**
 * @brief Check if the ports contains only meters.
 * @return True if the ports only contain meters.
 */
FALCON_CORE_C_API bool Ports_is_meters(PortsHandle handle);
// @category:read
FALCON_CORE_C_API PortsHandle Ports_intersection(PortsHandle handle,
                                                 PortsHandle other);
// @category:write
FALCON_CORE_C_API void Ports_push_back(PortsHandle          handle,
                                       InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API size_t Ports_size(PortsHandle handle);
// @category:read
FALCON_CORE_C_API bool Ports_empty(PortsHandle handle);
// @category:write
FALCON_CORE_C_API void Ports_erase_at(PortsHandle handle, size_t idx);
// @category:write
FALCON_CORE_C_API void Ports_clear(PortsHandle handle);
// @category:read
FALCON_CORE_C_API InstrumentPortHandle Ports_at(PortsHandle handle, size_t idx);
// @category:read
FALCON_CORE_C_API ListStringHandle Ports_items(PortsHandle handle);
// @category:read
FALCON_CORE_C_API bool Ports_contains(PortsHandle          handle,
                                      InstrumentPortHandle value);
// @category:read
FALCON_CORE_C_API size_t Ports_index(PortsHandle          handle,
                                     InstrumentPortHandle value);

#ifdef __cplusplus
}
#endif
