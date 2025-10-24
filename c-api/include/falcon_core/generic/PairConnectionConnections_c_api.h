#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connections_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionsHandle;
// Function declarations

PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second);
void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle);
ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle);
ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle);
bool PairConnectionConnections_equal(PairConnectionConnectionsHandle a, PairConnectionConnectionsHandle b);
// Serialization (from Song)
const char*      PairConnectionConnections_to_json_string(PairConnectionConnectionsHandle handle);
PairConnectionConnectionsHandle PairConnectionConnections_from_json_string(const char* json);

#ifdef __cplusplus
}
#endif