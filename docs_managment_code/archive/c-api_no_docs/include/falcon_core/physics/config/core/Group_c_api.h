#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/geometries/GateGeometryArray1D_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
typedef void* GroupHandle;

// Constructors
GroupHandle Group_create(ChannelHandle     name,
                         int               num_dots,
                         ConnectionsHandle screening_gates,
                         ConnectionsHandle reservoir_gates,
                         ConnectionsHandle plunger_gates,
                         ConnectionsHandle barrier_gates,
                         ConnectionsHandle order);

// Destructor
void Group_destroy(GroupHandle handle);

// Methods
ChannelHandle             Group_name(GroupHandle handle);
int                       Group_num_dots(GroupHandle handle);
GateGeometryArray1DHandle Group_order(GroupHandle handle);
bool              Group_has_channel(GroupHandle handle, ChannelHandle channel);
bool              Group_is_charge_sensor(GroupHandle handle);
ConnectionsHandle Group_get_all_channel_gates(GroupHandle handle);
ConnectionsHandle Group_screening_gates(GroupHandle handle);
ConnectionsHandle Group_reservoir_gates(GroupHandle handle);
ConnectionsHandle Group_plunger_gates(GroupHandle handle);
ConnectionsHandle Group_barrier_gates(GroupHandle handle);
ConnectionsHandle Group_ohmics(GroupHandle handle);
ConnectionsHandle Group_dot_gates(GroupHandle handle);
ConnectionHandle  Group_get_ohmic(GroupHandle handle);
ConnectionHandle  Group_get_barrier_gate(GroupHandle handle);
ConnectionHandle  Group_get_plunger_gate(GroupHandle handle);
ConnectionHandle  Group_get_reservoir_gate(GroupHandle handle);
ConnectionHandle  Group_get_screening_gate(GroupHandle handle);
ConnectionHandle  Group_get_dot_gate(GroupHandle handle);
ConnectionHandle  Group_get_gate(GroupHandle handle);
ConnectionsHandle Group_get_all_gates(GroupHandle handle);
ConnectionsHandle Group_get_all_connections(GroupHandle handle);
bool              Group_has_ohmic(GroupHandle handle, ConnectionHandle ohmic);
bool              Group_has_gate(GroupHandle handle, ConnectionHandle gate);
bool Group_has_barrier_gate(GroupHandle handle, ConnectionHandle barrier_gate);
bool Group_has_plunger_gate(GroupHandle handle, ConnectionHandle plunger_gate);
bool Group_has_reservoir_gate(GroupHandle      handle,
                              ConnectionHandle reservoir_gate);
bool Group_has_screening_gate(GroupHandle      handle,
                              ConnectionHandle screening_gate);
bool Group_equal(GroupHandle handle, GroupHandle other);
bool Group_not_equal(GroupHandle handle, GroupHandle other);

// Serialization (from Song)
StringHandle Group_to_json_string(GroupHandle handle);
GroupHandle  Group_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
