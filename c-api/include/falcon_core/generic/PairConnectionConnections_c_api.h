#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionsHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairConnectionConnections_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second);
// @category:deallocation
void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairConnectionConnections_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairConnectionConnections_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle);
// @category:read
bool PairConnectionConnections_equal(PairConnectionConnectionsHandle a, PairConnectionConnectionsHandle b);
// @category:read
bool PairConnectionConnections_not_equal(PairConnectionConnectionsHandle a, PairConnectionConnectionsHandle b);
// @category:read
StringHandle      PairConnectionConnections_to_json_string(PairConnectionConnectionsHandle handle);
// @category:allocation
PairConnectionConnectionsHandle PairConnectionConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif