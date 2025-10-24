#pragma once
#ifdef __cplusplus
    extern "C" {
#endif
#include "falcon_core/physics/device_structures/Connection_c_api.h"
#include "falcon_core/generic/String_c_api.h"

// Forward declarations for opaque handles
typedef void* PairConnectionConnectionHandle;
// Function declarations

PairConnectionConnectionHandle PairConnectionConnection_create(ConnectionHandle first, ConnectionHandle second);
void PairConnectionConnection_destroy(PairConnectionConnectionHandle handle);
ConnectionHandle PairConnectionConnection_first(PairConnectionConnectionHandle handle);
ConnectionHandle PairConnectionConnection_second(PairConnectionConnectionHandle handle);
bool PairConnectionConnection_equal(PairConnectionConnectionHandle a, PairConnectionConnectionHandle b);
// Serialization (from Song)
StringHandle      PairConnectionConnection_to_json_string(PairConnectionConnectionHandle handle);
PairConnectionConnectionHandle PairConnectionConnection_from_json_string(StringHandle json);

#ifdef __cplusplus
}
#endif