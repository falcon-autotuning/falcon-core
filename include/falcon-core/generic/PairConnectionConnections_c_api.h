#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon-core/physics/device_structures/Connections_c_api.h"
#include <stdbool.h>
#include "falcon-core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionsHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairConnectionConnectionsHandle PairConnectionConnections_create(ConnectionHandle first, ConnectionsHandle second);
// @category:allocation
FALCON_CORE_C_API PairConnectionConnectionsHandle PairConnectionConnections_copy(PairConnectionConnectionsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairConnectionConnections_destroy(PairConnectionConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionConnections_first(PairConnectionConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionsHandle PairConnectionConnections_second(PairConnectionConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool PairConnectionConnections_equal(PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool PairConnectionConnections_not_equal(PairConnectionConnectionsHandle handle, PairConnectionConnectionsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairConnectionConnections_to_json_string(PairConnectionConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API PairConnectionConnectionsHandle PairConnectionConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif