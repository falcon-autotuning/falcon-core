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
PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second);
// @category:allocation
PairConnectionConnectionHandle PairConnectionConnection_copy(PairConnectionConnectionHandle handle);
// @category:deallocation
void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle);
// @category:read
ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle);
// @category:read
ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle);
// @category:read
bool PairConnectionConnection_equal(PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other);
// @category:read
bool PairConnectionConnection_not_equal(PairConnectionConnectionHandle handle, PairConnectionConnectionHandle other);
// @category:read
StringHandle      PairConnectionConnection_to_json_string(PairConnectionConnectionHandle handle);
// @category:allocation
PairConnectionConnectionHandle PairConnectionConnection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif