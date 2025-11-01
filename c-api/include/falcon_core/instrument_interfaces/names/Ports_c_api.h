#pragma once
#include <cstddef>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/generic/ListInstrumentPort_c_api.h"
#include "falcon_core/generic/ListString_c_api.h"
#include "falcon_core/instrument_interfaces/names/InstrumentPort_c_api.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef void* PortsHandle;

// Constructors
PortsHandle Ports_create_empty();
PortsHandle Ports_create(ListInstrumentPortHandle items);

// Destructor
void Ports_destroy(PortsHandle handle);

// Methods
ListInstrumentPortHandle Ports_ports(PortsHandle handle);
ListStringHandle         Ports_default_names(PortsHandle handle);
ListConnectionHandle     Ports_get_psuedo_names(PortsHandle handle);
ListStringHandle         Ports__get_raw_names(PortsHandle handle);
ListStringHandle         Ports__get_instrument_facing_names(PortsHandle handle);
InstrumentPortHandle     Ports__get_psuedoname_matching_port(PortsHandle handle,
                                                             ConnectionHandle name);
InstrumentPortHandle     Ports__get_instrument_type_matching_port(
        PortsHandle handle, StringHandle type);
bool        Ports_is_knobs(PortsHandle handle);
bool        Ports_is_meters(PortsHandle handle);
PortsHandle Ports_intersection(PortsHandle handle, PortsHandle other);
void        Ports_push_back(PortsHandle handle, InstrumentPortHandle value);
size_t      Ports_size(PortsHandle handle);
bool        Ports_empty(PortsHandle handle);
void        Ports_erase_at(PortsHandle handle, size_t idx);
void        Ports_clear(PortsHandle handle);
const InstrumentPortHandle Ports_const_at(PortsHandle handle, size_t idx);
InstrumentPortHandle       Ports_at(PortsHandle handle, size_t idx);
ListStringHandle           Ports_items(PortsHandle handle);
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
