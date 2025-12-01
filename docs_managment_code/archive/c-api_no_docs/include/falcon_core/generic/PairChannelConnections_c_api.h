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

PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second);
void PairChannelConnections_destroy(PairChannelConnectionsHandle handle);
ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle);
ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle);
bool PairChannelConnections_equal(PairChannelConnectionsHandle a, PairChannelConnectionsHandle b);
bool PairChannelConnections_not_equal(PairChannelConnectionsHandle a, PairChannelConnectionsHandle b);
// Serialization (from Song)
StringHandle      PairChannelConnections_to_json_string(PairChannelConnectionsHandle handle);
PairChannelConnectionsHandle PairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif