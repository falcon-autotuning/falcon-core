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

// Constructors
PortsHandle Ports_create_empty();
PortsHandle Ports_create(ListInstrumentPortHandle items);

// Destructor
void Ports_destroy(PortsHandle handle);

// Methods
/* AUTO-DOC from cpp: Ports_ports | falcon_core::instrument_interfaces::names::Ports::ports */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::ports)
 * @brief return the collection of ports.
 */
ListInstrumentPortHandle Ports_ports(PortsHandle handle);
ListStringHandle         Ports_default_names(PortsHandle handle);
ListConnectionHandle     Ports_get_psuedo_names(PortsHandle handle);
/* AUTO-DOC from cpp: Ports__get_raw_names | falcon_core::instrument_interfaces::names::Ports::_get_raw_names */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::_get_raw_names)
 * @brief Return the raw string names of the ports.
 */
ListStringHandle         Ports__get_raw_names(PortsHandle handle);
/* AUTO-DOC from cpp: Ports__get_instrument_facing_names | falcon_core::instrument_interfaces::names::Ports::_get_instrument_facing_names */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::_get_instrument_facing_names)
 * @brief Gets a llist of names to satisfy an instrument interface.
 */
ListStringHandle         Ports__get_instrument_facing_names(PortsHandle handle);
/* AUTO-DOC from cpp: Ports__get_psuedoname_matching_port | falcon_core::instrument_interfaces::names::Ports::_get_psuedoname_matching_port */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::_get_psuedoname_matching_port)
 * @brief Check if any port has the given pseudo name.
 * @param name The pseudo name to check for.
 * @return The port with the given name
 * @throws std::runtime_error if no port has the given name.
 */
InstrumentPortHandle     Ports__get_psuedoname_matching_port(PortsHandle handle,
                                                             ConnectionHandle name);
/* AUTO-DOC from cpp: Ports__get_instrument_type_matching_port | falcon_core::instrument_interfaces::names::Ports::_get_instrument_type_matching_port */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::_get_instrument_type_matching_port)
 * @brief Check if any port has the given instrument type.
 * @param type The instrument type to check for.
 * @return The port with the given instrument type.
 * @throws std::runtime_error if no port has the given type.
 */
InstrumentPortHandle     Ports__get_instrument_type_matching_port(
        PortsHandle handle, StringHandle type);
/* AUTO-DOC from cpp: Ports_is_knobs | falcon_core::instrument_interfaces::names::Ports::is_knobs */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::is_knobs)
 * @brief Check if the ports contains only knobs.
 * @return True if the ports only contain knobs.
 */
bool        Ports_is_knobs(PortsHandle handle);
/* AUTO-DOC from cpp: Ports_is_meters | falcon_core::instrument_interfaces::names::Ports::is_meters */
/**
 * @brief (from C++: falcon_core::instrument_interfaces::names::Ports::is_meters)
 * @brief Check if the ports contains only meters.
 * @return True if the ports only contain meters.
 */
bool        Ports_is_meters(PortsHandle handle);
PortsHandle Ports_intersection(PortsHandle handle, PortsHandle other);
void        Ports_push_back(PortsHandle handle, InstrumentPortHandle value);
size_t      Ports_size(PortsHandle handle);
bool        Ports_empty(PortsHandle handle);
void        Ports_erase_at(PortsHandle handle, size_t idx);
void        Ports_clear(PortsHandle handle);
InstrumentPortHandle Ports_at(PortsHandle handle, size_t idx);
ListStringHandle     Ports_items(PortsHandle handle);
bool   Ports_contains(PortsHandle handle, InstrumentPortHandle value);
size_t Ports_index(PortsHandle handle, InstrumentPortHandle value);
bool   Ports_equal(PortsHandle a, PortsHandle b);
bool   Ports_not_equal(PortsHandle a, PortsHandle b);

// Serialization (from Song)
StringHandle Ports_to_json_string(PortsHandle handle);
PortsHandle  Ports_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
