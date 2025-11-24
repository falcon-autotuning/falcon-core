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
/* AUTO-DOC from cpp: Group_name | falcon_core::physics::config::core::Group::name */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::name)
 * @brief collect the name of this group.
 */
ChannelHandle             Group_name(GroupHandle handle);
/* AUTO-DOC from cpp: Group_num_dots | falcon_core::physics::config::core::Group::num_dots */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::num_dots)
 * @brief collect the number of dots in this group.
 */
int                       Group_num_dots(GroupHandle handle);
/* AUTO-DOC from cpp: Group_order | falcon_core::physics::config::core::Group::order */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::order)
 * @brief collect the order of the gates in this group.
 */
GateGeometryArray1DHandle Group_order(GroupHandle handle);
/* AUTO-DOC from cpp: Group_has_channel | falcon_core::physics::config::core::Group::has_channel */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::has_channel)
 * @brief Validates if this channel is present.
 * @param channel The channel to validate.
 * @returns true if the channel is present.
 */
bool              Group_has_channel(GroupHandle handle, ChannelHandle channel);
/* AUTO-DOC from cpp: Group_is_charge_sensor | falcon_core::physics::config::core::Group::is_charge_sensor */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::is_charge_sensor)
 * @brief Checks if this channel could be a charge sensor.
 * @returns true if the channel has a single dot.
 */
bool              Group_is_charge_sensor(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_all_channel_gates | falcon_core::physics::config::core::Group::get_all_channel_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::get_all_channel_gates)
 * @brief Gets all of the gates assocciated with this channel from the
 * config.
 * @param channel The channel to collect the gates for.
 * @returns The gates associated with this channel. If the channel is not
 * correct then empty gates are returned.
 */
ConnectionsHandle Group_get_all_channel_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_screening_gates | falcon_core::physics::config::core::StandardConfigConnections::screening_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::screening_gates)
 * @brief The screening gates from the config.
 * @return The screening gates.
 */
ConnectionsHandle Group_screening_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_reservoir_gates | falcon_core::physics::config::core::StandardConfigConnections::reservoir_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::reservoir_gates)
 * @brief The reservoir gates from the config.
 * @return The reservoir gates.
 */
ConnectionsHandle Group_reservoir_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_plunger_gates | falcon_core::physics::config::core::StandardConfigConnections::plunger_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::plunger_gates)
 * @brief The plunger gates from the config.
 * @return The plunger gates.
 */
ConnectionsHandle Group_plunger_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_barrier_gates | falcon_core::physics::config::core::StandardConfigConnections::barrier_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::barrier_gates)
 * @brief The barrier gates from the config.
 * @return The barrier gates.
 */
ConnectionsHandle Group_barrier_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_ohmics | falcon_core::physics::config::core::Group::ohmics */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::ohmics)
 * @brief collect the ohmics pertaining to this group.
 */
ConnectionsHandle Group_ohmics(GroupHandle handle);
/* AUTO-DOC from cpp: Group_dot_gates | falcon_core::physics::config::core::StandardConfigConnections::dot_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::dot_gates)
 * @brief Gets the connections of type as supplied.
 * @param conn_type The type of connection to get. The types of supported
 * connections are: Connection, Connection, Connection, Connection,
 * Connection, DotGate, Gate. and Connection
 * @returns the plural form of the connection type. This corresponds to the
 * conn_type
 */
ConnectionsHandle Group_dot_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_ohmic | falcon_core::physics::config::core::StandardConfigConnections::get_ohmic */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_ohmic)
 * @brief Gets the first ohmic connection.
 */
ConnectionHandle  Group_get_ohmic(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_barrier_gate | falcon_core::physics::config::core::StandardConfigConnections::get_barrier_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_barrier_gate)
 * @brief Gets the first barrier gate connection.
 */
ConnectionHandle  Group_get_barrier_gate(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_plunger_gate | falcon_core::physics::config::core::StandardConfigConnections::get_plunger_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_plunger_gate)
 * @brief Gets the first plunger gate connection.
 */
ConnectionHandle  Group_get_plunger_gate(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_reservoir_gate | falcon_core::physics::config::core::StandardConfigConnections::get_reservoir_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_reservoir_gate)
 * @brief Gets the first reservoir gate connection..
 */
ConnectionHandle  Group_get_reservoir_gate(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_screening_gate | falcon_core::physics::config::core::StandardConfigConnections::get_screening_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_screening_gate)
 * @brief Gets the first screening gate connection.
 */
ConnectionHandle  Group_get_screening_gate(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_dot_gate | falcon_core::physics::config::core::StandardConfigConnections::get_dot_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_dot_gate)
 * @brief Gets the first dot gate connection.
 */
ConnectionHandle  Group_get_dot_gate(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_gate | falcon_core::physics::config::core::StandardConfigConnections::get_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_gate)
 * @brief Gets the first gate connection.
 */
ConnectionHandle  Group_get_gate(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_all_gates | falcon_core::physics::config::core::StandardConfigConnections::get_all_gates */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_all_gates)
 * @brief Gets all of the gates for this collection from the config.
 */
ConnectionsHandle Group_get_all_gates(GroupHandle handle);
/* AUTO-DOC from cpp: Group_get_all_connections | falcon_core::physics::config::core::StandardConfigConnections::get_all_connections */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::get_all_connections)
 * @brief Gets all of the connections for this collection from the config.
 */
ConnectionsHandle Group_get_all_connections(GroupHandle handle);
/* AUTO-DOC from cpp: Group_has_ohmic | falcon_core::physics::config::core::StandardConfigConnections::has_ohmic */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::has_ohmic)
 * @brief If this ohmic is a member of this group or not.
 */
bool              Group_has_ohmic(GroupHandle handle, ConnectionHandle ohmic);
/* AUTO-DOC from cpp: Group_has_gate | falcon_core::physics::config::core::StandardConfigConnections::has_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::has_gate)
 * @brief If this gate is a member of this group or not.
 */
bool              Group_has_gate(GroupHandle handle, ConnectionHandle gate);
/* AUTO-DOC from cpp: Group_has_barrier_gate | falcon_core::physics::config::core::StandardConfigConnections::has_barrier_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::has_barrier_gate)
 * @brief If this gate is a barriergate of this group or not.
 */
bool Group_has_barrier_gate(GroupHandle handle, ConnectionHandle barrier_gate);
/* AUTO-DOC from cpp: Group_has_plunger_gate | falcon_core::physics::config::core::StandardConfigConnections::has_plunger_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::has_plunger_gate)
 * @brief If this gate is a plungergate of this group or not.
 */
bool Group_has_plunger_gate(GroupHandle handle, ConnectionHandle plunger_gate);
/* AUTO-DOC from cpp: Group_has_reservoir_gate | falcon_core::physics::config::core::StandardConfigConnections::has_reservoir_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::has_reservoir_gate)
 * @brief If this gate is a reservoirgate of this group or not.
 */
bool Group_has_reservoir_gate(GroupHandle      handle,
                              ConnectionHandle reservoir_gate);
/* AUTO-DOC from cpp: Group_has_screening_gate | falcon_core::physics::config::core::StandardConfigConnections::has_screening_gate */
/**
 * @brief (from C++: falcon_core::physics::config::core::StandardConfigConnections::has_screening_gate)
 * @brief If this gate is a screeninggate of this group or not.
 */
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
