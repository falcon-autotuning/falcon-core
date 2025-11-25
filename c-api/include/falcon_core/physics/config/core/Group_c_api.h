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
GroupHandle Group_create(ChannelHandle     name,
                         int               num_dots,
                         ConnectionsHandle screening_gates,
                         ConnectionsHandle reservoir_gates,
                         ConnectionsHandle plunger_gates,
                         ConnectionsHandle barrier_gates,
                         ConnectionsHandle order);
// @category:deallocation
void Group_destroy(GroupHandle handle);
// @category:read
ChannelHandle Group_name(GroupHandle handle);
// @category:read
int Group_num_dots(GroupHandle handle);
// @category:read
GateGeometryArray1DHandle Group_order(GroupHandle handle);
// @category:read
bool Group_has_channel(GroupHandle handle, ChannelHandle channel);
// @category:read
bool Group_is_charge_sensor(GroupHandle handle);
// @category:read
ConnectionsHandle Group_get_all_channel_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_screening_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_reservoir_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_plunger_gates(GroupHandle handle);
// @category:read
ConnectionsHandle Group_barrier_gates(GroupHandle handle);
<<<<<<< HEAD
/* AUTO-DOC from cpp: Group_ohmics |
 * falcon_core::physics::config::core::Group::ohmics */
/**
 * @brief (from C++: falcon_core::physics::config::core::Group::ohmics)
 * @brief collect the ohmics pertaining to this group.
 */
=======
// @category:read
>>>>>>> 8f545d27 (Lots of categroies added to the entirety of physics in the c-api headers)
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
// @category:read
bool Group_equal(GroupHandle handle, GroupHandle other);
// @category:read
bool Group_not_equal(GroupHandle handle, GroupHandle other);
// @category:read
StringHandle Group_to_json_string(GroupHandle handle);
// @category:allocation
GroupHandle Group_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif
