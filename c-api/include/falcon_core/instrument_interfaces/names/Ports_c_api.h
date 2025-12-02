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
PortsHandle Ports_create_empty();
// @category:allocation
PortsHandle Ports_create(ListInstrumentPortHandle items);
// @category:deallocation
void Ports_destroy(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports_ports | falcon_core::instrument_interfaces::names::Ports::ports */
/**
 * @brief return the collection of ports.
 */
ListInstrumentPortHandle Ports_ports(PortsHandle handle);
// @category:read
ListStringHandle Ports_default_names(PortsHandle handle);
// @category:read
ListConnectionHandle Ports_get_psuedo_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_raw_names | falcon_core::instrument_interfaces::names::Ports::_get_raw_names */
/**
 * @brief Return the raw string names of the ports.
 */
ListStringHandle Ports__get_raw_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_instrument_facing_names | falcon_core::instrument_interfaces::names::Ports::_get_instrument_facing_names */
/**
 * @brief Gets a llist of names to satisfy an instrument interface.
 */
ListStringHandle Ports__get_instrument_facing_names(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports__get_psuedoname_matching_port | falcon_core::instrument_interfaces::names::Ports::_get_psuedoname_matching_port */
/**
 * @brief Check if any port has the given pseudo name.
 * @param name The pseudo name to check for.
 * @return The port with the given name
 * @throws std::runtime_error if no port has the given name.
 */
InstrumentPortHandle Ports__get_psuedoname_matching_port(PortsHandle handle,
                                                         ConnectionHandle name);
// @category:read
/* AUTO-DOC from cpp: Ports__get_instrument_type_matching_port | falcon_core::instrument_interfaces::names::Ports::_get_instrument_type_matching_port */
/**
 * @brief Check if any port has the given instrument type.
 * @param type The instrument type to check for.
 * @return The port with the given instrument type.
 * @throws std::runtime_error if no port has the given type.
 */
InstrumentPortHandle Ports__get_instrument_type_matching_port(
    PortsHandle handle, StringHandle insttype);
// @category:read
/* AUTO-DOC from cpp: Ports_is_knobs | falcon_core::instrument_interfaces::names::Ports::is_knobs */
/**
 * @brief Check if the ports contains only knobs.
 * @return True if the ports only contain knobs.
 */
bool Ports_is_knobs(PortsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Ports_is_meters | falcon_core::instrument_interfaces::names::Ports::is_meters */
/**
 * @brief Check if the ports contains only meters.
 * @return True if the ports only contain meters.
 */
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
// @category:read
bool Ports_equal(PortsHandle a, PortsHandle b);
// @category:read
bool Ports_not_equal(PortsHandle a, PortsHandle b);
// @category:read
StringHandle Ports_to_json_string(PortsHandle handle);
// @category:allocation
PortsHandle Ports_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
