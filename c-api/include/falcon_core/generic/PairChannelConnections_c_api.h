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
FALCON_CORE_C_API PairChannelConnectionsHandle PairChannelConnections_create(ChannelHandle first, ConnectionsHandle second);
// @category:allocation
FALCON_CORE_C_API PairChannelConnectionsHandle PairChannelConnections_copy(PairChannelConnectionsHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairChannelConnections_destroy(PairChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API ChannelHandle PairChannelConnections_first(PairChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionsHandle PairChannelConnections_second(PairChannelConnectionsHandle handle);
// @category:read
FALCON_CORE_C_API bool PairChannelConnections_equal(PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other);
// @category:read
FALCON_CORE_C_API bool PairChannelConnections_not_equal(PairChannelConnectionsHandle handle, PairChannelConnectionsHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairChannelConnections_to_json_string(PairChannelConnectionsHandle handle);
// @category:allocation
FALCON_CORE_C_API PairChannelConnectionsHandle PairChannelConnections_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif