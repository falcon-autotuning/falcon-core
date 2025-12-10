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
PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second);
// @category:allocation
PairChannelConnectionsHandle PairChannelConnections_copy(PairChannelConnectionsHandle handle);
// @category:deallocation
void PairChannelConnections_destroy(PairChannelConnectionsHandle handle);
// @category:read
ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle);
// @category:read
ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle);
// @category:read
bool PairChannelConnections_equal(PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other);
// @category:read
bool PairChannelConnections_not_equal(PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other);
// @category:read
StringHandle      PairChannelConnections_to_json_string(PairChannelConnectionsHandle handle);
// @category:allocation
PairChannelConnectionsHandle PairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif