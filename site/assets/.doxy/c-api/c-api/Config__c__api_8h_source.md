

# File Config\_c\_api.h

[**File List**](files.md) **>** [**c-api**](dir_b95515f962db252ab24400aa771598a6.md) **>** [**include**](dir_e8b86741b2c2c43e24b257446086386c.md) **>** [**falcon\_core**](dir_320c7f873cf8bb1c06309e978e7d7eca.md) **>** [**physics**](dir_675f009264d19d6a7779f7cbdc1a7572.md) **>** [**config**](dir_581a120aab54b5f137a62afb53b974b4.md) **>** [**core**](dir_2d9342c5d4579911ee06a50b57a946ed.md) **>** [**Config\_c\_api.h**](Config__c__api_8h.md)

[Go to the documentation of this file](Config__c__api_8h.md)


```C++
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

// @category:allocation
ConfigHandle Config_copy(ConfigHandle handle);
// @category:deallocation
void Config_destroy(ConfigHandle handle);
// @category:read
bool Config_equal(ConfigHandle handle, ConfigHandle other);
// @category:read
bool Config_not_equal(ConfigHandle handle, ConfigHandle other);
// @category:read
StringHandle Config_to_json_string(ConfigHandle handle);
// @category:allocation
ConfigHandle Config_from_json_string(StringHandle json);
// @category:allocation
ConfigHandle Config_create(ConnectionsHandle        screening_gates,
                           ConnectionsHandle        plunger_gates,
                           ConnectionsHandle        ohmics,
                           ConnectionsHandle        barrier_gates,
                           ConnectionsHandle        reservoir_gates,
                           MapGnameGroupHandle      groups,
                           ImpedancesHandle         wiring_DC,
                           VoltageConstraintsHandle constraints);
// @category:read
/* AUTO-DOC from cpp: Config_num_unique_channels |
 * falcon_core::physics::config::core::Config::num_unique_channels */
int Config_num_unique_channels(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_voltage_constraints |
 * falcon_core::physics::config::core::Config::voltage_constraints */
VoltageConstraintsHandle Config_voltage_constraints(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_groups |
 * falcon_core::physics::config::core::Config::groups */
MapGnameGroupHandle Config_groups(ConfigHandle handle);
// @category:read
ImpedancesHandle Config_wiring_DC(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_channels |
 * falcon_core::physics::config::core::Config::channels */
ChannelsHandle Config_channels(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_impedance |
 * falcon_core::physics::config::core::Config::get_impedance */
ImpedanceHandle Config_get_impedance(ConfigHandle     handle,
                                     ConnectionHandle connection);
// @category:read
/* AUTO-DOC from cpp: Config_get_all_gnames |
 * falcon_core::physics::config::core::Config::get_all_gnames */
ListGnameHandle Config_get_all_gnames(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_all_groups |
 * falcon_core::physics::config::core::Config::get_all_groups */
ListGroupHandle Config_get_all_groups(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_has_channel |
 * falcon_core::physics::config::core::Config::has_channel */
bool Config_has_channel(ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_has_gname |
 * falcon_core::physics::config::core::Config::has_gname */
bool Config_has_gname(ConfigHandle handle, GnameHandle gname);
// @category:read
/* AUTO-DOC from cpp: Config_select_group |
 * falcon_core::physics::config::core::Config::select_group */
GroupHandle Config_select_group(ConfigHandle handle, GnameHandle gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_dot_number |
 * falcon_core::physics::config::core::Config::get_dot_number */
int Config_get_dot_number(ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_charge_sense_groups |
 * falcon_core::physics::config::core::Config::get_charge_sense_groups */
ListGnameHandle Config_get_charge_sense_groups(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_ohmic_in_charge_sensor |
 * falcon_core::physics::config::core::Config::ohmic_in_charge_sensor */
bool Config_ohmic_in_charge_sensor(ConfigHandle handle, ConnectionHandle ohmic);
// @category:read
/* AUTO-DOC from cpp: Config_get_associated_ohmic |
 * falcon_core::physics::config::core::Config::get_associated_ohmic */
ConnectionHandle Config_get_associated_ohmic(ConfigHandle     handle,
                                             ConnectionHandle reservoir_gate);
// @category:read
/* AUTO-DOC from cpp: Config_get_current_channels |
 * falcon_core::physics::config::core::Config::get_current_channels */
ChannelsHandle Config_get_current_channels(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_gname |
 * falcon_core::physics::config::core::Config::get_gname */
GnameHandle Config_get_gname(ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_group_barrier_gates |
 * falcon_core::physics::config::core::Config::get_group_barrier_gates */
ConnectionsHandle Config_get_group_barrier_gates(ConfigHandle handle,
                                                 GnameHandle  gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_group_plunger_gates |
 * falcon_core::physics::config::core::Config::get_group_plunger_gates */
ConnectionsHandle Config_get_group_plunger_gates(ConfigHandle handle,
                                                 GnameHandle  gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_group_reservoir_gates |
 * falcon_core::physics::config::core::Config::get_group_reservoir_gates */
ConnectionsHandle Config_get_group_reservoir_gates(ConfigHandle handle,
                                                   GnameHandle  gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_group_screening_gates |
 * falcon_core::physics::config::core::Config::get_group_screening_gates */
ConnectionsHandle Config_get_group_screening_gates(ConfigHandle handle,
                                                   GnameHandle  gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_group_dot_gates |
 * falcon_core::physics::config::core::Config::get_group_dot_gates */
ConnectionsHandle Config_get_group_dot_gates(ConfigHandle handle,
                                             GnameHandle  gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_group_gates |
 * falcon_core::physics::config::core::Config::get_group_gates */
ConnectionsHandle Config_get_group_gates(ConfigHandle handle,
                                         GnameHandle  gname);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_barrier_gates |
 * falcon_core::physics::config::core::Config::get_channel_barrier_gates */
ConnectionsHandle Config_get_channel_barrier_gates(ConfigHandle  handle,
                                                   ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_plunger_gates |
 * falcon_core::physics::config::core::Config::get_channel_plunger_gates */
ConnectionsHandle Config_get_channel_plunger_gates(ConfigHandle  handle,
                                                   ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_reservoir_gates |
 * falcon_core::physics::config::core::Config::get_channel_reservoir_gates */
ConnectionsHandle Config_get_channel_reservoir_gates(ConfigHandle  handle,
                                                     ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_screening_gates |
 * falcon_core::physics::config::core::Config::get_channel_screening_gates */
ConnectionsHandle Config_get_channel_screening_gates(ConfigHandle  handle,
                                                     ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_dot_gates |
 * falcon_core::physics::config::core::Config::get_channel_dot_gates */
ConnectionsHandle Config_get_channel_dot_gates(ConfigHandle  handle,
                                               ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_gates |
 * falcon_core::physics::config::core::Config::get_channel_gates */
ConnectionsHandle Config_get_channel_gates(ConfigHandle  handle,
                                           ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_ohmics |
 * falcon_core::physics::config::core::Config::get_channel_ohmics */
ConnectionsHandle Config_get_channel_ohmics(ConfigHandle  handle,
                                            ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_channel_order_no_ohmics |
 * falcon_core::physics::config::core::Config::get_channel_order_no_ohmics */
ConnectionsHandle Config_get_channel_order_no_ohmics(ConfigHandle  handle,
                                                     ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_num_unique_channels |
 * falcon_core::physics::config::core::Config::get_num_unique_channels */
int Config_get_num_unique_channels(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_return_channels_from_gate |
 * falcon_core::physics::config::core::Config::return_channels_from_gate */
ChannelsHandle Config_return_channels_from_gate(ConfigHandle     handle,
                                                ConnectionHandle gate);
// @category:read
/* AUTO-DOC from cpp: Config_return_channel_from_gate |
 * falcon_core::physics::config::core::Config::return_channel_from_gate */
ChannelHandle Config_return_channel_from_gate(ConfigHandle     handle,
                                              ConnectionHandle gate);
// @category:read
/* AUTO-DOC from cpp: Config_ohmic_in_channel |
 * falcon_core::physics::config::core::Config::ohmic_in_channel */
bool Config_ohmic_in_channel(ConfigHandle     handle,
                             ConnectionHandle ohmic,
                             ChannelHandle    channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_dot_channel_neighbors |
 * falcon_core::physics::config::core::Config::get_dot_channel_neighbors */
PairConnectionConnectionHandle Config_get_dot_channel_neighbors(
    ConfigHandle handle, ConnectionHandle dot_gate);
// @category:read
/* AUTO-DOC from cpp: Config_get_barrier_gate_dict |
 * falcon_core::physics::config::core::Config::get_barrier_gate_dict */
MapChannelConnectionsHandle Config_get_barrier_gate_dict(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_plunger_gate_dict |
 * falcon_core::physics::config::core::Config::get_plunger_gate_dict */
MapChannelConnectionsHandle Config_get_plunger_gate_dict(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_reservoir_gate_dict |
 * falcon_core::physics::config::core::Config::get_reservoir_gate_dict */
MapChannelConnectionsHandle Config_get_reservoir_gate_dict(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_screening_gate_dict |
 * falcon_core::physics::config::core::Config::get_screening_gate_dict */
MapChannelConnectionsHandle Config_get_screening_gate_dict(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_dot_gate_dict |
 * falcon_core::physics::config::core::Config::get_dot_gate_dict */
MapChannelConnectionsHandle Config_get_dot_gate_dict(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_gate_dict |
 * falcon_core::physics::config::core::Config::get_gate_dict */
MapChannelConnectionsHandle Config_get_gate_dict(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_barrier_gates |
 * falcon_core::physics::config::core::Config::get_isolated_barrier_gates */
ConnectionsHandle Config_get_isolated_barrier_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_plunger_gates |
 * falcon_core::physics::config::core::Config::get_isolated_plunger_gates */
ConnectionsHandle Config_get_isolated_plunger_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_reservoir_gates |
 * falcon_core::physics::config::core::Config::get_isolated_reservoir_gates */
ConnectionsHandle Config_get_isolated_reservoir_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_screening_gates |
 * falcon_core::physics::config::core::Config::get_isolated_screening_gates */
ConnectionsHandle Config_get_isolated_screening_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_dot_gates |
 * falcon_core::physics::config::core::Config::get_isolated_dot_gates */
ConnectionsHandle Config_get_isolated_dot_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_gates |
 * falcon_core::physics::config::core::Config::get_isolated_gates */
ConnectionsHandle Config_get_isolated_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_barrier_gates |
 * falcon_core::physics::config::core::Config::get_shared_barrier_gates */
ConnectionsHandle Config_get_shared_barrier_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_plunger_gates |
 * falcon_core::physics::config::core::Config::get_shared_plunger_gates */
ConnectionsHandle Config_get_shared_plunger_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_reservoir_gates |
 * falcon_core::physics::config::core::Config::get_shared_reservoir_gates */
ConnectionsHandle Config_get_shared_reservoir_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_screening_gates |
 * falcon_core::physics::config::core::Config::get_shared_screening_gates */
ConnectionsHandle Config_get_shared_screening_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_dot_gates |
 * falcon_core::physics::config::core::Config::get_shared_dot_gates */
ConnectionsHandle Config_get_shared_dot_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_gates |
 * falcon_core::physics::config::core::Config::get_shared_gates */
ConnectionsHandle Config_get_shared_gates(ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_channel_barrier_gates |
 * falcon_core::physics::config::core::Config::get_shared_channel_barrier_gates
 */
ConnectionsHandle Config_get_shared_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_channel_plunger_gates |
 * falcon_core::physics::config::core::Config::get_shared_channel_plunger_gates
 */
ConnectionsHandle Config_get_shared_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_channel_reservoir_gates |
 * falcon_core::physics::config::core::Config::get_shared_channel_reservoir_gates
 */
ConnectionsHandle Config_get_shared_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_channel_screening_gates |
 * falcon_core::physics::config::core::Config::get_shared_channel_screening_gates
 */
ConnectionsHandle Config_get_shared_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_channel_dot_gates |
 * falcon_core::physics::config::core::Config::get_shared_channel_dot_gates */
ConnectionsHandle Config_get_shared_channel_dot_gates(ConfigHandle  handle,
                                                      ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_shared_channel_gates |
 * falcon_core::physics::config::core::Config::get_shared_channel_gates */
ConnectionsHandle Config_get_shared_channel_gates(ConfigHandle  handle,
                                                  ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_channel_barrier_gates |
 * falcon_core::physics::config::core::Config::get_isolated_channel_barrier_gates
 */
ConnectionsHandle Config_get_isolated_channel_barrier_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_channel_plunger_gates |
 * falcon_core::physics::config::core::Config::get_isolated_channel_plunger_gates
 */
ConnectionsHandle Config_get_isolated_channel_plunger_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_channel_reservoir_gates |
 * falcon_core::physics::config::core::Config::get_isolated_channel_reservoir_gates
 */
ConnectionsHandle Config_get_isolated_channel_reservoir_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_channel_screening_gates |
 * falcon_core::physics::config::core::Config::get_isolated_channel_screening_gates
 */
ConnectionsHandle Config_get_isolated_channel_screening_gates(
    ConfigHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_channel_dot_gates |
 * falcon_core::physics::config::core::Config::get_isolated_channel_dot_gates */
ConnectionsHandle Config_get_isolated_channel_dot_gates(ConfigHandle  handle,
                                                        ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_channel_gates |
 * falcon_core::physics::config::core::Config::get_isolated_channel_gates */
ConnectionsHandle Config_get_isolated_channel_gates(ConfigHandle  handle,
                                                    ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_barrier_gates_by_channel |
 * falcon_core::physics::config::core::Config::get_isolated_barrier_gates_by_channel
 */
MapChannelConnectionsHandle Config_get_isolated_barrier_gates_by_channel(
    ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_plunger_gates_by_channel |
 * falcon_core::physics::config::core::Config::get_isolated_plunger_gates_by_channel
 */
MapChannelConnectionsHandle Config_get_isolated_plunger_gates_by_channel(
    ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_reservoir_gates_by_channel |
 * falcon_core::physics::config::core::Config::get_isolated_reservoir_gates_by_channel
 */
MapChannelConnectionsHandle Config_get_isolated_reservoir_gates_by_channel(
    ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_screening_gates_by_channel |
 * falcon_core::physics::config::core::Config::get_isolated_screening_gates_by_channel
 */
MapChannelConnectionsHandle Config_get_isolated_screening_gates_by_channel(
    ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_dot_gates_by_channel |
 * falcon_core::physics::config::core::Config::get_isolated_dot_gates_by_channel
 */
MapChannelConnectionsHandle Config_get_isolated_dot_gates_by_channel(
    ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_get_isolated_gates_by_channel |
 * falcon_core::physics::config::core::Config::get_isolated_gates_by_channel */
MapChannelConnectionsHandle Config_get_isolated_gates_by_channel(
    ConfigHandle handle);
// @category:read
/* AUTO-DOC from cpp: Config_generate_gate_relations |
 * falcon_core::physics::config::core::Config::generate_gate_relations */
GateRelationsHandle Config_generate_gate_relations(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_screening_gates(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_reservoir_gates(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_plunger_gates(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_barrier_gates(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_ohmics(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_dot_gates(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_ohmic(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_barrier_gate(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_plunger_gate(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_reservoir_gate(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_screening_gate(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_dot_gate(ConfigHandle handle);
// @category:read
ConnectionHandle Config_get_gate(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_get_all_gates(ConfigHandle handle);
// @category:read
ConnectionsHandle Config_get_all_connections(ConfigHandle handle);
// @category:read
bool Config_has_ohmic(ConfigHandle handle, ConnectionHandle ohmic);
// @category:read
bool Config_has_gate(ConfigHandle handle, ConnectionHandle gate);
// @category:read
bool Config_has_barrier_gate(ConfigHandle     handle,
                             ConnectionHandle barrier_gate);
// @category:read
bool Config_has_plunger_gate(ConfigHandle     handle,
                             ConnectionHandle plunger_gate);
// @category:read
bool Config_has_reservoir_gate(ConfigHandle     handle,
                               ConnectionHandle reservoir_gate);
// @category:read
bool Config_has_screening_gate(ConfigHandle     handle,
                               ConnectionHandle screening_gate);

#ifdef __cplusplus
}
#endif
```


