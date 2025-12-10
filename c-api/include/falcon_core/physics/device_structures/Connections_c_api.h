#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ConnectionsHandle;

// @category:allocation
ConnectionsHandle Connections_copy(ConnectionsHandle handle);
// @category:deallocation
void Connections_destroy(ConnectionsHandle handle);
// @category:read
bool Connections_equal(ConnectionsHandle handle, ConnectionsHandle other);
// @category:read
bool Connections_not_equal(ConnectionsHandle handle, ConnectionsHandle other);
// @category:read
StringHandle Connections_to_json_string(ConnectionsHandle handle);
// @category:allocation
ConnectionsHandle Connections_from_json_string(StringHandle json);
// @category:allocation
ConnectionsHandle Connections_create_empty();
// @category:allocation
ConnectionsHandle Connections_create(ListConnectionHandle items);
// @category:read
/* AUTO-DOC from cpp: Connections_is_gates |
 * falcon_core::physics::device_structures::Connections::is_gates */
/**
 * @brief Check if all connections are gates (not ohmics).
 */
bool Connections_is_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_ohmics |
 * falcon_core::physics::device_structures::Connections::is_ohmics */
/**
 * @brief Check if all connections are ohmics (not gates).
 */
bool Connections_is_ohmics(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_dot_gates |
 * falcon_core::physics::device_structures::Connections::is_dot_gates */
/**
 * @brief Check if all connections are dot gates (plunger or barrier).
 */
bool Connections_is_dot_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_plunger_gates |
 * falcon_core::physics::device_structures::Connections::is_plunger_gates */
/**
 * @brief Check if all connections are plunger gates.
 */
bool Connections_is_plunger_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_barrier_gates |
 * falcon_core::physics::device_structures::Connections::is_barrier_gates */
/**
 * @brief Check if all connections are barrier gates.
 */
bool Connections_is_barrier_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_reservoir_gates |
 * falcon_core::physics::device_structures::Connections::is_reservoir_gates */
/**
 * @brief Check if all connections are reservoir gates.
 */
bool Connections_is_reservoir_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_screening_gates |
 * falcon_core::physics::device_structures::Connections::is_screening_gates */
/**
 * @brief Check if all connections are screening gates.
 */
bool Connections_is_screening_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_intersection |
 * falcon_core::physics::device_structures::Connections::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
ConnectionsHandle Connections_intersection(ConnectionsHandle handle,
                                           ConnectionsHandle other);
// @category:write
void Connections_push_back(ConnectionsHandle handle, ConnectionHandle value);
// @category:read
size_t Connections_size(ConnectionsHandle handle);
// @category:read
bool Connections_empty(ConnectionsHandle handle);
// @category:write
void Connections_erase_at(ConnectionsHandle handle, size_t idx);
// @category:write
void Connections_clear(ConnectionsHandle handle);
// @category:read
ConnectionHandle Connections_at(ConnectionsHandle handle, size_t idx);
// @category:read
ListConnectionHandle Connections_items(ConnectionsHandle handle);
// @category:read
bool Connections_contains(ConnectionsHandle handle, ConnectionHandle value);
// @category:read
size_t Connections_index(ConnectionsHandle handle, ConnectionHandle value);

#ifdef __cplusplus
}
#endif
