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

// @category:allocation
GroupHandle Group_copy(GroupHandle handle);
// @category:deallocation
void Group_destroy(GroupHandle handle);
// @category:read
bool Group_equal(GroupHandle handle, GroupHandle other);
// @category:read
bool Group_not_equal(GroupHandle handle, GroupHandle other);
// @category:read
StringHandle Group_to_json_string(GroupHandle handle);
// @category:allocation
GroupHandle Group_from_json_string(StringHandle json);
// @category:allocation
GroupHandle Group_create(ChannelHandle     name,
                         int               num_dots,
                         ConnectionsHandle screening_gates,
                         ConnectionsHandle reservoir_gates,
                         ConnectionsHandle plunger_gates,
                         ConnectionsHandle barrier_gates,
                         ConnectionsHandle order);
// @category:read
/* AUTO-DOC from cpp: Group_name |
 * falcon_core::physics::config::core::Group::name */
/**
 * @brief collect the name of this group.
 */
ChannelHandle Group_name(GroupHandle handle);
// @category:read
/* AUTO-DOC from cpp: Group_num_dots |
 * falcon_core::physics::config::core::Group::num_dots */
/**
 * @brief collect the number of dots in this group.
 */
int Group_num_dots(GroupHandle handle);
// @category:read
/* AUTO-DOC from cpp: Group_order |
 * falcon_core::physics::config::core::Group::order */
/**
 * @brief collect the order of the gates in this group.
 */
GateGeometryArray1DHandle Group_order(GroupHandle handle);
// @category:read
/* AUTO-DOC from cpp: Group_has_channel |
 * falcon_core::physics::config::core::Group::has_channel */
/**
 * @brief Validates if this channel is present.
 * @param channel The channel to validate.
 * @returns true if the channel is present.
 */
bool Group_has_channel(GroupHandle handle, ChannelHandle channel);
// @category:read
/* AUTO-DOC from cpp: Group_is_charge_sensor |
 * falcon_core::physics::config::core::Group::is_charge_sensor */
/**
 * @brief Checks if this channel could be a charge sensor.
 * @returns true if the channel has a single dot.
 */
bool Group_is_charge_sensor(GroupHandle handle);
// @category:read
/* AUTO-DOC from cpp: Group_get_all_channel_gates |
 * falcon_core::physics::config::core::Group::get_all_channel_gates */
/**
 * @brief Gets all of the gates assocciated with this channel from the
 * config.
 * @param channel The channel to collect the gates for.
 * @returns The gates associated with this channel. If the channel is not
 * correct then empty gates are returned.
 */
ConnectionsHandle Group_get_all_channel_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_screening_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_reservoir_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_plunger_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_barrier_gates(GroupHandle handle);
// @category:read
/* AUTO-DOC from cpp: Group_ohmics |
 * falcon_core::physics::config::core::Group::ohmics */
/**
 * @brief collect the ohmics pertaining to this group.
 */
ConnectionsHandle Group_ohmics(GroupHandle handle);
// @category:read
ConnectionsHandle Group_dot_gates(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_ohmic(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_barrier_gate(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_plunger_gate(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_reservoir_gate(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_screening_gate(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_dot_gate(GroupHandle handle);
// @category:read
ConnectionHandle Group_get_gate(GroupHandle handle);
// @category:read
ConnectionsHandle Group_get_all_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_get_all_connections(GroupHandle handle);
// @category:read
bool Group_has_ohmic(GroupHandle handle, ConnectionHandle ohmic);
// @category:read
bool Group_has_gate(GroupHandle handle, ConnectionHandle gate);
// @category:read
bool Group_has_barrier_gate(GroupHandle handle, ConnectionHandle barrier_gate);
// @category:read
bool Group_has_plunger_gate(GroupHandle handle, ConnectionHandle plunger_gate);
// @category:read
bool Group_has_reservoir_gate(GroupHandle      handle,
                              ConnectionHandle reservoir_gate);
// @category:read
bool Group_has_screening_gate(GroupHandle      handle,
                              ConnectionHandle screening_gate);

#ifdef __cplusplus
}
#endif
