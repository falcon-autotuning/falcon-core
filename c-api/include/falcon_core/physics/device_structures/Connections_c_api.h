#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "falcon_core/generic/ListConnection_c_api.h"
#include "falcon_core/physics/device_structures/Connection_c_api.h"
typedef void* ConnectionsHandle;

// @category:allocation
FALCON_CORE_C_API ConnectionsHandle Connections_copy(ConnectionsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void Connections_destroy(ConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool Connections_equal(ConnectionsHandle handle,
                                         ConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool Connections_not_equal(ConnectionsHandle handle,
                                             ConnectionsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle
Connections_to_json_string(ConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API ConnectionsHandle
Connections_from_json_string(StringHandle json);
// @category:allocation
FALCON_CORE_C_API ConnectionsHandle Connections_create_empty();
// @category:allocation
FALCON_CORE_C_API ConnectionsHandle
Connections_create(ListConnectionHandle items);
// @category:read
/* AUTO-DOC from cpp: Connections_is_gates |
 * falcon_core::physics::device_structures::Connections::is_gates */
/**
 * @brief Check if all connections are gates (not ohmics).
 */
FALCON_CORE_C_API bool Connections_is_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_ohmics |
 * falcon_core::physics::device_structures::Connections::is_ohmics */
/**
 * @brief Check if all connections are ohmics (not gates).
 */
FALCON_CORE_C_API bool Connections_is_ohmics(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_dot_gates |
 * falcon_core::physics::device_structures::Connections::is_dot_gates */
/**
 * @brief Check if all connections are dot gates (plunger or barrier).
 */
FALCON_CORE_C_API bool Connections_is_dot_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_plunger_gates |
 * falcon_core::physics::device_structures::Connections::is_plunger_gates */
/**
 * @brief Check if all connections are plunger gates.
 */
FALCON_CORE_C_API bool Connections_is_plunger_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_barrier_gates |
 * falcon_core::physics::device_structures::Connections::is_barrier_gates */
/**
 * @brief Check if all connections are barrier gates.
 */
FALCON_CORE_C_API bool Connections_is_barrier_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_reservoir_gates |
 * falcon_core::physics::device_structures::Connections::is_reservoir_gates */
/**
 * @brief Check if all connections are reservoir gates.
 */
FALCON_CORE_C_API bool Connections_is_reservoir_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_is_screening_gates |
 * falcon_core::physics::device_structures::Connections::is_screening_gates */
/**
 * @brief Check if all connections are screening gates.
 */
FALCON_CORE_C_API bool Connections_is_screening_gates(ConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: Connections_intersection |
 * falcon_core::physics::device_structures::Connections::intersection */
/**
 * @brief Finds the intersection between this list and another.
 * @param other the other list to compare again.
 * @returns A list of values containing elements from both.
 */
FALCON_CORE_C_API ConnectionsHandle
Connections_intersection(ConnectionsHandle handle, ConnectionsHandle other);
// @category:write
FALCON_CORE_C_API void Connections_push_back(ConnectionsHandle handle,
                                             ConnectionHandle  value);
// @category:read
FALCON_CORE_C_API size_t Connections_size(ConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool Connections_empty(ConnectionsHandle handle);
// @category:write
FALCON_CORE_C_API void Connections_erase_at(ConnectionsHandle handle,
                                            size_t            idx);
// @category:write
FALCON_CORE_C_API void Connections_clear(ConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle Connections_at(ConnectionsHandle handle,
                                                  size_t            idx);
// @category:read
FALCON_CORE_C_API ListConnectionHandle
Connections_items(ConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool Connections_contains(ConnectionsHandle handle,
                                            ConnectionHandle  value);
// @category:read
FALCON_CORE_C_API size_t Connections_index(ConnectionsHandle handle,
                                           ConnectionHandle  value);

#ifdef __cplusplus
}
#endif
