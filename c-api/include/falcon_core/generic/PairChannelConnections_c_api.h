#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/autotuner_interfaces/names/Channel_c_api.h"
#include "falcon_core/physics/device_structures/Connections_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairChannelConnectionsHandle;
// Function declarations

// @category:allocation
/* AUTO-DOC from cpp: PairChannelConnections_create | falcon_core::generic::Pair::create */
/**
 * @brief Store a pair of values.
 * @param first The first value.
 * @param second The second value.
 */
PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second);
// @category:deallocation
void PairChannelConnections_destroy(PairChannelConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairChannelConnections_first | falcon_core::generic::Pair::first */
/**
 * @brief Get the stored first value.
 */
ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle);
// @category:read
/* AUTO-DOC from cpp: PairChannelConnections_second | falcon_core::generic::Pair::second */
/**
 * @brief Get the stored second value.
 */
ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle);
// @category:read
bool PairChannelConnections_equal(PairChannelConnectionsHandle a, PairChannelConnectionsHandle b);
// @category:read
bool PairChannelConnections_not_equal(PairChannelConnectionsHandle a, PairChannelConnectionsHandle b);
// @category:read
StringHandle      PairChannelConnections_to_json_string(PairChannelConnectionsHandle handle);
// @category:allocation
PairChannelConnectionsHandle PairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif