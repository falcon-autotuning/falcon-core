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
/* AUTO-DOC from cpp: Config_num_unique_channels | falcon_core::physics::config::core::Config::num_unique_channels */
/**
 * @brief Returns the number of unique channels associated with the current
 * sample.
 */
int                      Config_num_unique_channels(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_voltage_constraints | falcon_core::physics::config::core::Config::voltage_constraints */
/**
 * @brief Return the voltage constraints for the physical layout.
 */
VoltageConstraintsHandle Config_voltage_constraints(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_groups | falcon_core::physics::config::core::Config::groups */
/**
 * @brief Return the DC wiring impedances for the physical layout.
 */
MapGnameGroupHandle      Config_groups(ConfigHandle handle);
ImpedancesHandle         Config_wiring_DC(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_channels | falcon_core::physics::config::core::Config::channels */
/**
 * @brief Returns the channels of the config.
 */
ChannelsHandle           Config_channels(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_impedance | falcon_core::physics::config::core::Config::get_impedance */
/**
 * @brief Returns the impedance matching the connection in teh dcwiring.
 * @returns The impedance matching the connection in teh dcwiring. A nullptr
 * if no match is found.
 */
ImpedanceHandle          Config_get_impedance(ConfigHandle     handle,
                                              ConnectionHandle connection);
/* AUTO-DOC from cpp: Config_get_all_gnames | falcon_core::physics::config::core::Config::get_all_gnames */
/**
 * @brief Returns all of the group names.
 */
ListGnameHandle          Config_get_all_gnames(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_all_groups | falcon_core::physics::config::core::Config::get_all_groups */
/**
 * @brief Returns all of the groups.
 */
ListGroupHandle          Config_get_all_groups(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_has_channel | falcon_core::physics::config::core::Config::has_channel */
/**
 * @brief Validates if this is a proper Channel name in the set of all device
 * Channels.
 * @param channel The channel to validate.
 * @returns true if the channel exists, false otherwise.
 */
bool        Config_has_channel(ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_has_gname | falcon_core::physics::config::core::Config::has_gname */
/**
 * @brief Validates if this is a proper gatename.
 * @param gname The gname to validate.
 * @returns true if the gname exists, false otherwise.
 */
bool        Config_has_gname(ConfigHandle handle, GnameHandle gname);
/* AUTO-DOC from cpp: Config_select_group | falcon_core::physics::config::core::Config::select_group */
/**
 * @brief Finds a group from the name and returns it.
 * @param gname The name of the group to find.
 * @returns The group matching the name. A nullptr if no match is found.
 */
GroupHandle Config_select_group(ConfigHandle handle, GnameHandle gname);
/* AUTO-DOC from cpp: Config_get_dot_number | falcon_core::physics::config::core::Config::get_dot_number */
/**
 * @brief Finds the number of dots associated with a current channel from the
 * config.
 * @param channel The channel to find the number of dots for.
 * @returns The number of dots associated with the channel. A 0 if there is no
 * match.
 */
int         Config_get_dot_number(ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_charge_sense_groups | falcon_core::physics::config::core::Config::get_charge_sense_groups */
/**
 * @brief Finds all of the arrays of dots that are charge sensors, i.e. only
 * one quantum dot per channel.
 * @returns A vector of gnames that are charge sensors.
 */
ListGnameHandle Config_get_charge_sense_groups(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_ohmic_in_charge_sensor | falcon_core::physics::config::core::Config::ohmic_in_charge_sensor */
/**
 * @brief If the ohmic is inside of a charge sensor channel
 * @param ohmic The ohmic to check
 * @returns true if the ohmic is inside a charge sensor channel
 */
bool Config_ohmic_in_charge_sensor(ConfigHandle handle, ConnectionHandle ohmic);
/* AUTO-DOC from cpp: Config_get_associated_ohmic | falcon_core::physics::config::core::Config::get_associated_ohmic */
/**
 * @brief Every reservoir gate has an associated ohmic.
 * This pulls the associated ohmic from the config.
 * @param reservoir_gate The reservoir gate to find the associated ohmic for.
 * @returns The ohmic associated with the reservoir gate. A nullptr if no
 * match
 */
ConnectionHandle  Config_get_associated_ohmic(ConfigHandle     handle,
                                              ConnectionHandle reservoir_gate);
/* AUTO-DOC from cpp: Config_get_current_channels | falcon_core::physics::config::core::Config::get_current_channels */
/**
 * @brief Gets all of the current channels from the config.
 * @returns All of the current channels from the config.
 */
ChannelsHandle    Config_get_current_channels(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_gname | falcon_core::physics::config::core::Config::get_gname */
/**
 * @brief Gets the associated Gname with a Channel if it exists.
 * @param channel The channel to find the associated Gname for.
 * @returns The Gname associated with the Channel. A nullptr if no match is
 * found.
 */
GnameHandle       Config_get_gname(ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_group_barrier_gates | falcon_core::physics::config::core::Config::get_group_barrier_gates */
/**
 * @brief Gets all of the barrier gates assocated with the selected
 * group from the config.
 * @param gname The group name to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected group.
 * Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_group_barrier_gates(ConfigHandle handle,
                                                 GnameHandle  gname);
/* AUTO-DOC from cpp: Config_get_group_plunger_gates | falcon_core::physics::config::core::Config::get_group_plunger_gates */
/**
 * @brief Gets all of the plunger gates assocated with the selected
 * group from the config.
 * @param gname The group name to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected group.
 * Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_group_plunger_gates(ConfigHandle handle,
                                                 GnameHandle  gname);
/* AUTO-DOC from cpp: Config_get_group_reservoir_gates | falcon_core::physics::config::core::Config::get_group_reservoir_gates */
/**
 * @brief Gets all of the reservoir gates assocated with the selected
 * group from the config.
 * @param gname The group name to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected group.
 * Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_group_reservoir_gates(ConfigHandle handle,
                                                   GnameHandle  gname);
/* AUTO-DOC from cpp: Config_get_group_screening_gates | falcon_core::physics::config::core::Config::get_group_screening_gates */
/**
 * @brief Gets all of the screening gates assocated with the selected
 * group from the config.
 * @param gname The group name to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected group.
 * Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_group_screening_gates(ConfigHandle handle,
                                                   GnameHandle  gname);
/* AUTO-DOC from cpp: Config_get_group_dot_gates | falcon_core::physics::config::core::Config::get_group_dot_gates */
/**
 * @brief Gets all of the dot gates assocated with the selected
 * group from the config.
 * @param gname The group name to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected group.
 * Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_group_dot_gates(ConfigHandle handle,
                                             GnameHandle  gname);
/* AUTO-DOC from cpp: Config_get_group_gates | falcon_core::physics::config::core::Config::get_group_gates */
/**
 * @brief Gets all of the gates assocated with the selected
 * group from the config.
 * @param gname The group name to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected group.
 * Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_group_gates(ConfigHandle handle,
                                         GnameHandle  gname);
/* AUTO-DOC from cpp: Config_get_channel_barrier_gates | falcon_core::physics::config::core::Config::get_channel_barrier_gates */
/**
 * @brief Gets all of the barrier gates assocated with the selected
 * current channel from the config.
 * @param channel The channel to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected
 * channel. Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_barrier_gates(ConfigHandle  handle,
                                                   ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_plunger_gates | falcon_core::physics::config::core::Config::get_channel_plunger_gates */
/**
 * @brief Gets all of the plunger gates assocated with the selected
 * current channel from the config.
 * @param channel The channel to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected
 * channel. Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_plunger_gates(ConfigHandle  handle,
                                                   ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_reservoir_gates | falcon_core::physics::config::core::Config::get_channel_reservoir_gates */
/**
 * @brief Gets all of the reservoir gates assocated with the selected
 * current channel from the config.
 * @param channel The channel to find the gates for.
 * channel. Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_reservoir_gates(ConfigHandle  handle,
                                                     ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_screening_gates | falcon_core::physics::config::core::Config::get_channel_screening_gates */
/**
 * @brief Gets all of the screening gates assocated with the selected
 * current channel from the config.
 * @param channel The channel to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected
 * channel. Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_screening_gates(ConfigHandle  handle,
                                                     ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_dot_gates | falcon_core::physics::config::core::Config::get_channel_dot_gates */
/**
 * @brief Gets all of the dot gates assocated with the selected
 * current channel from the config.
 * @param channel The channel to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected
 * channel. Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_dot_gates(ConfigHandle  handle,
                                               ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_gates | falcon_core::physics::config::core::Config::get_channel_gates */
/**
 * @brief Gets all of the gates assocated with the selected
 * current channel from the config.
 * @param channel The channel to find the gates for.
 * @param type The gate type to find the gates for.
 * @returns All of the gates of a gatetype assocated with the selected
 * channel. Otherwise a nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_gates(ConfigHandle  handle,
                                           ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_ohmics | falcon_core::physics::config::core::Config::get_channel_ohmics */
/**
 * @brief Gets all of the ohmics assocated with the selected current channel.
 * @param channel The channel to find the ohmics for.
 * @returns All of the ohmics assocated with the selected channel. Otherwise a
 * nullptr if no match is found.
 */
ConnectionsHandle Config_get_channel_ohmics(ConfigHandle  handle,
                                            ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_channel_order_no_ohmics | falcon_core::physics::config::core::Config::get_channel_order_no_ohmics */
/**
 * @brief Gets all of the gates in the order at the selected channel from the
 * config with no ohmics.
 * @param channel The channel to find the gates for.
 * @returns All of the gates in the order at the selected channel. Otherwise a
 * nullptr
 */
ConnectionsHandle Config_get_channel_order_no_ohmics(ConfigHandle  handle,
                                                     ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_num_unique_channels | falcon_core::physics::config::core::Config::get_num_unique_channels */
/**
 * @brief Returns the number of unique channels associated with the current
 * sample.
 */
int               Config_get_num_unique_channels(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_return_channels_from_gate | falcon_core::physics::config::core::Config::return_channels_from_gate */
/**
 * @brief Returns all of the channels associated with a gate.
 * @param gate The gate to find the channels for.
 * @returns All of the channels associated with a gate. Otherwise a nullptr if
 * no match is found.
 */
ChannelsHandle    Config_return_channels_from_gate(ConfigHandle     handle,
                                                   ConnectionHandle gate);
/* AUTO-DOC from cpp: Config_return_channel_from_gate | falcon_core::physics::config::core::Config::return_channel_from_gate */
/**
 * @brief Returns the channel a given gate belongs to. If the gate is in
 * multiple channels, if will return the first channel if finds.
 * @param gate The gate to find the channel for.
 * @returns The channel the gate belongs to. A nullptr if no match is found.
 */
ChannelHandle     Config_return_channel_from_gate(ConfigHandle     handle,
                                                  ConnectionHandle gate);
/* AUTO-DOC from cpp: Config_ohmic_in_channel | falcon_core::physics::config::core::Config::ohmic_in_channel */
/**
 * @brief Checks if the ohmic is connected to a channel.
 * @param ohmic The ohmic to diagnose.
 * @param channel The channel to check the ohmic against.
 * @returns true if the ohmic is connected to the channel, false otherwise.
 */
bool              Config_ohmic_in_channel(ConfigHandle     handle,
                                          ConnectionHandle ohmic,
                                          ChannelHandle    channel);
/* AUTO-DOC from cpp: Config_get_dot_channel_neighbors | falcon_core::physics::config::core::Config::get_dot_channel_neighbors */
/**
 * @brief Gets the nearby neighbors of the selected gate in the dot channel.
 * @param dotgate The gate of interest (must be in dot channel)
 * @return A pair of GateSP (left, right) if found, nullptr otherwise.
 */
PairConnectionConnectionHandle Config_get_dot_channel_neighbors(
    ConfigHandle handle, ConnectionHandle dot_gate);
/* AUTO-DOC from cpp: Config_get_barrier_gate_dict | falcon_core::physics::config::core::Config::get_barrier_gate_dict */
/**
 * @brief Returns barrier gates indexed by channel.
 */
MapChannelConnectionsHandle Config_get_barrier_gate_dict(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_plunger_gate_dict | falcon_core::physics::config::core::Config::get_plunger_gate_dict */
/**
 * @brief Returns plunger gates indexed by channel.
 */
MapChannelConnectionsHandle Config_get_plunger_gate_dict(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_reservoir_gate_dict | falcon_core::physics::config::core::Config::get_reservoir_gate_dict */
/**
 * @brief Returns reservoir gates indexed by channel.
 */
MapChannelConnectionsHandle Config_get_reservoir_gate_dict(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_screening_gate_dict | falcon_core::physics::config::core::Config::get_screening_gate_dict */
/**
 * @brief Returns screening gates indexed by channel.
 */
MapChannelConnectionsHandle Config_get_screening_gate_dict(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_dot_gate_dict | falcon_core::physics::config::core::Config::get_dot_gate_dict */
/**
 * @brief Returns dot gates indexed by channel.
 */
MapChannelConnectionsHandle Config_get_dot_gate_dict(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_gate_dict | falcon_core::physics::config::core::Config::get_gate_dict */
/**
 * @brief Returns gates indexed by channel.
 */
MapChannelConnectionsHandle Config_get_gate_dict(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_barrier_gates | falcon_core::physics::config::core::Config::get_isolated_barrier_gates */
/**
 * @brief Task to find isolated barrier gates stored in the config.
 */
ConnectionsHandle Config_get_isolated_barrier_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_plunger_gates | falcon_core::physics::config::core::Config::get_isolated_plunger_gates */
/**
 * @brief Task to find isolated plunger gates stored in the config.
 */
ConnectionsHandle Config_get_isolated_plunger_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_reservoir_gates | falcon_core::physics::config::core::Config::get_isolated_reservoir_gates */
/**
 * @brief Task to find isolated reservoir gates stored in the config.
 */
ConnectionsHandle Config_get_isolated_reservoir_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_screening_gates | falcon_core::physics::config::core::Config::get_isolated_screening_gates */
/**
 * @brief Task to find isolated screening gates stored in the config.
 */
ConnectionsHandle Config_get_isolated_screening_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_dot_gates | falcon_core::physics::config::core::Config::get_isolated_dot_gates */
/**
 * @brief Task to find isolated dot gates stored in the config.
 */
ConnectionsHandle Config_get_isolated_dot_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_gates | falcon_core::physics::config::core::Config::get_isolated_gates */
/**
 * @brief Task to find isolated gates stored in the config.
 */
ConnectionsHandle Config_get_isolated_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_barrier_gates | falcon_core::physics::config::core::Config::get_shared_barrier_gates */
/**
 * @brief Task to find shared barrier gates stored in the config.
 */
ConnectionsHandle Config_get_shared_barrier_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_plunger_gates | falcon_core::physics::config::core::Config::get_shared_plunger_gates */
/**
 * @brief Task to find shared plunger gates stored in the config.
 */
ConnectionsHandle Config_get_shared_plunger_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_reservoir_gates | falcon_core::physics::config::core::Config::get_shared_reservoir_gates */
/**
 * @brief Task to find shared reservoir gates stored in the config.
 */
ConnectionsHandle Config_get_shared_reservoir_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_screening_gates | falcon_core::physics::config::core::Config::get_shared_screening_gates */
/**
 * @brief Task to find shared screening gates stored in the config.
 */
ConnectionsHandle Config_get_shared_screening_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_dot_gates | falcon_core::physics::config::core::Config::get_shared_dot_gates */
/**
 * @brief Task to find shared dot gates stored in the config.
 */
ConnectionsHandle Config_get_shared_dot_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_gates | falcon_core::physics::config::core::Config::get_shared_gates */
/**
 * @brief Task to find shared gates stored in the config.
 */
ConnectionsHandle Config_get_shared_gates(ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_shared_channel_barrier_gates | falcon_core::physics::config::core::Config::get_shared_channel_barrier_gates */
/**
 * @brief Finds the shared barrier gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gateytpe that are shared in
 * the selected channel.
 */
ConnectionsHandle Config_get_shared_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_shared_channel_plunger_gates | falcon_core::physics::config::core::Config::get_shared_channel_plunger_gates */
/**
 * @brief Finds the shared plunger gates in the selected
 * channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gateytpe that are shared in
 * the selected channel.
 */
ConnectionsHandle Config_get_shared_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_shared_channel_reservoir_gates | falcon_core::physics::config::core::Config::get_shared_channel_reservoir_gates */
/**
 * @brief Finds the shared reservoir gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gateytpe that are shared
 * in the selected channel.
 */
ConnectionsHandle Config_get_shared_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_shared_channel_screening_gates | falcon_core::physics::config::core::Config::get_shared_channel_screening_gates */
/**
 * @brief Finds the shared screening gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gateytpe that are shared
 * in the selected channel.
 */
ConnectionsHandle Config_get_shared_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_shared_channel_dot_gates | falcon_core::physics::config::core::Config::get_shared_channel_dot_gates */
/**
 * @brief Finds the shared dot gates of the gatetype in the selected channel.
 * @param channel The channel of the device of interest.
 * @return DotGatesSP list of all gates of the gateytpe that are shared in the
 * selected channel.
 */
ConnectionsHandle Config_get_shared_channel_dot_gates(ConfigHandle  handle,
                                                      ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_shared_channel_gates | falcon_core::physics::config::core::Config::get_shared_channel_gates */
/**
 * @brief Finds the shared gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return GatesSP<Gate> list of all gates of the gateytpe that are shared in
 * the selected channel.
 */
ConnectionsHandle Config_get_shared_channel_gates(ConfigHandle  handle,
                                                  ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_channel_barrier_gates | falcon_core::physics::config::core::Config::get_isolated_channel_barrier_gates */
/**
 * @brief Finds the isolated barrier gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gatetype that are isolated
 * in the selected channel.
 */
ConnectionsHandle Config_get_isolated_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_channel_plunger_gates | falcon_core::physics::config::core::Config::get_isolated_channel_plunger_gates */
/**
 * @brief Finds the isolated plunger gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gatetype that are isolated
 * in the selected channel.
 */
ConnectionsHandle Config_get_isolated_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_channel_reservoir_gates | falcon_core::physics::config::core::Config::get_isolated_channel_reservoir_gates */
/**
 * @brief Finds the isolated reservoir gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gatetype that are
 * isolated in the selected channel.
 */
ConnectionsHandle Config_get_isolated_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_channel_screening_gates | falcon_core::physics::config::core::Config::get_isolated_channel_screening_gates */
/**
 * @brief Finds the isolated screening gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return ConnectionsSP list of all gates of the gatetype that are
 * isolated in the selected channel.
 */
ConnectionsHandle Config_get_isolated_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_channel_dot_gates | falcon_core::physics::config::core::Config::get_isolated_channel_dot_gates */
/**
 * @brief Finds the isolated dot gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return DotGatesSP list of all gates of the gatetype that are isolated in
 * the selected channel.
 */
ConnectionsHandle Config_get_isolated_channel_dot_gates(ConfigHandle  handle,
                                                        ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_channel_gates | falcon_core::physics::config::core::Config::get_isolated_channel_gates */
/**
 * @brief Finds the isolated gates in the selected channel.
 * @param channel The channel of the device of interest.
 * @return GatesSP<Gate> list of all gates of the gatetype that are isolated
 * in the selected channel.
 */
ConnectionsHandle Config_get_isolated_channel_gates(ConfigHandle  handle,
                                                    ChannelHandle channel);
/* AUTO-DOC from cpp: Config_get_isolated_barrier_gates_by_channel | falcon_core::physics::config::core::Config::get_isolated_barrier_gates_by_channel */
/**
 * @brief Returns barrier gates indexed by channel which are
 * unshared.
 */
MapChannelConnectionsHandle Config_get_isolated_barrier_gates_by_channel(
    ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_plunger_gates_by_channel | falcon_core::physics::config::core::Config::get_isolated_plunger_gates_by_channel */
/**
 * @brief Returns plunger gates indexed by channel which are
 * unshared.
 */
MapChannelConnectionsHandle Config_get_isolated_plunger_gates_by_channel(
    ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_reservoir_gates_by_channel | falcon_core::physics::config::core::Config::get_isolated_reservoir_gates_by_channel */
/**
 * @brief Returns reservoir gates indexed by channel which are
 * unshared.
 */
MapChannelConnectionsHandle Config_get_isolated_reservoir_gates_by_channel(
    ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_screening_gates_by_channel | falcon_core::physics::config::core::Config::get_isolated_screening_gates_by_channel */
/**
 * @brief Returns screening gates indexed by channel which are
 * unshared.
 */
MapChannelConnectionsHandle Config_get_isolated_screening_gates_by_channel(
    ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_dot_gates_by_channel | falcon_core::physics::config::core::Config::get_isolated_dot_gates_by_channel */
/**
 * @brief Returns dot gates indexed by channel which are
 * unshared.
 */
MapChannelConnectionsHandle Config_get_isolated_dot_gates_by_channel(
    ConfigHandle handle);
/* AUTO-DOC from cpp: Config_get_isolated_gates_by_channel | falcon_core::physics::config::core::Config::get_isolated_gates_by_channel */
/**
 * @brief Returns gates indexed by channel which are
 * unshared.
 */
MapChannelConnectionsHandle Config_get_isolated_gates_by_channel(
    ConfigHandle handle);
/* AUTO-DOC from cpp: Config_generate_gate_relations | falcon_core::physics::config::core::Config::generate_gate_relations */
/**
 * @brief Returns the gate relations in the config.
 */
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
