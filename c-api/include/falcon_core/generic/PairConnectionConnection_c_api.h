#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include <stdbool.h>
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionHandle;
// Function declarations

// @category:allocation
FALCON_CORE_C_API PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second);
// @category:allocation
FALCON_CORE_C_API PairConnectionConnectionHandle PairConnectionConnection_copy(PairConnectionConnectionHandle handle);
// @category:deallocation
FALCON_CORE_C_API void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle);
// @category:read
FALCON_CORE_C_API ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle);
// @category:read
FALCON_CORE_C_API bool PairConnectionConnection_equal(PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other);
// @category:read
FALCON_CORE_C_API bool PairConnectionConnection_not_equal(PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other);
// @category:read
FALCON_CORE_C_API StringHandle      PairConnectionConnection_to_json_string(PairConnectionConnectionHandle handle);
// @category:allocation
FALCON_CORE_C_API PairConnectionConnectionHandle PairConnectionConnection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif