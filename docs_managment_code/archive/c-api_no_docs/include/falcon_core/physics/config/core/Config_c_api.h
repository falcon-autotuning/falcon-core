#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/autotuner_interfaces/names/Channels_c_api.h"
#include "falcon_core/autotuner_interfaces/names/Gname_c_api.h"
#include "falcon_core/generic/ListGname_c_api.h"
#include "falcon_core/generic/ListGroup_c_api.h"
#include "falcon_core/generic/MapChannelConnections_c_api.h"
#include "falcon_core/generic/MapGnameGroup_c_api.h"
#include "falcon_core/generic/PairConnectionConnection_c_api.h"
#include "falcon_core/generic/String_c_api.h"
#include "falcon_core/physics/config/core/Group_c_api.h"
#include "falcon_core/physics/config/core/VoltageConstraints_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include "falcon_core/physics/device_structures/GateRelations_c_api.h"
#include "falcon_core/physics/device_structures/Impedances_c_api.h"
typedef void* ConfigHandle;

// Constructors
ConfigHandle Config_create(ConnectionsHandle        screening_gates,
                           ConnectionsHandle        plunger_gates,
                           ConnectionsHandle        ohmics,
                           ConnectionsHandle        barrier_gates,
                           ConnectionsHandle        reservoir_gates,
                           MapGnameGroupHandle      groups,
                           ImpedancesHandle         wiring_DC,
                           VoltageConstraintsHandle constraints);

// Destructor
void Config_destroy(ConfigHandle handle);

// Methods
int                      Config_num_unique_channels(ConfigHandle handle);
VoltageConstraintsHandle Config_voltage_constraints(ConfigHandle handle);
MapGnameGroupHandle      Config_groups(ConfigHandle handle);
ImpedancesHandle         Config_wiring_DC(ConfigHandle handle);
ChannelsHandle           Config_channels(ConfigHandle handle);
ImpedanceHandle          Config_get_impedance(ConfigHandle     handle,
                                              ConnectionHandle connection);
ListGnameHandle          Config_get_all_gnames(ConfigHandle handle);
ListGroupHandle          Config_get_all_groups(ConfigHandle handle);
bool        Config_has_channel(ConfigHandle handle, ChannelHandle channel);
bool        Config_has_gname(ConfigHandle handle, GnameHandle gname);
GroupHandle Config_select_group(ConfigHandle handle, GnameHandle gname);
int         Config_get_dot_number(ConfigHandle handle, ChannelHandle channel);
ListGnameHandle Config_get_charge_sense_groups(ConfigHandle handle);
bool Config_ohmic_in_charge_sensor(ConfigHandle handle, ConnectionHandle ohmic);
ConnectionHandle  Config_get_associated_ohmic(ConfigHandle     handle,
                                              ConnectionHandle reservoir_gate);
ChannelsHandle    Config_get_current_channels(ConfigHandle handle);
GnameHandle       Config_get_gname(ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_group_barrier_gates(ConfigHandle handle,
                                                 GnameHandle  gname);
ConnectionsHandle Config_get_group_plunger_gates(ConfigHandle handle,
                                                 GnameHandle  gname);
ConnectionsHandle Config_get_group_reservoir_gates(ConfigHandle handle,
                                                   GnameHandle  gname);
ConnectionsHandle Config_get_group_screening_gates(ConfigHandle handle,
                                                   GnameHandle  gname);
ConnectionsHandle Config_get_group_dot_gates(ConfigHandle handle,
                                             GnameHandle  gname);
ConnectionsHandle Config_get_group_gates(ConfigHandle handle,
                                         GnameHandle  gname);
ConnectionsHandle Config_get_channel_barrier_gates(ConfigHandle  handle,
                                                   ChannelHandle channel);
ConnectionsHandle Config_get_channel_plunger_gates(ConfigHandle  handle,
                                                   ChannelHandle channel);
ConnectionsHandle Config_get_channel_reservoir_gates(ConfigHandle  handle,
                                                     ChannelHandle channel);
ConnectionsHandle Config_get_channel_screening_gates(ConfigHandle  handle,
                                                     ChannelHandle channel);
ConnectionsHandle Config_get_channel_dot_gates(ConfigHandle  handle,
                                               ChannelHandle channel);
ConnectionsHandle Config_get_channel_gates(ConfigHandle  handle,
                                           ChannelHandle channel);
ConnectionsHandle Config_get_channel_ohmics(ConfigHandle  handle,
                                            ChannelHandle channel);
ConnectionsHandle Config_get_channel_order_no_ohmics(ConfigHandle  handle,
                                                     ChannelHandle channel);
int               Config_get_num_unique_channels(ConfigHandle handle);
ChannelsHandle    Config_return_channels_from_gate(ConfigHandle     handle,
                                                   ConnectionHandle gate);
ChannelHandle     Config_return_channel_from_gate(ConfigHandle     handle,
                                                  ConnectionHandle gate);
bool              Config_ohmic_in_channel(ConfigHandle     handle,
                                          ConnectionHandle ohmic,
                                          ChannelHandle    channel);
PairConnectionConnectionHandle Config_get_dot_channel_neighbors(
    ConfigHandle handle, ConnectionHandle dot_gate);
MapChannelConnectionsHandle Config_get_barrier_gate_dict(ConfigHandle handle);
MapChannelConnectionsHandle Config_get_plunger_gate_dict(ConfigHandle handle);
MapChannelConnectionsHandle Config_get_reservoir_gate_dict(ConfigHandle handle);
MapChannelConnectionsHandle Config_get_screening_gate_dict(ConfigHandle handle);
MapChannelConnectionsHandle Config_get_dot_gate_dict(ConfigHandle handle);
MapChannelConnectionsHandle Config_get_gate_dict(ConfigHandle handle);
ConnectionsHandle Config_get_isolated_barrier_gates(ConfigHandle handle);
ConnectionsHandle Config_get_isolated_plunger_gates(ConfigHandle handle);
ConnectionsHandle Config_get_isolated_reservoir_gates(ConfigHandle handle);
ConnectionsHandle Config_get_isolated_screening_gates(ConfigHandle handle);
ConnectionsHandle Config_get_isolated_dot_gates(ConfigHandle handle);
ConnectionsHandle Config_get_isolated_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_barrier_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_plunger_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_reservoir_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_screening_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_dot_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_gates(ConfigHandle handle);
ConnectionsHandle Config_get_shared_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_shared_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_shared_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_shared_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_shared_channel_dot_gates(ConfigHandle  handle,
                                                      ChannelHandle channel);
ConnectionsHandle Config_get_shared_channel_gates(ConfigHandle  handle,
                                                  ChannelHandle channel);
ConnectionsHandle Config_get_isolated_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_isolated_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_isolated_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_isolated_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel);
ConnectionsHandle Config_get_isolated_channel_dot_gates(ConfigHandle  handle,
                                                        ChannelHandle channel);
ConnectionsHandle Config_get_isolated_channel_gates(ConfigHandle  handle,
                                                    ChannelHandle channel);
MapChannelConnectionsHandle Config_get_isolated_barrier_gates_by_channel(
    ConfigHandle handle);
MapChannelConnectionsHandle Config_get_isolated_plunger_gates_by_channel(
    ConfigHandle handle);
MapChannelConnectionsHandle Config_get_isolated_reservoir_gates_by_channel(
    ConfigHandle handle);
MapChannelConnectionsHandle Config_get_isolated_screening_gates_by_channel(
    ConfigHandle handle);
MapChannelConnectionsHandle Config_get_isolated_dot_gates_by_channel(
    ConfigHandle handle);
MapChannelConnectionsHandle Config_get_isolated_gates_by_channel(
    ConfigHandle handle);
GateRelationsHandle Config_generate_gate_relations(ConfigHandle handle);
ConnectionsHandle   Config_screening_gates(ConfigHandle handle);
ConnectionsHandle   Config_reservoir_gates(ConfigHandle handle);
ConnectionsHandle   Config_plunger_gates(ConfigHandle handle);
ConnectionsHandle   Config_barrier_gates(ConfigHandle handle);
ConnectionsHandle   Config_ohmics(ConfigHandle handle);
ConnectionsHandle   Config_dot_gates(ConfigHandle handle);
ConnectionHandle    Config_get_ohmic(ConfigHandle handle);
ConnectionHandle    Config_get_barrier_gate(ConfigHandle handle);
ConnectionHandle    Config_get_plunger_gate(ConfigHandle handle);
ConnectionHandle    Config_get_reservoir_gate(ConfigHandle handle);
ConnectionHandle    Config_get_screening_gate(ConfigHandle handle);
ConnectionHandle    Config_get_dot_gate(ConfigHandle handle);
ConnectionHandle    Config_get_gate(ConfigHandle handle);
ConnectionsHandle   Config_get_all_gates(ConfigHandle handle);
ConnectionsHandle   Config_get_all_connections(ConfigHandle handle);
bool Config_has_ohmic(ConfigHandle handle, ConnectionHandle ohmic);
bool Config_has_gate(ConfigHandle handle, ConnectionHandle gate);
bool Config_has_barrier_gate(ConfigHandle     handle,
                             ConnectionHandle barrier_gate);
bool Config_has_plunger_gate(ConfigHandle     handle,
                             ConnectionHandle plunger_gate);
bool Config_has_reservoir_gate(ConfigHandle     handle,
                               ConnectionHandle reservoir_gate);
bool Config_has_screening_gate(ConfigHandle     handle,
                               ConnectionHandle screening_gate);
bool Config_equal(ConfigHandle handle, ConfigHandle other);
bool Config_not_equal(ConfigHandle handle, ConfigHandle other);

// Serialization (from Song)
StringHandle Config_to_json_string(ConfigHandle handle);
ConfigHandle Config_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
